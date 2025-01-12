#ifndef GRAPH_H
#define GRAPH_H
#include "set.h"
#include <stdbool.h>

// #define N 10 // Number of nodes in the graph

/**
 * @defgroup graph_h GRAPH_H
 *
 * @brief A module for creating and manipulating graphs.
 *
 * This module provides a graph data structure and functions for creating and
 * manipulating graphs. The module is used by the files graph.c and
 * graph-test.c.
 *
 * @author Bran Mjöberg Quanne
 *
 * @since 2025-01-12
 *
 * @{
 */

/**
 * @brief The type for the graph.
 *
 * The graph is represented by a set of nodes and a set of edges.
 */
typedef struct {
  set *nodes; /**< A pointer to the set of nodes. */
  set *edges; /**< A pointer to the set of edges. */
} Graph;

/**
 * @brief Create a new graph.
 *
 * This function creates a new graph with N (0, ..., N-1) nodes without any edges.
 *
 * @param None.
 *
 * @return A pointer to the new graph.
 *
 * @note The user is responsible for freeing the memory allocated by this
 * function. This can be done by calling destroy_graph().
 */
Graph *create_graph();

/**
 * @brief Get the neighbours of a node.
 *
 * This function returns a new graph containing the neighbours of a node in the
 * given graph.
 *
 * @param graph The graph.
 * @param node The node.
 *
 * @return A new graph containing the neighbours of the node.
 *
 * @note Usage may result in undefined behaviour if the graph does not exist.
 * @note The user is responsible for freeing the memory allocated by this
 * function. This can be done by calling destroy_graph().
 */
Graph *neighbours(const Graph *graph, int node);

/**
 * @brief Get the number of nodes in the graph.
 *
 * This function returns the number of nodes in the graph.
 *
 * @param graph The graph.
 *
 * @return The number of nodes in the graph.
 *
 * @note Usage may result in undefined behaviour if the graph does not exist.
 */
int no_of_nodes(const Graph *graph);

/**
 * @brief Destroy a graph.
 *
 * This function destroys a graph and frees the memory allocated for it.
 *
 * @param graph The graph.
 *
 * @note Usage may result in undefined behavior if the graph does not exist or
 * if the memory is already freed elsewhere.
 */
void destroy_graph(Graph *graph);

/**
 * @brief Insert a node into the graph.
 *
 * This function inserts a node into the graph.
 *
 * @param graph The graph.
 * @param node The node.
 *
 * @note Usage may result in undefined behavior if the graph does not exist or
 * if the node is already in the graph.
 */
void insert_node(Graph *graph, int node);

/**
 * @brief Insert an edge into the graph.
 *
 * This function inserts an edge into the graph.
 *
 * @param graph The graph.
 * @param node1 The first node.
 * @param node2 The second node.
 *
 * @note Usage may result in undefined behavior if the graph does not exist or
 * if the edge is already in the graph.
 */
void insert_edge(Graph *graph, int node1, int node2);
/**
 * @}
 */
#endif
