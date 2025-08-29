#include <iostream>
#include <vector>
#include <deque>

using namespace std;

#define MAX 100

deque<int> dq;
bool visited[MAX];
vector<int> graph[MAX];

void dfs (int start) {
  dq.push_back(start);
  visited[start] = true;
  cout << start << " ";

  while(!dq.empty()) {
    int src = dq.back();
    dq.pop_back();
    for (int i = 0; i < graph[src].size(); i ++) {
      int dest = graph[src][i];
      if (!visited[dest]) {
        visited[dest] = true;
        cout << dest << " ";
        dq.push_back(src);
        dq.push_back(dest);
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
}
