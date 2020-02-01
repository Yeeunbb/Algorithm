#include <iostream>
#include <algorithm>

using namespace std;

int arr[1001][1001];
int dp[1001][10001];

int main(){

	int n, m;
	cin >> n >> m;
	for(int i=1; i<=n; i++){
		for(int j=1; j<=m; j++){
			cin >> arr[i][j];
			if(i==1){
				dp[i][j] = arr[i][j] + dp[i][j-1];
			}
			else if(j==1){
				dp[i][j] = arr[i][j] + dp[i-1][j];
			}
			else{
				dp[i][j] = arr[i][j] + max((max(dp[i-1][j],dp[i][j-1])),dp[i-1][j-1]);
			}
		}
	}


	cout << dp[n][m];


	return 0;
}

