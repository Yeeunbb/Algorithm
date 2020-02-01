#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <math.h>

using namespace std;

vector<vector<int>> v; //친구관계를 저장할 인접리스트
int visited[2001]; //방문한 노드인지 확인할 visited 배열
void dfs(int n); //깊이우선탐색함수
int COUNTN; //사람수를 셀 변수


int main(){
	int n, m, k, v1, v2;
	bool flag = true; //인접리스트를 가지치기 할 때 사용할 flag
	cin >> n >> m >> k;

	v.resize(n); //인접리스트 사이즈 설정

	for(int i=0; i<m; i++){
		cin >> v1 >> v2;
		v[v1].push_back(v2); //v1과 v2의 관계 입력
		v[v2].push_back(v1);
	}

	while(flag){

		flag = false; //k보다 적게 친구관계를 가진 사람이 존재하지 않을 경우, while문 종료

		for(int i=0; i<n; i++) {
			if(v[i].size() > 0 && v[i].size() < k){ //인접리스트에 값이 존재하고, k보다 적게 친구관계를 가진 경우
				visited[i] = 1; //해당 노드를 방문했다고 설정
				flag = true; //while문 계속
			}
		}

		for(int i=0; i<n; i++){
			for(int j=v[i].size()-1; j>=0; j--){ //인접리스트0번의 끝부터 확인
				if(visited[v[i][j]] == 1){ //현재 노드가 지워야할 노드를 포함 한 경우
					v[i].erase(v[i].begin() + j); //해당 노드 삭제
				}
				if(v[i].size() > 0 && v[i].size() < k) flag = true; //해당 노드를 삭제함으로써, 해당 인덱스의 친구관계가 k보다 작아진 경우, while문 계속
			}
		}

		for(int i=0; i<n; i++){ //가지치기가 끝났으므로, 지워야할 인덱스의 노드들을 모두 삭제
			if(visited[i] == 1 && v[i].size() > 0) v[i].clear();
		}
	}

	for(int i=0; i<n; i++){
		if(visited[i] != 1 && v[i].size()>0){ //방문하지 않았고, 노드에 리스트가 존재하는 경우,
			dfs(i); //dfs함수 실행
		}
	}
	cout << COUNTN;

	return 0;
}

void dfs(int n){

	visited[n] = 1; //방문했다고 체크
	COUNTN++; //사람 수 증가

	for(int i=0; i<v[n].size(); i++){
		if(visited[v[n][i]] != 1){
			dfs(v[n][i]);
		}
	}
}

