//n k 를 입력받는 계단
#include <iostream>

using namespace std;

int cost[100001]; //최종 결과 비용
int weight[100001]; //비용(가중치)

int main(){

	int n, k;

	cin >> n >> k;

	int* stair = new int[k];
	for(int i=0; i<k; i++){ //오를 수 있는 계단
		cin >> stair[i];
	}

	weight[0] = 0; //0번째 계단은 비용이 없다
	for(int i=1; i<=n; i++){ //각 계단 별 비용 입력
		cin >> weight[i];
	}

	for(int i=0; i<k; i++){ //오를 수 있는 계단의 경우, 각 위치에 비용 입력
		cost[stair[i]] = weight[stair[i]];
	}

	for(int i=1; i<=n; i++){ //첫 번째 계단부터 확인
		if(cost[i]==0) //값이 아직 지정되어 있지 않은 경우
		{
			int Min = 999999999; //그냥 큰 값 지정
			for(int j=0; j < k ; j++)
			{//내가 서있는 계단이, 오를 수 있는 계단의 크기보다 크고, 지금 위치로 오기 전에 서있던 계단의 비용이 0이 아닌 경우
				if(i-stair[j] > 0 && cost[i-stair[j]] > 0)
				{//지금 위치로 오기 전에 서있던 계단의 비용이 최솟값보다 작은 경우, 최솟값 초기화
					if(cost[i-stair[j]] < Min)
					{ //Min 갱신
						Min = cost[i-stair[j]];
					}
				}
			}
			if(Min != 999999999)
				cost[i] = Min + weight[i];
		}
	}

	if(cost[n]==0){ //값이 0이라는건, 갈수 없는 계단을 의미
		cout<< -1 << endl;;
	}
	else{
		cout<< cost[n] <<endl;
	}

	delete[] stair;
	return 0;
}

