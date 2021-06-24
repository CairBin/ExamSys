#ifndef EXAMDEMO_H
#define EXAMDEMO_H
#include <QDialog>
#include <QTimer>
#include <QTextEdit>
#include <QLabel>
#include <QRadioButton>
#include <QCheckBox>
#include <QGridLayout>
#include <QButtonGroup>

class ExamDemo : public QDialog
{
    Q_OBJECT
public:
    ExamDemo(QWidget* parent = 0);
    void initLayout(); //初始化布局管理器
    bool initTextEdit(); //初始化文本编辑器
    void initTimer();   //初始化计时器
    void initButtons(); //初始化按钮和标签
    bool selFinAjust();//判断题目是否完成
private:
    QTimer *m_timer; //计时器
    int m_timeGo; //考试已用时
    QTextEdit *m_textEdit; //考试题库显示
    QLabel *m_titleLabels[10]; //题目标签
    QButtonGroup *m_btnGroups[9]; //按钮分组
    QRadioButton *m_radioBtns[32]; //单选按钮
    QCheckBox *m_checkBtns[4]; //多选按钮
    QRadioButton *m_radioA; //判断题A选项
    QRadioButton *m_radioB; //判断题B选项


    QStringList m_answerList; //答案链表

    QGridLayout *m_layout; //布局管理器



private slots:
    void freshTime();
    void getScore();

};

#endif // EXAMDEMO_H
