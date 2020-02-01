#include <iostream>

using namespace std;

int brr[1000000]; //병합정렬 때, 정렬된 값을 저장할 배열

void merge(int arr[], int first, int last);
void mergeSort(int arr[], int first, int last);
int FindIntersection(int A[], int n);


int main(){
	int an, bn;
	cin >> an >> bn;
	int cn = an + bn;
	int* A = new int[an]; //A배열
	int* B = new int[bn]; //B배열
	int* C = new int[cn]; //정렬된 A와 B의 값을 저장할 배열 C
	int result = 0; //교집합의 원소 개수

	for(int i=0; i<an; i++){ //A배열 입력
		cin >> A[i];
	}

	for(int i=0; i<bn; i++){ //B배열 입력
		cin >> B[i];
	}

	mergeSort(A, 0, an-1); //A 병합정렬
	mergeSort(B, 0, bn-1); //B 병합정렬

	for(int k=0; k<an; k++){ //배열 C에 A값 저장
		C[k] = A[k];
	}
	for(int k=0; k<bn; k++){ //배열 C에 B값 저장
		C[k+an] = B[k];
	}

	mergeSort(C, 0, cn-1); //C 병합정렬
	result= FindIntersection(C, cn); //교집합의 원소개수를 구하는 함수
	cout << result;

	delete[] A;
	delete[] B;
	delete[] C;
	return 0;
}

void mergeSort(int arr[], int left, int right) { //병합정렬함수
	if(left < right) {
		int mid = (left + right)/2; //배열의 중간
		mergeSort(arr, left, mid); // 처음~중간 부분 sort
		mergeSort(arr, mid+1, right); //중간~끝 부분 sort
		merge(arr, left, right); //처음~끝 sort
	}
}

void merge(int arr[], int left, int right) { //병합정렬
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

	if(j > right){ //왼쪽에 값이 남았을 때
		for(; i<=mid; i++){
			brr[k] = arr[i];
			k++;
		}
	}
	else{ //오른쪽에 값이 남았을 때
		for(; j<=right; j++){
			brr[k] = arr[j];
			k++;
		}
	}

	for(int i=left; i<=right; i++){ //배열 초기화
		arr[i] = brr[i];
	}
}

int FindIntersection(int A[], int n){ //교집합을 찾는 함수
	int result=0;

	for(int i=0; i<n-1; i++){
		if(A[i] == A[i+1]) result++; //같은 값이 들어있을 때, result값 증가
	}

	return result;
}
