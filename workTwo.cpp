#include <iostream>
//�ŵ������� ������ ���ϱ� �ڵ�
using namespace std;
int recurMod (long long a, int n, int m); //����Լ�

int main(){
	int a, n, m;
	long long result; //�� ������� ������ ����
	cin >> a >> n >> m;

	result = recurMod(a,n, m);

	cout << result;
	return 0;
}

int recurMod (long long a, int n, int m){
	if( n==0 ) return 1; //Ż������
	else if( n%2 == 0) { //������ 2�� ����� ���
		long long temp = recurMod(a, n/2, m); //������ ����� ����Ѵ�
		return temp*temp % m; //m���� �������� ���ϴ� �� ���� �������ش�.
	}
	else
		return a*recurMod(a, n-1, m) % m; //������ Ȧ���� ���, a�� �Ѱ� ���� ���� �����ش�.
}



