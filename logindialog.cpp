#include "logindialog.h"
#include "ui_logindialog.h"
#include <QMessageBox>
#include <QFile>
#include <QTextStream>
LoginDialog::LoginDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::LoginDialog)
{
    ui->setupUi(this);
    ui->imgLabel->setScaledContents(true); //填充
    ui->imgLabel->resize(this->width(),this->height()); //图片与窗体宽高一致
    //设计窗口风格
    this->setWindowTitle("科目一考试登录"); //窗口标题
    this->setWindowFlags(Qt::Dialog | Qt::WindowCloseButtonHint);

}

LoginDialog::~LoginDialog()
{
    delete ui;
}


void LoginDialog::on_loginButton_clicked()
{
    //正则验证邮箱地址 格式： 用户名@域名
    /*
     * 元字符解释：
     * ^表示规则字符串的开始
     * $表示字符串的结束
     * +表示匹配次数>=1
     * *表示任意次数(可以为0)
     * {n,m}匹配次数至少n次，至多m次
     *
     */
    QRegExp rx("^[A-Za-z0-9]+([_\.][A-Za-z0-9]+)*@([A-Za-z0-9\-]+\.)+[A-Za-z]{2,6}$");
    rx.exactMatch(ui->accountEdit->text());
    bool res = rx.exactMatch(ui->accountEdit->text());
    if(!res){
        //匹配不成功
        QMessageBox::information(this,"提示","非法的邮箱地址，请您重新输入!");
        ui->accountEdit->clear(); //清空account输入框
        ui->codeEdit->clear(); //清空密码框
        ui->accountEdit->setFocus();//聚焦到输入框
        return;
    }
    else{
        //成功

        QString filename; //数据文件
        QString strAccInput; //用户输入账号
        QString strCode; //用户输入的密码
        QString strLine; //文件流，每次读取的一行数据
        QStringList strList; //字符串链表，用于分割存放一行的账号密码

        filename = "account.txt";
        strAccInput = ui->accountEdit->text();
        strCode = ui->codeEdit->text();

        QFile file(filename);
        QTextStream stream(&file);
        if(file.open(QIODevice::ReadOnly | QIODevice::Text))
        {
            //成功
            //QMessageBox::information(this,"提示","读取内容成功");

            /*
             *数据文件格式： 邮箱地址,密码
            */
                while(!stream.atEnd()) //直到读取到数据文件底部才停止读取
                {
                    strLine = stream.readLine(); //读取每行数据
                    strList = strLine.split(","); //split()分割方法，将数据文件英文逗号前的account和后面的code分割，然后被strList链表接收
                    // 字符串链表有两个元素 account对应0 code对应1
                    if(strAccInput == strList.at(0)) //匹配用户输入的account与字符串链表中第一个元素account
                    {
                        //账号一致
                        if(strCode == strList.at(1))//同理，匹配密码
                        {
                            //密码一致
                            QMessageBox::information(this,"提示","欢迎登陆科目一考试系统");
                            file.close();

                            done(Accepted);

                            return; //成功后直接返回
                        }
                        else{
                                QMessageBox::information(this,"提示","您输入的密码有误，请重新输入");
                                ui->codeEdit->clear();
                                ui->codeEdit->setFocus();
                                file.close();
                                return;
                        }

                    }
                    QMessageBox::information(this,"提示","您输入的账号有误，请重新输入");
                    ui->accountEdit->clear();
                    ui->codeEdit->clear();
                    ui->accountEdit->setFocus();




                }


        }
        else
        {
            //失败
            QMessageBox::information(this,"提示","读取账号数据失败");
        }

    }
}

void LoginDialog::on_CancelButton_2_clicked()
{
    done(Rejected);
}
