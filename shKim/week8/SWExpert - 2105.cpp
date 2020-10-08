//
//  SWExpert - 2105.cpp
//  DeltaCode
//
//  Created by 김성헌 on 2020/10/05.
//  Copyright © 2020 김성헌. All rights reserved.
//

#include <iostream>
#include <algorithm>

using namespace std;

int dx[4] = {1,1,-1,-1};
int dy[4] = {-1,1,-1,1};
int map[21][21];
int n;
int answer = -1;
pair<int,int> start;

bool correctDirectionCheck(int current,int opposite){
    switch (current) {
        case 0:
            if(opposite == 3) return false;
            else return true;
            break;
        case 1:
            if(opposite == 2) return false;
            else return true;
        case 2:
            if(opposite == 1) return false;
            else return true;
        case 3:
            if(opposite == 0) return false;
            else return true;
        default:
            break;
    }
    return false;
}

void dfs(int x,int y,int currentDir,int rotate,int info[4],bool eat[101],int cnt){
    if(eat[map[x][y]]) {
        if(x == start.first && y == start.second) answer = max(answer,cnt);
        return;
    }
    eat[map[x][y]] = true;
    //방향 그대로 가기
    int nx = x + dx[currentDir];
    int ny = y + dy[currentDir];
    if(nx>=0 && nx<n && ny>=0 && ny<n) {
        info[currentDir] += 1;
        dfs(nx,ny,currentDir,rotate,info,eat,cnt+1);
    }
    //방향꺾기
    for(int i=0;i<4;i++){
        if(currentDir == i) continue;
        if(!correctDirectionCheck(currentDir,i)) continue;
        if(info[i] != 0) continue;
        int nx = x + dx[i];
        int ny = y + dy[i];
        info[i] = 1;
        if(nx>=0 && nx<n && ny>=0 && ny<n) dfs(nx,ny,i,rotate+1,info,eat,cnt+1);
    }
}

int main(){
    int T;
    cin >> T;
    for(int t=0;t<T;t++){
        answer = -1;
        cin >> n;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cin >> map[i][j];
            }
        }
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                for(int k=0;k<4;k++){
                    start = {i,j};
                    bool eat[101];
                    int temp[4];
                    memset(temp,0,sizeof(temp));
                    temp[k] = 1;
                    memset(eat,false,sizeof(eat));
                    dfs(i,j,k,1,temp,eat,0);
                }
            }
        }
        
        cout << "#" << t+1 << " " << answer << endl;
    }
    return 0;
}
