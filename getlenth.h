//
// Created by fffei on 2019/10/18.
//

#ifndef SERVERS_GETLENTH_H
#define SERVERS_GETLENTH_H

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

#endif //SERVERS_GETLENTH_H
