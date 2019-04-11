/****************************************************************************
**
** Copyright (C) 2016 The Qt Company Ltd.
** Contact: https://www.qt.io/licensing/
**
** This file is part of the examples of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:BSD$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and The Qt Company. For licensing terms
** and conditions see https://www.qt.io/terms-conditions. For further
** information use the contact form at https://www.qt.io/contact-us.
**
** BSD License Usage
** Alternatively, you may use this file under the terms of the BSD license
** as follows:
**
** "Redistribution and use in source and binary forms, with or without
** modification, are permitted provided that the following conditions are
** met:
**   * Redistributions of source code must retain the above copyright
**     notice, this list of conditions and the following disclaimer.
**   * Redistributions in binary form must reproduce the above copyright
**     notice, this list of conditions and the following disclaimer in
**     the documentation and/or other materials provided with the
**     distribution.
**   * Neither the name of The Qt Company Ltd nor the names of its
**     contributors may be used to endorse or promote products derived
**     from this software without specific prior written permission.
**
**
** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE."
**
** $QT_END_LICENSE$
**
****************************************************************************/

#include <QtWidgets>
#include <qdebug.h>
#include <qglobal.h>
#include "codeeditor.h"
#include "casewordlistwidget.h"
#include "myhightlighter.h"

//![constructor]

CodeEditor::CodeEditor(QWidget *parent) : QPlainTextEdit(parent)
{
    lineNumberArea = new LineNumberArea(this);
    matchWordThrad = new MatchWordsThread;

    connect(this, SIGNAL(blockCountChanged(int)), this, SLOT(updateLineNumberAreaWidth(int)));
    connect(this, SIGNAL(updateRequest(QRect,int)), this, SLOT(updateLineNumberArea(QRect,int)));
    connect(this, SIGNAL(cursorPositionChanged()), this, SLOT(highlightCurrentLine()));
    connect(this->document(),SIGNAL(contentsChange(int,int,int)),SLOT(inserChanged(int,int,int)));
    connect(matchWordThrad,SIGNAL(matchCaseWordFinished(QList<QString>,QList<QString>,int)),this,SLOT(matchFinished(QList<QString>,QList<QString>,int)));
    connect(matchWordThrad,SIGNAL(hideListWidget()),this,SLOT(hideLisetWidget()));

    updateLineNumberAreaWidth(0);
    highlightCurrentLine();

    listWidget = new CaseWordListWidget(this);      //关键字提示窗口
    listWidget->hide();

    myHightLighter *highLighter = new myHightLighter(this->document());         //设置高亮器
    int i =0;
    i++;
}

CodeEditor::~CodeEditor()
{
    matchWordThrad->terminate(); //终止线程
    matchWordThrad->wait();     //等待线程终止
    delete matchWordThrad;

}
//![constructor]

//![extraAreaWidth]

int CodeEditor::lineNumberAreaWidth()
{
    int digits = 1;
    int max = qMax(1, blockCount());
    while (max >= 10) {
        max /= 10;
        ++digits;
    }

    int space = 20 + fontMetrics().width(QLatin1Char('9')) * digits;

    return space;
}

//![extraAreaWidth]

//![slotUpdateExtraAreaWidth]

void CodeEditor::updateLineNumberAreaWidth(int /* newBlockCount */)
{
    setViewportMargins(lineNumberAreaWidth(), 0, 0, 0);
}

//![slotUpdateExtraAreaWidth]

//![slotUpdateRequest]

void CodeEditor::updateLineNumberArea(const QRect &rect, int dy)
{
    if (dy)
        lineNumberArea->scroll(0, dy);
    else
        lineNumberArea->update(0, rect.y(), lineNumberArea->width(), rect.height());

    if (rect.contains(viewport()->rect()))
        updateLineNumberAreaWidth(0);
}

//![slotUpdateRequest]

//![resizeEvent]

void CodeEditor::resizeEvent(QResizeEvent *e)
{
    QPlainTextEdit::resizeEvent(e);

    QRect cr = contentsRect();
    lineNumberArea->setGeometry(QRect(cr.left(), cr.top(), lineNumberAreaWidth(), cr.height()));
}

//![resizeEvent]

//![cursorPositionChanged]

void CodeEditor::highlightCurrentLine()
{
    QList<QTextEdit::ExtraSelection> extraSelections;

    if (!isReadOnly()) {
        QTextEdit::ExtraSelection selection;

        QColor lineColor = QColor(Qt::yellow).lighter(160);

        selection.format.setBackground(lineColor);
        selection.format.setProperty(QTextFormat::FullWidthSelection, true);
        selection.cursor = textCursor();
        selection.cursor.clearSelection();
        extraSelections.append(selection);
    }

    setExtraSelections(extraSelections);
}

//![cursorPositionChanged]

//![extraAreaPaintEvent_0]

