#ifndef LOGINDIALOG_H
#define LOGINDIALOG_H

#include <QDialog>

QT_BEGIN_NAMESPACE
namespace Ui { class LoginDialog; }  //用于描述登录窗口界面信息
QT_END_NAMESPACE

class LoginDialog : public QDialog
{
    Q_OBJECT //QObject

public:
    LoginDialog(QWidget *parent = nullptr);
    ~LoginDialog();

private slots:
    void on_loginButton_clicked();

    void on_CancelButton_2_clicked();

private:
    Ui::LoginDialog *ui;
};
#endif // LOGINDIALOG_H
