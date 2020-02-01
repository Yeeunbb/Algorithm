#include <iostream>

using namespace std;
int min(int a, int b); //�ּڰ� ���
int min(int a, int b, int c);

int main(){

	int n;
	cin >> n; //��ܼ� �Է�
	int cost[10005]; //��ܿö󰥶� �߻��ϴ� ���
	int weight[10005]; //����ġ(�� ����� ���)

	weight[0] = 0; //0��° ��� = �ٴ� �� ����� ����
	for(int i=1; i<=n; i++){
		cin >> weight[i];
	}

	//�ʱⰪ ����
	cost[0] = 0;
	cost[1] = weight[1];
	cost[2] = weight[1] + weight[2];
	cost[3] = weight[3];

	for(int i=4; i<=n; i++){ //�����Ҵ��� �̿�
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
