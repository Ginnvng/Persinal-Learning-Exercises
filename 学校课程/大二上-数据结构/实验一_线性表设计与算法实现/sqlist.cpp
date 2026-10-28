#include <cstdlib>
#include <iostream>
using namespace std;

#define Initnum 100

typedef struct
{
    char *s;
    int length;
    int MAX_length;
} Sqlist;

void InitList(Sqlist &L)
{
    L.MAX_length = Initnum;
    L.length = 0;
    L.s = (char *)malloc(sizeof(char) * Initnum);
}

bool ListEmpty(Sqlist L)
{
    return L.length == 0;
}

bool DestroyList(Sqlist &L)
{
    free(L.s);
    L.s = NULL;
    L.length = 0;
    return true;
}

int ListLength(Sqlist L)
{
    return L.length;
}

bool DispList(Sqlist L)
{
    if (ListEmpty(L))
    {
        return false;
    }

    for (int i = 0; i < L.length; i++)
    {
        cout << L.s[i] << ' ';
    }
    cout << '\n';
    return true;
}

bool GetElem(Sqlist L, int i, char &e)
{
    if (L.length < i || i < 1)
    {
        return false;
    }

    e = L.s[i - 1];
    return true;
}

int LocateElem(Sqlist L, char e)
{
    for (int i = 0; i < L.length; i++)
    {
        if (e == L.s[i])
        {
            return i + 1;
        }
    }
    return 0;
}

bool ListInsert(Sqlist &L, int i, char e)
{
    if (i < 1 || i > L.length + 1)
    {
        cout << "i 的数值非法" << '\n';
        return false;
    }

    if (L.length >= L.MAX_length)
    {
        cout << "空间已满" << '\n';
        return false;
    }

    for (int j = L.length; j >= i; j--)
    {
        L.s[j] = L.s[j - 1];
    }

    L.s[i - 1] = e;
    L.length++;
    return true;
}

bool ListDelete(Sqlist &L, int i, char &e)
{
    if (i < 1 || i > L.length)
    {
        cout << "i 的数值非法" << '\n';
        return false;
    }

    e = L.s[i - 1];

    for (int j = i; j < L.length; j++)
    {
        L.s[j - 1] = L.s[j];
    }

    L.length--;

    return true;
}

// void CreateList(Sqlist &L, char a[], int n)
// {
// }