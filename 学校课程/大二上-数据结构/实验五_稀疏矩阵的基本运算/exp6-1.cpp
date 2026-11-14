#include "TSMatrix.cpp"
using namespace std;

int main(void)
{
    // 生成两个稀疏矩阵的三元组
    int a[M][N] = {{1, 0, 3, 0}, {0, 1, 0, 0}, {0, 0, 1, 0}, {0, 0, 1, 1}};
    int b[M][N] = {{3, 0, 0, 0}, {0, 4, 0, 0}, {0, 0, 1, 0}, {0, 0, 0, 2}};
    TSMatrix A, B;
    CreateMat(A, a);
    CreateMat(B, b);
    // 输出a转置矩阵的三元组
    TSMatrix TA;
    TranTat(A, TA);
    DispMat(TA);
    // 输出a+b的三元组
    TSMatrix C;
    MatAdd(A, B, C);
    DispMat(C);
    // 输出a*b的三元组
    TSMatrix X;
    MatMul(A, B, X);
    DispMat(X);
}