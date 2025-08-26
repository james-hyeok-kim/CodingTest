[Reference](https://gmlwjd9405.github.io/2018/08/15/algorithm-bfs.html)

# Graph Search

## 너비 우선 탐색(BFS, Breadth-First Search)

루트 노드(혹은 다른 임의의 노드)에서 시작해서 인접한 노드를 먼저 탐색하는 방법

</p align="center">
<img width="1000" height="1000" alt="image" src="https://github.com/user-attachments/assets/f6d2115f-b5a3-4d23-a6ff-6949f108ef49" />
</p>

## 너비 우선 탐색(BFS)의 시간 복잡도

* 인접 리스트로 표현된 그래프: O(N+E)
  * Node(N) + Edge(E)
  * 모든 간선에 대해서 한번씩 검사를 할 것이고, 각 정점을 한번씩 모두 방문하기 때문에 O(n+e)만큼의 시간복잡도를 가질 것이다.

* 인접 행렬로 표현된 그래프: O(N^2)
  * 정점 한개당 N번의 for loop를 돌기 때문에 O(n)의 시간이 걸리는데 이 for loop는 큐에 아무것도 없을 때까지 즉, 모든 정점을 방문할 때까지 실행되므로 n번 반복 실행된다.

## 장단점

* 장점
  * 너비를 우선으로 탐색하므로 답이 되는 경로가 여러 개인 경우에도 최단경로를 얻을 수 있다.
  * 경로가 무한히 깊어져도 최단경로를 반드시 찾을 수 잇다.
  * 노드 수가 적고 깊이가 얕은 해가 존재할 때 유리하다.
* 단점
  * DFS와 달리 큐를 이용하여 다음에 탐색할 정점들을 저장하므로 더 큰 저장공간이 필요하다.
