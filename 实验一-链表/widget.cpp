#include "widget.h"
#include "ui_widget.h"
#include <stdlib.h>
#include <QMessageBox>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    L = creat_L();  // 初始化链表
}

Widget::~Widget()
{
    delete ui;
    // 释放链表内存
    LNode *p = L;
    while (p != nullptr) {
        LNode *temp = p;
        p = p->next;
        free(temp);
    }
}

// 创建链表
LNode* Widget::creat_L()
{
    LNode *h;
    h = (LNode*)malloc(sizeof(LNode));
    h->next = nullptr;
    return h;
}

// 输出链表到 lineEdit_3
void Widget::out_L()
{
    LNode *p = L->next;
    QString text;
    while (p != nullptr) {
        text += QString::number(p->data) + " ";
        p = p->next;
    }
    ui->lineEdit_3->setText(text);
}

void Widget::on_pushButton_clicked()
{
    // 获取链表元素个数
    QString countStr = ui->lineEdit->text();
    int count = countStr.toInt();


    // 获取输入的元素列表
    QString elementsStr = ui->lineEdit_2->text();
    QStringList elementsList = elementsStr.split(" ", Qt::SkipEmptyParts);

    // 创建链表头节点
    L = (LNode *)malloc(sizeof(LNode));
    L->next = nullptr;
    LNode *tail = L;

    // 插入元素到链表
    for (int i = 0; i < count; ++i) {
        LNode *newNode = (LNode *)malloc(sizeof(LNode));
        newNode->data = elementsList[i].trimmed().toDouble(); // 解析 double 数据
        newNode->next = nullptr;
        tail->next = newNode;
        tail = newNode;
    }
    LNode *p = L->next;
    QString output;
    while (p) {
        output += QString::number(p->data, 'f', 4) + " "; // 使用 'f' 保留两位小数
        p = p->next;
    }
    ui->lineEdit_3->setText(output.trimmed());
}


// 按钮2：插入元素（输入 i 和 e，显示在 lineEdit_4）
void Widget::on_pushButton_4_clicked()
{
    int i = ui->lineEdit_7->text().toInt();
    double e = ui->lineEdit_8->text().toDouble();

    insert_L(i, e);
    out_L();
}

void Widget::on_tabWidget_currentChanged(int) {
    // 你的代码逻辑
}
// 插入元素
void Widget::insert_L(int i, ElemType e)
{
    LNode *s, *p;
    p = L;
    int j = 0;

    while (p != nullptr && j < i - 1) {
        p = p->next;
        j++;
    }

    if (p == nullptr || j > i - 1) {
        ui->lineEdit_4->setText("插入失败：位置错误！");
        return;
    }

    s = (LNode*)malloc(sizeof(LNode));
    s->data = e;
    s->next = p->next;
    p->next = s;

    ui->lineEdit_4->setText("插入成功：" + QString::number(e));
}

// 按钮3：删除元素（输入 i，显示在 lineEdit_4）
void Widget::on_pushButton_2_clicked()
{
    double i = ui->lineEdit_5->text().toDouble();
    int m = locat_L(i);
    ElemType deletedValue = delete_L(m);

    if (deletedValue != -1) {
        ui->lineEdit_4->setText("删除成功：" + QString::number(deletedValue));
    } else {
        ui->lineEdit_4->setText("删除失败：位置错误！");
    }

    out_L();
}

// 删除元素
ElemType Widget::delete_L(int i)
{
    LNode *p, *s;
    int j = 0;
    ElemType x;

    p = L;
    while (p->next != nullptr && j < i - 1) {
        p = p->next;
        j++;
    }

    if (p->next == nullptr || j > i - 1) {
        return -1; // 删除失败
    }

    s = p->next;
    x = s->data;
    p->next = s->next;
    free(s);

    return x;
}

// 按钮4：查找元素（输入 e，显示在 lineEdit_4）
void Widget::on_pushButton_3_clicked()
{
    double e = ui->lineEdit_6->text().toDouble();
    int loc = locat_L(e);

    if (loc != -1) {
        ui->lineEdit_4->setText("找到元素，位置：" + QString::number(loc));
    } else {
        ui->lineEdit_4->setText("未找到元素！");
    }
}

// 查找元素
int Widget::locat_L(ElemType e)
{
    LNode *p = L->next;
    int j = 1;

    while (p != nullptr && p->data != e) {
        p = p->next;
        j++;
    }

    if (p != nullptr) {
        return j;
    } else {
        return -1;
    }
}

