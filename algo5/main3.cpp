#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <math.h>

using namespace std;

vector<vector<int>> friends; //친구들의 정보를 저장할 인접 리스트
int visited[2001]; //방문한 노드인지 확인할 visited 배열
void dfs(int n); //깊이우선 탐색 함수
double COUNTN; //사람수를 셀 변수

int main(){
	int n, m, v1, v2;
	double sum=0, fn=0;

	cin >> n >> m;

	vector<double> set; //각 집합에 존재하는 사람수를 저장할 벡터

	friends.resize(n); //친구 수 설정

	for(int i=0; i<m; i++){
		cin >> v1 >> v2;
		friends[v1].push_back(v2); //v1과 v2사이의 관계 입력
		friends[v2].push_back(v1);

	}

	for(int i=0; i<n; i++){
		COUNTN = 0; //각 사람마다 카운트 0으로 초기화
		if(visited[i] != 1){ //아직 방문하지 않은 노드일 때,
			dfs(i); //dfs함수 실행
			fn++; //집단의 수 증가
			set.push_back(COUNTN); //그 집단에 속한 사람 수 저장
			sum += COUNTN; //총 합에 누적
		}
	}

	sort(set.begin(), set.end(), greater<double>()); //가장 큰 집단의 수와, 가장 작은 집단의 수를 구하기 위해 ,sort 사용

	cout << fn << endl;
	cout << (int)set[0] << " " << (int)set.back() << " ";

	sum /= fn;

	cout << fixed;
	cout.precision(1); //소수점 첫째자리까지 출력
	cout << sum;

	return 0;
}

void dfs(int n){

	if(visited[n] == 1) return; //이미방문한 노드이면 return

	visited[n] = 1; //방문했다고 체크
	COUNTN++; //사람 수 증가

	for(int i=0; i<friends[n].size(); i++){
		if(visited[friends[n][i]] != 1)
			dfs(friends[n][i]);
	}

}
