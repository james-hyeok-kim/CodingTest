#include <iostream>
#include <vector>
#include <deque>
#include <queue>

#define MAX 1000

using namespace std;

vector<int> graph[MAX];
bool visited[MAX];
deque<int> dq;
queue<int> q;

int dfs (int start) {
  dq.push_back(start);
  q.push(start);
  visited[start] = true;
  while (!dq.empty()) {
    int x = dq.back();
    dq.pop_back();
    for (int i = 0; i < graph[x].size(); i++) {
      int y = graph[x][i];
      if (!visited[y]) {
        dq.push_back(x);
        dq.push_back(y);
        visitied[y] = true;
        q.push(y);
        break;
      }
    }
  }
}

int main (void) {
  graph[1].push_back(2);
  graph[1].push_back(3);
  graph[1].push_back(8);

  graph[2].push_back(1);
  graph[2].push_back(7);

  graph[3].push_back(1);
  graph[3].push_back(4);
  graph[3].push_back(5);

  graph[4].push_back(3);
  graph[4].push_back(5);

  graph[5].push_back(3);
  graph[5].push_back(4);

  graph[6].push_back(7);

  graph[7].push_back(2);
  graph[7].push_back(6);
  graph[7].push_back(8);

  graph[8].push_back(1);
  graph[8].push_back(7);
  dfs(1);

  int q_size = q.size();
  cout << " q_size : " << q_size << endl;
  for (int i = 0; i < q_size; i++) {
    cout << "queue[" << i << "] = " << q.front() << endl;
    q.pop();
  }
  return 0;
}
