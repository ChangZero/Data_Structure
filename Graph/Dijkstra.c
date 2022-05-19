#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define INFINITE 9999  // �Ÿ��� �ʱⰪ
#define NUM_VERTICES 6 // ������ ����

// ��������Ʈ ����ü
typedef struct Adjacency
{
    struct Adjacency *link; // ����
    int vertex;             // ����
    int weight;             // ����
} Adjacency;

// ���� ����Ʈ
Adjacency *Graph_list[NUM_VERTICES];

void initGraph();
void insertEdge(int, int, int);
void DijkstraShortestPathsSingleTargetCount(int, int);
void trans_print(int , int , int);

int main()
{
    int start, end, i;

    // �׷��� ����.
    initGraph();

    printf("<Djkstra's SP algorithm>\n");
    printf("\n");
    for (i = 2; i < 6;i++)
        DijkstraShortestPathsSingleTargetCount(1, i); // ���ͽ�Ʈ�� �˰��� ����
    return 0;
}

// �׷����� �ʱ�ȭ���ִ� �Լ� - ���� ����ŭ ��������� �Ѵ�.
void initGraph()
{
    insertEdge(1, 2, 160);
    insertEdge(1, 3, 230);
    insertEdge(1, 4, 320);
    insertEdge(2, 3, 100);
    insertEdge(2, 4, 150);
    insertEdge(3, 4, 140);
    insertEdge(3, 5, 190);
    insertEdge(4, 5, 60);

    // E�� ������ �߰� - �̹� ������ �Ϸ�
    // F�� ������ �߰� - �̹� ������ �Ϸ�
}

void insertEdge(int start, int end, int weight)
{
    Adjacency *node; // ������ ���� ���

    // ��������� ������ ����� �Ѵ�.
    node = (Adjacency *)malloc(sizeof(Adjacency));
    node->vertex = end;
    node->weight = weight;
    node->link = Graph_list[start];
    Graph_list[start] = node;

    // �ݴ��ʿ����� ����
    node = (Adjacency *)malloc(sizeof(Adjacency));
    node->vertex = start;
    node->weight = weight;
    node->link = Graph_list[end];
    Graph_list[end] = node;
}

void trans_print(int u, int v, int distance)
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
    printf("%s -> %s : %d\n", start, end, distance);
}

void DijkstraShortestPathsSingleTargetCount(int start, int end)
{
    int distance[NUM_VERTICES]; // �Ÿ�
    int pathcnt[NUM_VERTICES];  // ��� ��
    int check[NUM_VERTICES];    // ���� �ȿ� �ִ��� ����
    Adjacency *tmp;             // �ֱٿ� ���� ������ �����ϱ� ���� ����ü ������
    int cycle, min, now, i;     // cycle : �۾� Ƚ��,
                                // min = �ִܰŸ��� ���� �񱳰�,
                                // now : �ֱٿ� ���� ����

    // �ʱ�ȭ ����
    for (i = 0; i < NUM_VERTICES; i++)
    {
        distance[i] = INFINITE; // �Ÿ��� �������� �ʱ�ȭ
        pathcnt[i] = 0;         // ��μ��� 0���� �ʱ�ȭ
        check[i] = 0;           // PQ�� �ִ��� ������ ���� ( PQ�� ����ִٸ� 0 )
    }
    distance[start] = 0; // �ʱ� start ���� - �ڽű����� �Ÿ��� 0
    cycle = 0;

    while (cycle < NUM_VERTICES - 1) // ��� ������ ���� �ϱ� ���ؼ�
    {
        min = INFINITE; // �ּҰ� �������� �ʱ�ȭ
        for (i = 0; i < NUM_VERTICES; i++)
            if (distance[i] < min && !check[i]) // ���� ���� ���� �� �Ÿ��� �ּ��� �������κ��� ����
            {
                min = distance[i];
                now = i; // ���濡 ���� ���� ��ġ
            }

        check[now] = 1;        // ���� �ȿ� �ֱ�
        tmp = Graph_list[now]; // ���濡 ���� ���� ������ ����ü ������

        while (tmp != NULL)
        {
            if (!check[tmp->vertex]) // ���� ���� �����̶��
            {
                // ������ �Ÿ� = ���� �ִܰŸ� -- �ٸ� ��θ� ���� ���� �ִܰŸ�
                if (min + tmp->weight == distance[tmp->vertex])
                    pathcnt[tmp->vertex] += pathcnt[now]; // �ִܰ�� ���� ����

                //  ������ �Ÿ� < ���� �ִܰŸ� --> ���� ��ȭ
                if (min + tmp->weight < distance[tmp->vertex])
                {
                    distance[tmp->vertex] = min + tmp->weight; // �ִܰŸ� ����
                    if (now == start)
                        pathcnt[tmp->vertex] = 1; // ���� ������������ �������̶�� ��μ� 1
                    else
                        pathcnt[tmp->vertex] = pathcnt[now]; // �� �̿ܿ��� �θ���ġ�� ��μ�
                }
            }                // if
            tmp = tmp->link; // ���� ���� ����, ���� �˻�
        }                    // while

        cycle++;
        if (now == end)
            break; // ���� ������ ���� ������ ���ٸ� ����
    }              // while

    trans_print(start, end, distance[end]); // ����� ���
}