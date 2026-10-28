#include "SqQueue.cpp"
#include <iostream>
using namespace std;

int main(void)
{
    SqQueue *q;
    // 初始化队列q
    InitQueue(q);
    // 判断队列q是否为空
    if (QueueEmpty(q))
    {
        cout << "队列为空" << '\n';
    }
    else
    {
        cout << "队列非空" << '\n';
    }
    // 依次进队元素 a、b、c
    enQueue(q, 'a');
    enQueue(q, 'b');
    enQueue(q, 'c');
    // 出队一个元素，输出该元素
    ElemType e;
    deQueue(q, e);
    cout << "删除元素为：" << e << '\n';
    // 依次进队元素 d、e、f
    enQueue(q, 'd');
    enQueue(q, 'e');
    enQueue(q, 'f');
    // 输出出队序列
    while (!QueueEmpty(q))
    {
        deQueue(q, e);
        cout << e << '\n';
    }
    // 释放队列
    Destory(q);
}