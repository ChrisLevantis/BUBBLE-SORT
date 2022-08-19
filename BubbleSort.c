#include <stdio.h>
#include <stdlib.h>

struct Array
{
    int size;
    int *arr;
    int elementsInserted; // για δικια μου βοηθεια...
};

struct Array *createArray(int newSize)
{
    struct Array *new_array = (struct Array*)malloc(sizeof(struct Array));
    new_array->size = newSize; 
    new_array->arr = (int*)malloc(sizeof(int) * new_array->size);

    return new_array;
}

void bubbleSort(struct Array *array)
{
    for(int i = 0;i < array->size - 1;i++) // το i ειναι για τις επαναληψεις...
    {
        int swap = 0;
        for(int j = 0;j < array->size - 1 - i;j++) // το j ειναι αυτο που παει με "ολα" και καθοριζει το ποσο θα παει απο το i...
        {
            if(array->arr[j] > array->arr[j + 1])
            {
                // Swap
                int temp = array->arr[j];
                array->arr[j] = array->arr[j+ 1];
                array->arr[j + 1] = temp;

                swap = 1;
            }
        }
        if(swap == 0) // είπαμε οτι το i ειναι μετρα τις επαναληψεις, αρα αμα το swap δεν γινει 1 τοτε σημαινει οτι ο αλγοριθμος πρεπει να τερματισει... 
        {
            break;
        }
    }
}

int pos = 0;
void insert(struct Array **array, int val)
{
    (*array)->arr[pos] = val;
    pos++;
    (*array)->elementsInserted++;
}

void printArray(struct Array *array)
{
    for(int i = 0 ;i < array->elementsInserted;i++)
    {
        printf("%d ", array->arr[i]);
    }
    printf("\n");
}

int main()
{   
    struct Array *array = createArray(8);

    insert(&array, 3);
    insert(&array, 89);
    insert(&array, 6);
    insert(&array, 556);
    insert(&array, 45);
    insert(&array, 12);
    insert(&array, 19996);
    insert(&array, 1);

    printf("Before Bubble Sort...\n");
    printArray(array);
    printf("\nAfter Bubble Sort...\n");
    bubbleSort(array);
    printArray(array);

    
}