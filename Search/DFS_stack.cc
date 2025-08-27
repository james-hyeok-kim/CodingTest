#include <iostream>
#include <vector>
#include <stack>
#include <algorithm> // std::sort를 사용하기 위함 (선택 사항)

using namespace std;

// 그래프를 표현하기 위한 구조
vector<int> graph[9]; // 노드의 개수에 맞게 크기 설정 (1번부터 8번까지 사용)
bool visited[9] = {false}; // 방문 여부 확인 배열

void dfs(int startNode) {
    stack<int> s;

    // 1. 시작 노드를 스택에 넣습니다.
    s.push(startNode);

    // 스택이 빌 때까지 반복합니다.
    while (!s.empty()) {
        // 2. 스택의 최상단 노드를 꺼냅니다.
        int currentNode = s.top();
        s.pop();

        // 3. 만약 이미 방문했다면 건너뜁니다.
        if (visited[currentNode]) {
            continue;
        }

        // 4. 방문하지 않았다면 방문 처리하고, 관련된 작업을 수행합니다.
        visited[currentNode] = true;
        cout << currentNode << " "; // 현재 노드 출력

        // 5. 현재 노드와 연결된 인접 노드들을 스택에 넣습니다.
        // ※ 스택은 LIFO(Last-In, First-Out) 구조이므로,
        // 노드 번호가 작은 순서부터 방문하고 싶다면 인접 노드 목록을
        // 내림차순으로 정렬한 뒤 스택에 넣어야 합니다.
        // 여기서는 오름차순으로 정렬 후 역순으로 스택에 삽입합니다.
        
        // 인접 노드 목록을 복사하여 정렬 (원본 순서 유지를 위해)
        vector<int> neighbors = graph[currentNode];
        sort(neighbors.begin(), neighbors.end(), greater<int>()); // 내림차순 정렬

        for (int neighbor : neighbors) {
            if (!visited[neighbor]) {
                s.push(neighbor);
            }
        }
    }
}

int main() {
    // 그래프 연결 정보 초기화 (인접 리스트)
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

    // 1번 노드부터 DFS 시작
    dfs(1);

    cout << endl;

    return 0;
}