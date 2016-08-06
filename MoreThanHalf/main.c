//
//  main.c
//  MoreThanHalf
//
//  Created by chenyufeng on 8/6/16.
//  Copyright © 2016 chenyufeng. All rights reserved.
//

// 数组中出现次数超过一半的数字
// 使用Partition划分
#include <stdio.h>
#include <stdlib.h>

void MoreThanHalf(int *arr, int start, int mid ,int end);
int Partition(int *arr, int start, int end);
void CheckNumber(int *arr, int length, int num);

int main(int argc, const char * argv[])
{
    //    1 1 4 4 4 7 7 7 7
    int array[] = {4,7,1,7,4,1,7,4,7};

    MoreThanHalf(array, 0, 4 ,8);

    return 0;
}

void MoreThanHalf(int *arr, int start, int mid ,int end)
{
    int index = Partition(arr, start, end);

    while (index != mid)
    {
        if (index < mid)
        {
            index = Partition(arr, index + 1, end);
        }
        else
        {
            // index > mid
            index = Partition(arr, start, index - 1);
        }
    }

    printf("%d\n",arr[index]);
    return;
}

int Partition(int *arr, int start, int end)
{
    int i = start, j = end, x = arr[start];

    while (i < j)
    {
        while (i < j && arr[j] >= x)
        {
            j--;
        }
        if (i < j)
        {
            arr[i++] = arr[j];
        }

        while (i < j && arr[i] < x)
        {
            i++;
        }
        if (i < j)
        {
            arr[j--] = arr[i];
        }
    }
    arr[i] = x;

    return i;
}

// 检查该数是否真的是超过一半的，也就是为了验证原先输入的数组中是否真的存在某个数超过数组长度一半
void CheckNumber(int *arr, int length, int num)
{
    int count = 0;
    for (int i = 0; i < length; i++)
    {
        if (arr[i] == num)
        {
            count++;
        }
    }

    if (count > length / 2)
    {
        printf("超过数组一半的数字是：%d\n",num);
    }
    else
    {
        printf("不存在超过数组一半的数字\n");
    }
    
    return ;
}

