#include "graph.h"
#include "set.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10 // Number of nodes in the graph

void depth_first(int node, Graph *graph, bool *visited);
void print_neighbour_list(Graph *graph);
void add_random_edges(Graph *graph);

int main(void)
{
    // Seed the random number generator
    srand(time(NULL));

    // Create a graph with N nodes
    Graph *graph = create_graph();

    // Add random edges to the graph
    add_random_edges(graph);

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

void add_random_edges(Graph *graph)
{
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i != j && rand() % 10 == 0) {
                insert_edge(graph, i, j);
            }
        }
    }
    // insert_edge(graph, 0, 1);
    // insert_edge(graph, 0, 2);
    // insert_edge(graph, 0, 3);
    // insert_edge(graph, 1, 4);
    // insert_edge(graph, 1, 5);
    // insert_edge(graph, 2, 6);
    // insert_edge(graph, 2, 7);
    // insert_edge(graph, 3, 8);
    // insert_edge(graph, 3, 9);
    // insert_edge(graph, 8, 5);
}

void depth_first(int node, Graph *graph, bool *visited)
{
    // Mark the node as visited and print it
    visited[node] = true;
    printf("%d", node);

    // Get the neighbours of the node
    Graph *neighbour_set = neighbours(graph, node);
    int *neighbour_nodes = set_get_values(neighbour_set->nodes);
    int neighbour_count = num_nodes(neighbour_set);

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
        int neighbour_count = num_nodes(neighbour_set);

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