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
LIFO, Push/Pop, 탐색 불가능, O(1)

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

### 순회방법
- 전위 순회(pre-order): 중왼오
- 중위 순회(in-order): 왼중오
- 후위 순회(post-order): 왼오중

### 힙(Heap)
### 이진탐색트리(Binary Search Tree)

## 그래프(Graph)
### DFS
### BFS
### Spanning Tree(ST) & Minimum ST(MST)
### Prim`s MSP algorithm
### Kruskal`s MSP algorithm
### Djkstra`s SP algorithm
### DBF algorithm
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