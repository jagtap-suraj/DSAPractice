// AOA Experiment No. 07

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct Edge
{
    int u;
    int v;
    int weight;
} Edge;

typedef struct Graph
{
    int num_vertices;
    int num_edges;
    Edge *edges;
} Graph;

Graph *create_graph(int num_vertices)
{
    Graph *graph = (Graph *)malloc(sizeof(Graph));
    graph->num_vertices = num_vertices;
    graph->num_edges = 0;
    graph->edges = NULL;
    return graph;
}

void add_edge(Graph *graph, int u, int v, int weight)
{
    Edge *edge = (Edge *)malloc(sizeof(Edge));
    edge->u = u;
    edge->v = v;
    edge->weight = weight;
    graph->edges = (Edge *)realloc(graph->edges, sizeof(Edge) * (unsigned long)(graph->num_edges + 1));
    graph->edges[graph->num_edges++] = *edge;
}

int *bellman_ford(Graph *graph, int start)
{
    int *distances = (int *)malloc(sizeof(int) * (unsigned long)graph->num_vertices);
    for (int i = 0; i < graph->num_vertices; i++)
    {
        distances[i] = INT_MAX;
    }
    distances[start] = 0;
    for (int i = 0; i < graph->num_vertices - 1; i++)
    {
        for (int j = 0; j < graph->num_edges; j++)
        {
            int u = graph->edges[j].u;
            int v = graph->edges[j].v;
            int weight = graph->edges[j].weight;
            if (distances[u] + weight < distances[v])
            {
                distances[v] = distances[u] + weight;
            }
        }
    }
    for (int i = 0; i < graph->num_edges; i++)
    {
        int u = graph->edges[i].u;
        int v = graph->edges[i].v;
        int weight = graph->edges[i].weight;
        if (distances[u] + weight < distances[v])
        {
            printf("Graph contains negative weight cycle and cannot be solved by Bellman-Ford algorithm \n");
            return NULL;
        }
    }
    return distances;
}

int main()
{
    int num_vertices, num_edges, start;
    printf("Enter number of vertices: ");
    scanf("%d", &num_vertices);
    printf("Enter number of edges: ");
    scanf("%d", &num_edges);
    Graph *graph = create_graph(num_vertices);
    for (int i = 0; i < num_edges; i++)
    {
        int u, v, weight;
        printf("Enter edge %d: ", i + 1);
        scanf("%d %d %d", &u, &v, &weight);
        add_edge(graph, u, v, weight);
    }
    printf("Enter start vertex: ");
    scanf("%d", &start);
    int *distances = bellman_ford(graph, start);
    if (distances != NULL)
    {
        printf("Shortest distances from vertex %d are: \n", start);
        for (int i = 0; i < num_vertices; i++)
        {
            printf("%d \t\t %d \n", i, distances[i]);
        }
    }
    return 0;
}
