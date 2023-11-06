#include <stdio.h>
#include "functions.h"

int main()
{
    t_d_list *ptr_to_t_d_list; // set a pointer [ptr_to_t_d_list] to a type [t_d_list]
    ptr_to_t_d_list = Empty_level_list(5); // set the pointer [ptr_to_t_d_list] to a empty level list which has a height (= max_level) of 5
    Insert_cell(ptr_to_t_d_list, 91, 3); // insert the cell containing value : 91 and 3 levels
    Insert_cell(ptr_to_t_d_list, 59, 1); // insert the cell containing value : 59 and 1 levels
    Insert_cell(ptr_to_t_d_list, 59, 5); // insert the cell containing value : 59 and 5 levels
    Insert_cell(ptr_to_t_d_list, 56, 3); // insert the cell containing value : 56 and 3 levels
    Insert_cell(ptr_to_t_d_list, 32, 5); // insert the cell containing value : 32 and 5 levels
    Insert_cell(ptr_to_t_d_list, 31, 2); // insert the cell containing value : 31 and 2 levels
    Insert_cell(ptr_to_t_d_list, 25, 1); // insert the cell containing value : 25 and 1 levels
    Insert_cell(ptr_to_t_d_list, 18, 4); // insert the cell containing value : 18 and 4 levels
    Display_level_list(ptr_to_t_d_list); // display the new level list
    return 0;
}
