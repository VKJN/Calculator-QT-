#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <math.h>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    operation = "";
    ui->Field->setText("");
    connect(ui->pushButton_0, SIGNAL(clicked()),this,SLOT(getDigit()));
    connect(ui->pushButton_1, SIGNAL(clicked()),this,SLOT(getDigit()));
    connect(ui->pushButton_2, SIGNAL(clicked()),this,SLOT(getDigit()));
    connect(ui->pushButton_3, SIGNAL(clicked()),this,SLOT(getDigit()));
    connect(ui->pushButton_4, SIGNAL(clicked()),this,SLOT(getDigit()));
    connect(ui->pushButton_5, SIGNAL(clicked()),this,SLOT(getDigit()));
    connect(ui->pushButton_6, SIGNAL(clicked()),this,SLOT(getDigit()));
    connect(ui->pushButton_7, SIGNAL(clicked()),this,SLOT(getDigit()));
    connect(ui->pushButton_8, SIGNAL(clicked()),this,SLOT(getDigit()));
    connect(ui->pushButton_9, SIGNAL(clicked()),this,SLOT(getDigit()));
    connect(ui->pushButton_point, SIGNAL(clicked()),this,SLOT(getDigit()));

    connect(ui->pushButton_C, SIGNAL(clicked()),this,SLOT(clearResult()));
    connect(ui->pushButton_equals, SIGNAL(clicked()),this,SLOT(getResult()));

    connect(ui->pushButton_plus, SIGNAL(clicked()),this,SLOT(checkOperation()));
    connect(ui->pushButton_minus, SIGNAL(clicked()),this,SLOT(checkOperation()));
    connect(ui->pushButton_division, SIGNAL(clicked()),this,SLOT(checkOperation()));
    connect(ui->pushButton_multiplication, SIGNAL(clicked()),this,SLOT(checkOperation()));
    connect(ui->pushButton_xy, SIGNAL(clicked()),this,SLOT(checkOperation()));

    connect(ui->pushButton_sqrt, SIGNAL(clicked()), this, SLOT(checkOperation()));
    connect(ui->pushButton_x2, SIGNAL(clicked()), this, SLOT(checkOperation()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::getDigit()
{
    QPushButton* btn = (QPushButton*)sender();
    if(ui->Field->text() == "0"){
        if(btn->text() != 0){
            ui->Field->setText(btn->text());
        }
    }
    else if(btn->text() == "."){
        QString str = ui->Field->text();
        if(str.count(".") == 0){
            QString field = ui->Field->text() + btn ->text();
            ui->Field->setText(field);
        }
    }
    else {
        QString field = ui->Field->text() + btn ->text();
        ui->Field->setText(field);
    }
}

void MainWindow::clearResult()
{
    ui->Field->setText("0");
    operation = "";
}

void MainWindow::checkOperation()
{
    QPushButton* btn = (QPushButton*)sender();
    operation = btn->text();
    prev = ui->Field->text();

    if(operation == "sqrt" || operation == "x^2"){
        getResult();
    }

    else{
     ui->Field->setText("0");
    }
}

void MainWindow::getResult(){
    float num1 = prev.toFloat();
    float num2 = ui->Field->text().toFloat();
    float result;
    switch((char)(operation[0].toLatin1())){
    case '+':
        result = num1 + num2;
        break;
    case '-':
        result = num1 - num2;
        break;
    case '*':
        result = num1 * num2;
        break;
    case '/':
        result = num1 / num2;
        break;
    }

    if (operation == "sqrt") {
        result = pow(num1, 0.5);
    }

    else if (operation == "x^2") {
        result = pow(num1, 2);
    }

    else if (operation == "x^y") {
        result = pow(num1, num2);
    }

    ui->Field->setNum(result);
    num1 = num2;
}
