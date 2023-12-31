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

void k_sum_unsorted(struct Array * arr, int k){
    for(int i=0; i<arr->length-1;i++){
        for(int j=i+1;j<arr->length;j++){
            if(arr->A[i]+arr->A[j] == k){
                printf("%d + %d = %d\n", arr->A[i], arr->A[j], k);
            }
        }
    }
}

void k_sum_unsorted_hash(struct Array * arr, int k){
    int m = max(arr);
    int * H = (int *)malloc(m*sizeof(int));
    for(int i=0; i<m; i++){
        H[i] = 0;
    }
    for(int i=0;i<arr->length;i++){
        H[arr->A[i]]++;
    }
    for(int i=0; i<arr->length;i++){
        if(H[k-arr->A[i]]!=0 && k-arr->A[i] >= 0){
            printf("%d + %d = %d\n", arr->A[i], k-arr->A[i], k);
            arr->A[i] = -1;
        }
    }
}

void k_sum_sorted(struct Array * arr, int k){
    int i=0, j=arr->length-1;
    while(i<j){
        if(arr->A[i]+arr->A[j] == k){
            printf("%d + %d = %d\n", arr->A[i], arr->A[j], k);
            i++;
            j--;
        } else if(arr->A[i]+arr->A[j] < k){
            i++;
        } else {
            j--;
        }
    }
}

int main() {
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

    int k = 10;

    return 0;
}