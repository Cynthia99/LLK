#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include "llkanarea.h"
#include "timearea.h"

class MainWidget : public QWidget
{
    Q_OBJECT
public:
    MainWidget(QWidget *parent = 0);
    void mousePressEvent(QMouseEvent *);

private:
    LLKanArea *llkanArea;
    TimeArea *timeArea;
};

#endif // MAINWIDGET_H
