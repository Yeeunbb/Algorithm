#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <math.h>

using namespace std;

vector<vector<int>> v; //ģ�����踦 ������ ��������Ʈ
int visited[2001]; //�湮�� ������� Ȯ���� visited �迭
void dfs(int n); //���̿켱Ž���Լ�
int COUNTN; //������� �� ����


int main(){
	int n, m, k, v1, v2;
	bool flag = true; //��������Ʈ�� ����ġ�� �� �� ����� flag
	cin >> n >> m >> k;

	v.resize(n); //��������Ʈ ������ ����

	for(int i=0; i<m; i++){
		cin >> v1 >> v2;
		v[v1].push_back(v2); //v1�� v2�� ���� �Է�
		v[v2].push_back(v1);
	}

	while(flag){

		flag = false; //k���� ���� ģ�����踦 ���� ����� �������� ���� ���, while�� ����

		for(int i=0; i<n; i++) {
			if(v[i].size() > 0 && v[i].size() < k){ //��������Ʈ�� ���� �����ϰ�, k���� ���� ģ�����踦 ���� ���
				visited[i] = 1; //�ش� ��带 �湮�ߴٰ� ����
				flag = true; //while�� ���
			}
		}

		for(int i=0; i<n; i++){
			for(int j=v[i].size()-1; j>=0; j--){ //��������Ʈ0���� ������ Ȯ��
				if(visited[v[i][j]] == 1){ //���� ��尡 �������� ��带 ���� �� ���
					v[i].erase(v[i].begin() + j); //�ش� ��� ����
				}
				if(v[i].size() > 0 && v[i].size() < k) flag = true; //�ش� ��带 ���������ν�, �ش� �ε����� ģ�����谡 k���� �۾��� ���, while�� ���
			}
		}

		for(int i=0; i<n; i++){ //����ġ�Ⱑ �������Ƿ�, �������� �ε����� ������ ��� ����
			if(visited[i] == 1 && v[i].size() > 0) v[i].clear();
		}
	}

	for(int i=0; i<n; i++){
		if(visited[i] != 1 && v[i].size()>0){ //�湮���� �ʾҰ�, ��忡 ����Ʈ�� �����ϴ� ���,
			dfs(i); //dfs�Լ� ����
		}
	}
	cout << COUNTN;

	return 0;
}

void dfs(int n){

	visited[n] = 1; //�湮�ߴٰ� üũ
	COUNTN++; //��� �� ����

	for(int i=0; i<v[n].size(); i++){
		if(visited[v[n][i]] != 1){
			dfs(v[n][i]);
		}
	}
}

