#include <iostream>
#include <utility>
#include <vector>
#include <queue>

#define SIZE 100

using namespace std;

struct cmp{
  bool operator()(pair<int, int> a, pair<int, int> b) {
    // default less - Max heap

    // Min heap (grater)
    //return a.second > b.second;

    // Max heap (less)
    return a.second < b.second;
  }
};
// pair<node, cost>
int number = 6;
int INF = 10000;

// 거리 작은순으로 구성되어있는 큐
priority_queue <pair<int, int>, vector<pair<int, int>>, cmp> pq;
int dist[SIZE];
vector<pair<int, int>> graph[SIZE];

void Dijkstra (int Start) {
  // 1. INF initialize
  for (int i = 1; i <= number; i++) {
    dist[i] = INF;
  }

  pq.push({Start, 0});
  // 2. 시작점 0 초기화
  dist[Start] = 0;
  // 정점 - 정점 {정점, 거리} 우선순위큐에 넣는다.
  while (pq.size()) {
    int now_node = pq.top().first;
    int now_cost = pq.top().second;
    pq.pop();
    // 3. dist[vertex] 보다 작으면 skip
    if (dist[now_node] < now_cost) continue;
    // now에 인접한 모든 간선 search
    for (int i = 0; i < graph[now_node].size(); i++) {
      int next_node = graph[now_node][i].first;
      int new_cost = now_cost+graph[now_node][i].second;  // cost+cost
        // 4. next_node dist를 update, 더 작은 값으로
        if (dist[next_node] > new_cost) {
          dist[next_node] = new_cost;
          pq.push({next_node, new_cost});
        }
    }
  }
}

int main(void) {
  graph[1].push_back(make_pair(2, 2));  // node, cost
  graph[1].push_back(make_pair(3, 5));
  graph[1].push_back(make_pair(4, 1));

  graph[2].push_back(make_pair(1, 2));
  graph[2].push_back(make_pair(3, 3));
  graph[2].push_back(make_pair(4, 2));

  graph[3].push_back(make_pair(1, 5));
  graph[3].push_back(make_pair(2, 3));
  graph[3].push_back(make_pair(4, 3));
  graph[3].push_back(make_pair(5, 1));
  graph[3].push_back(make_pair(6, 5));

  graph[4].push_back(make_pair(1, 1));
  graph[4].push_back(make_pair(2, 4));
  graph[4].push_back(make_pair(3, 3));
  graph[4].push_back(make_pair(5, 1));

  graph[5].push_back(make_pair(3, 1));
  graph[5].push_back(make_pair(4, 1));
  graph[5].push_back(make_pair(6, 2));

  graph[6].push_back(make_pair(3, 5));
  graph[6].push_back(make_pair(5, 2));

  Dijkstra(1);
  for (int i=1; i<= number; i++) {
      cout << "dist[" << i << "] = " << dist[i] << endl;
  }

  return 0;
}
