#include <iostream>

using namespace std;
int min(int a, int b); //최솟값 계산
int min(int a, int b, int c);

int main(){

	int n;
	cin >> n; //계단수 입력
	int cost[10005]; //계단올라갈때 발생하는 비용
	int weight[10005]; //가중치(각 계단의 비용)

	weight[0] = 0; //0번째 계단 = 바닥 은 비용이 없음
	for(int i=1; i<=n; i++){
		cin >> weight[i];
	}

	//초기값 설정
	cost[0] = 0;
	cost[1] = weight[1];
	cost[2] = weight[1] + weight[2];
	cost[3] = weight[3];

	for(int i=4; i<=n; i++){ //동적할당을 이용
		cost[i] = min(cost[i-4], cost[i-3], cost[i-1]) + weight[i];
	}
	cout << cost[n] << endl;

	return 0;
}



int min(int a, int b){
	if(a>=b)
		return b;
	else
		return a;
}

int min(int a, int b, int c){
	return min(min(a, b), c);
}
