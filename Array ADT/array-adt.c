#include <stdio.h>
#include <stdlib.h>

struct Array {
    int A[100];
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

int is_sorted(struct Array * arr){
    if(check_underflow(arr)==1){
        for(int i=0; i<arr->length-1; i++){
            if(arr->A[i] > arr->A[i+1]) return 0;
        }
        return 1;
    }
    else {
        return -1;
    }
}

void display(struct Array arr){
    printf("The elements are: ");
    for (int i = 0; i < arr.length; i++) printf("%d ", arr.A[i]);
    printf("\n");
}

void append(struct Array * arr, int x){
    if(check_overflow(arr) == 1){
        arr->A[arr->length] = x;
        arr->length++;
    }
    else printf("Array is full\n");
    display(*arr);
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
    display(*arr);
}

void delete(struct Array * arr, int index){
    if(check_underflow(arr) == 1){
        if(index <= arr->length && index >=0){
            for(int i=index; i<arr->length-1; i++) arr->A[i] = arr->A[i+1];
            arr->length--;
        }
        else printf("Invalid index\n");
    }
    else printf("Array is empty\n");
    display(*arr);
}

void linear_search(struct Array * arr, int key){
    if(check_underflow(arr) == 1){
        for(int i=0; i<arr->length; i++){
            if(arr->A[i] == key){
                printf("Element found at index %d\n", i);
                return;
            }
    }
    printf("Element not found\n");
    }
    else printf("Array is empty\n");
}

void binary_search(struct Array * arr, int key){
    if(check_underflow(arr)==1){
        if(is_sorted(arr)==1){
            int l=0, h=arr->length-1, mid;
            while(l<=h){
                mid = (l+h)/2;
                if(arr->A[mid] == key){
                    printf("element found at index %d\n", mid);
                    return;
                }
                else if(arr->A[mid] < key) l = mid+1;
                else h = mid-1;
            }
            printf("Element not found\n");
        }
        else printf("Array is not sorted\n");
    }
    else printf("Array is empty\n");
}

void get(struct Array * arr, int index){
    if(check_underflow(arr) == 1){
        if(index < arr->length && index >=0) printf("%d\n", arr->A[index]);
        else printf("Invalid index\n");
    }
    else printf("Array is empty\n");
}

void set(struct Array * arr, int index, int x){
    if(check_underflow(arr) == 1){
        if(index < arr->length && index >=0) arr->A[index] = x;
        else printf("Invalid index\n");
    }
    else printf("Array is empty\n");
    display(*arr);
}

void max_min(struct Array * arr){
    if(check_underflow(arr)==1){
        int max,min = arr->A[0];
        for(int i=1; i<arr->length; i++){
            if(arr->A[i] > max) max = arr->A[i];
            else if(arr->A[i] < min) min = arr->A[i];
        }
        printf("Max element is %d\n", max);
        printf("Min element is %d\n", min);
    }
    else printf("Array is empty\n");
}

void sum(struct Array * arr){
    if(check_underflow(arr)==1){
        int total = 0;
        for(int i=0; i<arr->length; i++) total+=arr->A[i];
        printf("Sum of all elements is %d\n", total);
    }
    else printf("Array is empty\n");
}

void avg(struct Array * arr){
    if(check_underflow(arr)==1){
        float total = 0;
        for(int i=0; i<arr->length; i++) total+=arr->A[i];
        total = total/arr->length;
        printf("Avg of all elements is %.2f\n", total);
    }
    else printf("Array is empty\n");
}

void reverse(struct Array * arr){
    if(check_underflow(arr)==1){
        int temp;
        for(int i=0,j=arr->length-1; i<j; i++,j--){
            temp = arr->A[i];
            arr->A[i] = arr->A[j];
            arr->A[j] = temp;
        }
    }
    else printf("Array is empty\n");
    display(*arr);
} 

void left_shift(struct Array * arr){
    if(check_underflow(arr)==1){
        for(int i=0;i<arr->length-1;i++) arr->A[i] = arr->A[i+1];
        arr->A[arr->length-1] = 0; 
    }
    else printf("Array is empty\n");
    display(*arr);
}

void right_shift(struct Array * arr){
    if(check_underflow(arr)==1){
        for(int i=arr->length-1;i>0;i--) arr->A[i] = arr->A[i-1];
        arr->A[0] = 0; 
    }
    else printf("Array is empty\n");
    display(*arr);
}

void left_rotation(struct Array * arr){
    if(check_underflow(arr)==1){
        int temp = arr->A[0];
        for(int i=0; i<arr->length-1; i++) arr->A[i] = arr->A[i+1];
        arr->A[arr->length-1] = temp;
    }
    else printf("Array is empty\n");
    display(*arr);
}

void right_rotation(struct Array * arr){
    if(check_underflow(arr)==1){
        int temp = arr->A[arr->length-1];
        for(int i=arr->length-1; i>0; i--) arr->A[i] = arr->A[i-1];
        arr->A[0] = temp;
    }
    else printf("Array is empty\n");
    display(*arr);
}

void sorted_insert(struct Array * arr, int x){
    if(check_overflow(arr)==1){
        if(is_sorted(arr)==1){
            int i = arr->length-1;
            while(arr->A[i] > x){
                arr->A[i+1] = arr->A[i];
                i--;
            }
            arr->A[i+1] = x;
            arr->length++;
        }
        else printf("Array is not sorted\n");
    }
    else printf("Array is full\n");
    display(*arr);
}

struct Array * merge(struct Array * arr1, struct Array * arr2){
    struct Array * arr3=(struct Array *)malloc(sizeof(struct Array));
    int i,j,k=0;
    while(i<arr1->length && j<arr2->length){
        if(arr1->A[i] < arr2->A[j]){ arr3->A[k] = arr1->A[i]; k++; i++;}
        else {arr3->A[k] = arr2->A[j]; k++; j++;}
    }
    for(;i<arr1->length;i++) arr3->A[k++] = arr1->A[i];
    for(;j<arr2->length;j++) arr3->A[k++] = arr2->A[j];
    arr3->length = arr1->length + arr2->length;
    arr3->size = arr1->size + arr2->size;
    return arr3;
}

int main() {
    struct Array arr1;
    int n;
    printf("Enter size of Array: ");
    scanf("%d", &arr1.size);
    arr1.length = 0;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter the elements: ");
    for (int i = 0; i < n; i++) scanf("%d", &arr1.A[i]);
    arr1.length = n;
    
    display(arr1);
    

    return 0;
}