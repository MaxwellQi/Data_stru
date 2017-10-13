//
//  Onelink.cpp
//  DataStruct_C++
//
//  Created by zhangqi on 13/10/2017.
//  Copyright © 2017 zhangqi. All rights reserved.
//

#include "Onelink.hpp"

/*
 *  建立单链表
 */
Onelink::Onelink(int n)
{
    head = NULL;    // n = 0时，构造空链表
    if (n > 0) {
        int i = 1;
        OnelinkNode *rear,*q;
        head = new OnelinkNode(i++);
        rear = head;
        while (i <= n) {
            q = new OnelinkNode(i++);
            rear->next = q;     // q节点链入 rear 节点之后
            rear = q;           // rear 指向新的链尾节点
        }
    }
}

/*
 *  销毁单链表
 */
Onelink::~Onelink()
{
    OnelinkNode *p = head, *q;
    while (p != NULL) {
        q = p;
        p = p->next;
        delete q;
    }
    head = NULL;
}

int Onelink::length() const
{
    int linkLen = 0;
    OnelinkNode *p = head;
    while (p != NULL) {
        linkLen++;
        p = p->next;
    }
    return linkLen;
}

/*
 *  定位，返回指向第 i 个节点的指针
 */
OnelinkNode * Onelink::index(int i)const
{
    if (i < 0) return NULL;
    int j = 0;
    OnelinkNode *p = head;
    while (p != NULL && j < i) {
        j++;
        p = p->next;
    }
    return p;
}

int Onelink::get(int i)const
{
    OnelinkNode *p = index(i);
    if (p != NULL) {
        return p->data;
    }
    return -32768;
    
}

/*
 *  设置第 i 个元素值为k
 */
bool Onelink::set(int i,int k)
{
    OnelinkNode *p = index(i);
    if (p != NULL) {
        p->data = k;
        return true;
    }
    return false;
}

/*
 *  k 值插入作为p节点的后继节点
 */
OnelinkNode * Onelink::insert(OnelinkNode *p,int k)
{
    OnelinkNode *q = new OnelinkNode(k);
    if (p == NULL) {
        p = q;
    }else{
        q->next = p->next;
        p->next = q;
    }
    return p;
    
}


/*
 *  删除 p 节点的后继节点
 */
bool Onelink::remove(OnelinkNode *p)
{
    if (p != NULL) {
        OnelinkNode *q = p->next;
        if (q != NULL) {
            p->next = q->next->next;
            delete q;
            return true;
        }
    }
    return false;
}

/*
 *  输出以 p 为头指针的单链表
 */
void Onelink::output(OnelinkNode *p)const
{
    while (p != NULL) {
        printf("%d ",p->data);
        p = p->next;
    }
    printf("\n");
    
}

/*
 *  输出以 head 为头指针的单链表
 */
void Onelink::ouput()const
{
    printf("Onelink:  ");
    output(head);
}




