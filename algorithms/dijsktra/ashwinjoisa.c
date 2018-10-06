//Dijkstra's Algorithm : O(ElogV)
//Min-priority Queue implemented using min-heap.

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define inf ((int)(1e9))
#define N 1000

typedef struct graph_adj_list
{
	int node;
	int weight;
	struct graph_adj_list *next;
}node;

typedef struct pair
{
	int weight;
	int node;
}pair;

node *adj[N] = {NULL};
pair min_heap[N];
int edges, nodes, pos;
int visited[N], dis[N];

void swap(int i, int j)
{
	int t1, t2;
	t1  = min_heap[i].weight;
	t2 = min_heap[i].node;

	min_heap[i].weight = min_heap[j].weight;
	min_heap[i].node = min_heap[j].node;

	min_heap[j].weight = t1;
	min_heap[j].node = t2;
}

void priority_enqueue(int w, int node)
{
	int temp;
	min_heap[++pos].weight = w;
	min_heap[pos].node = node;
	temp =  pos;

	while(temp>1)
	{
		if(min_heap[temp].weight < min_heap[temp/2].weight)
			swap(temp, temp/2);
		temp/=2;
	}
}

void min_heapify()
{
	int t1, t2;
	t1 = 1;
	while(t1<=pos)
	{
		if(min_heap[t1*2].weight < min_heap[t1*2 +1].weight)
			t2 = t1*2;
		else
			t2 = t1*2 +1;

		if(min_heap[t1].weight > min_heap[t2].weight)
		{
			swap(t1, t2);
			t1 = t2;
		}
		else
			break;
	}
}

pair priority_dequeue()
{
	min_heap[0].weight = min_heap[1].weight;
	min_heap[0].node = min_heap[1].node;

	min_heap[1].weight = min_heap[pos].weight;
	min_heap[1].node = min_heap[pos].node;

	min_heap[pos].weight = inf;
	min_heap[pos].node = inf;

	pos--;
	min_heapify();

	return min_heap[0];
}

int isempty()
{
	if(pos == 0)
		return 1;
	return 0;
}

void clear()
{
	int i;
	for(i=0; i<N; i++)
	{
		min_heap[i].weight = inf;
		min_heap[i].node = inf;
		visited[i] = 0;
		dis[i] = inf;
	}
	pos = 0;
}

void dijkstra()
{
	int i, x, w;
	pair p;
	node *temp;

	clear();
	dis[0] = 0;
	priority_enqueue(0, 0); //arbitraray weight -> 0, Source vertex - 0

	while(!isempty())
	{
		p = priority_dequeue();
		x = p.node;
		w = p.weight;

		if(visited[x])
			continue;
		visited[x] = 1;

		temp = adj[x];
		while(temp != NULL)
		{
			if(dis[temp->node] > dis[x] + temp->weight)
			{
				dis[temp->node] = dis[x] + temp->weight;
				priority_enqueue(dis[temp->node], temp->node);
			}
			temp = temp->next;
		}
	}
}

int main()
{
	int i, min_cost, x, y, w;
	node *temp;

	printf("Enter number of nodes and edges : ");
	scanf("%d%d", &nodes, &edges);

	printf("\nEnter the pair of edges(undirected) with thier weights (i, j, w) where 0<=i,j<n\n");
	for(i=0; i<edges; i++)
	{
		scanf("%d%d%d", &x, &y, &w);
		temp = (node *)malloc(sizeof(node));
		temp->node = y;
		temp->weight = w;
		temp->next = adj[x];
		adj[x] = temp;

		temp = (node *)malloc(sizeof(node));
		temp->node = x;
		temp->weight = w;
		temp->next = adj[y];
		adj[y] = temp;
	}

	dijkstra();
	printf("\nMinimum distance from sorce vertex(0) for node 0 to %d are\n", nodes-1);
	for(i=0; i<nodes; i++)
		printf("%d ", dis[i]);

	printf("\n\n");
}

/*

Test Case 1:
5 5
0 1 5
0 2 2
2 3 1
0 3 6
2 4 5

Output:
0 5 2 3 7

x-------------x

Test Case 2:
7 7
0 1 1
0 2 4
1 3 6
2 4 5
3 5 1
4 5 1
5 6 1

Output:
0 1 4 7 9 8 9

*/