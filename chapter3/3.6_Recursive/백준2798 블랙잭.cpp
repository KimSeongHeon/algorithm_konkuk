#include<iostream>
#include<algorithm> //max���� ���� include
#include<vector> //vector�ڷᱸ�� ���� ���� include
using namespace std;
vector<int> picked; // picked = ���� ī�带 ����.
int answer = 0;
void pick(int n,int m,vector<int> card, int index) {
	//n�� ī�尳��, m�� �ִ� ��, card�� ī�� ��ȣ, index�� vector<int> card�� index.
	if (picked.size() == 3) {
		//���� ���. �������� 3���̰�
		if (picked[0] + picked[1] + picked[2] <= m) //���� 3���� ���� m�� ���� ������
			answer = max(answer, picked[0] + picked[1] + picked[2]);
		//������ ��� ���Ͽ� ���� �� ���� ũ�� answer�� �־���
		cout << picked[0] << "\t" << picked[1] << "\t" << picked[2] << "\t" << endl;

		return;
	}
	for (int i = index; i < n; i++) {
		picked.push_back(card[i]); //�̰�
		pick(n, m, card, i + 1); //������ ����
		picked.pop_back(); //�ؿ� �� ������ pop ����
	}
}
//������ 149���� 6.2�� ����
//����� �ִ� nC3 �� �� �� �� ���� ����Ͽ� ���� ū ���� �̴� ���

int main(){
	int n, m; // n�� ī�� ����, m�� �ִ� ��
	vector<int> card; // ī�� ��ȣ�� ������ �ڷᱸ��
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		int data;
		cin >> data;
		card.push_back(data);
	} //�Է�
	pick(n,m,card,0);
	cout << answer;
	return 0;
}

int n, board[100][100];
int cache[100][100];
int jump2(int y, int x) {
	//���� ��� : ������ ���� ���̽�
	if (y >= n) return 0;
	//���� ��� : ������ ���̽�
	if (y == n - 1 && x == n - 1)  return 1;
	int &ret = cache[y][x];
	//�̹� �湮�� ���� ������
	if (ret != -1) return ret;
	else {
		int jumpSize = board[y][x];
		return ret = (jump2(y + jumpSize, x) || jump2(y, x + jumpSize));
	}
}