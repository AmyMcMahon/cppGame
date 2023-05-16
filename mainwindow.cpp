
#include "mainwindow.h"
#include "ZorkUL.h"
#include "Parser.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QMessageBox>

ZorkUL obj;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPixmap pixmapW("/Users/admcm/OneDrive/Documents/ZorkGui/Image.jpeg");
    QIcon ButtonIconW(pixmapW);
    QPixmap pixmapE("/Users/admcm/OneDrive/Documents/ZorkGui/ImageE.jpeg");
    QIcon ButtonIconE(pixmapE);
    QPixmap pixmapN("/Users/admcm/OneDrive/Documents/ZorkGui/ImageN.jpeg");
    QIcon ButtonIconN(pixmapN);
    QPixmap pixmapS("/Users/admcm/OneDrive/Documents/ZorkGui/ImageS.jpeg");
    QIcon ButtonIconS(pixmapS);
    ui->pushButtonW->setIcon(ButtonIconW);
    ui->pushButtonW->setIconSize(QSize(51,51));
    ui->pushButtonE->setIcon(ButtonIconE);
    ui->pushButtonE->setIconSize(QSize(51,51));
    ui->pushButtonN->setIcon(ButtonIconN);
    ui->pushButtonN->setIconSize(QSize(51,51));
    ui->pushButtonS->setIcon(ButtonIconS);
    ui->pushButtonS->setIconSize(QSize(51,51));
    ui->label->setText(QString::fromStdString(obj.printWelcome()));
    ui->label_2->setText(QString::fromStdString(obj.printWelcome()));
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_pushButton_clicked()
{
    qDebug() << "Button Pressed";
    QMessageBox:: information(this, "Message", "User pressed the button");
}


void MainWindow::on_pushButtonE_2_clicked()
{
    QString str = ui->lineEdit->text();
    string output = obj.getData(str.toStdString());
    QString str2 = QString::fromStdString(output);
    ui->label->setText(str2);
    ui->label_2->setText(str2);
}

//void MainWindow::updateData(){

//}


void MainWindow::on_pushButtonN_clicked()
{
    string instr = "go north";
    string output = obj.getData(instr);
    printOut (output);
}

void MainWindow::on_pushButtonW_clicked()
{
    string instr = "go west";
    string output = obj.getData(instr);
    printOut (output);
}


void MainWindow::on_pushButtonS_clicked()
{
    string instr = "go south";
    string output = obj.getData(instr);
    printOut (output);
}


void MainWindow::on_pushButtonE_clicked()
{
    string instr = "go east";
    string output = obj.getData(instr);
    printOut (output);
}

string ZorkUL::getData(string instr){
    Command* command = parser.getCommandGUI(instr);
    string output = processCommand(*command);
    return output;

}

void MainWindow:: printOut(string output){
    QString str = QString::fromStdString(output);
    ui->label->setText(str);
    ui->label_2->setText(str);
}

void MainWindow::on_putButton_clicked()
{
    string instr = "go east";
    string output = obj.getData(instr);
    printOut (output);
}


void MainWindow::on_helpButton_clicked()
{
    string instr = "info";
    string output = obj.getData(instr);
    printOut (output);
}


void MainWindow::on_invButton_clicked()
{
    string instr = "inventory";
    string output = obj.getData(instr);
    printOut (output);
}

