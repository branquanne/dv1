#include "graph.h"
#include "set.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10 // Number of nodes in the graph

void depth_first(int node, Graph *graph, bool *visited);
void print_neighbour_list(Graph *graph);

int main(void)
{
    // Seed the random number generator
    srand(time(NULL));

    // Create a graph with N nodes
    Graph *graph = create_graph();
    for (int i = 0; i < N; i++) {
        insert_node(graph, i);
    }

    // Add selected edges to the graph
    // insert_edge(graph, 0, 1);
    // insert_edge(graph, 0, 2);
    // insert_edge(graph, 0, 3);
    // insert_edge(graph, 0, 4);
    // insert_edge(graph, 0, 5);
    // insert_edge(graph, 0, 6);
    // insert_edge(graph, 0, 7);
    // insert_edge(graph, 0, 8);
    // insert_edge(graph, 0, 9);
    // insert_edge(graph, 1, 5);

    // Add random edges to the graph
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i != j && rand() % 3 == 0) {
                insert_edge(graph, i, j);
            }
        }
    }

    // Print the graph
    bool visited[N] = {false};
    printf("Depth-first traversal from node 0:\n");
    depth_first(0, graph, visited);
    printf("\n");

    // Print the neighbour list for each node
    printf("Neighbour list for each node:\n");
    print_neighbour_list(graph);

    // Destroy the graph
    destroy_graph(graph);

    return 0;
}

void depth_first(int node, Graph *graph, bool *visited)
{
    // Mark the node as visited and print it
    visited[node] = true;
    printf("%d", node);

    // Get the neighbours of the node
    Graph *neighbour_set = neighbours(graph, node);
    int *neighbour_nodes = set_get_values(neighbour_set->nodes);
    int neighbour_count = set_size(neighbour_set->nodes);

    // Recursively visit the neighbours
    for (int i = 0; i < neighbour_count; i++) {
        // Check if the neighbour is a member of the neighbour set and if it has not been visited
        if (set_member_of(neighbour_nodes[i], neighbour_set->nodes) && !visited[neighbour_nodes[i]]) {
            printf(" -> ");
            depth_first(neighbour_nodes[i], graph, visited);
        }
    }

    // Free the memory allocated for the neighbour set and the neighbour nodes
    free(neighbour_nodes);
    destroy_graph(neighbour_set);
}

void print_neighbour_list(Graph *graph)
{
    // Loop through all nodes in the graph
    for (int i = 0; i < N; i++) {
        printf("%d: ", i);

        // Get the neighbour set for the current node
        Graph *neighbour_set = neighbours(graph, i);
        int *neighbour_nodes = set_get_values(neighbour_set->nodes);
        int neighbour_count = set_size(neighbour_set->nodes);

        // Print the neighbour list for the current node
        for (int j = 0; j < neighbour_count; j++) {
            printf("%d ", neighbour_nodes[j]);
        }
        printf("\n");

        // Free the memory allocated for the neighbour set and the neighbour nodes
        free(neighbour_nodes);
        destroy_graph(neighbour_set);
    }
}