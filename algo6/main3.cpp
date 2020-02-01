#include <iostream>
#include <vector>
#include <queue>
//����ö �̵� ���
using namespace std;

int visited[1004]; //�湮�� ������ ������ �迭
vector<vector<int>> metro; //����ö�� ������ ������ ������ ����
queue<int> que; //bfs�Լ��� ����� ť
int n, m, s1, s2; //���ϫx �� ����n, ������ ���� �� m, ����� �� s1, ������ �� s2

void bfs(int m); //�ʺ�켱Ž��

int main(){
	int v1, v2;

	cin >> n;
	cin >> m;

	metro.resize(n); //��������Ʈ ũ�� ����

	for(int i=0; i<m; i++){
		cin >> v1 >> v2;
		metro[v1].push_back(v2); //metro���Ϳ� ���鰣�� ���� ����
		metro[v2].push_back(v1);
	}

	cin >> s1 >> s2;

	bfs(s1); //����� ������ �ʺ�켱Ž�� ����

	cout << visited[s2]-1;

	return 0;
}

void bfs(int m){ //�ʺ�켱Ž��
	visited[m] = 1; //���� ���� �湮������, visited�迭 1�� ����
	que.push(m); //���� ���� ����� ������ Ž���ϱ� ���� que�� ����

	while(!que.empty()){
		int x = que.front();
		que.pop();

		if(x == s2){ //Ž���ؾ��ϴ� ���� ���� �����ؾ� �� ���� ���
			return; //Ž�� ����
		}

		for(int i=0; i<metro[x].size(); i++){
			int y = metro[x][i]; //y�� ���翪�� ����� ���� ��
			if(visited[y] == 0){ //y���� ���� �湮���� ���� ���� ���
				que.push(y); //Ž���ϱ� ���� que�� ����
				visited[y] = visited[x] + 1; //y�� �ö����� �湮�� �� ������ ���� ���� �ö����� �湮�� Ƚ��+1
			}
		}
	}
}
