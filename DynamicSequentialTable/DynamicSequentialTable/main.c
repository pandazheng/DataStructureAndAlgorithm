//
//  main.c
//  DynamicSequentialTable
//
//  Created by panda zheng on 14-5-20.
//  Copyright (c) 2014年 panda zheng. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

#define MaxSize 10
typedef int ElemType;           /*将int定义为ElemType*/

typedef struct{
    int *elem;
    int length;
    int listsize;
}Sqlist;

/*初始化一个顺序表*/
void initSqlist(Sqlist *L)
{
    L->elem = (int *) malloc(MaxSize * sizeof(ElemType));
    if (!L->elem)
        return ;
    L->length = 0;
    L->listsize = MaxSize;
}

/*向顺序表中存入元素*/
void InsertElem(Sqlist *L,int i,ElemType item)
{
    ElemType *base,*insertPtr,*p;
    if ( i < 1 || i > L->length + 1)
        return ;
    if (L->length >= L->listsize)
    {
        base = (ElemType *)realloc(L->elem,(L->listsize + 10) * sizeof(ElemType));
        L->listsize = L->listsize + 100;
    }
    insertPtr = &(L->elem[i-1]);
    for (p = &(L->elem[L->length - 1]) ; p >= insertPtr ; p--)
    {
        *(p+1) = *p;
    }
    *insertPtr = item;
    L->length++;
}

/*从顺序中删除元素*/
void DelElem(Sqlist *L,int i)
{
    ElemType *delItem,*q;
    if (i < 1 || i > L->length)
        return ;
    delItem = &(L->elem[i-1]);
    q = L->elem + L->length - 1;
    for (++delItem ; delItem <= q ; ++delItem)
        *(delItem - 1) = *delItem;
    L->length--;
}

int main(int argc, const char * argv[])
{
    Sqlist l;
    int i;
    initSqlist(&l);
    for (i = 0 ; i < 15 ; i++)
    {
        InsertElem(&l, i + 1, i + 1);
    }
    printf("\nThe content of the list is \n");
    for (i = 0 ; i < l.length ; i++)
        printf("%d  ",l.elem[i]);
    DelElem(&l, 5);
    printf("\nDelete the fifth element\n");
    for (i = 0 ; i < l.length ; i++)
        printf("%d  ",l.elem[i]);
    printf("\nover\n");
    return 0;
}

