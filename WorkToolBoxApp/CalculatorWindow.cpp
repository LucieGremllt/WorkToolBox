#include "CalculatorWindow.h"
#include <QFont>
#include <QApplication>
#include <QPushButton>
#include <QLineEdit>
#include <QMainWindow>
#include <QString>
#include <string>

CalculatorWindow::CalculatorWindow(QWidget* parent) : QWidget(parent)
{
    setWindowFlags(Qt::Window | Qt::WindowCloseButtonHint);
    setFixedSize(370, 460);

    this->setWindowTitle("Calculator");

    countResults = 0;



    QFont ButtonFont;
    ButtonFont.setPointSize(18);
    QFont DisplayFont1;
    DisplayFont1.setPointSize(20);
    QFont DisplayFont2;
    DisplayFont2.setPointSize(24);


    setStyleSheet(
        "QPushButton {"
        "   background-color: #A867C7;"
        "   border-radius: 5px;"
        "}"
        "CalculatorWindow {"
        "   background-color: #84429E;"
        "}"
        "#MainDisplay {"
        "   color: #84429E;"
        "   background-color: white;"
        "}"
        "#ResultDisplay {"
        "   color: #787878;"
        "   background-color: white;"
        "}"
    );

    //UI

    //TextAreas
    MainDisplay = new QLineEdit(this);
    MainDisplay->setObjectName("MainDisplay");
    MainDisplay->setGeometry(10, 10, 350, 60);
    MainDisplay->setReadOnly(true);
    MainDisplay->setAlignment(Qt::AlignCenter);
    MainDisplay->setPlaceholderText("Tapez votre calcul");
    MainDisplay->setFont(DisplayFont1);

    ResultDisplay = new QLineEdit(this);
    ResultDisplay->setObjectName("ResultDisplay");
    ResultDisplay->setGeometry(10, 70, 350, 60);
    ResultDisplay->setReadOnly(true);
    ResultDisplay->setAlignment(Qt::AlignCenter);
    ResultDisplay->setFont(DisplayFont2);


    //Digits panel
    button1 = new QPushButton("1", this);
    button1->setGeometry(10, 160, 80, 50);
    button1->setFont(ButtonFont);
    button2 = new QPushButton("2", this);
    button2->setGeometry(100, 160, 80, 50);
    button2->setFont(ButtonFont);
    button3 = new QPushButton("3", this);
    button3->setGeometry(190, 160, 80, 50);
    button3->setFont(ButtonFont);
    button4 = new QPushButton("4", this);
    button4->setGeometry(10, 220, 80, 50);
    button4->setFont(ButtonFont);
    button5 = new QPushButton("5", this);
    button5->setGeometry(100, 220, 80, 50);
    button5->setFont(ButtonFont);
    button6 = new QPushButton("6", this);
    button6->setGeometry(190, 220, 80, 50);
    button6->setFont(ButtonFont);
    button7 = new QPushButton("7", this);
    button7->setGeometry(10, 280, 80, 50);
    button7->setFont(ButtonFont);
    button8 = new QPushButton("8", this);
    button8->setGeometry(100, 280, 80, 50);
    button8->setFont(ButtonFont);
    button9 = new QPushButton("9", this);
    button9->setGeometry(190, 280, 80, 50);
    button9->setFont(ButtonFont);
    ParenthesisL = new QPushButton("(", this);
    ParenthesisL->setGeometry(10, 340, 80, 50);
    ParenthesisL->setFont(ButtonFont);
    button0 = new QPushButton("0", this);
    button0->setGeometry(100, 340, 80, 50);
    button0->setFont(ButtonFont);
    ParenthesisR = new QPushButton(")", this);
    ParenthesisR->setGeometry(190, 340, 80, 50);
    ParenthesisR->setFont(ButtonFont);

    //operators
    buttonPlus = new QPushButton("+", this);
    buttonPlus->setGeometry(280, 160, 80, 50);
    buttonPlus->setFont(ButtonFont);
    buttonMinus = new QPushButton("-", this);
    buttonMinus->setGeometry(280, 220, 80, 50);
    buttonMinus->setFont(ButtonFont);
    buttonMult = new QPushButton("x", this);
    buttonMult->setGeometry(280, 280, 80, 50);
    buttonMult->setFont(ButtonFont);
    buttonDiv = new QPushButton("/", this);
    buttonDiv->setGeometry(280, 340, 80, 50);
    buttonDiv->setFont(ButtonFont);
    ViewResults = new QPushButton("Last", this);
    ViewResults->setGeometry(280, 400, 80, 50);
    ViewResults->setFont(ButtonFont);

    //Other
    buttonDot = new QPushButton(".", this);
    buttonDot->setGeometry(10, 400, 80, 50);
    buttonDot->setFont(ButtonFont);
    buttonEqual = new QPushButton("=", this);
    buttonEqual->setGeometry(100, 400, 80, 50);
    buttonEqual->setFont(ButtonFont);
    buttonReturn = new QPushButton("Del", this);
    buttonReturn->setGeometry(190, 400, 80, 50);
    buttonReturn->setFont(ButtonFont);

    //UX
    connect(button1, &QPushButton::clicked, this, [this](){MainDisplay->insert("1");});
    connect(button2, &QPushButton::clicked, this, [this]() {MainDisplay->insert("2");});
    connect(button3, &QPushButton::clicked, this, [this]() {MainDisplay->insert("3");});
    connect(button4, &QPushButton::clicked, this, [this]() {MainDisplay->insert("4");});
    connect(button5, &QPushButton::clicked, this, [this]() {MainDisplay->insert("5");});
    connect(button6, &QPushButton::clicked, this, [this]() {MainDisplay->insert("6");});
    connect(button7, &QPushButton::clicked, this, [this]() {MainDisplay->insert("7");});
    connect(button8, &QPushButton::clicked, this, [this]() {MainDisplay->insert("8");});
    connect(button9, &QPushButton::clicked, this, [this]() {MainDisplay->insert("9");});
    connect(button0, &QPushButton::clicked, this, [this]() {MainDisplay->insert("0");});
    connect(buttonPlus, &QPushButton::clicked, this, [this]() {MainDisplay->insert("+");});
    connect(buttonMinus, &QPushButton::clicked, this, [this]() {MainDisplay->insert("-");});
    connect(buttonMult, &QPushButton::clicked, this, [this]() {MainDisplay->insert("*");});
    connect(buttonDiv, &QPushButton::clicked, this, [this]() {MainDisplay->insert("/");});
    connect(buttonDot, &QPushButton::clicked, this, [this]() {MainDisplay->insert(".");});
    connect(buttonReturn, &QPushButton::clicked, this, [this]() {MainDisplay->setText("");});
    connect(ParenthesisL, &QPushButton::clicked, this, [this]() {MainDisplay->insert("(");});
    connect(ParenthesisR, &QPushButton::clicked, this, [this]() {MainDisplay->insert(")");});
    connect(buttonEqual, &QPushButton::clicked, this, [this]() {equalButtonClicked();});
    connect(ViewResults, &QPushButton::clicked, this, [this]() {});

}

void CalculatorWindow::equalButtonClicked()
{

}

