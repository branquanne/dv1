#include "list.h"
#include <stdlib.h>
#include <string.h>

/*
 * Description:   This file handles the definitions of the functions used to
 * create, manipulate and destroy a list.
 *
 * Author:        Bran Mjöberg Quanne
 * Date:          2024-11-15
 */

/*
 * Description:   This function takes a constant character pointer as input,
 *                calculates its length, allocates memory for a new string of
 *                the same length plus one for the null terminator, and copies
 *                the input string to the newly allocated memory.
 *
 * Input:         The input string to be cloned.
 *
 * Output:        A pointer to the newly allocated string which is a clone of
 *                the input string.
 */

static char *clone_string(const char *in)
{
    size_t len = strlen(in);
    char *out = calloc(len + 1, sizeof(char));

    strncpy(out, in, len);

    return out;
}

/*
 * Description:   This function allocates memory for a new node, initializes its
 *                `next` and `prev` pointers to NULL, and sets its `value` to a
 *                clone of the provided string.
 *
 * Input:         The string value to be stored in the new node.
 *
 * Output:        A pointer to the newly created node.
 */
static struct node *make_node(const char *value)
{
    struct node *n = malloc(sizeof(struct node));
    n->next = NULL;
    n->prev = NULL;
    n->value = clone_string(value);

    return n;
}

List *list_create(void)
{
    List *lst = malloc(sizeof(List));
    lst->head.next = &lst->head;
    lst->head.prev = &lst->head;
    lst->head.value = NULL;
    return lst;
}

void list_destroy(List *lst)
{
    struct node *n = lst->head.next;
    while (n != &lst->head) {
        struct node *node = n->next;
        free(n->value);
        free(n);
        n = node;
    }
    free(lst);
}

bool list_is_empty(const List *lst)
{
    if (lst->head.next == &lst->head) {
        return true;
    }
    return false;
}

ListPos list_first(List *lst)
{
    ListPos pos = {.node = lst->head.next};

    return pos;
}

ListPos list_end(List *lst)
{
    ListPos pos = {.node = &lst->head};

    return pos;
}

bool list_pos_equal(ListPos p1, ListPos p2)
{
    if (p1.node == p2.node) {
        return true;
    }
    return false;
}

ListPos list_next(ListPos pos)
{
    pos.node = pos.node->next;
    return pos;
}

ListPos list_prev(ListPos pos)
{
    pos.node = pos.node->prev;
    return pos;
}

ListPos list_insert(ListPos pos, const char *value)
{
    // Create a new node.
    struct node *node = make_node(value);

    // Find nodes before and after (may be the same node: the head of the list).
    struct node *before = pos.node->prev;
    struct node *after = pos.node;

    // Link to node after.
    node->next = after;
    after->prev = node;

    // Link to node before.
    node->prev = before;
    before->next = node;

    // Return the position of the new element.
    pos.node = node;
    return pos;
}

ListPos list_remove(ListPos pos)
{
    struct node *before = pos.node->prev;
    struct node *after = pos.node->next;

    before->next = after;
    after->prev = before;

    free(pos.node->value);
    free(pos.node);

    pos.node = after;
    return pos;
}

const char *list_inspect(ListPos pos) { return pos.node->value; }
