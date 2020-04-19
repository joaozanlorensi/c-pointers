#include <stdio.h>
#include <stdlib.h>

typedef struct custom_t{
    int data;
    struct custom_t *next;
} custom_t;
void make_second_next_equal_to_first(custom_t *first_element);
void append(custom_t *element, custom_t* my_list);
void print_list(custom_t* my_list);
void remove_list_element(custom_t *element, custom_t **my_list);

// Following the steps you will build a circular list
int main()
{
    // Step 1: working with custom_t in main and creating a reference between each element
    custom_t first_element;
    first_element.data = 23;

    custom_t second_element;
    second_element.data = 43;

    first_element.next = &second_element;

    // Let's check the addresses:
    printf("First element address: %p\nFirst element's next pointer: %p\nSecond element's address: %p\n\n", 
            &first_element, (first_element.next), &second_element);

    // Let's check the data:
    printf("First element data: %d\nFirst element's next data: %d\nSecond element's data: %d\n\n", 
            first_element.data, (first_element.next)->data, second_element.data);
    // Note that (*var).data equals (var)->data
    printf("First element data: %d\nFirst element's next data: %d\nSecond element's data: %d\n", 
            first_element.data, (*first_element.next).data, second_element.data);

    //
    printf("\n\n\n\n");
    //

    // Step 2: Call a function to make the second element's next variable equal to the first element
    make_second_next_equal_to_first(&first_element);
    
    printf("First element address: %p\nFirst element's next: %p\nSecond element's address: %p\nSecond element's next: %p\n\n", 
            &first_element, (first_element.next), &second_element, second_element.next);
    // Note that second_element.next equals (first_element.next)->next
    printf("First element address: %p\nFirst element's next: %p\nSecond element's address: %p\nSecond element's next: %p\n", 
            &first_element, (first_element.next), &second_element, (first_element.next)->next);

    //
    printf("\n\n\n\n");
    //

    // Step 3: adding a third element, then making the second element's next equal to the third element, and the third element's next equal to the first element
    custom_t third_element;

    third_element.data = 95;
    
    // Here we get to the list concept!
    custom_t* list;

    list = &first_element;

    append(&third_element, list);

    printf("First element address: %p\nFirst element's next: %p\nSecond element's address: %p\nSecond element's next:   %p\nThird element address: %p\nThird element's next: %p\n", 
    &first_element, (first_element.next), &second_element, second_element.next, &third_element, third_element.next);

    //
    printf("\n\n\n\n");
    //

    // Step 4: printing my list:
    
    print_list(list);

    //
    printf("\n\n\n\n");
    //

    // Step 5: removing an element:
    remove_list_element(&first_element, &list); // Now we use pointer to pointer because we want to modify a pointer's value by reference
    print_list(list);

    return 0;
}

void make_second_next_equal_to_first(custom_t *first_element){
    (first_element->next)->next = first_element;
    return;
}

void append(custom_t *element, custom_t *my_list){
    custom_t *aux = my_list;
    custom_t *first = my_list;
    while(aux->next != first){
        aux = aux->next;
    }
    element->next = first;
    aux->next = element;
    return;
}

void print_list(custom_t *my_list){
    custom_t *first = my_list;

    int counter = 1;
    do{
        printf("Element %d's data: %d\n", counter, my_list->data);
        my_list = my_list->next;
        counter++;
    }while(my_list != first);
    return;
}

void remove_list_element(custom_t *element, custom_t **my_list){
    while((*my_list)->next != element){
        (*my_list) = (*my_list)->next;
    }
    (*my_list)->next = element->next;

    return;
}