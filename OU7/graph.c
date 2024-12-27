#include "graph.h"
#include "set.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define N 10 // Number of nodes in the graph

Graph *create_empty_graph()
{
    Graph *graph = malloc(sizeof(Graph));
    graph->edges = set_empty();
    graph->nodes = set_empty();
    return graph;
}

Graph *create_graph()
{
    Graph *graph = malloc(sizeof(Graph));
    graph->edges = set_empty();
    graph->nodes = set_empty();
    for (int i = 0; i < N; i++) {
        insert_node(graph, i);
    }
    return graph;
}

void destroy_graph(Graph *graph)
{
    set_destroy(graph->edges);
    set_destroy(graph->nodes);
    free(graph);
}

Graph *neighbours(const Graph *graph, int node)
{
    Graph *neighbours = create_empty_graph();
    int *edges = set_get_values(graph->edges);
    for (int i = 0; i < set_size(graph->edges); i++) {

        // Extract the two nodes from the edge
        int node1 = edges[i] / 1000;
        int node2 = edges[i] % 1000;

        if (node1 == node) {
            insert_node(neighbours, node2);
        }
        else if (node2 == node) {
            insert_node(neighbours, node1);
        }
    }
    free(edges);
    return neighbours;
}

int num_nodes(const Graph *graph)
{
    return set_size(graph->nodes);
}

void insert_node(Graph *graph, int node)
{
    set_insert(node, graph->nodes);
}

void insert_edge(Graph *graph, int node1, int node2)
{
    // Ensure that node1 < node2
    set_insert(node1 * 1000 + node2, graph->edges);
    set_insert(node2 * 1000 + node1, graph->edges);
}
