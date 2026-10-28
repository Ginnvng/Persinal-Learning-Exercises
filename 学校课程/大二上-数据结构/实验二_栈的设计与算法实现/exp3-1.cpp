#include "sqstack.cpp"
#include <iostream>
using namespace std;

int main(void)
{
    Sqstack s;
    InitStack(s);
    Push(s, 'a');
    Push(s, 'b');
    Push(s, 'c');
    Push(s, 'd');
    Push(s, 'e');
    if (StackEmpty(s))
    {
        cout << "空" << '\n';
    }
    else
        cout << "非空" << '\n';

    char e;
    while (!StackEmpty(s))
    {
        Pop(s, e);
        cout << e << '\n';
    }

    if (StackEmpty(s))
    {
        cout << "空" << '\n';
    }
    else
        cout << "非空" << '\n';
    DestroyStack(s);
}