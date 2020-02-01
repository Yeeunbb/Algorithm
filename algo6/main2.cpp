#include <iostream>
#include <vector>
#include <queue>
//미로찾기 문제
using namespace std;

char road[104][104]; //갈수있는지,없는지 도로상황 입력받을 배열
int visited[104][104]; //방문한 길인지 표시할 함수
int dir[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}}; //현재있는 길에서 상,하,좌,우를 표시할 좌표
int x, y; //길의 x축, y축
int m, n; //길의 크기
int result_x, result_y; //최종 정답 칸의 x,y값
bool flag = false; //마지막 셀에 도착한게 맞은지 확인할 flag

void bfs(int i, int j); //bfs함수 선언

int main(){
	int result=999999; //초기에 result값은 매우 큰 값으로 지정
	cin >> m >> n;

	for(int i=0; i<m; i++){
		for(int j=0; j<n; j++){ //도로 상황 입력받음
			cin >> road[i][j];
		}
	}

	for(int i=0; i<n; i++){
		for(int k=0; k<m; k++){
			for(int j=0; j<n; j++){ //visited함수를 for문이 돌때마다 초기화
				visited[k][j] = 0;
			}
		}
		if(road[0][i] == '1'){ //첫번째 줄에 있는 길 중에서, 갈 수 있는 길일 때,
			flag = false;
			bfs(0, i); //너비우선 탐색
			//처음으로 마지막셀에 도달했을때, 도달할때까지 이동한 횟수가 이전 횟수(result값)보다 작고, 마지막셀에 도달한것이 맞을경우
			if(result > visited[result_y][result_x] && flag){
				result = visited[result_y][result_x]; //result값 갱신
			}
		}
	}

	if(result != 999999){ //마지막줄에 있는 길까지 도달 한 경우
		cout << result;
	}
	else{ //도달하지 못한 경우. == 길이 없는 경우
		cout << "-1";
	}

	return 0;
}


void bfs(int i, int j){ //너비우선 탐색함수
queue<pair<int, int>> que; //bfs함수에 사용할 큐
	visited[i][j] = 1; //해당 길은 방문했으므로 visited함수를 1로 설정
	que.push(pair<int, int>(i, j)); //해당 길에 대해서 탐색해야하므로 que에 저장

	while(!que.empty()){
		y = que.front().first; //좌표값 설정
		x = que.front().second;
		que.pop();

		if(y == m-1){ //마지막 줄에 도달한 경우
			result_x = x; //도달했을 때의, x좌표값 저장
			result_y = y;
			flag = true; //flag를 true로
			return; //탐색 종료
		}

		for(int i=0; i<4; i++){
			int next_y = y + dir[i][0]; //현재 경로의 상,하,좌,우를 탐색
			int next_x = x + dir[i][1];

			//현재 탐색해야 하는 좌표가, 도로의 범위를 벗어나지 않았고, 갈 수 있는 도로이며, 방문하지 않은 경우
			if(next_y < m && next_y >= 0 && next_x < n && next_x >= 0 && visited[next_y][next_x] == 0 && road[next_y][next_x] == '1'){
				visited[next_y][next_x] = visited[y][x] + 1; //이전 도로로 올때까지 이동한 횟수+1
				que.push(pair<int, int>(next_y, next_x)); //현재 도로와 연결된 다른 도로를 탐색하기 위해 que에 저장
			}
		}
	}
}
