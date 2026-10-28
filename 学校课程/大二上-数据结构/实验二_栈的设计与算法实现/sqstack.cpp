#include <iostream>
using namespace std;
#define Initnum 100

typedef struct
{
    char *data;
    int top;
    int MAX_length;

} Sqstack;

void InitStack(Sqstack &L)
{
    L.data = (char *)malloc(sizeof(char) * Initnum);
    L.top = -1;
    L.MAX_length = Initnum;
}

bool DestroyStack(Sqstack &L)
{
    free(L.data);
    L.data = NULL;
    L.top = -1;
    return true;
}

bool StackEmpty(Sqstack L)
{
    if (L.top == -1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool Push(Sqstack &L, char e)
{
    if (L.top + 1 == L.MAX_length)
        return false;
    L.data[L.top + 1] = e;
    L.top++;
    return true;
}

bool Pop(Sqstack &L, char &e)
{
    if (L.top == -1)
        return false;
    e = L.data[L.top];
    L.top--;
    return true;
}

bool Gettop(Sqstack &L, char &e)
{
    if (L.top == -1)
        return false;
    e = L.data[L.top];
    return true;
}