#include "graph.h"
#include "set.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10 // Number of nodes in the graph

/*
 * File: 		graph-test.c
 *
 * Description: Test program for the graph module. Creates an undirected graph with N nodes and adds random edges to the graph.
 *              Performs a depth-first traversal of the graph and prints the neighbour list for each node.
 * 				Uses the graph module to create and manipulate the graph.
 *
 * Author: 		Bran Mjöberg Quanne
 *
 * Date: 		2024-12-27
 */

void depth_first(int node, Graph *graph, bool *visited);
void print_neighbour_list(Graph *graph);
void add_random_edges(Graph *graph);

/*
 * Description: Main function for the program. Creates a graph, adds random edges to the graph,
 * 				performs a depth-first traversal of the graph, prints the neighbour list for each node,
 * 				and destroys the graph.
 *
 * Input: 		None.
 *
 * Output: 		0 if the program runs successfully.
 */
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

/*
 * Description: Add random edges to the graph.
 *
 * Input: 		A pointer to the graph.
 *
 * Output: 		None.
 */
void add_random_edges(Graph *graph)
{
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i != j && rand() % 10 == 0) {
                insert_edge(graph, i, j);
            }
        }
    }
}

/*
 * Description: Perform a depth-first traversal of the graph.
 *
 * Input: 		The current node, a pointer to the graph, and an array of visited nodes.
 *
 * Output: 		None.
 */
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

/*
 * Description: Print the neighbour list for each node in the graph.
 *
 * Input: 		A pointer to the graph.
 *
 * Output: 		None.
 */
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