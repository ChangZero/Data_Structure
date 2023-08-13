# 자료구조
자료구조 이론 정리 구현 및 텀프로젝트
## 기초지식(basic)
- BigO: 알고리즘 수행 시 데이터가 증가함에 따라 처리시간 증가율을 예측하기 위한 식; 함수의 상한을 표기함
- 선형구조: 자료를 구성하는 원소들을 순차적으로 나열시킨 구조 (ex)배열, 연결리스트, 스택, 큐
- 비선형구조: 하나의 자료 뒤에 여러개의 자료가 존재할 수 있는 형태 (ex)트리, 그래프
### [배열 및 구조(Array & Structure)](https://github.com/ChangZero/Data_Structure/blob/main/exersice_class/week02/ex01.c)
포인터: 다른 변수의 주소값을 갖는 변수<br>
이중포인터: 포인터의 주소값을 저장하는 변수<br>
### [순환(Recursion)](https://github.com/ChangZero/Data_Structure/tree/main/Recursion)
함수가 수행 도중에 자기 자신을 다시 호출하여 결과를 도출 (ex) 펙토리얼, 피보나치, 이항계수, 이진탐색

**장점**
> 복잡한 알고리즘 쉽게 작성 가능

**단점**
> 함수호출에 따른 오버헤드(반복문보다 수행 속도 느림)
## [스택(Stack)](https://github.com/ChangZero/Data_Structure/blob/main/Stack%20and%20Queue/stack.c)
LIFO, Push/Pop, 탐색 불가능<br>

시간복잡도
> O(1)

## [큐(Queue)](https://github.com/ChangZero/Data_Structure/blob/main/Stack%20and%20Queue/queue.c)
FIFO, Enqueue/Dequeue, 탐색 불가능<br>
시간복잡도
> O(1)

원형큐(Circular Queue)
> 선형큐의 문제점 해결(rear이 가르키는 포인터가 배열의 마지막 인덱스를 가르키고 있을 때 앞쪽에서 Dequeue로 발생한 배열의 빈 공간을 활용 불가) -> (rear+1) % size


## [연결리스트(Linked List)](https://github.com/ChangZero/Data_Structure/tree/main/Linked_list)
단방향, 양방향, 원형<br>
데이터를 저장하는 노드와 연결정보를 가지는 포인터로 구성, O(1):insert in the front , O(n): search, insert in the rear/원형연결리스트일때는 O(1)

**_Array와 Linked List의 차이점_**
> 배열은 비슷한 유형의 선형 데이터를 저장하는데 사용할 수 있지만 제한 사항이 있음
> 1) 배열의 크기가 고정되어 있어 미리 요소의 점 대해 할당을 받아야 함
> 2) 새로운 요소를 삽입하는 것은 비용이 많이 듬 (공간을 만들고, 기존 요소 전부 이동)

**장점**
> 1) 동적 크기
> 2) 삽입/삭제 용이

**단점**
> 1) 임의로 액세스를 허용할 수 없음. 즉, 첫 번째 노드부터 순차적으로 요소에 액세스 해야함 (이진 검색 수행 불가능)
> 2) 포인터의 여분의 메모리 공간이 목록의 각 요소에 필요
## [트리(Tree)](https://github.com/ChangZero/Data_Structure/tree/main/Tree)
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

### [힙(Heap)](https://github.com/ChangZero/Data_Structure/blob/main/heap/ex01.c)
완전 이진 트리의 종류 중 하나<br>
**우선 순위 큐**: 우선순위의 개념을 큐에 도입한 자료구조
> 데이터간에 우선순위 존재, 우선순위가 높은 데이터가 먼저 나감<br>

최대힙(max heap): 부모 노드의 키 값이 자식 노드의 키 값보다 크거나 같은 완전 이진 트리<br>
최소힙(min heap): 부모 노드의 키 값이 자식 노드의 키 값보다 작거나 같은 완전 이진 트리<br>

**시간복잡도**

> 삽입시: O(logn)<br>
> 삭제시: O(logn)<br>

