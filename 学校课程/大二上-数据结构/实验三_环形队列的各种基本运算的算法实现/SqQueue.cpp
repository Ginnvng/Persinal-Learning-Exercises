#include <iostream>
using namespace std;
#define MaxSize 10

typedef char ElemType;
typedef struct
{
    ElemType data[MaxSize];
    int front, rear, count;
} SqQueue;

void InitQueue(SqQueue *&q)
{
    q = (SqQueue *)malloc(sizeof(ElemType) * MaxSize);
    q->front = q->rear = q->count = 0;
}

void Destory(SqQueue *&q)
{
    free(q);
    q = NULL;
}

bool QueueEmpty(SqQueue *q)
{
    return (q->front == q->rear);
}

bool enQueue(SqQueue *&q, ElemType e)
{
    if (q->front == (q->rear + 1) % MaxSize)
    {
        cout << "队列已满" << '\n';
        return false;
    }

    q->rear = (q->rear + 1) % MaxSize;
    q->data[q->rear] = e;
    q->count++;
    return true;
}

bool deQueue(SqQueue *&q, ElemType &e)
{
    if (QueueEmpty(q))
    {
        cout << "删除失败，队列已空" << '\n';
        return false;
    }

    q->front = (q->front + 1) % MaxSize;
    e = q->data[q->front];
    q->count--;
    return true;
}
