#include <iostream>
#include <vector>
#include <queue>
//지하철 이동 경로
using namespace std;

int visited[1004]; //방문한 역인지 저정할 배열
vector<vector<int>> metro; //지하철역 사이의 정보를 저장할 벡터
queue<int> que; //bfs함수에 사용할 큐
int n, m, s1, s2; //지하쳘 역 갯수n, 인접한 역의 쌍 m, 출발할 역 s1, 도착할 역 s2

void bfs(int m); //너비우선탐색

int main(){
	int v1, v2;

	cin >> n;
	cin >> m;

	metro.resize(n); //인접리스트 크기 설정

	for(int i=0; i<m; i++){
		cin >> v1 >> v2;
		metro[v1].push_back(v2); //metro벡터에 역들간의 정보 저장
		metro[v2].push_back(v1);
	}

	cin >> s1 >> s2;

	bfs(s1); //출발할 역에서 너비우선탐색 시작

	cout << visited[s2]-1;

	return 0;
}

void bfs(int m){ //너비우선탐색
	visited[m] = 1; //현재 역은 방문했으니, visited배열 1로 설정
	que.push(m); //현재 역과 연결된 역들을 탐색하기 위해 que에 저장

	while(!que.empty()){
		int x = que.front();
		que.pop();

		if(x == s2){ //탐색해야하는 현재 역이 도착해야 할 역인 경우
			return; //탐색 종료
		}

		for(int i=0; i<metro[x].size(); i++){
			int y = metro[x][i]; //y는 현재역과 연결된 다음 역
			if(visited[y] == 0){ //y역이 아직 방문하지 않은 역일 경우
				que.push(y); //탐색하기 위해 que에 저장
				visited[y] = visited[x] + 1; //y에 올때까지 방문한 역 갯수는 이전 역을 올때까지 방문한 횟수+1
			}
		}
	}
}
