#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <math.h>

using namespace std;

vector<vector<int>> friends; //ģ������ ������ ������ ���� ����Ʈ
int visited[2001]; //�湮�� ������� Ȯ���� visited �迭
void dfs(int n); //���̿켱 Ž�� �Լ�
double COUNTN; //������� �� ����

int main(){
	int n, m, v1, v2;
	double sum=0, fn=0;

	cin >> n >> m;

	vector<double> set; //�� ���տ� �����ϴ� ������� ������ ����

	friends.resize(n); //ģ�� �� ����

	for(int i=0; i<m; i++){
		cin >> v1 >> v2;
		friends[v1].push_back(v2); //v1�� v2������ ���� �Է�
		friends[v2].push_back(v1);

	}

	for(int i=0; i<n; i++){
		COUNTN = 0; //�� ������� ī��Ʈ 0���� �ʱ�ȭ
		if(visited[i] != 1){ //���� �湮���� ���� ����� ��,
			dfs(i); //dfs�Լ� ����
			fn++; //������ �� ����
			set.push_back(COUNTN); //�� ���ܿ� ���� ��� �� ����
			sum += COUNTN; //�� �տ� ����
		}
	}

	sort(set.begin(), set.end(), greater<double>()); //���� ū ������ ����, ���� ���� ������ ���� ���ϱ� ���� ,sort ���

	cout << fn << endl;
	cout << (int)set[0] << " " << (int)set.back() << " ";

	sum /= fn;

	cout << fixed;
	cout.precision(1); //�Ҽ��� ù°�ڸ����� ���
	cout << sum;

	return 0;
}

void dfs(int n){

	if(visited[n] == 1) return; //�̹̹湮�� ����̸� return

	visited[n] = 1; //�湮�ߴٰ� üũ
	COUNTN++; //��� �� ����

	for(int i=0; i<friends[n].size(); i++){
		if(visited[friends[n][i]] != 1)
			dfs(friends[n][i]);
	}

}
