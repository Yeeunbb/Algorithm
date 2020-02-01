#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <map>
//����ö ���
using namespace std;

struct Metro{ //���� ������ ����ü
   string station;
   int index;
};

int m, l, staionIndex; //�� ���� ���� m, ���� ȣ�� l, ���� �ε����� ������ staionIndex
int visited[10000]; //���� �湮�ߴ��� ǥ���� visited�迭
string s1, s2, start, last; //������ ���踦 �Է¹����� ����� s1, s2, ���ۿ��� ������ start, last
vector<vector<Metro>> metro; //��������Ʈ�� ��Ÿ�� ����ö �� ����
map<string, int> maap; //���� �ε����� �����ϱ����� map���
queue<int> que; //bfs�Լ��� ����� ť
int trace[10000]; //��θ� ������ �迭
int reverT[1000]; //trace�� ��ΰ� �������� ����Ǿ������Ƿ�, �ٽ� ������ ������ �迭
int lastStation; //���������� �ε���

void bfs(int m); //�ʺ�켱Ž��

int main(){

   cin >> m;
   metro.resize(m*2); //���� �� ��� �Էµ��� �𸣹Ƿ� ���Ƿ� ������ ����

   for(int i=0; i<m; i++){
      cin >> l >> s1 >> s2;
      Metro S1, S2;
      if(maap.find(s1) == maap.end()){ //ó������ ���� ���̸� �� ���
         S1.station = s1; //���̸� ����
         S1.index = staionIndex; //���� �ε��� ����
         maap.insert(make_pair(s1, staionIndex)); //map�� ���� �̸��� �ε����� ����
         staionIndex++; //�ε��� ����
      }
      else{ //�̹� �����ϴ� ���� ���,
         S1.station = s1; //���̸� ����
         S1.index = maap.find(s1)->second; //���� �ε��� ����
      }

      if(maap.find(s2) == maap.end()){ //ó������ ���� ���̸� �� ���
         S2.station = s2;
         S2.index = staionIndex;
         maap.insert(make_pair(s2, staionIndex));
         staionIndex++;
      }
      else{ //�̹� �����ϴ� ���� ���
         S2.station = s2;
         S2.index = maap.find(s2)->second;
      }

      metro[S1.index].push_back(S2); //�� ������ ���踦 ����
      metro[S2.index].push_back(S1);
   }

   cin >> start >> last; //��߿��� ������ �Է¹���

   lastStation = maap.find(last)->second; //�������� �ε��� ����

   bfs(maap.find(start)->second); //���ۿ� �ε����� ������ �ʺ�켱Ž�� ����

   if(visited[lastStation] == 0){ //�����ؾ��� ���� �湮���� ���� ���
      cout << "-1";
   }
   else{//�����ؾ��� ���� �湮�Ѱ��
   cout << visited[maap.find(last)->second] << endl; //������ ���µ� �湮�� ������ ���� ���

   int w=0;
   int tmp = lastStation;
   while(tmp != -1){ //�湮�� ��� ������ �ٽ� ����
      reverT[w] = trace[tmp];
      tmp = trace[tmp];
      w++;
   }

   map<string, int>::iterator iterr;
   for(int i=w-2; i>=0; i--){ //���� ��θ� ����ϱ� ���ؼ�
      for(iterr=maap.begin(); iterr!=maap.end(); iterr++){
         if(reverT[i] == iterr->second){
            cout << iterr->first << " ";
         }
      }
   }
   cout << last; //�������� ���
   }

   return 0;
}

void bfs(int m){ //�ʺ�켱Ž��
   visited[m] = 1; //�湮�� �� ���
   que.push(m); //���� ����� �ٸ� ���� Ž���ϱ� ���� ť�� ����
   trace[m] = -1; //���ۿ��� ��ΰ� �����Ƿ� -1�� ����

   while(!que.empty()){
      int x = que.front();
      que.pop();

      for(int i=0; i<metro[x].size(); i++){
         int y = metro[x][i].index; //���� ���� �ε����� y�� ����
         if(visited[y] == 0){ //���� �湮���� ���� ���� ��쿡
            que.push(y); //ť�� Ž���ϱ����� ����
            visited[y] = visited[x] + 1; //y���� ���µ� �湮�� ���� ������, ������� �湮�� ���ǰ���+1
            trace[y] = x; //������ �湮�� �� ����. ��θ� �� �� �ֱ� ����
         }
      }
   }
}
