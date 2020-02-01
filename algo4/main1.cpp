//가장 위의 계단으로 올라 갈때, 올라가는 방법의 수
#include<iostream>

using namespace std;

int main(){

	int n; //총 계단 수
	cin >> n;
	int arr[21]; //계단 마다 올라갈 방법의 수 저장할 배열

	arr[0] = arr[1] = arr[2] = 1; //초기값 초기화
	arr[3] = 2;

	for(int i=4; i<=n; i++){ //동적계획이용
		arr[i] = arr[i-4] + arr[i-3] + arr[i-1];
	}

	cout << arr[n] << endl;

	return 0;
}

