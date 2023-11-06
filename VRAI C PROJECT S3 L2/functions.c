#include "functions.h"
#include <stdio.h>

// Create Cell function
t_d_cell *Create_cell(int value, int nb_levels) // Create cell function, it takes 2 parameters : the value of the new cell [new_cell] and the number of levels [nb_levels], it returns the address of the new cell
{
    t_d_cell *new_cell = (t_d_cell*)malloc(sizeof(t_d_cell)); // Allocating memory for [t_d_cell] structure, assigning the address of this allocated memory block to the pointer variable [new_cell]
    if (new_cell == NULL) // Check if pointer [new_cell] points to the block of memory of size [t_d_cell]
    {
        printf("The memory allocation hasn't been done correctly\n"); // Error in the memory allocation of the [t_d_cell] structure
        return NULL;
    }
    new_cell->value = value; // Copy the new value in parameters to the value variable in the [t_d_cell] structure
    new_cell->next = (t_d_cell**)malloc(nb_levels*sizeof(t_d_cell*)); // Allocates a block a memory of size [t_d_cell*nb_levels] for storing pointers, assigning the address of this allocated memory block (dynamic array of pointers next) to the double pointer variable [next]
    if (new_cell->next == NULL) // Check if double pointer [next] points to the block of memory of size [nb_levels*t_d_cell]
    {
        printf("The memory allocation hasn't been done correctly\n"); // Error in the memory allocation of the dynamic array of pointers (next)
        return NULL;
    }
    for (int i = 0; i < nb_levels; i++) // iterate [nb_levels] times to allocate dynamically a block a memory of size cell [t_d_cell] for each level of the [t_d_cell]
    {
        new_cell->next[i] = (t_d_cell*)malloc(sizeof(t_d_cell)); // Allocating block memory of size [t_d_cell] for each pointers of the dynamic array [next]
    }
    for (int i = 0; i < nb_levels; i++) // iterate nb_levels time for setting up the different levels, here all levels of the [t_d_cell] must point to NULL
    {
        new_cell->next[i] = NULL; // initialize all cells at different level pointing to NULL
    }
    return (new_cell); // returns the address of the new cell
}

// Empty level list function
t_d_list *Empty_level_list(int max_level)  // Empty level list function, it takes 1 parameter : the [max_level] of the level list, it returns the address of the level list
{
    t_d_list *my_empty_level_list; // initialize a pointer [my_empty_level_list] to my_empty_level_list
    my_empty_level_list = (t_d_list*)malloc(sizeof(t_d_list)); // allocate a memory block of size [t_d_list]
    if (my_empty_level_list == NULL) // Check if pointer [my_empty_level_list] points to the block of memory of size [t_d_list]
    {
        printf("The memory allocation hasn't been done correctly\n"); // Error in the memory allocation of the [t_d_list]
        return NULL;
    }
    my_empty_level_list->max_level = max_level; // copy [max_level] in parameter to the new level list [t_d_list] [max_level]
    my_empty_level_list->head = (t_d_cell**)malloc(max_level*sizeof(t_d_cell*)); // Allocates a block a memory for storing pointers, assigning the address of this allocated memory block (dynamic array of pointers head) to the double pointer variable [head]
    if (my_empty_level_list->head == NULL) // Check if double pointer variable [head] points to the block of memory (dynamic array of pointers head)
    {
        printf("The memory allocation hasn't been done correctly\n"); // Error in the memory allocation of the [t_d_cell] structure
        return NULL;
    }
    for (int i = 0; i < max_level; i++) // iterate [max_levels] time for setting up the different levels of the [t_d_list], here all levels (heads) of the [t_d_list] must point to NULL
    {
        my_empty_level_list->head[i] = NULL; // initialize all heads pointing to NULL
    }
    return(my_empty_level_list); // return the address of the empty level list
}

// Display a level list function
void Display_level_list(t_d_list *my_t_d_list) // Display level list function, it takes 1 parameter : the address of the level list [my_t_d_list]
{
    if (my_t_d_list->max_level == 0) // Check if the level list is not created ?
    {
        printf("The level list is empty\n"); // Display it's impossible to display a none created level list
    }
    else
    {
        t_d_cell *temp_ptr; // Initialize a temporary pointer which points to [t_d_cell] structure
        for (int i = 0; i < my_t_d_list->max_level; i++)  // Iterate [max_level] times to print all the different levels of the [t_d_list]
        {
            temp_ptr = my_t_d_list->head[i]; // temporary pointer get the address of the first byte memory block allocated for [t_d_cell]
            printf("[list head_%d @-]--> ", i); // print the different level one by one starting from 0
            while (temp_ptr != NULL) // while the temporary pointer don't point to NULL on each level to display from head to tail
            {
                printf("[ %d|@-]-->", temp_ptr->value); // display the value of each cell on every level
                temp_ptr = temp_ptr->next[i]; // move the temporary pointer to it cell successor
            }
            printf("NULL\n"); // display the end of each level
        }
    }
    return;
}

