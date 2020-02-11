#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSortFilterProxyModel>
#include "myaddressbookmodel.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_actionOpen_an_Address_Book_triggered();

    void on_tableView_clicked(const QModelIndex &index);

    void addDigit(QString digit);

    void on_dig1PushButton_clicked();

    void on_dig2PushButton_clicked();

    void on_dig7PushButton_clicked();

    void on_dig3PushButton_clicked();

    void on_dig4PushButton_clicked();

    void on_dig5PushButton_clicked();

    void on_dig6PushButton_clicked();

    void on_dig8PushButton_clicked();

    void on_dig0PushButton_clicked();

    void on_dig9PushButton_clicked();

    void on_deletePushButton_clicked();

    void on_callPushButton_clicked();



private:
    Ui::MainWindow *ui;
    MyAddressBookModel *myModel;
    QSortFilterProxyModel *proxyModel;
    QRegExp getExpression();
};
#endif // MAINWINDOW_H
