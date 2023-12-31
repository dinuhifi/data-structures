#include <stdio.h>
#include <stdlib.h>

struct Array {
    int *A;
    int size;
    int length;
};

void display(struct Array * arr){
    printf("Elements are: ");
    for(int i=0; i<arr->length; i++){
        printf("%d ", arr->A[i]);
    }
    printf("\n");
}

int max(struct Array * arr){
    int max = arr->A[0];
    for(int i=1; i<arr->length; i++){
        if(arr->A[i] > max) max = arr->A[i];
    }
    return max;
}

// Works only for sorted array

void find_one_missing_sorted(struct Array * arr){
    int diff = arr->A[0];
    int diff1 = 0;
    for(int i=0; i<arr->length-1;i++){
        diff1 = arr->A[i] - i;
        if(diff1 != diff){
            printf("Missing element is: %d\n", i+diff);
            break;
        }
    }
}

void find_many_missing_sorted(struct Array * arr){
    int diff = arr->A[0];
    int diff1 = 0;
    for(int i=0; i<arr->length-1;i++){
        diff1 = arr->A[i] - i;
        if(diff1 != diff){
            while(diff<diff1){
                printf("Missing element is: %d\n", i+diff);
                diff++;
            }
        }
    }
}

// Works for both sorted and unsorted array

void find_missing_hashtable(struct Array * arr){
    int m = max(arr);
    int * H = (int *)malloc(m*sizeof(int));
    for(int i=0; i<m; i++){
        H[i] = 0;
    }
    for(int i=0;i<arr->length;i++){
        H[arr->A[i]] += 1;
    }
    for(int i=1; i<m; i++){
        if(H[i] == 0){
            printf("Missing element is: %d\n", i);
        }
    }
}

int main(){
    struct Array arr;
    int n;
    printf("Enter size of Array: ");
    scanf("%d", &arr.size);
    arr.A = (int *)malloc(arr.size*sizeof(int));

    printf("Enter number of elements: ");
    scanf("%d", &arr.length);
    for(int i=0; i<arr.length; i++){
        printf("Enter element %d: ", i+1);
        scanf("%d", &arr.A[i]);
    }
    display(&arr);
    find_one_missing_sorted(&arr);
    printf("\n");
    find_many_missing_sorted(&arr);
    printf("\n");
    find_missing_hashtable(&arr);
    printf("\n");

    return 0;
}