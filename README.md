# 자료구조
자료구조 이론 정리 구현 및 텀프로젝트
## 기초지식(basic)
- BigO: 알고리즘 수행 시 데이터가 증가함에 따라 처리시간 증가율을 예측하기 위한 식; 함수의 상한을 표기함
- 선형구조: 자료를 구성하는 원소들을 순차적으로 나열시킨 구조 (ex)배열, 연결리스트, 스택, 큐
- 비선형구조: 하나의 자료 뒤에 여러개의 자료가 존재할 수 있는 형태 (ex)트리, 그래프
### 배열 및 구조(Array & Structure)
포인터: 다른 변수의 주소값을 갖는 변수<br>
이중포인터: 포인터의 주소값을 저장하는 변수<br>
### 순환(Recursion)
함수가 수행 도중에 자기 자신을 다시 호출하여 결과를 도출 (ex) 펙토리얼, 피보나치, 이항계수, 이진탐색

**장점**
> 복잡한 알고리즘 쉽게 작성 가능

**단점**
> 함수호출에 따른 오버헤드(반복문보다 수행 속도 느림)
## 스택(Stack)
LIFO, Push/Pop, 탐색 불가능<br>

O(1)

## 큐(Queue)
FIFO, Enqueue/Dequeue, 탐색 불가능, O(1)<br>
원형큐(Circular Queue): 선형큐의 문제점 해결(rear이 가르키는 포인터가 배열의 마지막 인덱스를 가르키고 있을 때 앞쪽에서 Dequeue로 발생한 배열의 빈 공간을 활용 불가) -> (rear+1) % size


## 연결리스트(Linked List)
단방향, 양방향, 원형<br>
데이터를 저장하는 노드와 연결정보를 가지는 포인터로 구성, O(1):insert in the front , O(n): search, insert in the rear/원형연결리스트일때는 O(1)

**Array와 Linked List의 차이점**
> 배열은 비슷한 유형의 선형 데이터를 저장하는데 사용할 수 있지만 제한 사항이 있음
> 1) 배열의 크기가 고정되어 있어 미리 요소의 점 대해 할당을 받아야 함
> 2) 새로운 요소를 삽입하는 것은 비용이 많이 듬 (공간을 만들고, 기존 요소 전부 이동)

**장점**
> 1) 동적 크기
> 2) 삽입/삭제 용이

**단점**
> 1) 임의로 액세스를 허용할 수 없음. 즉, 첫 번째 노드부터 순차적으로 요소에 액세스 해야함 (이진 검색 수행 불가능)
> 2) 포인터의 여분의 메모리 공간이 목록의 각 요소에 필요
## 트리(Tree)
노드(node)들과 노드들을 연결하는 간선(edge)들고 구성, 가장 첫 노드= Root Node, 계층구조

**순회방법**
- 전위 순회(pre-order): 중왼오
- 중위 순회(in-order): 왼중오
- 후위 순회(post-order): 왼오중
### 이진트리(Binary Tree)
모든 노드들이 둘 이하의 자식을 가진 트리
#### 경사이진트리(Skewd Binary Tree)
> 모든 노드가 왼쪽 혹은 오른쪽에 있는 트리
#### 포화이진트리(Full Binary Tree)
> 모든 노드가 두 개의 자식 노드를 가지며 모든 잎 노드가 동일한 깊이 또는 레벨을 가지는 트리
#### 완전이진트리(CBT, Complete Binary Tree)
> 마지막 레벨을 제외하고 모든 레벨이 완전히 채워져 있는 트리(왼쪽부터 채워져야함), 다 채워질 필요 없음
### 힙(Heap)
완전 이진 트리의 종류 중 하나<br>
**우선 순위 큐**: 우선순위의 개념을 큐에 도입한 자료구조
> 데이터간에 우선순위 존재, 우선순위가 높은 데이터가 먼저 나감<br>

최대힙(max heap): 부모 노드의 키 값이 자식 노드의 키 값보다 크거나 같은 완전 이진 트리<br>
최소힙(min heap): 부모 노드의 키 값이 자식 노드의 키 값보다 작거나 같은 완전 이진 트리<br>

**시간복잡도**

> 삽입시: O(logn)<br>
> 삭제시: O(logn)<br>

### 이진탐색트리(BST, Binary Search Tree)
이진탐색 + 연결리스트<br>
1. 모든 노드는 고유키를 가진다.
2. 노드의 왼쪽 하위 트리에는 노드의 키보다 작은 키가 있는 노드만 포함
3. 노드의 오른쪽 하위 트리에는 노드의 키보다 큰 키가 있는 노드만 포함
4. 왼쪽 및 오른쪽 하위 트리도 각각 이진탐색트리여야함
   
시간복잡도
> 보통은 트리의 높이만큼 O(logn)<br>
> skewed이면 O(n)


