#include <iostream>

using namespace std;

char Ameba[101][101]; //아메바 배열
int visited[101][101]; //방문한 픽셀인지 확인할 배열
int count; //픽셀을 세는 변수

void dfs(int i, int j, int m, int n); //깊이우선 탐색 함수

int main(){

	int M, N, max=0, AmebaN = 0;;
	cin >> M >> N;

	for(int i=0; i<M; i++){ //아메바 정보 입력받음
		for(int j=0; j<N; j++){
			cin >> Ameba[i][j];
		}
	}

	for(int i=0; i<M; i++){
		for(int j=0; j<N; j++){
			if(Ameba[i][j] == '1' && visited[i][j] != 1){ //만약 아메바가 존재하는 픽셀이고, 방문하지 않았다면
				dfs(i, j, M, N); //dfs함수 실행
				AmebaN++; //아메바의 갯수 카운트
			}
			if(count > max){ //픽셀의 수가 가장 많은 아메바의 픽셀 수 카운트
				max = count;
			}
			count = 0;
		}
	}

	cout << AmebaN << " " << max;


	return 0;
}

void dfs(int i, int j, int m, int n){

	if(visited[i][j] != 1){ //만약 방문하지 않았다면
		visited[i][j] = 1; //방문으로 바꾸어주고
		count++; //픽셀의 갯수 증가
	}

	if(Ameba[i][j+1] == '1' && visited[i][j+1] != 1 && j+1 < n) //현재 픽셀의 오른쪽칸
		dfs(i, j+1, m, n);
	if(Ameba[i+1][j+1] == '1' && visited[i+1][j+1] != 1 && i+1 < m && j+1 < n) //현재 픽셀의 대각선 오른쪽 아래
		dfs(i+1, j+1, m, n);
	if(Ameba[i+1][j] == '1' && visited[i+1][j] != 1 && i+1 < m) //현재 픽셀의 바로 아래
		dfs(i+1, j, m, n);
	if(Ameba[i+1][j-1] == '1' && visited[i+1][j-1] != 1 && i+1 < m && j-1 >= 0) //현재 픽셀의 왼쪽 대각선 아래
		dfs(i+1, j-1, m, n);
	if(Ameba[i][j-1] == '1' && visited[i][j-1] != 1 && j-1 >= 0) //현재 픽셀의 왼쪽칸
		dfs(i, j-1, m, n);
	if(Ameba[i-1][j-1] == '1' && visited[i-1][j-1] != 1 && i-1 >=0 && j-1 >=0) //현재 픽셀의 왼쪽 대각선 위
		dfs(i-1, j-1, m, n);
	if(Ameba[i-1][j] == '1' && visited[i-1][j] != 1 && i-1 >= 0) //현재 픽셀의 바로 위
		dfs(i-1, j, m, n);
	if(Ameba[i-1][j+1] == '1' && visited[i-1][j+1] != 1 && i-1 >= 0 && j+1 < n) //현재 픽셀의 오른쪽 대각선 위
		dfs(i-1, j+1, m, n);
}
