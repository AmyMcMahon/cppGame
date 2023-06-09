
#include "mainwindow.h"
#include "ZorkUL.h"
#include "Parser.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QMessageBox>

ZorkUL obj;
bool hasK = false;
bool item1O = false;
bool item2O = false;
bool item3O = false;
bool item4O = false;

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
    QPixmap pixmapF("C:/Users/admcm/cppGame/flashlight.png");
    QIcon item2(pixmapF);
    QIcon invItem1(pixmapF);
    ui->pushButtonW->setIcon(ButtonIconW);
    ui->pushButtonW->setIconSize(QSize(51,51));
    ui->pushButtonE->setIcon(ButtonIconE);
    ui->pushButtonE->setIconSize(QSize(51,51));
    ui->pushButtonN->setIcon(ButtonIconN);
    ui->pushButtonN->setIconSize(QSize(51,51));
    ui->pushButtonS->setIcon(ButtonIconS);
    ui->pushButtonS->setIconSize(QSize(51,51));
    ui->pushButtonN->setVisible(false);
    ui->pushButtonS->setVisible(false);
    ui->pushButtonE->setVisible(false);
    ui->pushButtonW->setVisible(false);
    ui->invItem1->setVisible(false);
    ui->invItem2->setVisible(false);
    ui->invItem3->setVisible(false);
    ui->invItem4->setVisible(false);
    ui->item1->setVisible(false);
    ui->item2->setVisible(true);
    ui->item3->setVisible(false);
    ui->item4->setVisible(false);
    ui->exitInv->setVisible(false);
    ui->item2->setIcon(item2);
    ui->item3->setIcon(QIcon());
    ui->item1->setIconSize(QSize(111,111));
    ui->item4->setIconSize(QSize(111,111));
    ui->item2->setIconSize(QSize(111,111));
    ui->item3->setIconSize(QSize(111,111));
    ui->invItem2->setIconSize(QSize(111,111));
    ui->invItem3->setIconSize(QSize(111,111));
    ui->invItem1->setIconSize(QSize(111,111));
    ui->invItem4->setIconSize(QSize(111,111));
    ui->label_2->setText(QString::fromStdString(obj.currentR()));
    ui->label->setText(QString::fromStdString(obj.printWelcome()));
    ui->label_3->setText(QString::fromStdString(obj.printWelcome()));
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
    if (str== "inventory"){
        string output = "";
        for (Item i : stringInv)
            output += (i).getShortDescription() + ", ";
        ui->label->setText(QString::fromStdString(output));
        ui->label_3->setText(QString::fromStdString(output));
    } else{
        setLabel(str.toStdString());
    }
    //ui->label_2->setText(str2);
}

