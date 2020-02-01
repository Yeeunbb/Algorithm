#include <iostream>

using namespace std;

void quickSort(int a[], int first, int last);

int main(){

	int n;
	int count = 0;
	int max = 0;
	int value = 0;

	cin >> n;
	int* a = new int[n];

	for(int i=0; i<n; i++){ //n만큼 수 입력 받음
		cin >> a[i];
	}

	quickSort(a, 0, n-1); //퀵정렬

	int now = a[0];
	for(int i=0; i<n; i++){
		if(now == a[i]){ //같은 숫자가 나타날 때 마다
			count++; //카운트 증가
			if(max<=count){ //가장 많이 나타나는 수의 횟수 초기화
				max = count;
				value = now; //가장많이 나타나는 수는 value
			}
		}
		else{ //같은 수가 아닐 때
			count = 0; //카운트 초기화
			now = a[i]; //now 초기화
			count++;
		}
	}

	cout << value << " " << max;

	return 0;
}

void quickSort(int a[], int first, int last) { //퀵정렬
	int temp;
	if(first < last){
		int left = first+1, right = last;
		int pivot = a[first]; //피봇을 배열의 첫번째로 두는 퀵정렬
		while(left <= right){
			while(left <= last && a[left] < pivot)
				left++; //left의 값이 피봇보다 작으면, left 포인트 증가
			while(right >= first + 1 && a[right] >= pivot)
				right--; //right의 값이 피봇보다 같거나 크면, right 포인트 감소
			if(left <= right){ //left 포인트가 right 포인트를 지나치지 않았을 때
				temp = a[left]; //left포인트 위치의 값과 right 포인트 위치의 값 swap
				a[left] = a[right];
				a[right] = temp;
				left++;
				right--;
			}
		}
		temp = a[first]; //피봇 초기화
		a[first] = a[right];
		a[right] = temp;
		quickSort(a, first, right-1);
		quickSort(a, right+1, last);
	}
}
