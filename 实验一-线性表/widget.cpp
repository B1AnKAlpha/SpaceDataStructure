#include "widget.h"
#include "ui_widget.h"
#include <stdlib.h>
#include <sstream>
#include <vector>

using namespace std;

SeqList InitList()
{
    SeqList L = (SeqList)malloc(sizeof(List));
    L->Last = -1;
    return L;
}

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    L = InitList();
}

Widget::~Widget()
{
    delete ui;
    free(L);
}

void Widget::on_pushButton_clicked()
{

    QString a = ui->lineEdit->text();
    QString n = ui->lineEdit_2->text();

    double p[MAX] = {};
    stringstream ss(n.toStdString());
    std::string t;
    std::vector<std::string> res;

    while (ss >> t) {
        res.push_back(t);
    }

    int m = 0;
    for (auto s : res) {
        p[m] = stod(s);
        m++;
    }

    for (int i = 0; i < a.toInt(); i++) {
        L->elem[i] = p[i];
        L->Last++;
    }

    QString text;
    for (int i = 0; i <= L->Last; i++) {
        text += QString::number(L->elem[i]) + " ";
    }
    ui->lineEdit_3->setText(text);
}

int Location(SeqList L, datatype x)
{
    for (int i = 0; i <= L->Last; i++) {
        if (L->elem[i] == x) {
            return i;
        }
    }
    return -1;
}

void Widget::on_pushButton_2_clicked()
{
    QString shan = ui->lineEdit_5->text();
    datatype x = shan.toDouble();

    int i = Location(L, x);
    if (i == -1) {
        ui->lineEdit_3->setText("你所查找的元素不在表中，请重新输入你要删除的元素:");
        return;
    }

    for (int j = i; j < L->Last; j++) {
        L->elem[j] = L->elem[j + 1];
    }
    L->Last--;

    QString text;
    for (int k = 0; k <= L->Last; k++) {
        text += QString::number(L->elem[k]) + " ";
    }
    ui->lineEdit_4->setText(text);
}

void Widget::on_pushButton_3_clicked()
{
    QString cha = ui->lineEdit_6->text();
    datatype x = cha.toDouble();
    int i = Location(L, x);
    ui->lineEdit_4->setText(QString::number(i));
}


void Widget::on_pushButton_4_clicked()
{
    QString n = ui->lineEdit_7->text();
    QString charuzhi = ui->lineEdit_8->text();
    if((L->Last+1)>MAX)
        printf("表已满，不能插入!");
    else
    {
        L->Last++;
        for(int i=L->Last;i>n.toInt()-1;i--)
            L->elem[i+1]=L->elem[i];
        L->elem[n.toInt()]=charuzhi.toDouble();
    }

    QString text;
    for (int i = 0; i <= L->Last; i++) {
        text += QString::number(L->elem[i]) + " ";
    }
    ui->lineEdit_4->setText(text);
}

