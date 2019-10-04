#include <iostream>
//거듭제곱의 나머지 구하기 코드
using namespace std;
int recurMod (long long a, int n, int m); //재귀함수

int main(){
	int a, n, m;
	long long result; //총 결과값을 저장할 변수
	cin >> a >> n >> m;

	result = recurMod(a,n, m);

	cout << result;
	return 0;
}

int recurMod (long long a, int n, int m){
	if( n==0 ) return 1; //탈출조건
	else if( n%2 == 0) { //지수가 2의 배수일 경우
		long long temp = recurMod(a, n/2, m); //반으로 나누어서 계산한다
		return temp*temp % m; //m으로 나머지를 구하는 것 까지 진행해준다.
	}
	else
		return a*recurMod(a, n-1, m) % m; //지수가 홀수일 경우, a를 한개 빼서 따로 곱해준다.
}



