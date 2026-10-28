void Move(SqList *&L)
{
    // 双指针，一个在开头，一个在结尾
    int i = 0, j = L->length - 1, temp;
    while (i < j)
    {
        // 让i先从头开始探，直到i遇到大于等于0的值
        while (i < j && L->data[i] < 0)
        {
            i++;
        }
        // 让 j 从结尾开始探，直到 j 遇到小于0 的值
        while (i < j && L->data[j] >= 0)
        {
            j--;
        }
        // 都遇到不符合条件的值的情况下，互换
        if (i < j)
        {
            temp = L->data[i];
            L->data[i] = L->data[j];
            L->data[j] = temp;
        }
    }
}