### [이진탐색트리(BST, Binary Search Tree)](https://github.com/ChangZero/Data_Structure/blob/main/Tree/ex2.c)
이진탐색 + 연결리스트<br>
1. 모든 노드는 고유키를 가진다.
2. 노드의 왼쪽 하위 트리에는 노드의 키보다 작은 키가 있는 노드만 포함
3. 노드의 오른쪽 하위 트리에는 노드의 키보다 큰 키가 있는 노드만 포함
4. 왼쪽 및 오른쪽 하위 트리도 각각 이진탐색트리여야함
   
시간복잡도
> 보통은 트리의 높이만큼 O(logn)<br>
> skewed이면 O(n)


## [그래프(Graph)](https://github.com/ChangZero/Data_Structure/tree/main/Graph)
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

### [DFS](https://github.com/ChangZero/Data_Structure/blob/main/Graph/ex01.c)
> 깊이 우선 탐색, 스택 or 재귀함수로 구현

시간복잡도
> 인접행렬: O(V^2)
> 인접리스트: O(V+E)

### [BFS](https://github.com/ChangZero/Data_Structure/blob/main/Graph/ex01.c)
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
>       - 즉, 가장 낮은 가중치를 먼저 선택한다.
> 3. 위의 과정을 트리가 (N-1)개의 간선을 가질 때까지 반복한다.

#### [Kruskal`s MSP algorithm](https://github.com/ChangZero/Data_Structure/blob/main/Graph/krusdal.c)
탐욕적인(Greedy) 방법을 이용하여 그래프의 모든 정점을 최소 비용으로 연결하는 최적 해답을 구하는 알고리즘

**과정**

> 1. 그래프의 간선들을 가중치의 오름차순으로 정렬한다.
> 2. 정렬된 간선 리스트에서 순서대로 사이클을 형성하지 않는 간선을 선택한다.
>       - 즉, 가장 낮은 가중치를 먼저 선택한다.
>       - 사이클을 형성하는 간선을 제외한다.
> 3. 해당 간선을 현재의 MST(최소 비용 신장 트리)의 집합에 추가한다.

**_Prim MSP와 Kruskal MST 차이점_**
> Prim MSP는 정점 선택을 기반으로 하는 알고리즘으로 이전 단계에서 만들어진 신장 트리를 확장하는 방법이지만, Kruskal MST는 간선 선택을 기반으로 하는 알고리즘으로 이전 단게 만들어진 신장 트리와는 상관없이 무조건 최소 간선만을 선택하는 방법이다.


### [Djkstra`s SP algorithm](https://github.com/ChangZero/Data_Structure/blob/main/Graph/Dijkstra.c)
동적계획법을 활용하여 그래프의 한 정점에서 다른 정점까지의 최단 경로를 구하는 알고리즘

시간복잡도
> O(E+V^2) = O(V^2)

**과정**
> 1. 출발노드 설정
> 2. 출발 노드를 기준으로 각 노드의 최소 비용 저장
> 3. 방문하지 않는 노드 중에서 가장 비용이 적게드는 노드 선택
> 4. 해당 노드를 거쳐 특정한 노드로 가는 경우를 고려하여 최소비용 갱신
> 5. 3번, 4번 과정 반복

