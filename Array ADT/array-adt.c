#include <stdio.h>
#include <stdlib.h>

struct Array {
    int *A;
    int size;
    int length;
};

int check_overflow(struct Array * arr){
    if(arr->length == arr->size) return 0;
    else return 1;
}

int check_underflow(struct Array * arr){
    if(arr->length == 0) return 0;
    else return 1;
}

void display(struct Array * arr){
    printf("The elements are: ");
    for (int i = 0; i < arr->length; i++) printf("%d ", arr->A[i]);
    printf("\n");
}

void append(struct Array * arr, int x){
    if(check_overflow(arr) == 1){
        arr->A[arr->length] = x;
        arr->length++;
    }
    else printf("Array is full\n");
    display(arr);
}

void insert(struct Array * arr, int index, int x){
    if(check_overflow(arr) == 1) {
        if(index <= arr->length && index >= 0){
            for(int i=arr->length; i>index; i--) arr->A[i] = arr->A[i-1];
            arr->A[index] = x;
            arr->length++;
        }
        else printf("Invalid index\n");
    }
    else printf("Array is full\n");
    display(arr);
}

void delete(struct Array * arr, int index){
    if(check_underflow(arr) == 1){
        if(index < arr->length && index >=0){
            for(int i=index; i<arr->length-1; i++) arr->A[i] = arr->A[i+1];
            arr->length--;
        }
        else printf("Invalid index\n");
    }
    else printf("Array is empty\n");
    display(arr);
}

int main() {
    struct Array arr;
    int n;
    printf("Enter size of Array: ");
    scanf("%d", &arr.size);
    arr.A = (int *)malloc(arr.size * sizeof(int));
    arr.length = 0;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter the elements: ");
    for (int i = 0; i < n; i++) scanf("%d", &arr.A[i]);
    arr.length = n;
    
    display(&arr);
    append(&arr, 10);
    insert(&arr, 3, 20);
    delete(&arr, 1);
    printf("Length of array: %d\n", arr.length);

    return 0;
}