#ifndef VRAI_C_PROJECT_FUNCTIONS_H
#define VRAI_C_PROJECT_FUNCTIONS_H

#include <stdlib.h>

typedef struct s_d_cell
{
    int value; // initialize a variable name value of type int
    struct s_d_cell **next; // next is a double pointer, this means that it points to many others pointers which each of them point to a structure of type [s_d_cell] <=> [t_d_cell]
} t_d_cell;

typedef struct s_d_list
{
    int max_level; // initialize a variable name max_level of type int
    t_d_cell **head; // head is a double pointer, this means that it points to many others pointers which each of them point to structure of type [s_d_cell] <=> [t_d_cell]
} t_d_list;

t_d_cell *Create_cell(int value, int nb_levels); // Create cell function, it takes 2 parameters : the value of the new cell [new_cell] and the number of levels [nb_levels], it returns the address of the new cell

t_d_list *Empty_level_list(int max_level); // Create empty level list function, it takes 1 parameter : the number of levels [max_level] of the level list, it returns the address of the empty level list

void Display_level_list(t_d_list *my_t_d_list); // Display level list function, it displays the entire level list, it takes 1 parameter : the address of the level list [my_t_d_list]

void Insert_cell_at_head(t_d_list *my_t_d_list, int value, int level); // Insert a cell at the head of the level list, it takes 3 parameters : address of the level list, value of the new cell, number of level of the new cell

void Insert_cell(t_d_list *my_t_d_list, int value, int level); // Insert a new cell in the level list at each level [max_level] with it respect number of level [level] of the new cell

#endif //VRAI_C_PROJECT_FUNCTIONS_H
