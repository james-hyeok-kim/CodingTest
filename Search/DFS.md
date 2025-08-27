[Reference](https://gmlwjd9405.github.io/2018/08/14/algorithm-dfs.html)

# 그래프 탐색

## 깊이 우선 탐색 (DFS, Depth First Search)
루트 노드(혹은 다른 임의의 노드)에서 시작해서 다음 분기(branch)로 넘어가기 전에 해당 분기를 완벽하게 탐색하는 방법
</p align="center">
<img width="1000" height="1000" alt="image" src="https://github.com/user-attachments/assets/b7686ef7-83ce-4cf7-9d16-f684fe764dbd" />
</p>

## 깊이 우선 탐색(DFS)의 시간 복잡도
DFS는 그래프(정점의 수: N, 간선의 수: E)의 모든 간선을 조회한다.

* 인접 리스트로 표현된 그래프: O(N+E)

* 인접 행렬로 표현된 그래프: O(N^2)

즉, 그래프 내에 적은 숫자의 간선만을 가지는 희소 그래프(Sparse Graph) 의 경우 인접 행렬보다 인접 리스트를 사용하는 것이 유리하다.
