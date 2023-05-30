
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "Parser.h"
#include <string>
using namespace std;
#include <QMainWindow>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class Character;

class MainWindow : public QMainWindow

{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    Parser parser;
    string objectU = "null";
    vector<string> stringInv;
    void printOut(string output);
    bool hasF = false;
    bool hasK = false;
    void setLabel(string instr);

public slots:

    void on_pushButton_clicked();
    void on_pushButtonE_2_clicked();
    void on_pushButtonN_clicked();

    void on_pushButtonW_clicked();

    void on_pushButtonS_clicked();

    void on_pushButtonE_clicked();

    void on_putButton_clicked();

    void on_helpButton_clicked();

    void on_invButton_clicked();

    void on_mapButton_clicked();

    void on_item2_clicked();

    void on_takeButton_clicked();

    void getInv(Character& character);

    void on_useButton_clicked();

private slots:
    void on_item3_clicked();

    void on_exitInv_clicked();

    void on_invItem3_clicked();

    void on_openButton_clicked();

    void on_invItem2_clicked();

    void on_item1_clicked();

    void on_invItem1_clicked();

    void on_winB_clicked();

    void on_smashButton_clicked();

private:
    Ui::MainWindow *ui;

};

#endif // MAINWINDOW_H
