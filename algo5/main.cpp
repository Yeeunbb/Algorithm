#include <iostream>
#include <vector>
//셀 이동 코드
using namespace std;

int sell[10000]; //셀값을 저장할 배열
int check[100000]; //셀을 지났는지 확인하는 배열
vector<vector<int>> DFS; //셀을 그래프로 저장
void dfs(int m); //dfs 함수


int main(){
	int n, max = 0,max_i = 0, count=0;
	cin >> n;

	DFS.resize(n); //인접리스트 크기 설정

	for(int i=0; i<n; i++){ //셀 값 입력 받음
		cin >> sell[i];
	}

	for(int i=0; i<n; i++){
		if(i+sell[i] < n && sell[i]!=0) //셀의 위치에서 셀의 값만큼 오른쪽으로 이동가능할 때
			DFS[i].push_back(i+sell[i]); //벡터에 저장

		if(i-sell[i] >=0 && sell[i]!=0) //셀의 위치에서 셀의 값만큼 왼쪽으로 이동 가능할 때
			DFS[i].push_back(i-sell[i]); //벡터에 저장
	}

	for(int i=0; i<n; i++){ //각 셀에서 도달가능한 셀이 몇개인지 세기
		count = 0;
		for(int k=0; k<n; k++) check[k] = 0; //새로운 셀을 셀때마다 체크 배열 초기화
		dfs(i); //깊이 탐색
		for(int j=0; j<n; j++){
			if(check[j] == 1) count++; //각 셀 마다 갈 수 있는 셀일 때 count변수 증가
		}
		if(count >= max){ //도달할 수 있는 셀이 가장 많은 셀 찾기
			max_i = i;
			max = count;
		}

	}

	cout << max_i <<" " << max << endl;

	return 0;
}

void dfs(int m){ //깊이우선탐색 함수

	if(check[m] == 1) return; //이미 방문한 주소면 return
	check[m] = 1; //방문했다고 체크
	for(int i=0; i<DFS[m].size(); i++){
		dfs(DFS[m][i]);
	}
}
