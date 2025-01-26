#include "graph.h"
#include "set.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
 * File: 		    graph-test.c
 *
 * Description: Test program for the graph module. Creates an undirected graph
 *              with N nodes and adds random edges to the graph. Performs a depth-first
 *              traversal of the graph and prints the neighbour list for each node. Uses the
 *              graph module to create and manipulate the graph.
 *
 * Author: 		  Bran Mjöberg Quanne
 *
 * Date: 		    2025-01-12
 */

void depth_first(int node, Graph *graph, bool *visited);
void print_neighbour_list(Graph *graph);
void add_random_edges(Graph *graph);

/*
 * Description: Main function for the program. Creates a graph, adds random
 *              edges to the graph, performs a depth-first traversal of the graph, prints the
 *              neighbour list for each node, and destroys the graph.
 *
 * Input: 		  None.
 *
 * Output: 		  0 if the program runs successfully.
 */
int main(void) {
  srand(time(NULL));

  int graph_size = 10;
  Graph *graph = create_graph(graph_size);

  add_random_edges(graph);

  bool visited[no_of_nodes(graph)];
  for (int i = 0; i < no_of_nodes(graph); i++) {
    visited[i] = false;
  }

  printf("Depth-first traversal from node 0:\n");
  depth_first(0, graph, visited);
  printf("\n");

  printf("Neighbour list for each node:\n");
  print_neighbour_list(graph);

  destroy_graph(graph);

  return 0;
}

/*
 * Description: Add random edges to the graph.
 *
 * Input: 		  A pointer to the graph.
 *
 * Output: 		  None.
 */
void add_random_edges(Graph *graph) {
  for (int i = 0; i < no_of_nodes(graph); i++) {
    for (int j = i + 1; j < no_of_nodes(graph); j++) {
      if (rand() % 2) {
        insert_edge(graph, i, j);
      }
    }
  }
}

/*
 * Description: Perform a depth-first traversal of the graph. The depth-first traversal will not include any disconnected nodes.
 *
 * Input: 		  The current node, a pointer to the graph, and an array
 *              of visited nodes.
 *
 * Output: 		  None.
 */
void depth_first(int node, Graph *graph, bool *visited) {
  visited[node] = true;
  printf("%d", node);

  Graph *neighbour_set = neighbours(graph, node);
  int *neighbour_nodes = set_get_values(neighbour_set->nodes);

  for (int i = 0; i < no_of_nodes(graph); i++) {
    if (set_member_of(i, neighbour_set->nodes)) {
      if (!visited[i]) {
        printf(" -> ");
        depth_first(i, graph, visited);
      }
    }
  }

  free(neighbour_nodes);
  destroy_graph(neighbour_set);
}

/*
 * Description: Print the neighbour list for each node in the graph.
 *
 * Input: 		  A pointer to the graph.
 *
 * Output: 		  None.
 */
void print_neighbour_list(Graph *graph) {
  for (int i = 0; i < no_of_nodes(graph); i++) {
    printf("%d: ", i);

    Graph *neighbour_set = neighbours(graph, i);
    int *neighbour_nodes = set_get_values(neighbour_set->nodes);
    int neighbour_count = no_of_nodes(neighbour_set);

    for (int j = 0; j < neighbour_count; j++) {
      printf("%d ", neighbour_nodes[j]);
    }
    printf("\n");

    free(neighbour_nodes);
    destroy_graph(neighbour_set);
  }
}
