#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

typedef double ElemType;

typedef struct LNode {
    ElemType data;
    struct LNode *next;
} LNode;  // 结点结构

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void on_pushButton_clicked();   // 建立链表
    void on_pushButton_2_clicked(); // 插入元素
    void on_pushButton_3_clicked(); // 删除元素
    void on_pushButton_4_clicked(); // 查找元素

private:
    Ui::Widget *ui;
    LNode *L;  // 链表头指针

    LNode* creat_L();           // 初始化链表
    void insert_L(int i, ElemType e); // 插入元素
    ElemType delete_L(int i);    // 删除元素
    int locat_L(ElemType e);     // 查找元素
    void out_L();                // 输出链表
};

#endif // WIDGET_H
