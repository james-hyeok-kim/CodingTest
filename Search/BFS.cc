#include <vector>
#include <queue>
#include <map>
#include <iostream>

using namespace std;

// BFS 함수 정의
// 매개변수: 그래프(인접 리스트), 시작 노드, 노드 개수
void bfs(const map<int, vector<int>>& graph, int startNode) {
    // 1. 큐(queue)와 방문 여부를 확인할 배열을 초기화합니다.
    queue<int> q;
    // 노드 번호에 맞춰 거리를 저장하기 위해 map을 사용 (노드가 0부터 시작하지 않을 수도 있으므로)
    map<int, int> distance; 

    // 모든 노드의 거리를 -1 (미방문 상태)로 초기화
    for (auto const& [node, neighbors] : graph) {
        distance[node] = -1;
    }

    // 2. 시작 노드를 큐에 넣고 방문 처리 및 거리 설정
    q.push(startNode);
    distance[startNode] = 0;

    // 3. 큐가 비어있을 때까지 반복
    while (!q.empty()) {
        // 3-1. 큐에서 현재 노드를 하나 꺼냅니다.
        int currentNode = q.front();
        q.pop();

        cout << "현재 방문 노드: " << currentNode 
                  << ", 거리: " << distance[currentNode] << endl;

        // 3-2. 현재 노드와 연결된 모든 이웃 노드를 확인
        // graph.at(currentNode)는 currentNode에 연결된 이웃 노드들의 vector를 반환
        for (int neighbor : graph.at(currentNode)) {
            // 3-3. 아직 방문하지 않은 이웃 노드라면,
            if (distance[neighbor] == -1) {
                // 거리를 현재 노드 + 1로 설정
                distance[neighbor] = distance[currentNode] + 1;
                // 큐에 이웃 노드를 추가
                q.push(neighbor);
            }
        }
    }
    
    cout << "\n--- 최종 결과 ---" << std::endl;
    cout << "'" << startNode << "' 노드에서 각 노드까지의 최단 거리:" << std::endl;
    for (auto const& [node, dist] : distance) {
        cout << node << ": " << dist << endl;
    }
}

int main() {
    // 인접 리스트로 그래프 표현 (map과 vector 사용)
    map<int, vector<int>> my_graph = {
        {1, {2, 3}},
        {2, {1, 4, 5}},
        {3, {1, 6}},
        {4, {2}},
        {5, {2, 6}},
        {6, {3, 5}}
    };
    
    int start_node = 1;
    bfs(my_graph, start_node);

    return 0;
}