#include <iostream>
using namespace std;

#define M 4
#define N 4
#define MaxSize 16
#define ElemType int

typedef struct
{
    int r;
    int c;
    ElemType d;
} TupNode;

typedef struct
{
    int rows;
    int cols;
    int nums;
    TupNode data[MaxSize];
} TSMatrix;

// 从一个二维稀疏矩阵创造其三元组表示

void CreateMat(TSMatrix &t, ElemType A[M][N])
{
    int i, j;
    t.rows = M;
    t.cols = N;
    t.nums = 0;
    for (i = 0; i < M; i++)
    {
        for (j = 0; j < N; j++)
        {
            if (A[i][j] != 0)
            {
                t.data[t.nums].r = i;
                t.data[t.nums].c = j;
                t.data[t.nums].d = A[i][j];
                t.nums++;
            }
        }
    }
}

// 三元组元素的赋值

bool Value(TSMatrix &t, ElemType x, int i, int j)
{
    int k = 0, k1;
    if (i >= t.rows || j >= t.cols)
    {
        return false;
    }
    while (k < t.nums && i > t.data[k].r)
        k++;
    while (k < t.nums && i == t.data[k].r && j > t.data[k].c)
        k++;
    if (i == t.data[k].r && j == t.data[k].c)
    {
        t.data[k].d = x;
    }
    else
    {
        for (k1 = t.rows - 1; k1 > t.data[k].r; k1--)
        {
            t.data[k1 + 1].r = t.data[k1].r;
            t.data[k1 + 1].c = t.data[k1].c;
            t.data[k1 + 1].d = t.data[k1].d;
        }
        t.data[k].r = i;
        t.data[k].c = j;
        t.data[k].d = x;
        t.nums++;
    }
    return true;
}

// 将指定位置的元素赋值给变量
bool Value(TSMatrix &t, int i, int j)
{
    int k = 0;
    if (i >= t.rows || j >= t.cols)
    {
        return false;
    }
    while (k < t.nums && i > t.data[k].r)
        k++;
    while (k < t.nums && i == t.data[k].r && j > t.data[k].c)
        k++;
    if (i == t.data[k].r && j == t.data[k].c)
    {
    }
    else
    {
        
        }
    return true;
}
