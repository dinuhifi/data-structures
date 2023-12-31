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

// Hashtable method gives a sorted resultant array.
// Hashtable takes up lot of space but is efficient in terms of time complexity.
// Hashtable can be used for searching algorithms like this.

// Works only for sorted array

void find_duplicates_sorted(struct Array * arr){
    int last = 0;
    int count=0;
    for(int i=0;i<arr->length-1;i++){
        if(arr->A[i] == arr->A[i+1]){
            count=i+1;
            if(arr->A[i] != last){
                printf("Duplicate element is: %d\n", arr->A[i]);
                last = arr->A[i];
            }
            while(arr->A[i] == arr->A[count]) count++;
            printf("%d is appearing %d times\n", arr->A[i], count-i);
            i = count-1;
        }
    }
}

void find_duplicates_sorted_hashtable(struct Array * arr){
    int H[arr->A[arr->length-1]];
    for(int i=0; i<arr->A[arr->length-1]; i++){
        H[i] = 0;
    }
    for(int i=0;i<arr->length;i++){
        H[arr->A[i]]++;
    }
    for(int i=0; i<arr->A[arr->length-1]; i++){
        if(H[i] > 1) printf("%d is duplicate element and is appearing %d times\n", i, H[i]);
    }
}

// Works for unsorted array

void find_duplicates_unsorted(struct Array * arr){
    int count = 1;
    for(int i=0;i<arr->length-1;i++){
        count = 1;
        if(arr->A[i] != -1){
            for(int j=i+1;j<arr->length;j++){
                if(arr->A[i]==arr->A[j]){
                    count++;
                    arr->A[j] = -1;
                }
            }
            if(count > 1) printf("%d is a duplicate and is appearing %d times\n", arr->A[i], count);
        }
    }
}

void find_duplicates_unsorted_hashtable(struct Array * arr){
    int m = max(arr);
    int * H = (int *)malloc(m*sizeof(int));
    for(int i=0; i<m; i++){
        H[i] = 0;
    }
    for(int i=0; i< arr->length; i++){
        H[arr->A[i]]++;
    }
    for(int i=0; i<m; i++){
        if(H[i] > 1) printf("%d is a duplicate and is appearing %d times\n", i, H[i]);
    }
}

int main() {
    struct Array arr;
    printf("Enter size of array: ");
    scanf("%d", &arr.size);
    arr.A = (int *)malloc(arr.size * sizeof(int));

    printf("Enter number of elements: ");
    scanf("%d", &arr.length);
    for(int i=0; i<arr.length; i++){
        printf("Enter element %d: ", i+1);
        scanf("%d", &arr.A[i]);
    }

    display(&arr);

    return 0;
}