void MainWindow::setLabel(string instr){
    qDebug() << instr;
    string output = obj.getData(instr);
    qDebug() << output;
    QString str2 = QString::fromStdString(output);
    qDebug() <<str2;
    ui->label->setText(str2);
    ui->label_3->setText(str2);
    if (instr.find("take") != std::string::npos){
        string object = instr.substr(5);
        stringInv.push_back(object);
        if(objectU=="flashlight"){
            ui->item2->setIcon(QIcon());
            ui->item2->setVisible(false);
            item2O = false;
        }else if (objectU == "key" && obj.currentR() == "attic"){
            ui->pushButtonN->setVisible(true);
            hasK = true;
            ui->item3->setIcon(QIcon());
            item3O = false;
            ui->item3->setVisible(false);
        } else if (objectU == "flashlight"){
            ui->item2->setIcon(QIcon());
            ui->item2->setVisible(false);
            item2O = false;
        } else if (objectU == "codes"){
            ui->item3->setIcon(QIcon());
            ui->item3->setVisible(false);
            item3O = false;
            QPixmap pixmapF("C:/Users/admcm/cppGame/book.png");
            QIcon item3(pixmapF);
            ui->item1->setIcon(item3);
            ui->item1->setVisible(true);
            item1O = true;
        } else if (objectU == "book"){
            ui->item1->setIcon(QIcon());
            ui->item1->setVisible(false);
            item1O = false;
            QPixmap pixmapF("C:/Users/admcm/cppGame/bookshelf.png");
            QIcon item3(pixmapF);
            ui->item4->setIcon(item3);
            ui->item4->setVisible(true);
            item4O = true;
        }else if (objectU == "uvLight"){
            ui->item2->setIcon(QIcon());
            ui->item2->setVisible(false);
            item2O = false;
        } else if (objectU == "hammer"){
            ui->item2->setIcon(QIcon());
            ui->item2->setVisible(false);
            item2O = false;
        } else if (objectU == "key"){
            QPixmap pixmapF("C:/Users/admcm/cppGame/ldoor.jpg");
            QIcon item3(pixmapF);
            ui->item3->setVisible(true);
            item3O = true;
        } else if (objectU=="null"){
            setLabel("You must select an item");
        }

    }else if (instr.find("use") != std::string::npos){
        if (objectU == "flashlight"){
            QPixmap pixmapF("C:/Users/admcm/cppGame/key.png");
            QIcon item3(pixmapF);
            ui->item3->setIcon(item3);
            item3O = true;
            ui->invItem1->setIcon(QIcon());
            ui->invItem1->setVisible(false);
            ui->item2->setIcon(QIcon());
            item2O = false;
            stringInv.clear();
            //stringInv.erase(std::remove(stringInv.begin(), stringInv.end(), "flashlight"), stringInv.end());
        }else if (objectU == "key" && obj.currentR() == "Office"){
            ui->invItem3->setIcon(QIcon());
            ui->invItem3->setVisible(false);
            stringInv.clear();
            hasK = false;
        }else if (objectU == "uvLight"){
            ui->invItem2->setIcon(QIcon());
            ui->invItem2->setVisible(false);
            QPixmap pixmapF("C:/Users/admcm/cppGame/combo.jpg");
            QIcon item3(pixmapF);
            ui->item3->setIcon(item3);
            item3O = true;
        }else if (objectU == "codes"){
            ui->invItem1->setIcon(QIcon());
            ui->invItem1->setVisible(false);
            ui->pushButtonS->setVisible(true);
        }else if (objectU=="null"){
            setLabel("You must select an item");
        }

    }else if (instr.find("open") != std::string::npos){
        if (objectU == "safe"){
            if (!hasK){
                QPixmap pixmapF("C:/Users/admcm/cppGame/codes.jpg");
                QIcon item3(pixmapF);
                ui->item3->setIcon(item3);
                ui->item3->setVisible(true);
                ui->item2->setIcon(QIcon());
                ui->item2->setVisible(false);
            } else {
                ui->label_3->setText("you must use the key to open the safe");
                ui->label->setText("you must use the key to open the safe");
            }

        } else if (objectU == "lock"){
            ui->item3->setIcon(QIcon());
            ui->item3->setVisible(false);
            ui->pushButtonS->setVisible(true);
        }else if (objectU=="null"){
            setLabel("You must select an item");
        }

    } else if(instr.find("put") != std::string::npos){
        string object = instr.substr(4);
        stringInv.erase(std::remove(stringInv.begin(), stringInv.end(), object), stringInv.end());
        if (objectU == "book"){
            ui->invItem2->setIcon(QIcon());
            ui->invItem2->setVisible(false);
            ui->item4->setIcon(QIcon());
            item4O = false;
            ui->pushButtonW->setVisible(true);
        }else if (objectU=="null"){
            setLabel("You must select an item");
        }

    } else if(instr.find("win") != std::string::npos){
        qDebug() << "work";
        ui->label->setText ("Congrats you have escaped from the game");
        ui->label_2->setText("Escape");
        ui->label_3->setText("Congrats you have escaped from the game");
        ui->invItem1->setVisible(false);
        ui->invItem2->setVisible(false);
        ui->invItem3->setVisible(false);
        ui->invItem4->setVisible(false);
        ui->item1->setVisible(false);
        ui->item2->setVisible(false);
        ui->item3->setVisible(false);
        ui->item4->setVisible(false);
    } else if (instr.find("smash") != std::string::npos){
        if (objectU == "vase"){
            QPixmap pixmapF("C:/Users/admcm/cppGame/key.png");
            QIcon item1(pixmapF);
            ui->item1->setVisible(true);
        }else if (objectU=="null"){
            setLabel("You must select an item");
        }
    }
}

