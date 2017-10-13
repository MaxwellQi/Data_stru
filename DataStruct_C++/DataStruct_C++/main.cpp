//
//  main.cpp
//  DataStruct_C++
//
//  Created by zhangqi on 13/10/2017.
//  Copyright © 2017 zhangqi. All rights reserved.
//

#include <iostream>
#include "Onelink.hpp"


/*
 * 单向链表逆转
 */
void reverse(Onelink &h1)
{
    OnelinkNode *p = h1.head, *q, *front = NULL;
    while (p != NULL) {
        q = p->next;
        p->next = front;
        front = p;
        p = q;
    }
    h1.head = front;
}

int main(int argc, const char * argv[]) {

    Onelink h1(5);
    h1.ouput();
    reverse(h1);
    
    printf("Reverse!\n");
    h1.ouput();
    
    return 0;
}
