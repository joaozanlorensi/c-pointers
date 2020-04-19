/* 
    Author: Joao Pedro Zanlorensi Cardoso
    References:
                - http://wiki.inf.ufpr.br/maziero/doku.php?id=prog2:ponteiros_para_funcoes
                - http://wiki.inf.ufpr.br/maziero/doku.php?id=prog2:ponteiros
                - https://beginnersbook.com/2014/01/c-passing-pointers-to-functions/    
*/

#include <stdio.h>
#include <stdlib.h>

void pointer_to_pointer();
void pointer_arithmetics();
void change_variable_value_using_pointer(int *variable, int complement);
void pass_array_by_reference_using_pointer(int *array, int array_len);
void square(float *number);
void apply_func_to_array(float *array, int array_lenght, void (*function)(float *number));

// just uncomment what you would like to study in the main function!
int main()
{
    // pointers to pointers:
        pointer_to_pointer();

    // pointers arithmetics:
        // pointer_arithmetics();

    // changing a variable's value using a pointer (passing variables by reference):
        // int variable = 5;
        // int addend = 0.5 * variable;
        // printf("original value of variable:     %d\n", variable);
        // printf("value_to_add: %d\n", addend);
        // change_variable_value_using_pointer(&variable, addend);
        // printf("value of variable after change:     %d\n", variable);

    // pass array by reference using pointer:
        // int array[] = {5, 10, 30, 120};
        // int array_len = sizeof(array)/sizeof(*array);
        // pass_array_by_reference_using_pointer(array, array_len); // this function changes the value of the last element in the array to 0
        // for (int i = 0; i < array_len; i++)
        // {
        //     printf("%d ", array[i]);
        // }
        // printf("\n");

    // pointer to function:
        // float array[] = {1.0, 2.0, 4.0, 8.0};
        // int array_len = sizeof(array)/sizeof(array[0]);
        // apply_func_to_array(array, array_len, square);
        // for (int i = 0; i < array_len; i++)
        // {
        //     printf("%.2f ", array[i]);
        // }
        // printf("\n");

    return 0;
}

void pointer_to_pointer()
{
    int int_var = 465;
    int *direct_pointer;
    int **indirect_pointer;

    direct_pointer = &int_var;
    indirect_pointer = &direct_pointer;

    printf("&int_var value: %p\n", &int_var);
    printf("&direct_pointer value: %p\n", &direct_pointer);
    printf("&indirect_pointer value: %p\n\n", &indirect_pointer);

    printf("int_var value: %d\n", int_var);
    printf("direct_pointer value: %p\n", direct_pointer);
    printf("indirect_pointer value: %p\n\n", indirect_pointer);

    printf("*direct_pointer value: %d\n", *direct_pointer);
    printf("*indirect_pointer value: %p\n\n", *indirect_pointer);

    printf("**indirect_pointer value: %d\n\n", **indirect_pointer);

    return;
}

void pointer_arithmetics()
{
    int array[3] = {1, 2, 3};
    int *pointer;
    int **indirect_pointer;

    pointer = array; // simply calling "array" returns the address of the first element of the array
    indirect_pointer = &pointer;
    printf("pointer value: %p\n", pointer);
    printf("*pointer value: %d\n", *pointer);
    printf("**indirect_pointer value: %d\n\n", **indirect_pointer);

    pointer++;

    printf("pointer value: %p\n", pointer);
    printf("*pointer value: %d\n", *pointer);
    printf("**indirect_pointer value: %d\n\n", **indirect_pointer);

    return;
}

void change_variable_value_using_pointer(int *variable, int complement)
{
    *variable += complement;
}

void pass_array_by_reference_using_pointer(int *array, int array_len)
{
    // this function modifies the array's last value to 0
    int last_element_value = 0;
    for (int i = 0; i < (array_len - 1); i++)
    {
        array++;
    }
    *array = last_element_value;
    return;
}

void square(float *number)
{
    (*number) *= (*number);
    return;
}

void apply_func_to_array(float *array, int array_lenght, void (*function)(float *number))
{
    for (int i = 0; i < array_lenght; i++)
    {
        function(array);
        array++;
    }
    return;
}