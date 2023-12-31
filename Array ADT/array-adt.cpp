#include <iostream>
using namespace std;
#include <stdio.h>
#include <stdlib.h>

class Array {
    private:
        int *A;
        int size;
        int length;
    public:
        Array(){
            size = 10;
            length = 0;
            A = new int[size];
        }
        Array(int sz){
            size = sz;
            length = 0;
            A = new int[size];
        }
        ~Array(){
            delete []A;
        }
    int check_overflow();
    int check_underflow();
    int is_sorted();
    void display();
    void append(int x);
    void insert(int index, int x);
    void Delete(int index);
    void linear_search(int key);
    void binary_search(int key);
    void get(int index);
    void set(int index, int x);
    void max_min();
    void sum();
    void avg();
    void reverse();
    void left_shift();
    void right_shift();
    void left_rotation();
    void right_rotation();
    void sorted_insert(int x);
    Array* merge(Array arr2);

};

int Array::check_overflow(){
    if(length == size) return 0;
    else return 1;
}

int Array::check_underflow(){
    if(length == 0) return 0;
    else return 1;
}

int Array::is_sorted(){
    if(check_underflow()==1){
        for(int i=0; i<length-1; i++){
            if(A[i] > A[i+1]) return 0;
        }
        return 1;
    }
    else {
        return -1;
    }
}

void Array::display(){
    printf("The elements are: ");
    for (int i = 0; i < length; i++) printf("%d ", A[i]);
    printf("\n");
}

void Array::append(int x){
    if(check_overflow() == 1){
        A[length] = x;
        length++;
    }
    else printf("Array is full\n");
    display();
}

void Array::insert(int index, int x){
    if(check_overflow() == 1) {
        if(index <= length && index >= 0){
            for(int i=length; i>index; i--) A[i] = A[i-1];
            A[index] = x;
            length++;
        }
        else printf("Invalid index\n");
    }
    else printf("Array is full\n");
    display();
}

void Array::Delete(int index){
    if(check_underflow() == 1){
        if(index <= length && index >=0){
            for(int i=index; i<length-1; i++) A[i] = A[i+1];
            length--;
        }
        else printf("Invalid index\n");
    }
    else printf("Array is empty\n");
    display();
}

void Array::linear_search(int key){
    if(check_underflow() == 1){
        for(int i=0; i<length; i++){
            if(A[i] == key){
                printf("Element found at index %d\n", i);
                return;
            }
    }
    printf("Element not found\n");
    }
    else printf("Array is empty\n");
}

void Array::binary_search(int key){
    if(check_underflow()==1){
        if(is_sorted()==1){
            int l=0, h=length-1, mid;
            while(l<=h){
                mid = (l+h)/2;
                if(A[mid] == key){
                    printf("element found at index %d\n", mid);
                    return;
                }
                else if(A[mid] < key) l = mid+1;
                else h = mid-1;
            }
            printf("Element not found\n");
        }
        else printf("Array is not sorted\n");
    }
    else printf("Array is empty\n");
}

void Array::get(int index){
    if(check_underflow() == 1){
        if(index < length && index >=0) printf("%d\n", A[index]);
        else printf("Invalid index\n");
    }
    else printf("Array is empty\n");
}

void Array::set(int index, int x){
    if(check_underflow() == 1){
        if(index < length && index >=0) A[index] = x;
        else printf("Invalid index\n");
    }
    else printf("Array is empty\n");
    display();
}

void Array::max_min(){
    if(check_underflow()==1){
        int max,min = A[0];
        for(int i=1; i<length; i++){
            if(A[i] > max) max = A[i];
            else if(A[i] < min) min = A[i];
        }
        printf("Max element is %d\n", max);
        printf("Min element is %d\n", min);
    }
    else printf("Array is empty\n");
}

void Array::sum(){
    if(check_underflow()==1){
        int total = 0;
        for(int i=0; i<length; i++) total+=A[i];
        printf("Sum of all elements is %d\n", total);
    }
    else printf("Array is empty\n");
}

void Array::avg(){
    if(check_underflow()==1){
        float total = 0;
        for(int i=0; i<length; i++) total+=A[i];
        total = total/length;
        printf("Avg of all elements is %.2f\n", total);
    }
    else printf("Array is empty\n");
}

void Array::reverse(){
    if(check_underflow()==1){
        int temp;
        for(int i=0,j=length-1; i<j; i++,j--){
            temp = A[i];
            A[i] = A[j];
            A[j] = temp;
        }
    }
    else printf("Array is empty\n");
    display();
} 

void Array::left_shift(){
    if(check_underflow()==1){
        for(int i=0;i<length-1;i++) A[i] = A[i+1];
        A[length-1] = 0; 
    }
    else printf("Array is empty\n");
    display();
}

void Array::right_shift(){
    if(check_underflow()==1){
        for(int i=length-1;i>0;i--) A[i] = A[i-1];
        A[0] = 0; 
    }
    else printf("Array is empty\n");
    display();
}

void Array::left_rotation(){
    if(check_underflow()==1){
        int temp = A[0];
        for(int i=0; i<length-1; i++) A[i] = A[i+1];
        A[length-1] = temp;
    }
    else printf("Array is empty\n");
    display();
}

void Array::right_rotation(){
    if(check_underflow()==1){
        int temp = A[length-1];
        for(int i=length-1; i>0; i--) A[i] = A[i-1];
        A[0] = temp;
    }
    else printf("Array is empty\n");
    display();
}

void Array::sorted_insert(int x){
    if(check_overflow()==1){
        if(is_sorted()==1){
            int i = length-1;
            while(A[i] > x){
                A[i+1] = A[i];
                i--;
            }
            A[i+1] = x;
            length++;
        }
        else printf("Array is not sorted\n");
    }
    else printf("Array is full\n");
    display();
}

Array* Array::merge(Array arr2){
    Array * arr3 = new Array(length+arr2.length);
    int i,j,k=0;
    while(i<length && j<arr2.length){
        if(A[i] < arr2.A[j]){ arr3->A[k] = A[i]; k++; i++;}
        else {arr3->A[k] = arr2.A[j]; k++; j++;}
    }
    for(;i<length;i++) arr3->A[k++] = A[i];
    for(;j<arr2.length;j++) arr3->A[k++] = arr2.A[j];
    arr3->length = length + arr2.length;
    return arr3;
}

int main() {
    Array *arr1;
    int n,sz;
    printf("Enter size of Array: ");
    scanf("%d", &sz);
    arr1 = new Array(sz);
    arr1->append(10);
    arr1->append(20);
    arr1->append(30);
    return 0;
}