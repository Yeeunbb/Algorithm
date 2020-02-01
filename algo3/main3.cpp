#include <iostream>
#include <iomanip>

using namespace std;

struct People{ //손님의 정보를 저장할 구조체
	int Arrive_time; //도착 시간 정보
	int Consult_time; //검사 시간 정보
	int Real_Arrive; //실제로 도착한 시간 정보
	int End_Time; //검사가 끝나는 시간 정보
};

void arrayToHeap(People arr[], int n); //배열을 힙으로 만드는 함수
void rebuildHeap(People arr[], int root, int n); //최소힙으로 만드는 함수

int main(){
	int k, n; //심사대 수 :k, 승객 수 :n
	float result = 0;
	int waiting_time=0; //총 기다린 시간
	cin >> k >> n;
	People* Airport = new People[k]; //심사대 수 만큼 구조체 배열 생성
	People* customer = new People[n]; //사람 수 만큼 구조체 배열 생성

	for(int i=0; i<n; i++){ //손님 정보
		cin >> customer[i].Arrive_time >> customer[i].Consult_time;
		customer[i].Real_Arrive = 0;
		customer[i].End_Time = 0;
		if(i!=0){ //진짜 도착한 시간은 앞사람이 진짜 도착한 시간 + 내가 온 시간
			customer[i].Real_Arrive = customer[i-1].Real_Arrive + customer[i].Arrive_time;
		}
	}

	for(int i=0; i<k; i++){ //심사대 수만큼 먼저 온 사람들 집어 넣기.
		Airport[i] = customer[i];
		Airport[i].End_Time = Airport[i].Real_Arrive + Airport[i].Consult_time;
	}//심사가 끝나는 시간은 진짜 도착한 시간 + 검사하는 시간

	arrayToHeap(Airport, k); //심사대 배열을 힙으로 만들 기

	for(int i=k; i<n; i++){ //Airport 힙의 root에 나머지 손님들 넣기
		if(Airport[0].End_Time - customer[i].Real_Arrive>=0){
			waiting_time += Airport[0].End_Time - customer[i].Real_Arrive;
			customer[i].End_Time += Airport[0].End_Time + customer[i].Consult_time;
		}
		else{ //기다리는 시간이 없을 경우
			customer[i].End_Time = customer[i].Real_Arrive + customer[i].Consult_time;
		}
		Airport[0] = customer[i]; //root 대체
		arrayToHeap(Airport, k); //최솟값이 root에 오도록 다시 정렬
	}


	result = (float)waiting_time / n;
	cout << fixed << setprecision(1) << result << endl;

	return 0;
}

void arrayToHeap(People arr[], int n){ //배열을 힙으로 만드는 함수
	for(int root = n/2 -1; root >= 0; root--){
		rebuildHeap(arr, root, n);
	}
/* 힙을 다시 배열로 만드는 코드
	int heap_size = n;
	for(int last = n-1; last > 0; last--){
		int temp = arr[0];
		arr[0] = arr[last];
		arr[last] = temp;
		heap_size--;
		rebuildHeap(arr, 0, heap_size);
	} */
}

void rebuildHeap(People arr[], int root, int n){ //root가 최솟값이 되도록 만드는 rebuildHeap
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

