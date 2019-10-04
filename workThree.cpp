/*#include <iostream>

using namespace std;

int* csort(int c[], int n, int m); //배열값을 한 칸 씩 밀어주는 함수

int main(){
	int n, m; //n은 입력받을 정수의 수, m은 그 정수의 값
	cin >> n;

	int* arr = new int[n]; //R의 숫자열을 저장할 배열
	int* brr = new int[n]; //S의 숫자열을 저장할 배열
	int* crr = new int[n]; //1부터 n까지의 수를 저장할 배열

	for(int i=0; i<n; i++){
		cin >> arr[i]; //arr배열에 값 저장
		crr[i] = i+1; //crr배열에 1~n까지 값 저장(순차적으로)
	}

	for(int i=n-1; i>=0; i--){ //brr값 찾기
		m = arr[i];
		brr[i] = crr[m]; //brr의 값은 arr의 값만큼의 index를 가지는 crr의 값
		if(m >= brr[i]){ //S수열이 만들어지 지않는 경우
			brr[n-1] = -1;
		}
		crr = csort(crr, n, m); //crr 수열 정리
	}

	if(brr[n-1] == -1){
		cout << "-1"; //crr이 만들어지지 않는 경우
	}

	else{
		for(int i=0; i<n; i++){
			cout<< brr[i] << " ";
		}
	}

	delete[] arr;
	delete[] brr;
	delete[] crr;

	return 0;
}

int* csort(int c[], int n, int m){

	for(int i=m; i<n; i++){ //crr의 값을 뽑아서 사용. 뽑은부분부터 뒷 값을 땡겨주기
		c[i] = c[i+1];
	}
	return c;
}
*/
