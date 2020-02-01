#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <map>
//지하철 경로
using namespace std;

struct Metro{ //역을 저장할 구조체
   string station;
   int index;
};

int m, l, staionIndex; //역 쌍의 개수 m, 역의 호선 l, 역을 인덱스로 저장할 staionIndex
int visited[10000]; //역에 방문했는지 표시할 visited배열
string s1, s2, start, last; //역간의 관계를 입력받을때 사용할 s1, s2, 시작역과 도착역 start, last
vector<vector<Metro>> metro; //인접리스트로 나타낼 지하철 역 벡터
map<string, int> maap; //역을 인덱스로 저장하기위해 map사용
queue<int> que; //bfs함수에 사용할 큐
int trace[10000]; //경로를 저장할 배열
int reverT[1000]; //trace에 경로가 역순으로 저장되어있으므로, 다시 역으로 저장할 배열
int lastStation; //마지막역의 인덱스

void bfs(int m); //너비우선탐색

int main(){

   cin >> m;
   metro.resize(m*2); //역이 총 몇개가 입력될지 모르므로 임의로 사이즈 조정

   for(int i=0; i<m; i++){
      cin >> l >> s1 >> s2;
      Metro S1, S2;
      if(maap.find(s1) == maap.end()){ //처음으로 나온 역이름 일 경우
         S1.station = s1; //역이름 저장
         S1.index = staionIndex; //역의 인덱스 저장
         maap.insert(make_pair(s1, staionIndex)); //map에 역의 이름과 인덱스를 저장
         staionIndex++; //인덱스 증가
      }
      else{ //이미 존재하는 역일 경우,
         S1.station = s1; //역이름 저장
         S1.index = maap.find(s1)->second; //역의 인덱스 저장
      }

      if(maap.find(s2) == maap.end()){ //처음으로 나온 역이름 일 경우
         S2.station = s2;
         S2.index = staionIndex;
         maap.insert(make_pair(s2, staionIndex));
         staionIndex++;
      }
      else{ //이미 존재하는 역일 경우
         S2.station = s2;
         S2.index = maap.find(s2)->second;
      }

      metro[S1.index].push_back(S2); //역 사이의 관계를 저장
      metro[S2.index].push_back(S1);
   }

   cin >> start >> last; //출발역과 도착역 입력받음

   lastStation = maap.find(last)->second; //마지막역 인덱스 저장

   bfs(maap.find(start)->second); //시작역 인덱스를 가지고 너비우선탐색 시작

   if(visited[lastStation] == 0){ //도착해야할 역에 방문하지 못한 경우
      cout << "-1";
   }
   else{//도착해야할 역에 방문한경우
   cout << visited[maap.find(last)->second] << endl; //역까지 가는데 방문한 역들의 갯수 출력

   int w=0;
   int tmp = lastStation;
   while(tmp != -1){ //방문한 경로 역으로 다시 저장
      reverT[w] = trace[tmp];
      tmp = trace[tmp];
      w++;
   }

   map<string, int>::iterator iterr;
   for(int i=w-2; i>=0; i--){ //역의 경로를 출력하기 위해서
      for(iterr=maap.begin(); iterr!=maap.end(); iterr++){
         if(reverT[i] == iterr->second){
            cout << iterr->first << " ";
         }
      }
   }
   cout << last; //도착역도 출력
   }

   return 0;
}

void bfs(int m){ //너비우선탐색
   visited[m] = 1; //방문한 역 출력
   que.push(m); //역과 연결된 다른 역들 탐색하기 위해 큐에 저장
   trace[m] = -1; //시작역은 경로가 없으므로 -1로 지정

   while(!que.empty()){
      int x = que.front();
      que.pop();

      for(int i=0; i<metro[x].size(); i++){
         int y = metro[x][i].index; //다음 역의 인덱스를 y에 저장
         if(visited[y] == 0){ //아직 방문하지 않은 역일 경우에
            que.push(y); //큐에 탐색하기위해 저장
            visited[y] = visited[x] + 1; //y까지 오는데 방문한 역의 갯수는, 현재까지 방문한 역의갯수+1
            trace[y] = x; //이전에 방문한 역 저장. 경로를 알 수 있기 위해
         }
      }
   }
}