void MainWindow::getInv(Character& character){
    stringInv = character.stringInv;
}


void MainWindow::on_pushButtonN_clicked()
{
    string instr = "go north";
    string output = obj.getData(instr);
    printOut (output);
    ui->pushButtonN->setVisible(false);
    ui->label_2->setText(QString::fromStdString(obj.currentR()));
    if(obj.currentR() == "Office"){
        QPixmap pixmapF("C:/Users/admcm/cppGame/safe.jpg");
        QIcon item2(pixmapF);
        ui->item2->setIcon(item2);
        ui->item2->setVisible(true);
        item2O = true;
    }
}

void MainWindow::on_pushButtonW_clicked()
{
    string instr = "go west";
    string output = obj.getData(instr);
    printOut (output);
    ui->label_2->setText(QString::fromStdString(obj.currentR()));
    ui->pushButtonW->setVisible(false);
    if(obj.currentR() == "Bathroom"){
        QPixmap pixmapF("C:/Users/admcm/cppGame/uv.jpg");
        QIcon item2(pixmapF);
        ui->item2->setIcon(item2);
        ui->item2->setVisible(true);
        item2O = true;
    }
}


void MainWindow::on_pushButtonS_clicked()
{
    string instr = "go south";
    ui->label_2->setText(QString::fromStdString(obj.currentR()));
    string output = obj.getData(instr);
    printOut (output);
    ui->pushButtonS->setVisible(false);
    if(obj.currentR() == "Bedroom"){
        QPixmap pixmapF("C:/Users/admcm/cppGame/hammer.jpg");
        QIcon item2(pixmapF);
        ui->item2->setIcon(item2);
        ui->item2->setVisible(true);
        item2O = true;
    } else if(obj.currentR() == "Landing"){
        setLabel("win");
    }
}


void MainWindow::on_pushButtonE_clicked()
{
    string instr = "go east";
    ui->label_2->setText(QString::fromStdString(obj.currentR()));
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
    ui->label_3->setText(str);
}

void MainWindow::on_putButton_clicked()
{
    string instr = "put " + objectU;
    setLabel(instr);
}


void MainWindow::on_helpButton_clicked()
{
    string instr = "info";
    string output = obj.getData(instr);
    QString str = QString::fromStdString(output);
    printOut (output);
}