// Insert a cell with levels at the beginning (head) of the list
void Insert_cell_at_head(t_d_list *my_t_d_list,int value, int level) // Insert cell at head function, it takes 3 parameters : the address of the level list [my_t_d_list], the value of the new cell and it levels
{
    if (my_t_d_list->max_level == 0) // Check if the level list is not created ?
    {
        printf("The insertion can't be done because the level list is not created\n"); // Display it's impossible to insert a cell in a none created level list
    }
    else
    {
        t_d_cell *new_cell; // Initialize a temporary pointer which points to [t_d_cell] structure
        new_cell = Create_cell(value, level); // the pointer [new_cell] points to the address of the new cell
        for (int i = 0; i < level; i++) // iterating [level] times to set each level of the level list and each level of the new cell
        {
            new_cell->next[i] = my_t_d_list->head[i]; // set each level of the new cell to point to it respect level of the level list
            my_t_d_list->head[i] = new_cell; // actualize the new head for each level of the level list respect to it level of the new cell
        }
    }
    return;
}

// Insert a cell with levels in the level list
void Insert_cell(t_d_list *my_t_d_list, int value, int level) // Insert a cell with levels in the level list, not necessary at head, it takes 3 parameters : the address of the level list [my_t_d_list], the value of the new cell and its number of levels
{
    if (my_t_d_list->max_level == 0) // Check if the level list is not created ?
    {
        printf("The insertion can't be done because the level list is not created\n"); // Display it's impossible to insert a cell in a none created level list
    }
    else // case non empty level list
    {
        t_d_cell *new_cell; // Initialize a temporary pointer which points to [t_d_cell] structure
        new_cell = Create_cell(value, level); // the pointer [new_cell] points to the address of the new cell
        for (int i = 0; i < level; i++) // iterating [level] times to set each level of the level list and each level of the new cell
        {
            // case empty level
            if (my_t_d_list->head[i] == NULL) // checks the head (= NULL) for each level of the level list according to the number of levels in the cell
            {
                my_t_d_list->head[i] = new_cell; // if yes, then add the new cell to the head of the level list which head is (= NULL)
            }
            else
            //non empty level
            {
                if (new_cell->value <= my_t_d_list->head[i]->value) // check if the value of the new cell is smaller or equal to the value of the first cell for each level of the level list according to the number of levels in the cell, one by one, thanks to the (for loop)
                {
                    new_cell->next[i] = my_t_d_list->head[i]; // point each level of the new cell to it respect level of the first cell which value of the first cell is greater or equal to the value of the new cell
                    my_t_d_list->head[i] = new_cell; // point each [heads] of the level list to it respect level of the new cell
                }
                else if (new_cell->value > my_t_d_list->head[i]->value) // if cell to insert is not at head (= middle or tail ?), check for each level of the level list according to the number of levels in the cell
                {
                    t_d_cell *temp_ptr, *prev_ptr; // Initialize 2 temporary pointers which point to [t_d_cell] structure
                    temp_ptr = my_t_d_list->head[i]; // [temp_ptr] points to the first cell of each level of the level list according to the number of levels in the cell
                    while (new_cell->value > temp_ptr->value && temp_ptr->next[i] != NULL) // if the value of the new cell is greater than the first value of the first cell of each level of the level list according to the number of levels in the cell, one by one, thanks to the (for loop), and the cell successor exist
                    {
                        prev_ptr = temp_ptr; // save the address of [temp_ptr]
                        temp_ptr = temp_ptr->next[i]; // move the temporary pointer [temp_ptr] to its cell successor
                    } // at the end of the day either temp arrive on the (last cell) or temp is (somewhere in the middle)
                    if (new_cell->value < temp_ptr->value) // case insertion is before the last cell
                    {
                        new_cell->next[i] = prev_ptr->next[i]; // point each level of the new cell to it respect level of the before last cell
                        prev_ptr->next[i] = new_cell; // point each level of the before last cell to it respect level of the new cell
                    }
                    else if (new_cell->value > temp_ptr->value) // case insert at the tail
                    {
                        new_cell->next[i] = temp_ptr->next[i]; // point each level of the new cell to it respect level of the last cell
                        temp_ptr->next[i] = new_cell; // point each level of the last cell to it respect level of the new cell
                    }
                    else // if the cell to insert is at the middle or somewhere else in the middle
                    {
                        if (new_cell->value == temp_ptr->value) // if the value of the new cell is equal to the value of the cell pointed by [temp_ptr]
                        {
                            new_cell->next[i] = prev_ptr->next[i]; // point each level of the new cell to it respect level of the previous cell [prev_ptr]
                            prev_ptr->next[i] = new_cell; // point each level of the previous cell to it respect level of the new cell
                        }
                    }
                }
            }
        }
    }
    return;
}