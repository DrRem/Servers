//
// Created by fffei on 2019/10/20.
//

#include "get_len.h"

int get_len(int x)
{
    int len=0;
    while(x)
    {
        x/=10;
        len++;
    }
    return len;
}