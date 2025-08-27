[Reference](https://meojiktard.tistory.com/13)

# Dijkstra 알고리즘 
다이나믹 프로그래밍을 활용한 최단경로 탐색 알고리즘

최단거리는 여러개의 최단거리로 이루어져 있기 때문



<p align="center">
<img width="400" height="200" alt="image" src="https://github.com/user-attachments/assets/7cc48b74-5ac3-4b98-a483-c8c2997af86d" />
</p>

1. Priority Queue(방문 프로세스 조작) + Array(가중치 저장)
* array 초기화 INF
<p align="center">
<img width="500" height="300" alt="image" src="https://github.com/user-attachments/assets/0de450a7-fdb8-4c2b-a682-ebcfbf980d4e" />
</p>

2. 첫 방문 '0' update

<p align="center">
<img width="500" height="300" alt="image" src="https://github.com/user-attachments/assets/b0fb3094-fa68-49e2-a46f-182d2fde61cb" />
</p>

3. 인접 노드 탐색
Node 2 = 8, Node 3 = 2 update, Priority queue에는 3이 앞으로 정렬
<p align="center">
<img width="500" height="300" alt="image" src="https://github.com/user-attachments/assets/2549a0c7-84d1-4809-9c0b-5476baf956ff" />
</p>

4. 다음 노드로 이동

<p align="center">
<img width="500" height="300" alt="image" src="https://github.com/user-attachments/assets/26199168-1ae3-4715-a2a2-2281553d073e" />
</p>

5. 1번 node는 가중치 update 하지 않는다, 기본 0이 제일 작으므로

<p align="center">
<img width="500" height="300" alt="image" src="https://github.com/user-attachments/assets/296c91c3-fa6a-445f-82e4-fca9eed1c992" />
</p>

6. 4번노드 가중치 update, 현재 2+1 = 3

<p align="center">
<img width="500" height="300" alt="image" src="https://github.com/user-attachments/assets/d9dd5768-bd93-49f1-87bd-337cbe153b8c" />
</p>

7. 5번노드 가중치 update

<p align="center">
<img width="500" height="300" alt="image" src="https://github.com/user-attachments/assets/49dbd2a9-3777-416d-8ce4-872d7d3b96c6" />
</p>

8. 4,5 node에서도 인접 node check 해야하지만 update 안될거기때문에 생략

<p align="center">
<img width="500" height="300" alt="image" src="https://github.com/user-attachments/assets/2839b19e-e711-43c9-8e62-c128345e7d4b" />
</p>

Dijk[1]: 1 -> 1까지의 최단 경로

Dijk[2]: 1 -> 2까지의 최단 경로

Dijk[3]: 1 -> 3까지의 최단 경로

Dijk[4]: 1 -> 4까지의 최단 경로

Dijk[5]: 1 -> 5까지의 최단 경로



* 그 다음 스텝으로 노드1에서 노드 5로 갈수 있나, 다시 봐봤더니 -2+(-9)=-11로 이미 저장되어 있는 -9보다 작은 비용이기에 또 이동이 가능해 집니다! 이런 이유때문에 음수 가중치가 있는 그래프인 경우에 다익스트라 기법은 계속해서 돌고 돌아 무한대의 시간으로 탐색을 하기 때문에 활용할 수 없습니다.

<p align="center">
<img width="300" height="300" alt="image" src="https://github.com/user-attachments/assets/5176fdbf-cb99-4b5d-86e1-1e42b83c6166" />
</p> 

---

## 시간 복잡도

시간 복잡도는 입력 크기에 따라 알고리즘의 실행 시간이 얼마나 걸리는지 나타냅니다. 다익스트라 알고리즘의 시간 복잡도는 구현 방식에 따라 달라집니다.

### 배열 기반 구현

시간 복잡도: O(V^2) (V는 정점의 개수)

설명: 각 정점까지의 최단 거리를 저장하는 배열을 사용하여 구현합니다.

장점: 구현이 간단합니다.

단점: 정점의 개수가 많은 경우 비효율적입니다.

### 우선순위 큐 기반 구현

시간 복잡도: O(E log V) (E는 간선의 개수, V는 정점의 개수)

설명: 우선순위 큐(힙)을 사용하여 최단 거리가 가장 짧은 정점을 빠르게 선택합니다.

장점: 배열 기반 구현보다 효율적입니다. 특히 간선의 개수가 적은 희소 그래프에서 성능이 좋습니다.

단점: 구현이 다소 복잡합니다.

일반적으로 우선순위 큐 기반 구현이 더 많이 사용됩니다.

### 공간 복잡도

공간 복잡도는 입력 크기에 따라 알고리즘이 사용하는 메모리 공간이 얼마나 되는지 나타냅니다. 다익스트라 알고리즘의 공간 복잡도는 다음과 같습니다.

공간 복잡도: O(V + E) (V는 정점의 개수, E는 간선의 개수)

설명: 각 정점까지의 최단 거리를 저장하는 배열과 그래프 정보를 저장하는 인접 리스트(또는 인접 행렬)을 사용합니다.

V: 최단 거리 저장 공간

E: 그래프 정보 저장 공간


---


## 우선순위 큐(Priority Queue)의 시간 복잡도.

요소를 추가, 제거할 때 내부적으로 이진 힙(Binary Heap)구조로 최적화되어, 가장 높은 우선순위 요소에 빠르게 접근할 수 있다.

삽입 (Insertion) : O(log n) : 이진 힙(Binary Heap)을 사용하는 경우, 데이터 삽입시 (log n) 이 걸림.

최상위 요소 접근 (Access Minimum/Maximum) : O(1)

최상위 요소 제거 (Deletion of Minimum/Maximum) : O(log n)

요소 개수 확인: O(1)

push() :  　 우선순위 큐에 원소를 추가한다
pop()  :       우선순위 큐에서 top의 원소를 제거한다
top() :         우선순위 큐에서 top에 있는 원소 즉 우선순위가 높은 원소를 반환한다.
empty() :     우선순위 큐가 비어있으면 true를 반환하고 그렇지 않으면 false를 반환한다
size() :        우선순위 큐에 포함되어 있는 원소의 수를 반환한다

