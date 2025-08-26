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

* 인접 행렬로 표현된 그래프: O(N^2)
