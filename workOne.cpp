#include <iostream>
//�ֽ��ڵ�
using namespace std;

struct V_storage{ //�ֽ��� �갪, �ǰ�, ������ �ִ밡 �Ǵ� ��, �ּҰ� �Ǵ� ���� �����ϴ� ����ü
	int firstV, lastV;
	int MIN, MAX;
};

V_storage Devide(int a[], int first, int last); //���Ұ� ����

int main() {
	int n; //�Է¹��� ��¥
	int R_first, R_last; //�ֽ��� �� ��, �ֽ��� �� ��

	cin >> n;
	int* arr = new int[n]; //n��ŭ �ֽ� ���� �Է¹��� �迭
	V_storage result; //������� ������ ����ü

	for(int i=0; i<n; i++){ //�ֽ� �� ����
		cin >> arr[i];
	}

	result = Devide(arr, 0, n-1);

	if(result.lastV - result.firstV == 0){
		cout<< "0"; //�̵��� 0�� ���, 0�� ���
	}

	else{ //�̵��� �����ϴ� ���
		R_first = result.firstV;
		R_last = result.lastV;
		cout << R_first << " "<< R_last << " "<< result.lastV - result.firstV << endl;
	}


	delete[] arr;
	return 0;
}

V_storage Devide(int a[], int first, int last){ //���Ұ������� ���� �̵��� ���ϴ� �Լ�
	V_storage left; //���� �κ��� ���� ������ ����ü
	V_storage right; //������ �κ��� ���� ������ ����ü
	V_storage r; //�̵��� ū ���� ������ ����ü = ���������� return�� ����ü
	int vL, vR, vM; //�̵��� �ӽ÷� ������ �� ������.
	int mid; //�迭�� �߰���ġ�� ������ ����

	mid = (first+last) / 2;

	if(first == last) { //Ż������. ���� �迭�� ���
		r.MAX = a[first]; //�ִ밡�Ǵ�
		r.MIN = a[first]; //�ּҰ� �Ǵ�
		r.firstV = a[first]; //�곯¥
		r.lastV = a[last]; //�ǳ�¥�� ��� �����Ƿ� �� ���� first�ε����� ������ �迭��
		return r;
	}

	else{ //�迭�� 2�� �̻��϶�,
		left = Devide(a, first, mid); //first���� mid���� ���� Ȯ��
		right = Devide(a, mid+1, last); //mid+1���� last���� ���� Ȯ��
		//������� �ֽ��� ���� �ִ��϶���, �ּ��϶��� ����.

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
		//vL, vR, vM�� left, right, mid �� ���������� �ִ��̵��� �����Ѵ�.
		vL = left.lastV - left.firstV;
		vR = right.lastV - right.firstV;
		vM = right.MAX - left.MIN;
		//�������, ���������� ������ r�� ���Ѵ�.
		if(vL>vR){ //left���� ���� �̵��� right���� ���� ������ Ŭ ��
			if(vL>vM){ //left���� ���� �̵��� ���� ū ���
				r.firstV = left.firstV;
				r.lastV = left.lastV;
			}
			else if(vL == vM){ //�̵��� �������
				if(left.firstV < left.MIN){ //�ֽ��� ���� ��, �ֽ� ���� �� ���� ��츦 ������ ���Ѵ�.
					r.firstV = left.firstV;
					r.lastV = left.lastV;
				}
				else{
					r.firstV = left.MIN;
					r.lastV = right.MAX;
				}
			}
			else{ // left�� �ּҿ� right�� �ִ밪�� ���� ���� ū �ִ������� ���
				r.firstV = left.MIN;
				r.lastV = right.MAX;
			}
		}

		else if(vL == vR){
			if(vM > vL){ // left�� �ּҿ� right�� �ִ밪�� ���� ���� ū �ִ������� ���
				r.firstV = left.MIN;
				r.lastV = right.MAX;
			}
			else if(vM == vL){ //�� �������� ���� �ִ��̵��� �� ���� ���
				if(left.firstV < right.firstV){ //�ֽ��� �� ���� �ֽ� ���� ���� ���� ��츦 ������ ���Ѵ�.
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
