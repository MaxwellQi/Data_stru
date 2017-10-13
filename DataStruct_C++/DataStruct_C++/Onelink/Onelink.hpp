//
//  Onelink.hpp
//  DataStruct_C++
//
//  Created by zhangqi on 13/10/2017.
//  Copyright © 2017 zhangqi. All rights reserved.
//

#ifndef Onelink_hpp
#define Onelink_hpp

#include <stdio.h>

class OnelinkNode
{
public:
    int data;
    OnelinkNode *next;
    OnelinkNode(int k = 0, OnelinkNode *nextnode = NULL)  // 构造节点，内联函数
    {
        data = k;
        next = NULL;
    }
    ~OnelinkNode(){};
};

class Onelink
{
public:
    OnelinkNode *head;  // 单链表的头指针
    Onelink(int n = 0); // 构造函数,以n个自然数建立单链表
    ~Onelink();
    bool isEmpty()const // 判断单链表是否为空
    {
        return head == NULL;
    }
    bool isFull()const  // 判断单链表是否已满(总是不满的)
    {
        return false;
    }
    
    int length() const; // 返回单链表长度
    OnelinkNode * index(int i)const;    // 定位，返回指向第 i 个节点的指针
    int get(int i)const;    // 返回第 i 个数据元素值
    bool set(int i,int k);  // 设置第 i 个元素值为k
    OnelinkNode * insert(OnelinkNode *p,int k);  // k 值插入作为p节点的后继节点
    
    bool remove(OnelinkNode *p);    // 删除 p 节点的后继节点
    void output(OnelinkNode *p)const;   // 输出以 p 为头指针的单链表
    void ouput()const;  // 输出以 head 为头指针的单链表
    
    

    
};


#endif /* Onelink_hpp */