## 그래프(Graph)
정점(Vertex)와 간선(Edge)로 구성
**그래프와 트리의 차이점**
> 트리는 그래프의 하위개념이다. 다만, 트리는 사이클이 존재하지 않는(acyclic) 그래프이다.

### 그래프 종류
1. 무방향 그래프(Undirected Graph): 간선에 방향 x
2. 방향 그래프(Directed Graph): 간선에 방향 o
3. 완전 그래프(Completed Graph): 한 정점에서 다른 모든 정점과 연결되어 최대 간선 수를 가지는 그래프
4. 부분 그래프(Weight Grapth): 간선에 가중치(weight) 할당한 그래프
5. 유향 비순환 그래프(DAG, Directed Acyclic Graph): 방향 그래프에서 사이클이 없는 그래프
6. 연결 그래프(Connected Graph): 떨어져 있는 정점이 없는 그래프
7. 단절 그래프(Disconnected Graph): 연결되지 않는 정점이 있는 그래프

### DFS
> 깊이 우선 탐색, 스택 or 재귀함수로 구현

시간복잡도
> 인접행렬: O(V^2)
> 인접리스트: O(V+E)

### BFS
> 너비 우선 탐색, 큐로 구현

시간복잡도
> 인접행렬: O(V^2)
> 인접리스트: O(V+E)

### Spanning Tree(ST)
**Spanning Tree 란**
> 그래프 내의 모든 정점을 포함하는 트리, 통신네트워크 구축에 주로 사용

### 최소신장트리(MST, Mininum Spanning Tree)
Spanning Tree 중에서 사용된 간선들의 가중치 합이 최소인 트리

#### Prim`s MSP algorithm
시작 정점에서 출발하여 신장트리 집합을 단계적으로 확장 해나가는 방법

**과정**

> 1. 시작 단계에서는 시작 정점만이 MST(최소 비용 신장 트리) 집합에 포함된다.
> 2. 앞 단계에서 만들어진 MST 집합에 인접한 정점들 중에서 최소 간선으로 연결된 정점을 선택하여 트리를 확장한다.
> 3. 즉, 가장 낮은 가중치를 먼저 선택한다.
> 4. 위의 과정을 트리가 (N-1)개의 간선을 가질 때까지 반복한다.

#### Kruskal`s MSP algorithm
탐욕적인 방법을 이용하여 그래프의 모든 정점을 최소 비용으로 연결하는 최적 해답을 구하는 알고리즘

**과정**

> 1. 그래프의 간선들을 가중치의 오름차순으로 정렬한다.
> 2. 정렬된 간선 리스트에서 순서대로 사이클을 형성하지 않는 간선을 선택한다.
> 3. 즉, 가장 낮은 가중치를 먼저 선택한다.
> 4. 사이클을 형성하는 간선을 제외한다.
> 5. 해당 간선을 현재의 MST(최소 비용 신장 트리)의 집합에 추가한다.

**Prim MSP와 Kruskal MST 차이점**
> Prim MSP는 정점 선택을 기반으로 하는 알고리즘으로 이전 단계에서 만들어진 신장 트리를 확장하는 방법이지만, Kruskal MST는 간선 선택을 기반으로 하는 알고리즘으로 이전 단게 만들어진 신장 트리와는 상관없이 무조건 최소 간선만을 선택하는 방법이다.

**과정**

> 1. 그래프의 간선들을 가중치의 오름차순으로 정렬한다.
> 2. 정렬된 간선 리스트에서 순서대로 사이클을 형성하지 않는 간선을 선택한다.
>       - 즉, 가장 낮은 가중치를 먼저 선택한다.
>       - 사이클을 형성하는 간선을 제외한다.
> 3. 해당 간선을 현재의 MST(최소 비용 신장 트리)의 집합에 추가한다.


### Djkstra`s SP algorithm
그래프의 한 정점에서 다른 정점까지의 최단 경로를 구하는 알고리즘

시간복잡도
> O(E+V^2) = O(V^2)

**과정**
> 1. 출발노드 설정
> 2. 출발 노드를 기준으로 각 노드의 최소 비용 저장
> 3. 방문하지 않는 노드 중에서 가장 비용이 적게드는 노드 선택
> 4. 해당 노드를 거쳐 특정한 노드로 가는 경우를 고려하여 최소비용 갱신
> 5. 3번, 4번 과정 반복

## 정렬(Sorting)

### 버블정렬(Bubble sorting)
### 삽입정렬(Insertion sorting)
### 쉘정렬(Shell sorting)
### 퀵정렬(Quick sorting)
### 힙정렬(Heap sorting)
### 라딕스정렬(Radix sorting)
## 해싱(Hashing)


## 텀프로젝트1
스택을 활용한 계산기 프로그램

## 텀프로젝트2
다중 연결리스트를 활용한 학생등록 시스템

## 텀프로젝트3
이진탐색트리를 활용한 재고 관리 시스템

## 텀프로젝트4
정렬알고리즘비교