#include <iostream>
//주식코드
using namespace std;

struct V_storage{ //주식을 산값, 판값, 이익이 최대가 되는 값, 최소가 되는 값을 저장하는 구조체
	int firstV, lastV;
	int MIN, MAX;
};

V_storage Devide(int a[], int first, int last); //분할과 정복

int main() {
	int n; //입력받을 날짜
	int R_first, R_last; //주식을 산 날, 주식을 판 날

	cin >> n;
	int* arr = new int[n]; //n만큼 주식 값을 입력받을 배열
	V_storage result; //결과값을 저장할 구조체

	for(int i=0; i<n; i++){ //주식 값 저장
		cin >> arr[i];
	}

	result = Devide(arr, 0, n-1);

	if(result.lastV - result.firstV == 0){
		cout<< "0"; //이득이 0인 경우, 0을 출력
	}

	else{ //이득이 존재하는 경우
		R_first = result.firstV;
		R_last = result.lastV;
		cout << R_first << " "<< R_last << " "<< result.lastV - result.firstV << endl;
	}


	delete[] arr;
	return 0;
}

V_storage Devide(int a[], int first, int last){ //분할과정복을 통해 이득을 구하는 함수
	V_storage left; //왼쪽 부분의 값을 저장할 구조체
	V_storage right; //오른쪽 부분의 값을 저장할 구조체
	V_storage r; //이득이 큰 값을 저장할 구조체 = 최종적으로 return할 구조체
	int vL, vR, vM; //이득을 임시로 저장해 놀 변수들.
	int mid; //배열의 중간위치를 저장할 변수

	mid = (first+last) / 2;

	if(first == last) { //탈출조건. 단일 배열일 경우
		r.MAX = a[first]; //최대가되는
		r.MIN = a[first]; //최소가 되는
		r.firstV = a[first]; //산날짜
		r.lastV = a[last]; //판날짜가 모두 같으므로 그 값은 first인덱스를 가지는 배열값
		return r;
	}

	else{ //배열이 2개 이상일때,
		left = Devide(a, first, mid); //first부터 mid까지 값을 확인
		right = Devide(a, mid+1, last); //mid+1부터 last까지 값을 확인
		//여기부턴 주식의 값이 최대일때와, 최소일때를 구함.

		if(left.MAX > right.MAX){
			r.MAX = left.MAX;
		}
		else{
			r.MAX = right.MAX;
		}

		if(left.MIN > right.MIN){
			r.MIN = right.MIN;
		}
		else{
			r.MIN = left.MIN;
		}
		//vL, vR, vM은 left, right, mid 각 구역에서의 최대이득을 저장한다.
		vL = left.lastV - left.firstV;
		vR = right.lastV - right.firstV;
		vM = right.MAX - left.MIN;
		//여기부턴, 최종적으로 리턴할 r을 구한다.
		if(vL>vR){ //left에서 구한 이득이 right에서 구한 값보다 클 때
			if(vL>vM){ //left에서 구한 이득이 가장 큰 경우
				r.firstV = left.firstV;
				r.lastV = left.lastV;
			}
			else if(vL == vM){ //이득이 같은경우
				if(left.firstV < left.MIN){ //주식을 샀을 때, 주식 값이 더 작은 경우를 값으로 취한다.
					r.firstV = left.firstV;
					r.lastV = left.lastV;
				}
				else{
					r.firstV = left.MIN;
					r.lastV = right.MAX;
				}
			}
			else{ // left의 최소와 right의 최대값의 차가 가장 큰 최대이익일 경우
				r.firstV = left.MIN;
				r.lastV = right.MAX;
			}
		}

		else if(vL == vR){
			if(vM > vL){ // left의 최소와 right의 최대값의 차가 가장 큰 최대이익일 경우
				r.firstV = left.MIN;
				r.lastV = right.MAX;
			}
			else if(vM == vL){ //각 구역에서 구한 최대이득이 다 같은 경우
				if(left.firstV < right.firstV){ //주식을 산 날의 주식 값이 가장 작은 경우를 값으로 취한다.
					if(left.firstV < left.MIN){
						r.firstV = left.firstV;
						r.lastV = left.lastV;
					}
					else{
						r.firstV = left.MIN;
						r.lastV = right.MAX;
					}
				}
				else{
					if(right.firstV < left.MIN){
						r.firstV = right.firstV;
						r.lastV = right.lastV;
					}
					else{
						r.firstV = left.MIN;
						r.lastV = right.MAX;
					}
				}
			}

			else{ //vL == vR >vM
				if(left.firstV < right.firstV){
					r.firstV = left.firstV;
					r.lastV = left.lastV;
				}
				else{
					r.firstV = right.firstV;
					r.lastV = right.lastV;
				}
			}
		}
		else{ //vL < vR
			if(vR > vM){
				r.firstV = right.firstV;
				r.lastV = right.lastV;
			}
			else if(vR == vM){
				if(right.firstV < left.MIN){
					r.firstV = right.firstV;
					r.lastV = right.lastV;
				}
				else{
					r.firstV = left.MIN;
					r.lastV = right.MAX;
				}
			}
			else{ // vL < vR < vM
				r.firstV = left.MIN;
				r.lastV = right.MAX;
			}
		}

		return r;
	}
}
