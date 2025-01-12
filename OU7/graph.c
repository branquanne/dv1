#include "graph.h"
#include "set.h"
#include <stdbool.h>
#include <stdlib.h>

// #define N 10 // Number of nodes in the graph

/*
 * File:         graph.c
 *
 * Description: This file the implementation of the graph module. The graph module
 *              provides a graph data structure and functions for creating and
 *              manipulating graphs. The graph module is used by the files graph.c
 *              and graph-test.c. The declaration of the functions can be found in
 *              the file graph.h.
 *
 * Author:      Bran Mjöberg Quanne
 *
 * Date:        2025-01-12
 */

/* --- The following function is not declared in graph.h and is merely a helper function --- */

/*
 * Description: This function creates a new graph with no nodes or edges.
 *
 * Input:       None.
 *
 * Output:      A pointer to the new graph.
 */
Graph *create_empty_graph() {
  Graph *graph = malloc(sizeof(Graph));
  graph->edges = set_empty();
  graph->nodes = set_empty();
  return graph;
}

/* --- The following functions are declared in graph.h and are implemented here --- */

Graph *create_graph() {
  Graph *graph = malloc(sizeof(Graph));
  graph->edges = set_empty();
  graph->nodes = set_empty();
  for (int i = 0; i < N; i++) {
    insert_node(graph, i);
  }
  return graph;
}

void destroy_graph(Graph *graph) {
  set_destroy(graph->edges);
  set_destroy(graph->nodes);
  free(graph);
}

Graph *neighbours(const Graph *graph, int node) {
  Graph *neighbours = create_empty_graph();
  int *edges = set_get_values(graph->edges);
  for (int i = 0; i < set_size(graph->edges); i++) {

    // Since the edges are stored as node1 * 1000 + node2, we can extract the
    // nodes by dividing by 1000 and taking the remainder.
    int node1 = edges[i] / 1000;
    int node2 = edges[i] % 1000;

    if (node1 == node) {
      insert_node(neighbours, node2);
    } else if (node2 == node) {
      insert_node(neighbours, node1);
    }
  }
  free(edges);
  return neighbours;
}

int no_of_nodes(const Graph *graph) { return set_size(graph->nodes); }

void insert_node(Graph *graph, int node) { set_insert(node, graph->nodes); }

void insert_edge(Graph *graph, int node1, int node2) {

  // Store the edges as node1 * 1000 + node2 and node2 * 1000 + node1.
  // Since we are using a bitvectors, we need to store the edges in a way that
  // allows us to easily check if an edge exists.
  set_insert(node1 * 1000 + node2, graph->edges);
  set_insert(node2 * 1000 + node1, graph->edges);
}
