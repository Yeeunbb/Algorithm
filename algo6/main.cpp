#include <iostream>
#include <vector>
#include <queue>
//셀 이동 코드
using namespace std;

int cell[100000]; //셀값을 저장할 배열
int visited[100000]; //셀을 지났는지 확인하는 배열
vector<vector<int>> graph; //셀을 그래프로 저장
void bfs(int m); //bfs함수
queue<int> que; //bfs함수에 사용할 큐
int start, last; //시작 셀과 도착예정 셀
int count=0; //셀 이동 횟수
int now; //현재 셀
int result = 0; //결과값 변수

int main(){

	int n;

	cin >> n;
	cin >> start >> last;

	graph.resize(n); //인접리스트 크기 설정

	for(int i=0; i<n; i++){ //셀 값 입력 받음
		cin >> cell[i];
	}

	for(int i=0; i<n; i++){

		if(i-cell[i] >=0 && cell[i]!=0) //셀의 위치에서 셀의 값만큼 왼쪽으로 이동 가능할 때
			graph[i].push_back(i-cell[i]); //벡터에 저장

		if(i+cell[i] < n && cell[i]!=0) //셀의 위치에서 셀의 값만큼 오른쪽으로 이동가능할 때
			graph[i].push_back(i+cell[i]); //벡터에 저장
	}

	bfs(start); //너비 우선 탐색

	if(visited[last] != 0){ //도착예정 셀에 도착가능한 경우
		cout << visited[last] - 1; //방문할때까지 거쳐간 셀 횟수 출력
	}
	else{ //도착예정 셀에 도착하지 못한 경우
		cout << "-1";
	}

	return 0;

}

void bfs(int m){ //너비우선탐색 함수
	visited[m] = 1; //해당 셀 m은 방문한것이므로 visited를 1로 바꿔줌.
	que.push(m); //que에 저장해서 탐색 예정임을 표시

	while(!que.empty()){ //큐가 비어질때까지 반복
		now = que.front(); //탐색해야 하는 큐를 match에 넣어줌
		que.pop();

		for(int i=0; i<graph[now].size(); i++){
			int y = graph[now][i]; //match노드에 연결된 다음 노드를 y에 넣어줌

			if(visited[y] == 0){ //y노드가 방문되지 않은 노드일 경우
				que.push(y); //que에 저장해서 탐색예정임을 표시
				visited[y] = visited[now] + 1; //y노드는 match노드에 도달할때까지 이동한 횟수 + 1
			}
		}
	}
}
