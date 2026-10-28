#include "sqlist.cpp"
#include <iostream>

int main(void)
{
    char e;
    Sqlist L;
    // 初始化顺序表L
    InitList(L);
    // 依次插入a、b、c、d、e元素
    ListInsert(L, 1, 'a');
    ListInsert(L, 2, 'b');
    ListInsert(L, 3, 'c');
    ListInsert(L, 4, 'd');
    ListInsert(L, 5, 'e');
    // 输出顺序表L
    DispList(L);
    // 输出顺序表L的长度
    cout << ListLength(L) << '\n';
    // 判断顺序表是否为空
    if (ListEmpty(L))
    {
        cout << "为空" << '\n';
    }
    else
    {
        cout << "不为空" << '\n';
    }
    // 输出顺序表L的第3个元素
    if (GetElem(L, 3, e))
    {
        cout << e << '\n';
    }
    // 输出元素a的位置
    cout << LocateElem(L, 'a') << '\n';
    // 在第4个元素位置上插入元素
    ListInsert(L, 4, 'f');
    // 输出顺序表L
    DispList(L);
    // 删除顺序表L的第3个元素
    ListDelete(L, 3, e);
    cout << e << '\n';
    // 输出顺序表L
    DispList(L);
    // 释放顺序表L
    DestroyList(L);
}