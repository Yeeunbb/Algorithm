/*
#include <iostream>
#include <algorithm>

using namespace std;

int dp[1001];
int num[1001];
int result;

int main(){
	int n;

	cin >> n;

	for(int i=0; i<n; i++){
		cin >> num[i];
		int now = 0;
		for(int j=0; j<i; ++j) {
			if(num[i] > num[j])
				now = max(now, dp[j]);
		}
		dp[i] = now + 1;
		result = max(result, dp[i]);
	}

	cout << result;

	return 0;
}

*/
