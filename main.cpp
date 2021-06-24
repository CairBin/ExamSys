#include "logindialog.h"
#include <examdemo.h>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    LoginDialog w;
    int res = w.exec();
    if(res == QDialog::Accepted){
        ExamDemo w;
        return a.exec();
        //        w.show();
    }else{
        return 0;
    }





}
