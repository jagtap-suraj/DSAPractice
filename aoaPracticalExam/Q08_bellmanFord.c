

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <conio.h>

#define INF INT_MAX
#define MAX_EDGES 100
#define MAX_VERTICES 50

typedef struct Edge {
    int source, destination, weight;
} Edge;

void BellmanFord(int vertices, int edges, int source, Edge edge[], int distance[]) {
    int i, j;
    for (i = 0; i < vertices; ++i) {
	distance[i] = INF;
    }
    distance[source] = 0;


    for (i = 1; i < vertices; ++i) {
	for (j = 0; j < edges; ++j) {
	    int u = edge[j].source;
	    int v = edge[j].destination;
	    int weight = edge[j].weight;
	    if (distance[u] != INF && distance[u] + weight < distance[v]) {
		distance[v] = distance[u] + weight;
	    }
	}
    }


    for (i = 0; i < edges; ++i) {
	int u = edge[i].source;
	int v = edge[i].destination;
	int weight = edge[i].weight;
	if (distance[u] != INF && distance[u] + weight < distance[v]) {
	    printf("Graph contains negative weight cycle\n");
	    return;
	}
    }


    printf("Vertex    Distance from Source\n");
    for (i = 0; i < vertices; ++i) {
	printf("%d\t  %d\n", i, distance[i]);
    }
}

int main() {
    int vertices, edges, source, i;
    Edge edge[MAX_EDGES];
    int distance[MAX_VERTICES]; //distance is used for storing the distance of vertex from source
    clrscr();
    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);

    printf("Enter the number of edges: ");
    scanf("%d", &edges);

    printf("Enter the source vertex: ");
    scanf("%d", &source);

    for (i = 0; i < edges; ++i) {
	printf("Enter edge %d's source destination and weights: ", i+1);
	scanf("%d %d %d", &edge[i].source, &edge[i].destination, &edge[i].weight);
    }

    BellmanFord(vertices, edges, source, edge, distance);
    getch();
    return 0;
}


/*
Enter the number of vertices: 4
Enter the number of edges: 5
Enter the source vertex: 0
Enter edge 1's source destination and weights: 0 1 5
Enter edge 2's source destination and weights: 0 1 6
Enter edge 3's source destination and weights: 1 2 7
Enter edge 4's source destination and weights: 1 4 -5
Enter edge 5's source destination and weights: 1 3 6

Vertex    Distance from Source
0         0
1         5
2         12
3         11
*/