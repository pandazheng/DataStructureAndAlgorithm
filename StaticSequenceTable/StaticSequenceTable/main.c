//
//  main.c
//  StaticSequenceTable
//
//  Created by panda zheng on 14-5-20.
//  Copyright (c) 2014年 panda zheng. All rights reserved.
//

#include <stdio.h>

#define MaxSize 10

/*向顺序表中存入元素*/
void insertElem(int Sqlist[],int *len,int i,int x)
{
    int t;
    if (*len == MaxSize || i < 1 || i > *len + 1)
    {
        printf("This insert is illegal\n");
        return ;
    }
    
    for (t = *len - 1 ; t >= i - 1 ; t --)
        Sqlist[t+1] = Sqlist[t];
    Sqlist[i-1] = x;
    *len = *len + 1;
}

/*向顺序表中删除元素*/
void DelElem(int Sqlist[] , int *len , int i)
{
    int j;
    if (i < 1 || i > *len)
    {
        printf("This delete is illegal\n");
        return ;
    }
    
    for (j = i ; j < *len ; j++)
        Sqlist[j-1] = Sqlist[j];      /*将第i个元素之后的元素前移*/
    *len = *len - 1;
}



int main(int argc, const char * argv[])
{
    /*按照题目要求进行测试*/
    int Sqlist[MaxSize];
    int len;
    int i;
    
    for (i = 0 ; i < 6 ; i++)
        scanf("%d",&Sqlist[i]);
    len = 6;
    
    for (i = 0 ; i < len ; i++)
        printf("%d ",Sqlist[i]);
    printf("\n The spare length is %d\n",MaxSize - len);
    
    insertElem(Sqlist, &len, 3, 0);
    for (i = 0 ; i < len ; i++)
        printf("%d ",Sqlist[i]);
    printf("\nThe spare length is %d\n",MaxSize - len);
    
    insertElem(Sqlist, &len, 5, 0);
    DelElem(Sqlist, &len, 6);
    for (i = 0 ; i < len ; i++)
        printf("%d ",Sqlist[i]);
    printf("\nThe spare length is %d\n",MaxSize - len);
    return 0;
}

