//
//  PG - 43104 - �������Ӥ� ���������Ӥ����̤�.cpp
//  ���������̤����̤����Ĥ��̤�����
//
//  Created by �輺�� on 2020/04/10.
//  Copyright �� 2020 �輺��. All rights reserved.
//

#include<iostream>
#include<algorithm>
#include <string>
#include <vector>
#include <memory.h>
using namespace std;
long long cache[81]; //n ��° ���簢���� �Ѻ��� ����
long long cal(int n){
    if(n<0) return 0;
    long long &ret = cache[n];
    if(ret != -1) return ret;
    ret = cal(n-2)+cal(n-1);
    return ret;
}
long long solution(int N) {
    memset(cache,-1,sizeof(cache));
    cache[1] = 1; cache[2] = 1;
    return cal(N)*4+cal(N-1)*2;
}