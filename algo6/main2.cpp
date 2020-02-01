#include <iostream>
#include <vector>
#include <queue>
//�̷�ã�� ����
using namespace std;

char road[104][104]; //�����ִ���,������ ���λ�Ȳ �Է¹��� �迭
int visited[104][104]; //�湮�� ������ ǥ���� �Լ�
int dir[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}}; //�����ִ� �濡�� ��,��,��,�츦 ǥ���� ��ǥ
int x, y; //���� x��, y��
int m, n; //���� ũ��
int result_x, result_y; //���� ���� ĭ�� x,y��
bool flag = false; //������ ���� �����Ѱ� ������ Ȯ���� flag

void bfs(int i, int j); //bfs�Լ� ����

int main(){
	int result=999999; //�ʱ⿡ result���� �ſ� ū ������ ����
	cin >> m >> n;

	for(int i=0; i<m; i++){
		for(int j=0; j<n; j++){ //���� ��Ȳ �Է¹���
			cin >> road[i][j];
		}
	}

	for(int i=0; i<n; i++){
		for(int k=0; k<m; k++){
			for(int j=0; j<n; j++){ //visited�Լ��� for���� �������� �ʱ�ȭ
				visited[k][j] = 0;
			}
		}
		if(road[0][i] == '1'){ //ù��° �ٿ� �ִ� �� �߿���, �� �� �ִ� ���� ��,
			flag = false;
			bfs(0, i); //�ʺ�켱 Ž��
			//ó������ ���������� ����������, �����Ҷ����� �̵��� Ƚ���� ���� Ƚ��(result��)���� �۰�, ���������� �����Ѱ��� �������
			if(result > visited[result_y][result_x] && flag){
				result = visited[result_y][result_x]; //result�� ����
			}
		}
	}

	if(result != 999999){ //�������ٿ� �ִ� ����� ���� �� ���
		cout << result;
	}
	else{ //�������� ���� ���. == ���� ���� ���
		cout << "-1";
	}

	return 0;
}


void bfs(int i, int j){ //�ʺ�켱 Ž���Լ�
queue<pair<int, int>> que; //bfs�Լ��� ����� ť
	visited[i][j] = 1; //�ش� ���� �湮�����Ƿ� visited�Լ��� 1�� ����
	que.push(pair<int, int>(i, j)); //�ش� �濡 ���ؼ� Ž���ؾ��ϹǷ� que�� ����

	while(!que.empty()){
		y = que.front().first; //��ǥ�� ����
		x = que.front().second;
		que.pop();

		if(y == m-1){ //������ �ٿ� ������ ���
			result_x = x; //�������� ����, x��ǥ�� ����
			result_y = y;
			flag = true; //flag�� true��
			return; //Ž�� ����
		}

		for(int i=0; i<4; i++){
			int next_y = y + dir[i][0]; //���� ����� ��,��,��,�츦 Ž��
			int next_x = x + dir[i][1];

			//���� Ž���ؾ� �ϴ� ��ǥ��, ������ ������ ����� �ʾҰ�, �� �� �ִ� �����̸�, �湮���� ���� ���
			if(next_y < m && next_y >= 0 && next_x < n && next_x >= 0 && visited[next_y][next_x] == 0 && road[next_y][next_x] == '1'){
				visited[next_y][next_x] = visited[y][x] + 1; //���� ���η� �ö����� �̵��� Ƚ��+1
				que.push(pair<int, int>(next_y, next_x)); //���� ���ο� ����� �ٸ� ���θ� Ž���ϱ� ���� que�� ����
			}
		}
	}
}
