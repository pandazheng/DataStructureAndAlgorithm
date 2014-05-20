//
//  main.c
//  LinkList
//
//  Created by panda zheng on 14-5-20.
//  Copyright (c) 2014年 panda zheng. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;

typedef struct node
{
    ElemType data;
    struct node *next;
}LNode,*LinkList;


/*创建一个链表，包含n个结点*/
LinkList CreateLinkList (int n)
{
    LinkList p,r = NULL,list = NULL;
    ElemType e;
    int i;
    for (i = 1 ; i <= n ; i++)
    {
        scanf("%d",&e);
        p = (LinkList) malloc(sizeof(LNode));
        p->data = e;
        p->next = NULL;
        if (!list)
            list = p;
        else
            r->next = p;
        r = p;
    }
    
    return list;
}

/*向链表中存入结点*/
void insertList(LinkList *list,LinkList q,ElemType e)
{
    LinkList p;
    p = (LinkList)malloc(sizeof(LNode));
    p->data = e;
    if (!*list)
    {
        *list = p;
        p->next = NULL;
    }
    else
    {
        p->next = q->next;
        q->next = p;
    }
}

/*删除链表的某个结点*/
void delLink(LinkList *list,LinkList q)
{
    LinkList r;
    if (q == *list)
    {
        *list = q->next;
        free(q);
    }
    else
    {
        for (r = *list ; r->next != q ; r = r->next)
        {
            //循环到要删除的节点的，前一个节点处
        };
        if (r->next != NULL)
        {
            r->next = q->next;
            free(q);
        }
    }
}


/*销毁一个链表*/
void destroyLinkList(LinkList *list)
{
    LinkList p,q;
    p = *list;
    while(p)
    {
        q = p->next;
        free(p);
        p = q;
    }
    *list = NULL;
}


int main(int argc, const char * argv[])
{
    int e,i;
    LinkList l,q;
    q = l = CreateLinkList(1);
    scanf("%d",&e);
    while(e)
    {
        insertList(&l, q, e);
        q = q->next;
        scanf("%d",&e);
    }
    q = l;
    printf("The content of the linklist\n");
    while(q)
    {
        printf("%d  ",q->data);
        q = q->next;
    }
    
    q = l;
    printf("\nDelete the fifth element\n");
    for (i = 0 ; i < 4 ; i++)
    {
        q = q->next;
    }
    delLink(&l, q);
    q = l;
    while(q)
    {
        printf("%d  ",q->data);
        q = q->next;
    }
    destroyLinkList(&l);
    printf("\n");
    return 0;
}

