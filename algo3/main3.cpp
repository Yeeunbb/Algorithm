#include <iostream>
#include <iomanip>

using namespace std;

struct People{ //�մ��� ������ ������ ����ü
	int Arrive_time; //���� �ð� ����
	int Consult_time; //�˻� �ð� ����
	int Real_Arrive; //������ ������ �ð� ����
	int End_Time; //�˻簡 ������ �ð� ����
};

void arrayToHeap(People arr[], int n); //�迭�� ������ ����� �Լ�
void rebuildHeap(People arr[], int root, int n); //�ּ������� ����� �Լ�

int main(){
	int k, n; //�ɻ�� �� :k, �°� �� :n
	float result = 0;
	int waiting_time=0; //�� ��ٸ� �ð�
	cin >> k >> n;
	People* Airport = new People[k]; //�ɻ�� �� ��ŭ ����ü �迭 ����
	People* customer = new People[n]; //��� �� ��ŭ ����ü �迭 ����

	for(int i=0; i<n; i++){ //�մ� ����
		cin >> customer[i].Arrive_time >> customer[i].Consult_time;
		customer[i].Real_Arrive = 0;
		customer[i].End_Time = 0;
		if(i!=0){ //��¥ ������ �ð��� �ջ���� ��¥ ������ �ð� + ���� �� �ð�
			customer[i].Real_Arrive = customer[i-1].Real_Arrive + customer[i].Arrive_time;
		}
	}

	for(int i=0; i<k; i++){ //�ɻ�� ����ŭ ���� �� ����� ���� �ֱ�.
		Airport[i] = customer[i];
		Airport[i].End_Time = Airport[i].Real_Arrive + Airport[i].Consult_time;
	}//�ɻ簡 ������ �ð��� ��¥ ������ �ð� + �˻��ϴ� �ð�

	arrayToHeap(Airport, k); //�ɻ�� �迭�� ������ ���� ��

	for(int i=k; i<n; i++){ //Airport ���� root�� ������ �մԵ� �ֱ�
		if(Airport[0].End_Time - customer[i].Real_Arrive>=0){
			waiting_time += Airport[0].End_Time - customer[i].Real_Arrive;
			customer[i].End_Time += Airport[0].End_Time + customer[i].Consult_time;
		}
		else{ //��ٸ��� �ð��� ���� ���
			customer[i].End_Time = customer[i].Real_Arrive + customer[i].Consult_time;
		}
		Airport[0] = customer[i]; //root ��ü
		arrayToHeap(Airport, k); //�ּڰ��� root�� ������ �ٽ� ����
	}


	result = (float)waiting_time / n;
	cout << fixed << setprecision(1) << result << endl;

	return 0;
}

void arrayToHeap(People arr[], int n){ //�迭�� ������ ����� �Լ�
	for(int root = n/2 -1; root >= 0; root--){
		rebuildHeap(arr, root, n);
	}
/* ���� �ٽ� �迭�� ����� �ڵ�
	int heap_size = n;
	for(int last = n-1; last > 0; last--){
		int temp = arr[0];
		arr[0] = arr[last];
		arr[last] = temp;
		heap_size--;
		rebuildHeap(arr, 0, heap_size);
	} */
}

void rebuildHeap(People arr[], int root, int n){ //root�� �ּڰ��� �ǵ��� ����� rebuildHeap
	int smallChild;
	People x = arr[root];
	int current = root;
	while(2*current + 1 < n){
		int leftChild = 2*current + 1;
		int rightChild = leftChild + 1;

		if(rightChild < n  && (arr[rightChild].End_Time < arr[leftChild].End_Time))
			smallChild = rightChild;
		else
			smallChild = leftChild;

		if(x.End_Time > arr[smallChild].End_Time){
			arr[current] = arr[smallChild];
			current = smallChild;
		}
		else
			break;
	}
	arr[current] = x;
}