void CodeEditor::lineNumberAreaPaintEvent(QPaintEvent *event)
{
    QPainter painter(lineNumberArea);
    painter.fillRect(event->rect(), Qt::lightGray);

//![extraAreaPaintEvent_0]

//![extraAreaPaintEvent_1]
    QTextBlock block = firstVisibleBlock();
    int blockNumber = block.blockNumber();
    int top = (int) blockBoundingGeometry(block).translated(contentOffset()).top();
    int bottom = top + (int) blockBoundingRect(block).height();
//![extraAreaPaintEvent_1]

//![extraAreaPaintEvent_2]
    while (block.isValid() && top <= event->rect().bottom()) {
        if (block.isVisible() && bottom >= event->rect().top()) {
            QString number = QString::number(blockNumber + 1);
            painter.setPen(Qt::black);
            painter.drawText(0, top, lineNumberArea->width(), fontMetrics().height(),
                             Qt::AlignCenter, number);
        }
        block = block.next();
        top = bottom;
        bottom = top + (int) blockBoundingRect(block).height();
        ++blockNumber;
    }



}
/*
*文本改变事件
* @position 插入位置
* @charsRemoved 删除字符的个数
* @charsAdded 增加字符的个数
* 在这个事件里取词，根据光标的位置，取当前输入的单词
*/
void  CodeEditor::inserChanged(int position, int charsRemoved, int charsAdded)
{
    QTextCursor cursor = this->textCursor();        //获取当前文本光标
    QString blockText = cursor.block().text();      //获取光标所在文本块的文本
    blockText = blockText.left(cursor.positionInBlock());   //获取光标之前的文本

    matchWordThrad->setMatchWord(blockText);

}
/*
*关键字匹配完成槽
* 将关键字放入listwidget中
* 如果没有匹配的关键字，则隐藏listwidget
* @vipCaseWords 完全匹配的关键字
* @lowCaseWords 模糊匹配的关键字
* @caseWordSize 用户键入关键字的长度
*/
void CodeEditor::matchFinished(QList<QString> vipCaseWords, QList<QString> lowCaseWords,int caseWordSize)
{
    if(vipCaseWords.size() == 0 && lowCaseWords.size() == 0)
    {
        listWidget->hide();
        return;
    }
    this->caseWordCurrentSize = caseWordSize;
    listWidget->clear();
    listWidget->addItems(vipCaseWords);
    listWidget->addItems(lowCaseWords);
    listWidget->setCurrentRow(0);
    //设置listwidget的位置
    QTextBlock block = firstVisibleBlock();
    QTextCursor cursor = this->textCursor();
    QTextBlock cursorBlock = cursor.block();
    int y = 3;
    while(block != cursorBlock)     //获取文本块在当前显示区域是第几行
    {
        y = y + blockBoundingRect(block).height();          //加上文本块矩形的高度（获取的矩形是加上了行距的）
        block = block.next();
    }
    y = y + blockBoundingRect(block).height();
  //  int x = 3 + cursor.positionInBlock() *fontMetrics().width('a');
    int x = 3 + lineNumberAreaWidth();                  //加上行号显示区域的宽度
    QString text = QString(cursorBlock.text()).left(cursor.positionInBlock());
    for(int i = 0; i < text.size();i++)         //获取光标前所有字符相加的宽度，用于关键字提示框的位置
    {
        x = x + fontMetrics().width(text.at(i));
    }
    listWidget->move(x,y);
    listWidget->show();
}
/*
*键盘按下事件
*/
void CodeEditor::keyPressEvent(QKeyEvent *event)
{
    if(!listWidget->isHidden())
    {
        if(event->key() == Qt::Key_Up               //传入上下按键
                ||event->key() == Qt::Key_Down)
        {
            listWidget->keyPressEvent(event);
            return;
        }
        if(event->text() == "\r")               //如果是回车符，则键入关键字
        {
            QString caseWord = listWidget->currentItem()->text();           //获取当前关键字
            QTextCursor cursor = this->textCursor();            //获取光标信息

            cursor.movePosition(QTextCursor::Left,QTextCursor::KeepAnchor,caseWordCurrentSize);

            cursor.insertText(caseWord);    //插入关键字
            this->setTextCursor(cursor);    //设置光标信息
            return;
        }

    }
    //按下tab按键不键入tab符，而是键入连续的空格，可以解决无法获取tab符实际长度的问题
    if(event->key() == Qt::Key_Tab)
    {
        QTextCursor cursor = this->textCursor();
        cursor.insertText("     ");
        this->setTextCursor(cursor);
        return;
    }

    QPlainTextEdit::keyPressEvent(event);
}
//隐藏关键词提示的listwiget
void CodeEditor::hideLisetWidget()
{
    listWidget->hide();
}
//重写字体设置函数
void CodeEditor::setFont(const QFont &font)
{
    QPlainTextEdit::setFont(font);
    listWidget->setFont(font);
}
