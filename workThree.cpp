/*#include <iostream>

using namespace std;

int* csort(int c[], int n, int m); //�迭���� �� ĭ �� �о��ִ� �Լ�

int main(){
	int n, m; //n�� �Է¹��� ������ ��, m�� �� ������ ��
	cin >> n;

	int* arr = new int[n]; //R�� ���ڿ��� ������ �迭
	int* brr = new int[n]; //S�� ���ڿ��� ������ �迭
	int* crr = new int[n]; //1���� n������ ���� ������ �迭

	for(int i=0; i<n; i++){
		cin >> arr[i]; //arr�迭�� �� ����
		crr[i] = i+1; //crr�迭�� 1~n���� �� ����(����������)
	}

	for(int i=n-1; i>=0; i--){ //brr�� ã��
		m = arr[i];
		brr[i] = crr[m]; //brr�� ���� arr�� ����ŭ�� index�� ������ crr�� ��
		if(m >= brr[i]){ //S������ ������� ���ʴ� ���
			brr[n-1] = -1;
		}
		crr = csort(crr, n, m); //crr ���� ����
	}

	if(brr[n-1] == -1){
		cout << "-1"; //crr�� ��������� �ʴ� ���
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

	for(int i=m; i<n; i++){ //crr�� ���� �̾Ƽ� ���. �����κк��� �� ���� �����ֱ�
		c[i] = c[i+1];
	}
	return c;
}
*/
