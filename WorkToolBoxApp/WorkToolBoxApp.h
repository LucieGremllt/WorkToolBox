#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_WorkToolBoxApp.h"

class WorkToolBoxApp : public QMainWindow
{
    Q_OBJECT

public:
    WorkToolBoxApp(QWidget *parent = nullptr);
    ~WorkToolBoxApp();

private:
    Ui::WorkToolBoxAppClass ui;
};