## [정렬(Sorting)](https://github.com/ChangZero/Data_Structure/tree/main/Sorting)
안정정렬(Stable Sort): 중복된 값을 입력 순서와 동일하게 정렬 [ex] 버블정렬, 삽입정렬<br>
불안정정렬(Unstable Sort): 중복된 값이 입력 순서와 동일하지 않게 정렬 [ex] 퀵정렬<br>
### 버블정렬(Bubble sorting)
서로 인접한 두 원소의 크기를 비교하여, 조건에 맞지 않다면 자리를 교환하며 정렬하는 알고리즘
![버블정렬](https://github.com/ChangZero/Data_Structure/assets/97018869/0735a673-9ba9-4b9e-9916-93b3cb8beb8d)



시간복잡도
> 최선, 최악, 평균의 경우 모두 O(n^2)

장점
> 구현이 매우 간단
> 별도의 메모리 공간 필요 x

단점
> 시간복잡도가 굉장히 비효율적
> 정렬되어 있지 않은 원소가 많을 시 교환연산(swap)이 많이 발생


### 삽입정렬(Insertion sorting)
2번째 원소부터 시작하여 그 앞의 원소들과 비교하여 삽입할 위치를 지정한 후, 원소를 뒤로 옯기고 지정된 자리에 자료를 삽입하여 정렬하는 알고리즘
<br>
![삽입정렬](https://github.com/ChangZero/Data_Structure/assets/97018869/10cf6790-83bd-4df1-aa81-5a20c169b1b5)

과정
> 1. **배열 순회 시작**: 배열의 두 번째 요소부터 시작하여 마지막 요소까지 순회합니다.
삽입할 요소 선택: 현재 순회 중인 요소를 선택하고, 이를 삽입할 위치를 찾습니다.
>2. **정렬된 부분 배열과 비교**: 현재 선택한 요소를 정렬된 부분 배열과 비교하며, 삽입할 위치를 찾습니다. 정렬된 부분 배열은 현재 요소의 왼쪽에 위치하며, 이미 정렬된 상태를 유지합니다.
>3. **요소 삽입**: 삽입할 위치를 찾았다면, 현재 요소를 해당 위치로 이동시킵니다. 이때, 삽입할 위치 이후의 요소들은 한 칸씩 오른쪽으로 이동하여 자리를 만듭니다.
>4. **다음 요소로 이동**: 현재 요소를 삽입한 후, 다음 순회를 위해 다음 요소로 이동합니다.
>5. **반복**: 모든 요소에 대해 위의 과정을 반복합니다. 이렇게 하면 배열은 작은 요소부터 큰 요소 순서로 정렬됩니다

시간복잡도
> 최선의 경우 O(n)으로 효율성이 좋음<br>
> 평균 혹은 최악의 경우 O(n^2)

장점
> 알고리즘이 단순<br>
> 어느정도 정렬이 되어있는 경우, 매우 효율적<br>
> 별도의 메모리 공간 필요 x

단점
> 평균과 최악의 시간복잡도가 비효율적<br>
> 배열의 길이가 길어 질수록 비효율적

### 쉘정렬(Shell sorting)
삽입정렬의 개선된 버전으로, 배열을 일정한 간격(간격은 일련의 정해진 값들로 결정)으로 나누어 부분적으로 정렬한 후, 점차 간격을 줄여가며 배열을 정렬하는 정렬알고리즘

과정
>1. **간격(Gap) 선택**: 먼저 정렬할 배열과 간격을 선택합니다. 간격은 일련의 정해진 값들로 결정됩니다. 일반적으로 간격의 초기 값은 배열의 길이를 반으로 나눈 후, 이를 계속 반으로 나눠가며 결정합니다.
>2. **간격에 따른 부분 배열 정렬**: 선택한 간격에 따라 배열을 일정한 부분 배열로 나눕니다. 이 부분 배열들은 각각 삽입 정렬이나 다른 간단한 정렬 알고리즘을 사용하여 정렬됩니다. 삽입 정렬은 작은 규모의 부분 배열을 효율적으로 정렬하는데 사용됩니다.
>3. **간격 축소**: 정렬된 부분 배열들을 간격을 줄여가며 다시 하나의 배열로 합칩니다. 간격을 줄여가면서 이러한 합병 과정을 반복합니다. 이 과정을 반복하면서 간격이 1이 될 때까지 정렬을 수행합니다.
>4. **최종 정렬**: 간격이 1이 되면 최종적으로 전체 배열에 대해 정렬을 수행합니다. 이때는 부분 배열이 거의 정렬된 상태이므로, 삽입 정렬이 빠르게 수행됩니다.

시간복잡도
> O(NlogN) ~ O(N^2)

장점
> 삽입정렬보다 빠른 속도

단점
> 간격에 따른 성능 차이 발생

### 퀵정렬(Quick sorting)
분할 정복 방법을 기반으로 하는 정렬 알고리즘으로, 평균적으로 매우 빠른 실행 속도를 가지는 알고리즘 중 하나입니다. 배열을 분할하고 정복하는 방식을 사용하여 배열을 정렬한다.
<br>
![퀵정렬](https://github.com/ChangZero/Data_Structure/assets/97018869/5b3a1b72-52f4-4ad6-b0d4-989d0652baeb)

**분할 정복(Divide and Conquer)**
> 문제를 작은 2개의 문제로 분리하고 각각을 해결한 다음, 결과를 모아서 원래의 문제를 해결하는 전략

과정
> 1. **피벗 선택**: 배열에서 피벗(pivot)을 선택합니다. 피벗은 배열의 요소 중 하나로 선택되며, 이 값을 기준으로 배열을 분할합니다. 피벗을 선택하는 방법에는 여러가지가 있습니다 (첫 번째 요소, 마지막 요소, 중간 요소, 랜덤 요소 등). <br>
> 2. **분할**: 피벗을 기준으로 배열을 분할합니다. 작은 값은 피벗의 왼쪽으로, 큰 값은 피벗의 오른쪽으로 이동시킵니다. 이렇게 하면 피벗을 기준으로 배열이 두 부분으로 나뉩니다.<br>
> 3. **재귀적 정렬**: 분할된 두 부분 배열에 대해 재귀적으로 퀵 정렬을 수행합니다. 각 부분 배열에 대해 피벗을 선택하고 분할을 수행하여 배열이 적절하게 정렬될 때까지 이 과정을 반복합니다.<br>
> 4. **정복**: 분할된 부분 배열들이 정렬되었으면, 전체 배열도 정렬이 완료됩니다.

시간복잡도
> 최선/평균 경우 O(logn) <br>
> 최악의 경우 O(n^2)

장점
> 매우 빠른 정렬 성능

단점
> 최악의 경우 예외처리 필요, 불안정 정렬<br>
> 피벗 선택에 따라 성능 차이 발생

### 힙정렬(Heap sorting)
힙을 활용한 정렬알고리즘

과정
> 1. 완전 이진 트리 구성
> 2. 힙생성(Heapify)

시간복잡도
> O(NlogN) = O(logN)[힙생성] + N[전체데이터 수]

장점
> 빠른 속도


## [해싱(Hashing)](https://github.com/ChangZero/Data_Structure/tree/main/Hasing)
특정 키 값으로 데이터의 저장 위치를 탐색, 삭제, 저장하는 방법

_해시 테이블을 쓰는 이유?_
> 적은 자원으로 많은 데이터 효율적 관리

시간복잡도
> O(1)

### 충돌 문제 해결

> 1. **체이닝** : 연결리스트로 노드를 계속 추가해나가는 방식
   (제한 없이 계속 연결 가능, but 메모리 문제)
> 2. **Open Addressing** : 해시 함수로 얻은 주소가 아닌 다른 주소에 데이터를 저장할 수 있도록 허용 (해당 키 값에 저장되어있으면 다음 주소에 저장)
> 3. **선형 탐사** : 정해진 고정 폭으로 옮겨 해시값의 중복을 피함
> 4. **제곱 탐사** : 정해진 고정 폭을 제곱수로 옮겨 해시값의 중복을 피함

## 텀프로젝트1
[**스택을 활용한 계산기 프로그램**](https://github.com/ChangZero/Data_Structure/blob/main/project1/proj1.c)
<br>
텍스트 문서로 부터 infix 표현을 입력받아서 해당 Infix 스트링을 postfix형태로 변환하고 postfix 스트링을 출력한다. 마지막으로 postfix 스트링을 evaluate (평가)하고 값을 출력하는 계산기 설계
## 텀프로젝트2
[**다중 연결리스트를 활용한 학생등록 시스템**](https://github.com/ChangZero/Data_Structure/blob/main/project2/proj2.c)
<br>
5000명의 학생과 35개의 코스 등록(add) 및 등록취소(drop)를 처리하는 소프트웨어 시스템 설계


## 텀프로젝트3
[**이진탐색트리를 활용한 재고 관리 시스템**](https://github.com/ChangZero/Data_Structure/blob/main/project3/proj3.c)
<br>
새로운 컨포넌트(conponent)를 추가 (add), 컨포넌트를 삭제 (delete), 재고품목에서부터 아이템을 제거 (remove), 재고품목에 아이템을 추가 (add), 그리고 재고목록을 출력하는 재고관리 시스템 설계

## 텀프로젝트4
[**정렬알고리즘 성능 비교**](https://github.com/ChangZero/Data_Structure/blob/main/project4/proj4.c)

## 참고자료
HOROWITZ, SAHNI, ANDERSON-FREED, ⌜C로 쓴 자료구조론⌟, 이석호, 교보문고, 2008<br>
https://github.com/gyoogle/tech-interview-for-developer/tree/master <br>
GIF 이미지 출처: https://jinhyy.tistory.com/9
