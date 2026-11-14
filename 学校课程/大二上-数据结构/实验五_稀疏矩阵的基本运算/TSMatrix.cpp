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
        for (k1 = t.nums - 1; k1 >= k; k1--)
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
bool Assign(TSMatrix &t, ElemType &X, int i, int j)
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
        X = t.data[k].d;
    }
    else
    {
        X = 0;
    }
    return true;
}

// 输出三元组
void DispMat(TSMatrix &t)
{
    if (t.nums <= 0)
        return;
    printf("\t%d\t%d\t%d\n", t.rows, t.cols, t.nums);
    printf("\t-----------------------------\n");
    for (int k = 0; k < t.nums; k++)
    {
        printf("\t%d\t%d\t%d\n", t.data[k].r, t.data[k].c, t.data[k].d);
    }
    cout << '\n';
}

// 稀疏矩阵的转置
void TranTat(TSMatrix &t, TSMatrix &tb)
{
    int k, k1 = 0, v;
    tb.rows = t.cols;
    tb.cols = t.rows;
    tb.nums = t.nums;
    if (t.nums != 0)
    {
        for (v = 0; v < t.cols; v++)
        {
            for (k = 0; k < t.nums; k++)
            {
                if (t.data[k].c == v)
                {
                    tb.data[k1].c = t.data[k].r;
                    tb.data[k1].r = t.data[k].c;
                    tb.data[k1].d = t.data[k].d;
                    k1++;
                }
            }
        }
    }
}

// 三元组的加法
bool MatAdd(const TSMatrix &A, const TSMatrix &B, TSMatrix &C)
{
    if (A.rows != B.rows || A.cols != B.cols)
        return false;

    int i = 0, j = 0, k = 0;
    while (i < A.nums && j < B.nums)
    {
        int pa = A.data[i].r * A.cols + A.data[i].c; // A 当前元素的位置编号
        int pb = B.data[j].r * B.cols + B.data[j].c; // B 当前元素的位置编号

        if (pa < pb)
            C.data[k++] = A.data[i++];
        else if (pa > pb)
            C.data[k++] = B.data[j++];
        else
        {
            int sum = A.data[i].d + B.data[j].d;
            if (sum != 0)
                C.data[k++] = {A.data[i].r, A.data[i].c, sum};
            i++;
            j++;
        }
    }
    while (i < A.nums)
        C.data[k++] = A.data[i++];
    while (j < B.nums)
        C.data[k++] = B.data[j++];

    C.rows = A.rows;
    C.cols = A.cols;
    C.nums = k;
    return true;
}

// 三元组的乘法
bool MatMul(const TSMatrix &A, const TSMatrix &B, TSMatrix &C)
{
    if (A.rows != B.rows || A.cols != B.cols)
        return false;
    C.nums = 0;
    C.cols = B.cols;
    C.rows = A.rows;
    // 先查行，在此行下找非零元素的列，找该列对应的B的行元素，将A元素与B该行的元素相乘相加，存到下标为B的列数的ctemp
    int ar = 0, br = 0; // a和b的行和列
    int ka = 0, k = 0;
    while (ar < A.rows)
    {
        int ctemp[B.cols] = {0};
        while (ka < A.nums &&
               A.data[ka].r <= ar) // 此循环：在A中找到行一致的所有元素
        {
            if (ar == A.data[ka].r)
            {
                int kb = 0;
                br = A.data[ka].c;
                while (kb < B.nums &&
                       B.data[kb].r <= br) // 此循环：在B中找到行一致的所有元素
                {
                    if (br == B.data[kb].r)
                    {
                        ctemp[B.data[kb].c] += B.data[kb].d * A.data[ka].d;
                    }
                    kb++;
                }
            }
            ka++;
        }
        // 以上已经把A这一行的数据计算完成，加入累加器了，下面将累加器的数据转移到C中
        // 累加器的下标对应C的列，C的行对应A的行
        for (int i = 0; i < B.cols; i++)
        {
            if (ctemp[i] != 0)
            {
                C.data[k].d = ctemp[i];
                C.data[k].r = ar;
                C.data[k].c = i;
                C.nums++;
                k++;
            }
        }
        ar++;
    }
    return true;
}
