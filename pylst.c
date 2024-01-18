#include <stdio.h>
#include <stdlib.h>

// Define a structure for a node in the list
typedef struct lst_node
{
    char *data;
    int length;
    int alloc;
    struct lst_node *next;
} lst_node;

// Define a structure for the Python-style list
typedef struct pylist
{
    lst_node *head;
    lst_node *tail;
    int count;
} pylist;

// Function to create a new empty list
pylist *pylist_new();

// Function to append a string to the list
int pylist_append(pylist *self, const char *string);

// Function to print the list
void pylist_print(pylist *self);

// Function to delete the entire list
void pylist_del(pylist *self);

// Function to get the length of the list
int pylist_len(pylist *self);

// Function to find the index of a string in the list
int pylist_index(pylist *self, const char *string);

// Function to initialize a new list_node
lst_node *pystr_new();

int main()
{
    // Create a new empty list
    printf("\nCreate a new empty list.\n");
    pylist *lst = pylist_new();

    // Append string 'Hello World' to the list
    printf("\nAppend string 'Hello World' to the list.\n");
    pylist_append(lst, "Hello World");

    // Print the list
    printf("\nPrinting list.\n");
    pylist_print(lst);

    // Append string 'Second Entry' to the list
    printf("\nAppend string 'Second Entry' to the list.\n");
    pylist_append(lst, "Second Entry");

    // Print the list
    printf("\nPrinting list.\n");
    pylist_print(lst);

    // Append string 'Third Entry' to the list
    printf("\nAppend string 'Third Entry' to the list.\n");
    pylist_append(lst, "Third Entry");

    // Print the list
    printf("\nPrinting list.\n");
    pylist_print(lst);

    // Print the length of the list
    printf("\nPrinting length of list.\n");
    printf("Length = %d\n", pylist_len(lst));

    // Print the index value of 'Third Entry'. Index returns a '-1', if it does not exist.
    printf("\nPrinting index value of 'Third Entry'.\n");
    printf("'Third Entry' in List? Index = %d\n", pylist_index(lst, "Third Entry"));

    // Print the index value of 'Eeello World'. Index returns a '-1', if it does not exist.
    printf("\nPrinting index value of 'Eeello World'.\n");
    printf("'Eeello World' in List? Index = %d\n", pylist_index(lst, "Eeello World"));

    // Print the index value of 'Hello World'. Index returns a '-1', if it does not exist.
    printf("\nPrinting index value of 'Hello World'.\n");
    printf("'Hello World' in List? Index = %d\n", pylist_index(lst, "Hello World"));

    // Delete the entire list
    printf("\nDelete the entire list.\n");
    pylist_del(lst);

    // Print the length of the list after deletion

    // Print the list after deletion
    printf("\nPrinting list.\n");
    pylist_print(lst);

    return 0;
}

// Function to create a new empty list
pylist *pylist_new()
{
    pylist *new_list = (pylist *)malloc(sizeof(pylist));
    if (new_list == NULL)
    {
        printf("Not enough memory!");
        return NULL;
    }

    new_list->head = pystr_new();
    new_list->tail = new_list->head;
    new_list->count = 0;
    return new_list;
}

// Function to append a string to the list
int pylist_append(pylist *self, const char *string)
{
    if (string != NULL)
    {
        for (int i = 0; string[i] != '\0'; i++)
        {
            if (self->tail->length < (self->tail->alloc - 1))
            {
                // Move NULL character from array to the next position
                self->tail->data[self->tail->length + 1] = self->tail->data[self->tail->length];
                // Place the new character where the "NULL" character used to be
                self->tail->data[self->tail->length] = string[i];
                // Increment length of array
                self->tail->length++;
            }
            else
            {
                // If all positions are filled in the array, copy the array to a new array with "10" more spaces
                self->tail->data = (char *)realloc(self->tail->data, self->tail->alloc + 10);

                if (self->tail->data == NULL)
                {
                    printf("Not enough memory!");
                    pylist_del(self);
                    return -1; // Return an error indicator
                }
                self->tail->alloc += 10;
                // Move NULL character from array to the next position
                self->tail->data[self->tail->length + 1] = self->tail->data[self->tail->length];
                // Place the new character where the "NULL" character used to be
                self->tail->data[self->tail->length] = string[i];
                // Increment length of array
                self->tail->length++;
            }
        }
        self->count++;
        self->tail->next = pystr_new();
        self->tail = self->tail->next;
    }

    return 0;
}

// Function to delete the entire list
void pylist_del(pylist *self)
{
    lst_node *current, *next;
    current = self->head;
    while (current)
    {
        if (current->data != NULL)
        {
            free(current->data);
        }
        next = current->next;
        free(current);
        current = next;
    }
    self->head = NULL;
    self->tail = NULL;
    free(self);
}

// Function to print the list
void pylist_print(pylist *self)
{
    printf("[");
    lst_node *ptr = self->head;

    while (ptr)
    {
        if (ptr->data[0] != '\0')
        {
            printf("'%s'", ptr->data);
            if (ptr->next->length != 0)
            {
                printf(", ");
            }
        }

        ptr = ptr->next;
    }

    printf("]\n");
}

// Function to get the length of the list
int pylist_len(pylist *self)
{
    return self->count;
}

// Function to find the index of a string in the list
int pylist_index(pylist *self, const char *string)
{
    int index = 0;
    int is_present = -1;
    lst_node *ptr = self->head;

    while (ptr)
    {
        // Check if the current node is not NULL and has valid data
        if (ptr->data[0] != '\0' && ptr != NULL)
        {
            int i;

            // Iterate through the characters of both the input string and the list node's data
            for (i = 0; string[i] && ptr->data[i]; i++)
            {
                // If characters don't match, set is_present to -1 and break the loop
                if (string[i] != ptr->data[i])
                {
                    is_present = -1;
                    break;
                }
            }

            // If both strings match until the end, set is_present to the current index and break the loop
            if (string[i] == '\0' && ptr->data[i] == '\0')
            {
                is_present = index;
                break;
            }
        }

        // Move to the next node in the list
        ptr = ptr->next;
        index++;
    }

    return is_present;
}

// Initialize a new list_node
lst_node *pystr_new()
{
    lst_node *p = (lst_node *)malloc(sizeof(lst_node));

    // Check if memory allocation was successful
    if (p == NULL)
    {
        printf("Not enough memory!");
        return p;
    }

    // Initialize pystr members
    p->length = 0;
    p->alloc = 10;
    p->next = NULL;

    // Calloc adds a '\0' terminator at initialization, similar to writing "p->data[0] = '\0';"
    p->data = (char *)calloc(p->alloc, sizeof(char));

    // Check if memory allocation for data was successful
    if (p->data == NULL)
    {
        printf("Not enough memory!");
        free(p); // Free the allocated pystr structure
        p = NULL;
    }

    return p;
}