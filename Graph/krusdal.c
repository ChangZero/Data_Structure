#include <stdio.h>
#include <string.h>

#define MAX_VERTICES 100
#define INF 1000
int parent[MAX_VERTICES]; // 부모 노드
int num[MAX_VERTICES];    // 각 집합의 크기
// 초기화
void set_init(int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        parent[i] = -1;
        num[i] = 1; // 각 집합은 자신의 노드 만으로 구성
    }
}
// vertex가 속하는 집합을 반환
int set_find(int vertex)
{
    int p, s, i = -1;
    for (i = vertex; (p = parent[i]) >= 0; i = p)
        ;  // 루트 노드까지 반복
    s = i; // 집합의 대표 원소
    for (i = vertex; (p = parent[i]) >= 0; i = p)
        parent[i] = s; // 집합의 모든 원소들의 부모를 s로 설정
    return s;
}

// 두개의 원소가 속한 집합을 합침
void set_union(int s1, int s2)
{
    if (num[s1] < num[s2])
    {
        parent[s1] = s2;
        num[s2] += num[s1];
    }
    else
    {
        parent[s2] = s1;
        num[s1] += num[s2];
    }
}
typedef struct
{
    int key; // 간선의 가중치
    int u;   // 정점 1
    int v;   // 정점 2
} element;
#define MAX_ELEMENT 100
typedef struct
{
    element heap[MAX_ELEMENT];
    int heap_size;
} HeapType;

// 초기화 함수
void init(HeapType *h)
{
    h->heap_size = 0;
}
// 히프 내용 출력 함수
void print_heap(HeapType *h)
{
    int i, level = 1;
    printf("\n===================");
    for (i = 1; i <= h->heap_size; i++)
    {
        if (i == level)
        {
            printf("\n");
            level *= 2;
        }
        printf("\t%d", h->heap[i].key);
    }
    printf("\n===================");
}

void insert_min_heap(HeapType *h, element item)
{
    int i;
    i = ++(h->heap_size);
    // 트리를 거슬러 올라가면서 부모 노드와 비교하는 과정
    while ((i != 1) && (item.key < h->heap[i / 2].key))
    {
        h->heap[i] = h->heap[i / 2];
        i /= 2;
    }
    h->heap[i] = item; // 새로운 노드를 삽입
}
element delete_min_heap(HeapType *h)
{
    int parent, child;
    element item, temp;
    item = h->heap[1];
    temp = h->heap[(h->heap_size)--];
    parent = 1;
    child = 2;
    while (child <= h->heap_size)
    {
        // 현재 노드의 자식노드중 더 작은 자식노드를 찾는다.
        if ((child < h->heap_size) &&
            (h->heap[child].key > h->heap[child + 1].key))
            child++;
        if (temp.key <= h->heap[child].key)
            break;
        // 한단계 아래로 이동
        h->heap[parent] = h->heap[child];
        parent = child;
        child *= 2;
    }
    h->heap[parent] = temp;
    return item;
}

void insert_heap_edge(HeapType *h, int u, int v, int weight)
{
    element e;
    e.u = u;
    e.v = v;
    e.key = weight;
    insert_min_heap(h, e);
}
// 인접 행렬이나 인접 리스트에서 간선들을 읽어서 히프에 삽입
// 다음은 예제 그래프의 간선들을 삽입
void insert_all_edges(HeapType *h)
{
    insert_heap_edge(h, 1, 2, 160);
    insert_heap_edge(h, 1, 3, 230);
    insert_heap_edge(h, 1, 4, 320);
    insert_heap_edge(h, 2, 3, 100);
    insert_heap_edge(h, 2, 4, 150);
    insert_heap_edge(h, 3, 4, 140);
    insert_heap_edge(h, 3, 5, 190);
    insert_heap_edge(h, 4, 5, 60);
}
void trans_print(int u, int v, int key)
{
    char start[10];
    char end[10];
    switch (u)
    {
    case 1:
        strcpy(start, "Ulsan");
        break;
    case 2:
        strcpy(start, "Sangju");
        break;
    case 3:
        strcpy(start, "Deajon");
        break;
    case 4:
        strcpy(start, "Icheon");
        break;
    case 5:
        strcpy(start, "Seoul");
        break;
    default:
        break;
    }

    switch (v)
    {
    case 1:
        strcpy(end, "Ulsan");
        break;
    case 2:
        strcpy(end, "Sangju");
        break;
    case 3:
        strcpy(end, "Deajon");
        break;
    case 4:
        strcpy(end, "Icheon");
        break;
    case 5:
        strcpy(end, "Seoul");
        break;
    default:
        break;
    }
    printf("(%s,%s) %d \n", start, end, key);
}
// kruskal의 최소 비용 신장 트리 프로그램
int kruskal(int n)
{
    int edge_sum = 0;
    int edge_accepted = 0; // 현재까지 선택된 간선의 수
    HeapType h;            // 최소 히프
    int uset, vset;        // 정점 u와 정점 v의 집합 번호
    element e;             // 히프 요소
    init(&h);              // 히프 초기화
    insert_all_edges(&h);  // 히프에 간선들을 삽입
    set_init(n);           // 집합 초기화
    while (edge_accepted < (n - 1))
    {                            // 간선의 수 < (n-1)
        e = delete_min_heap(&h); // 최소 히프에서 삭제
        uset = set_find(e.u);    // 정점 u의 집합 번호
        vset = set_find(e.v);    // 정점 v의 집합 번호
        if (uset != vset)
        { // 서로 속한 집합이 다르면
            //printf("(%d,%d) %d \n", e.u, e.v, e.key);
            edge_sum += e.key;
            trans_print(e.u, e.v, e.key);
            edge_accepted++;
            set_union(uset, vset); // 두개의 집합을 합친다.
        }
    }
    return edge_sum;
}
int main()
{
    printf("<Kruskal's algorithm>\n");
    printf("\ntotal: %d\n", kruskal(5));
    return 0;
}