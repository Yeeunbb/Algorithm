#include <iostream>

using namespace std;

int brr[1000000]; //�������� ��, ���ĵ� ���� ������ �迭

void merge(int arr[], int first, int last);
void mergeSort(int arr[], int first, int last);
int FindIntersection(int A[], int n);


int main(){
	int an, bn;
	cin >> an >> bn;
	int cn = an + bn;
	int* A = new int[an]; //A�迭
	int* B = new int[bn]; //B�迭
	int* C = new int[cn]; //���ĵ� A�� B�� ���� ������ �迭 C
	int result = 0; //�������� ���� ����

	for(int i=0; i<an; i++){ //A�迭 �Է�
		cin >> A[i];
	}

	for(int i=0; i<bn; i++){ //B�迭 �Է�
		cin >> B[i];
	}

	mergeSort(A, 0, an-1); //A ��������
	mergeSort(B, 0, bn-1); //B ��������

	for(int k=0; k<an; k++){ //�迭 C�� A�� ����
		C[k] = A[k];
	}
	for(int k=0; k<bn; k++){ //�迭 C�� B�� ����
		C[k+an] = B[k];
	}

	mergeSort(C, 0, cn-1); //C ��������
	result= FindIntersection(C, cn); //�������� ���Ұ����� ���ϴ� �Լ�
	cout << result;

	delete[] A;
	delete[] B;
	delete[] C;
	return 0;
}

void mergeSort(int arr[], int left, int right) { //���������Լ�
	if(left < right) {
		int mid = (left + right)/2; //�迭�� �߰�
		mergeSort(arr, left, mid); // ó��~�߰� �κ� sort
		mergeSort(arr, mid+1, right); //�߰�~�� �κ� sort
		merge(arr, left, right); //ó��~�� sort
	}
}

void merge(int arr[], int left, int right) { //��������
	int mid = (left + right) /2;
	int i=left, j=mid+1, k=left;

	while(i <= mid && j <= right){
		if(arr[i] <= arr[j]){
			brr[k] = arr[i];
			k++;
			i++;
		}

		else{
			brr[k] = arr[j];
			k++;
			j++;
		}
	}

	if(j > right){ //���ʿ� ���� ������ ��
		for(; i<=mid; i++){
			brr[k] = arr[i];
			k++;
		}
	}
	else{ //�����ʿ� ���� ������ ��
		for(; j<=right; j++){
			brr[k] = arr[j];
			k++;
		}
	}

	for(int i=left; i<=right; i++){ //�迭 �ʱ�ȭ
		arr[i] = brr[i];
	}
}

int FindIntersection(int A[], int n){ //�������� ã�� �Լ�
	int result=0;

	for(int i=0; i<n-1; i++){
		if(A[i] == A[i+1]) result++; //���� ���� ������� ��, result�� ����
	}

	return result;
}
