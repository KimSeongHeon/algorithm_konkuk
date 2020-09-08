//
//  PG - 43105 - ���ä����̤��������������Ť�.cpp
//  ���������̤����̤����Ĥ��̤�����
//
//  Created by �輺�� on 2020/04/10.
//  Copyright �� 2020 �輺��. All rights reserved.
//

#include<iostream>
#include <string>
#include <vector>
#include <memory.h>
using namespace std;
int cache[501][501];//x,y���� ������ ��
int cal(int x,int y,vector<vector<int>> &triangle){
    int &ret = cache[x][y];
    if(ret != -1) return ret;
    if(y!=0 && y!=x) ret = max(cal(x-1,y-1,triangle) + triangle[x][y],cal(x-1,y,triangle) + triangle[x][y]);
    else if(y==0) ret = cal(x-1,y,triangle) + triangle[x][y];
    else if(y==x) ret = cal(x-1,y-1,triangle) + triangle[x][y];
    return ret;
}
int solution(vector<vector<int>> triangle) {
    memset(cache,-1,sizeof(cache));
    int answer = -1;
    cache[0][0] = triangle[0][0];
    for(int i=0;i<triangle.size();i++){
        answer = max(answer,cal((int)triangle.size()-1,i,triangle));
    }   
    return answer;
}