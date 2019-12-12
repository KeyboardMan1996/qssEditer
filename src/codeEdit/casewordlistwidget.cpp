#include "casewordlistwidget.h"

CaseWordListWidget::CaseWordListWidget(QWidget *parent)
    :QListWidget(parent)
{

}

void CaseWordListWidget::keyPressEvent(QKeyEvent *event)
{
    QListWidget::keyPressEvent(event);
}
