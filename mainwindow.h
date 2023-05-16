
#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "Parser.h"
#include <string>
using namespace std;
#include <QMainWindow>



QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow

{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    Parser parser;
    void printOut(string output);

private slots:
    void on_pushButton_clicked();
    void updateData(string info);
    void on_pushButtonE_2_clicked();
    void on_pushButtonN_clicked();

    void on_pushButtonW_clicked();

    void on_pushButtonS_clicked();

    void on_pushButtonE_clicked();

    void on_putButton_clicked();

    void on_helpButton_clicked();

    void on_invButton_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
