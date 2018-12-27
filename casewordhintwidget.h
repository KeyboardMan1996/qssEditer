#ifndef CASEWORDHINTWIDGET_H
#define CASEWORDHINTWIDGET_H

#include <QWidget>

namespace Ui {
class CaseWordHintWidget;
}

class CaseWordHintWidget : public QWidget
{
    Q_OBJECT

public:
    explicit CaseWordHintWidget(QWidget *parent = 0);
    ~CaseWordHintWidget();

private:
    Ui::CaseWordHintWidget *ui;
};

#endif // CASEWORDHINTWIDGET_H
