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

	for(int i=0; i<n; i++){ //n��ŭ �� �Է� ����
		cin >> a[i];
	}

	quickSort(a, 0, n-1); //������

	int now = a[0];
	for(int i=0; i<n; i++){
		if(now == a[i]){ //���� ���ڰ� ��Ÿ�� �� ����
			count++; //ī��Ʈ ����
			if(max<=count){ //���� ���� ��Ÿ���� ���� Ƚ�� �ʱ�ȭ
				max = count;
				value = now; //���帹�� ��Ÿ���� ���� value
			}
		}
		else{ //���� ���� �ƴ� ��
			count = 0; //ī��Ʈ �ʱ�ȭ
			now = a[i]; //now �ʱ�ȭ
			count++;
		}
	}

	cout << value << " " << max;

	return 0;
}

void quickSort(int a[], int first, int last) { //������
	int temp;
	if(first < last){
		int left = first+1, right = last;
		int pivot = a[first]; //�Ǻ��� �迭�� ù��°�� �δ� ������
		while(left <= right){
			while(left <= last && a[left] < pivot)
				left++; //left�� ���� �Ǻ����� ������, left ����Ʈ ����
			while(right >= first + 1 && a[right] >= pivot)
				right--; //right�� ���� �Ǻ����� ���ų� ũ��, right ����Ʈ ����
			if(left <= right){ //left ����Ʈ�� right ����Ʈ�� ����ġ�� �ʾ��� ��
				temp = a[left]; //left����Ʈ ��ġ�� ���� right ����Ʈ ��ġ�� �� swap
				a[left] = a[right];
				a[right] = temp;
				left++;
				right--;
			}
		}
		temp = a[first]; //�Ǻ� �ʱ�ȭ
		a[first] = a[right];
		a[right] = temp;
		quickSort(a, first, right-1);
		quickSort(a, right+1, last);
	}
}
