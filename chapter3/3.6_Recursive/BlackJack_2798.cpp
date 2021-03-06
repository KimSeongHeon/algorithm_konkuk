#include<iostream>
#include<algorithm> //max쓰기 위해 include
#include<vector> //vector자료구조 쓰기 위해 include
using namespace std;
vector<int> picked; // picked = 뽑은 카드를 넣음.
int answer = 0;
void pick(int n,int m,vector<int> card, int index) {
	//n은 카드개수, m은 최대 합, card는 카드 번호, index는 vector<int> card의 index.
	if (picked.size() == 3) {
		//기저 사례. 뽑은것이 3개이고
		if (picked[0] + picked[1] + picked[2] <= m) //뽑은 3개의 합이 m을 넘지 않으면
			answer = max(answer, picked[0] + picked[1] + picked[2]);
		//이전의 답과 비교하여 이전 답 보다 크면 answer에 넣어줌
		cout << picked[0] << "\t" << picked[1] << "\t" << picked[2] << "\t" << endl;

		return;
	}
	for (int i = index; i < n; i++) {
		picked.push_back(card[i]); //뽑고
		pick(n, m, card, i + 1); //밑으로 가서
		picked.pop_back(); //밑에 다 봤으면 pop 해줌
	}
}
//페이지 149쪽의 6.2와 동일
//만들수 있는 nC3 을 다 고른 뒤 합을 계산하여 가장 큰 것을 뽑는 방식

int main(){
	int n, m; // n은 카드 개수, m은 최대 합
	vector<int> card; // 카드 번호를 저장할 자료구조
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		int data;
		cin >> data;
		card.push_back(data);
	} //입력
	pick(n,m,card,0);
	cout << answer;
	return 0;
}

int n, board[100][100];
int cache[100][100];
int jump2(int y, int x) {
	//기저 사례 : 범위를 넘은 케이스
	if (y >= n) return 0;
	//기저 사례 : 도착한 케이스
	if (y == n - 1 && x == n - 1)  return 1;
	int &ret = cache[y][x];
	//이미 방문한 적이 있으면
	if (ret != -1) return ret;
	else {
		int jumpSize = board[y][x];
		return ret = (jump2(y + jumpSize, x) || jump2(y, x + jumpSize));
	}
}