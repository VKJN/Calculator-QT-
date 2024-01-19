#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
    QString operation;
    QString prev;

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void getDigit();
    void clearResult();
    void checkOperatoin();
    void getResult();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
