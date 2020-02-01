#include <iostream>
#include <vector>
//�� �̵� �ڵ�
using namespace std;

int sell[10000]; //������ ������ �迭
int check[100000]; //���� �������� Ȯ���ϴ� �迭
vector<vector<int>> DFS; //���� �׷����� ����
void dfs(int m); //dfs �Լ�


int main(){
	int n, max = 0,max_i = 0, count=0;
	cin >> n;

	DFS.resize(n); //��������Ʈ ũ�� ����

	for(int i=0; i<n; i++){ //�� �� �Է� ����
		cin >> sell[i];
	}

	for(int i=0; i<n; i++){
		if(i+sell[i] < n && sell[i]!=0) //���� ��ġ���� ���� ����ŭ ���������� �̵������� ��
			DFS[i].push_back(i+sell[i]); //���Ϳ� ����

		if(i-sell[i] >=0 && sell[i]!=0) //���� ��ġ���� ���� ����ŭ �������� �̵� ������ ��
			DFS[i].push_back(i-sell[i]); //���Ϳ� ����
	}

	for(int i=0; i<n; i++){ //�� ������ ���ް����� ���� ����� ����
		count = 0;
		for(int k=0; k<n; k++) check[k] = 0; //���ο� ���� �������� üũ �迭 �ʱ�ȭ
		dfs(i); //���� Ž��
		for(int j=0; j<n; j++){
			if(check[j] == 1) count++; //�� �� ���� �� �� �ִ� ���� �� count���� ����
		}
		if(count >= max){ //������ �� �ִ� ���� ���� ���� �� ã��
			max_i = i;
			max = count;
		}

	}

	cout << max_i <<" " << max << endl;

	return 0;
}

void dfs(int m){ //���̿켱Ž�� �Լ�

	if(check[m] == 1) return; //�̹� �湮�� �ּҸ� return
	check[m] = 1; //�湮�ߴٰ� üũ
	for(int i=0; i<DFS[m].size(); i++){
		dfs(DFS[m][i]);
	}
}
