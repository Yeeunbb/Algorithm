#include <iostream>
#include <vector>
#include <queue>
//�� �̵� �ڵ�
using namespace std;

int cell[100000]; //������ ������ �迭
int visited[100000]; //���� �������� Ȯ���ϴ� �迭
vector<vector<int>> graph; //���� �׷����� ����
void bfs(int m); //bfs�Լ�
queue<int> que; //bfs�Լ��� ����� ť
int start, last; //���� ���� �������� ��
int count=0; //�� �̵� Ƚ��
int now; //���� ��
int result = 0; //����� ����

int main(){

	int n;

	cin >> n;
	cin >> start >> last;

	graph.resize(n); //��������Ʈ ũ�� ����

	for(int i=0; i<n; i++){ //�� �� �Է� ����
		cin >> cell[i];
	}

	for(int i=0; i<n; i++){

		if(i-cell[i] >=0 && cell[i]!=0) //���� ��ġ���� ���� ����ŭ �������� �̵� ������ ��
			graph[i].push_back(i-cell[i]); //���Ϳ� ����

		if(i+cell[i] < n && cell[i]!=0) //���� ��ġ���� ���� ����ŭ ���������� �̵������� ��
			graph[i].push_back(i+cell[i]); //���Ϳ� ����
	}

	bfs(start); //�ʺ� �켱 Ž��

	if(visited[last] != 0){ //�������� ���� ���������� ���
		cout << visited[last] - 1; //�湮�Ҷ����� ���İ� �� Ƚ�� ���
	}
	else{ //�������� ���� �������� ���� ���
		cout << "-1";
	}

	return 0;

}

void bfs(int m){ //�ʺ�켱Ž�� �Լ�
	visited[m] = 1; //�ش� �� m�� �湮�Ѱ��̹Ƿ� visited�� 1�� �ٲ���.
	que.push(m); //que�� �����ؼ� Ž�� �������� ǥ��

	while(!que.empty()){ //ť�� ����������� �ݺ�
		now = que.front(); //Ž���ؾ� �ϴ� ť�� match�� �־���
		que.pop();

		for(int i=0; i<graph[now].size(); i++){
			int y = graph[now][i]; //match��忡 ����� ���� ��带 y�� �־���

			if(visited[y] == 0){ //y��尡 �湮���� ���� ����� ���
				que.push(y); //que�� �����ؼ� Ž���������� ǥ��
				visited[y] = visited[now] + 1; //y���� match��忡 �����Ҷ����� �̵��� Ƚ�� + 1
			}
		}
	}
}
