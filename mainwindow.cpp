//Daniela Castro
//Dr.Park
//CSC2230 Lab3


#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QFileDialog>
#include <iostream>
#include <QMessageBox>
#include <QSortFilterProxyModel>

QHash<QString, QString> EXPRESSIONS ({{"1","1"},
                                      {"2","[2abc]"},
                                      {"3","[3def]"},
                                      {"4","[4ghi]"},
                                      {"5","[5jkl]"},
                                      {"6","[6mno]"},
                                      {"7","[7pqrs]"},
                                      {"8","[8tuv]"},
                                      {"9","[9wxyz]"},
                                      {"0","0"},
                                      {"*","*"},
                                      {"#","#"},});

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    myModel(new MyAddressBookModel(this))

{
    ui->setupUi(this);
    proxyModel = new QSortFilterProxyModel(this);
    proxyModel->setSourceModel(myModel);
    proxyModel->setFilterKeyColumn(-1);
    ui->tableView->setModel(proxyModel);

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_actionOpen_an_Address_Book_triggered()
{
    QString fileName = QFileDialog::getOpenFileName(this,
                       tr("Open Address Book"), "",
                       tr("Address Book (*.csv);;All Files (*)"));

    std::cout << fileName.toStdString() << std::endl;

    myModel->openFile(fileName);
}

void MainWindow::on_tableView_clicked(const QModelIndex &index)
{
    std::cout << index.row() << "," << index.column() << std::endl;
    ui->phoneNumberLabel->setText(myModel->getPhoneNumber(index.row()));


}

void MainWindow::addDigit(QString digit)
{
    QString phoneNumber = ui->phoneNumberLabel->text();
    if(phoneNumber.length() == 12)
        return;
    if(phoneNumber.length() == 7 || phoneNumber.length() == 3)
        phoneNumber = phoneNumber + "-";
    phoneNumber = phoneNumber + digit;
    ui->phoneNumberLabel->setText(phoneNumber);
    proxyModel->setFilterRegExp(getExpression());

}

QRegExp MainWindow::getExpression()
{
    QString expression = "^";
    foreach(QChar character, ui->phoneNumberLabel->text()) {
        if(character == '-')
            continue;
        expression.append(EXPRESSIONS.value(character));
    }

    return QRegExp(expression, Qt::CaseInsensitive);
}

void MainWindow::on_dig1PushButton_clicked()
{
    addDigit("1");
}

void MainWindow::on_dig2PushButton_clicked()
{
    addDigit("2");
}

void MainWindow::on_dig3PushButton_clicked()
{
    addDigit("3");
}

void MainWindow::on_dig4PushButton_clicked()
{
    addDigit("4");
}

void MainWindow::on_dig5PushButton_clicked()
{
    addDigit("5");
}

void MainWindow::on_dig6PushButton_clicked()
{
    addDigit("6");
}

void MainWindow::on_dig7PushButton_clicked()
{
    addDigit("7");
}

void MainWindow::on_dig8PushButton_clicked()
{
    addDigit("8");
}

void MainWindow::on_dig9PushButton_clicked()
{
    addDigit("9");
}

void MainWindow::on_dig0PushButton_clicked()
{
    addDigit("0");
}

void MainWindow::on_deletePushButton_clicked()
{
    QString phoneNumber = ui->phoneNumberLabel->text();

    int length = phoneNumber.length();
    if(length == 0)
        return;
    int remove = 1;
    if(length == 5 || length == 9)
        remove = 2;
    ui->phoneNumberLabel->setText(phoneNumber.left(length - remove));
    proxyModel->setFilterRegExp(getExpression());

}

void MainWindow::on_callPushButton_clicked()
{
    QString phoneNumber = ui->phoneNumberLabel->text();
    QMessageBox msgBox;
    msgBox.setText("Calling " + phoneNumber + "...");
    msgBox.exec();
    ui->phoneNumberLabel->setText("");
    proxyModel->setFilterRegExp(getExpression());

}

