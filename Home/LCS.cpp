#include <iostream>
#include <algorithm>

using namespace std;

int dp[1001][1001];

int main(){
	string str1;
	string str2;
	int result = 0;

	cin>>str1;
	cin>>str2;

	for(int i=1; i<=str1.length(); i++){
		for(int j=1; j<=str2.length(); j++){
			if(str1[i-1] == str2[j-1])
				dp[i][j] = dp[i-1][j-1] + 1;
			else
				dp[i][j] = max(dp[i][j-1], dp[i-1][j]);

			if(result < dp[i][j])
				result = dp[i][j];
		}
	}

	cout << result;

	return 0;
}
