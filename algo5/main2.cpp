#include <iostream>

using namespace std;

char Ameba[101][101]; //�Ƹ޹� �迭
int visited[101][101]; //�湮�� �ȼ����� Ȯ���� �迭
int count; //�ȼ��� ���� ����

void dfs(int i, int j, int m, int n); //���̿켱 Ž�� �Լ�

int main(){

	int M, N, max=0, AmebaN = 0;;
	cin >> M >> N;

	for(int i=0; i<M; i++){ //�Ƹ޹� ���� �Է¹���
		for(int j=0; j<N; j++){
			cin >> Ameba[i][j];
		}
	}

	for(int i=0; i<M; i++){
		for(int j=0; j<N; j++){
			if(Ameba[i][j] == '1' && visited[i][j] != 1){ //���� �Ƹ޹ٰ� �����ϴ� �ȼ��̰�, �湮���� �ʾҴٸ�
				dfs(i, j, M, N); //dfs�Լ� ����
				AmebaN++; //�Ƹ޹��� ���� ī��Ʈ
			}
			if(count > max){ //�ȼ��� ���� ���� ���� �Ƹ޹��� �ȼ� �� ī��Ʈ
				max = count;
			}
			count = 0;
		}
	}

	cout << AmebaN << " " << max;


	return 0;
}

void dfs(int i, int j, int m, int n){

	if(visited[i][j] != 1){ //���� �湮���� �ʾҴٸ�
		visited[i][j] = 1; //�湮���� �ٲپ��ְ�
		count++; //�ȼ��� ���� ����
	}

	if(Ameba[i][j+1] == '1' && visited[i][j+1] != 1 && j+1 < n) //���� �ȼ��� ������ĭ
		dfs(i, j+1, m, n);
	if(Ameba[i+1][j+1] == '1' && visited[i+1][j+1] != 1 && i+1 < m && j+1 < n) //���� �ȼ��� �밢�� ������ �Ʒ�
		dfs(i+1, j+1, m, n);
	if(Ameba[i+1][j] == '1' && visited[i+1][j] != 1 && i+1 < m) //���� �ȼ��� �ٷ� �Ʒ�
		dfs(i+1, j, m, n);
	if(Ameba[i+1][j-1] == '1' && visited[i+1][j-1] != 1 && i+1 < m && j-1 >= 0) //���� �ȼ��� ���� �밢�� �Ʒ�
		dfs(i+1, j-1, m, n);
	if(Ameba[i][j-1] == '1' && visited[i][j-1] != 1 && j-1 >= 0) //���� �ȼ��� ����ĭ
		dfs(i, j-1, m, n);
	if(Ameba[i-1][j-1] == '1' && visited[i-1][j-1] != 1 && i-1 >=0 && j-1 >=0) //���� �ȼ��� ���� �밢�� ��
		dfs(i-1, j-1, m, n);
	if(Ameba[i-1][j] == '1' && visited[i-1][j] != 1 && i-1 >= 0) //���� �ȼ��� �ٷ� ��
		dfs(i-1, j, m, n);
	if(Ameba[i-1][j+1] == '1' && visited[i-1][j+1] != 1 && i-1 >= 0 && j+1 < n) //���� �ȼ��� ������ �밢�� ��
		dfs(i-1, j+1, m, n);
}
