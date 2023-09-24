#include "sort.h"

/**
 * cocktail_sort_list - Sorts a doubly linked list of integers in ascending
 *                      order using the Cocktail Shaker sort algorithm.
 *
 * @list: A pointer to a pointer to the head of the list.
 */
void cocktail_sort_list(listint_t **list)
{
    int swapped = 1;
    listint_t *current;
    listint_t *start = NULL;
    listint_t *end = NULL;

    if (list == NULL || *list == NULL || (*list)->next == NULL)
        return;

    while (swapped)
    {
        swapped = 0;

        for (current = start; current && current->next != end; current = current->next)
        {
            if (current->n > current->next->n)
            {
                swap_nodes(list, &current, &current->next);
                swapped = 1;
                print_list(*list); 
            }
        }

        if (!swapped)
            break;

        end = current;

        swapped = 0;

        for (current = end; current && current->prev != start; current = current->prev)
        {
            if (current->n < current->prev->n)
            {
                swap_nodes(list, &current, &current->prev);
                swapped = 1;
                print_list(*list); 
            }
        }

        start = current;

        if (!swapped)
            break;

        print_list(*list); 
    }
}

/**
 * swap_nodes - Swaps two nodes in a doubly linked list.
 *
 * @list: A pointer to a pointer to the head of the list.
 * @node1: A pointer to the first node to swap.
 * @node2: A pointer to the second node to swap.
 */
void swap_nodes(listint_t **list, listint_t **node1, listint_t **node2)
{
    listint_t *temp1 = *node1;
    listint_t *temp2 = *node2;

    if (temp1->prev != NULL)
        temp1->prev->next = temp2;
    else
        *list = temp2;

    if (temp2->next != NULL)
        temp2->next->prev = temp1;

    temp1->next = temp2->next;
    temp2->prev = temp1->prev;
    temp1->prev = temp2;
    temp2->next = temp1;
}