void MainWindow::on_invButton_clicked()
{
    ui->item1->setVisible(false);
    ui->item2->setVisible(false);
    ui->item3->setVisible(false);
    ui->item4->setVisible(false);
    ui->exitInv->setVisible(true);
    string instr = "inventory";
    ui->label_2->setText("inventory");
    string output = obj.getData(instr);

    for(int i = 0; i < stringInv.size(); i++){
        qDebug() << "inv item " <<stringInv[i];
    }

    for (size_t i = 0; i < stringInv.size(); i++) {
        if (stringInv[i] == "flashlight") {
            QPixmap pixmapF("C:/Users/admcm/cppGame/flashlight.png");
            QIcon invItem1(pixmapF);
            ui->invItem1->setVisible(true);
            ui->invItem1->setIcon(invItem1);
        } else if (stringInv[i] == "key") {
            QPixmap pixmapF("C:/Users/admcm/cppGame/key.png");
            QIcon invItem3(pixmapF);
            ui->invItem3->setIcon(invItem3);
            ui->invItem3->setVisible(true);
        } else if (stringInv[i] == "codes") {
            QPixmap pixmapF("C:/Users/admcm/cppGame/codes.jpg");
            QIcon invItem1(pixmapF);
            ui->invItem1->setIcon(invItem1);
            ui->invItem1->setVisible(true);
        } else if (stringInv[i] == "book") {
            QPixmap pixmapF("C:/Users/admcm/cppGame/book.png");
            QIcon invItem1(pixmapF);
            ui->invItem2->setIcon(invItem1);
            ui->invItem2->setVisible(true);
        }else if (stringInv[i] == "uvLight") {
            QPixmap pixmapF("C:/Users/admcm/cppGame/uv.jpg");
            QIcon invItem1(pixmapF);
            ui->invItem2->setIcon(invItem1);
            ui->invItem2->setVisible(true);
        } else if (stringInv[i] == "hammer") {
            QPixmap pixmapF("C:/Users/admcm/cppGame/hammer.jpg");
            QIcon invItem1(pixmapF);
            ui->invItem2->setIcon(invItem1);
            ui->invItem2->setVisible(true);
        }
    }
}


void MainWindow::on_mapButton_clicked()
{
    string instr = "map";
    string output = obj.getData(instr);
    QString str = QString::fromStdString(output);
//    ui-> label_3 ->setText(str);
    printOut (output);
}


void MainWindow::on_item2_clicked()
{
    string room = obj.currentR();
    if (room == "attic"){
        objectU = ("flashlight");
        ui->invItem1->setIcon(QIcon());
    }else if (room == "Office"){
        objectU = "safe";
    }else if (room == "Bathroom"){
        objectU = "uvLight";
    }else if (room == "Bedroom"){
        objectU = "hammer";
    } else if (room == "Landing"){
        objectU="vase";
    }
}


void MainWindow::on_takeButton_clicked()
{
    string instr = "take " + objectU;
    setLabel(instr);

}


void MainWindow::on_useButton_clicked()
{
    string instr = "use " + objectU;
    setLabel(instr);
}


void MainWindow::on_item3_clicked()
{
    string room = obj.currentR();
    if (room == "attic"){
        objectU = ("key");
    } else if (room == "Office"){
        objectU = ("codes");
    }else if (room == "Bathroom"){
        objectU = ("lock");
    }
}


void MainWindow::on_exitInv_clicked()
{
    if (item1O){
        ui->item1->setVisible(true);
    }
    if (item2O){
        ui->item2->setVisible(true);
    }
    if (item3O){
        ui->item3->setVisible(true);
    }
    if (item4O){
        ui->item4->setVisible(true);
    }
    ui->invItem1->setVisible(false);
    ui->invItem2->setVisible(false);
    ui->invItem3->setVisible(false);
    ui->invItem4->setVisible(false);
    ui->exitInv->setVisible(false);
    ui->label_2->setText(QString::fromStdString(obj.currentR()));
}


void MainWindow::on_invItem3_clicked()
{
    string room = obj.currentR();
    if (room == "Office"){
        objectU = ("key");
    }
}


void MainWindow::on_openButton_clicked()
{
    string instr = "open " + objectU;
    setLabel(instr);
}


void MainWindow::on_invItem2_clicked()
{
    string room = obj.currentR();
    if (room == "Office"){
        objectU = ("book");
    }else if (room == "Bathroom"){
        objectU = ("uvLight");
    }
}


void MainWindow::on_item1_clicked()
{
    string room = obj.currentR();
    if (room == "Office"){
        objectU = ("book");
    } if (room == "Landing"){
        objectU = "key1";
    }
}


void MainWindow::on_invItem1_clicked()
{
    string room = obj.currentR();
    if (room == "Bedroom"){
        objectU = ("codes");
    }
}


void MainWindow::on_winB_clicked()
{
    setLabel("win");

}


void MainWindow::on_smashButton_clicked()
{
    string instr = "smash " + objectU;
    setLabel(instr);

}

