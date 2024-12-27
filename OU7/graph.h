#ifndef GRAPH_H
#define GRAPH_H
#include "set.h"
#include <stdbool.h>

typedef struct {
    set *nodes;
    set *edges;
} Graph;

Graph *create_graph();
Graph *neighbours(const Graph *graph, int node);
int num_nodes(const Graph *graph);
void destroy_graph(Graph *graph);
void insert_node(Graph *graph, int node);
void insert_edge(Graph *graph, int node1, int node2);
void remove_node(Graph *graph, int node);
void remove_edge(Graph *graph, int node1, int node2);
bool has_node(const Graph *graph, int node);
bool has_edge(const Graph *graph, int node1, int node2);

#endif
