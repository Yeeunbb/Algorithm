//n k �� �Է¹޴� ���
#include <iostream>

using namespace std;

int cost[100001]; //���� ��� ���
int weight[100001]; //���(����ġ)

int main(){

	int n, k;

	cin >> n >> k;

	int* stair = new int[k];
	for(int i=0; i<k; i++){ //���� �� �ִ� ���
		cin >> stair[i];
	}

	weight[0] = 0; //0��° ����� ����� ����
	for(int i=1; i<=n; i++){ //�� ��� �� ��� �Է�
		cin >> weight[i];
	}

	for(int i=0; i<k; i++){ //���� �� �ִ� ����� ���, �� ��ġ�� ��� �Է�
		cost[stair[i]] = weight[stair[i]];
	}

	for(int i=1; i<=n; i++){ //ù ��° ��ܺ��� Ȯ��
		if(cost[i]==0) //���� ���� �����Ǿ� ���� ���� ���
		{
			int Min = 999999999; //�׳� ū �� ����
			for(int j=0; j < k ; j++)
			{//���� ���ִ� �����, ���� �� �ִ� ����� ũ�⺸�� ũ��, ���� ��ġ�� ���� ���� ���ִ� ����� ����� 0�� �ƴ� ���
				if(i-stair[j] > 0 && cost[i-stair[j]] > 0)
				{//���� ��ġ�� ���� ���� ���ִ� ����� ����� �ּڰ����� ���� ���, �ּڰ� �ʱ�ȭ
					if(cost[i-stair[j]] < Min)
					{ //Min ����
						Min = cost[i-stair[j]];
					}
				}
			}
			if(Min != 999999999)
				cost[i] = Min + weight[i];
		}
	}

	if(cost[n]==0){ //���� 0�̶�°�, ���� ���� ����� �ǹ�
		cout<< -1 << endl;;
	}
	else{
		cout<< cost[n] <<endl;
	}

	delete[] stair;
	return 0;
}

