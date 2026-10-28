#include <iostream>
using namespace std;

#define MaxSize 100

typedef struct
{
    char data[MaxSize];
    int length;
} SqString;

bool StrAssign(SqString &s, string cstr)
{
    s.length = 0;
    int strlen = cstr.length();
    if (strlen > MaxSize)
    {
        return false;
    }

    for (int i = 0; i < strlen; i++)
    {
        s.data[i] = cstr[i];
        s.length++;
    }

    return true;
}

bool DestoryStr(SqString &s)
{
    s.length = 0;
    return true;
}

bool StrCopy(SqString &s, SqString t)
{
    if (t.length > MaxSize)
    {
        return false;
    }

    for (int i = 0; i < t.length; i++)
    {
        s.data[i] = t.data[i];
    }

    s.length = t.length;
    return true;
}

bool StrEqual(SqString s, SqString t)
{
    if (s.length != t.length)
    {
        return false;
    }

    for (int i = 0; i < s.length; i++)
    {
        if (s.data[i] != t.data[i])
        {
            return false;
        }
    }

    return true;
}

int StrLength(SqString s)
{
    return s.length;
}

SqString Concat(SqString s, SqString t)
{
    SqString str;
    str.length = 0;
    if (s.length + t.length > MaxSize)
        return str;
    int i = 0, j = 0;
    for (i = 0; i < s.length; i++)
    {
        str.data[i] = s.data[i];
    }
    for (j = 0; j < t.length; j++)
    {
        str.data[i + j] = t.data[j];
    }
    str.length = s.length + t.length;
    return str;
}

SqString SubStr(SqString s, int i, int j)
{
    SqString str;
    str.length = 0;
    if (j < 0)
        return str;
    if (i < 1 || i > s.length)
        return str;
    if (i + j - 1 > s.length)
        return str;
    for (int size = 0; size < j; size++)
    {
        str.data[size] = s.data[i - 1 + size];
    }
    str.length = j;
    return str;
}

SqString InsStr(SqString s1, int i, SqString s2)
{
    SqString str;
    str.length = 0;
    int sumlen = s1.length + s2.length;
    if (sumlen > MaxSize)
        return str;
    if (i < 1 || i > s1.length + 1)
        return str;
    for (int j = 0; j < i - 1; j++)
    {
        str.data[j] = s1.data[j];
    }
    for (int j = 0; j < s2.length; j++)
    {
        str.data[i - 1 + j] = s2.data[j];
    }
    for (int j = i - 1; j < s1.length; j++)
    {
        str.data[j + s2.length] = s1.data[j];
    }
    str.length = sumlen;
    return str;
}

SqString DelStr(SqString s, int i, int j)
{
    SqString str;
    str.length = 0;
    if (j < 0)
        return str;
    if (i < 1 || i > s.length)
        return str;
    if (i + j - 1 > s.length)
        return str;
    for (int size = 0; size < i - 1; size++)
    {
        str.data[size] = s.data[size];
    }
    for (int size = 0; size < s.length - i + 1 - j; size++)
    {
        str.data[i - 1 + size] = s.data[i - 1 + j + size];
    }
    str.length = s.length - j;
    return str;
}

SqString RepStr(SqString s, int i, int j, SqString t)
{
    SqString str;
    str.length = 0;
    if (j < 0)
        return str;
    if (i < 1 || i > s.length)
        return str;
    if (i + j - 1 > s.length)
        return str;
    int sumlen = s.length - j + t.length;
    if (sumlen > MaxSize)
        return str;
    for (int size = 0; size < i - 1; size++)
    {
        str.data[size] = s.data[size];
    }
    for (int size = 0; size < t.length; size++)
    {
        str.data[i - 1 + size] = t.data[size];
    }
    for (int size = 0; size < s.length - i + 1 - j; size++)
    {
        str.data[i - 1 + t.length + size] = s.data[i - 1 + j + size];
    }
    str.length = sumlen;
    return str;
}

void DispStr(SqString s)
{
    for (int i = 0; i < s.length; i++)
    {
        cout << s.data[i] << ' ';
    }
    cout << '\n';
}