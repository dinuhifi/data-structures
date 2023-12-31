#include<iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

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
        void display();
        int max();
        void fill_values();
        void k_sum_unsorted(int k);
        void k_sum_unsorted_hash(int k);
        void k_sum_sorted(int k);
};

void Array::display(){
    printf("Elements are: ");
    for(int i=0; i<length; i++){
        printf("%d ", A[i]);
    }
    printf("\n");
}

int Array::max(){
    int max = A[0];
    for(int i=1; i<length; i++){
        if(A[i] > max) max = A[i];
    }
    return max;
}

void Array::fill_values(){
    cout << "Enter number of elements: ";
    cin >> length;
    cout << "Enter elements: ";
    for(int i=0; i<length; i++){
        cin >> A[i];
    }
}

void Array::k_sum_unsorted(int k){
    for(int i=0; i<length-1;i++){
        for(int j=i+1;j<length;j++){
            if(A[i]+A[j] == k){
                printf("%d + %d = %d\n", A[i], A[j], k);
            }
        }
    }
}

void Array::k_sum_unsorted_hash(int k){
    int m = max();
    int * H = new int[m];
    for(int i=0; i<m; i++){
        H[i] = 0;
    }
    for(int i=0;i<length;i++){
        H[A[i]]++;
    }
    for(int i=0; i<length;i++){
        if(H[k-A[i]]!=0 && k-A[i] >= 0){
            printf("%d + %d = %d\n", A[i], k-A[i], k);
            A[i] = -1;
        }
    }
}

void Array::k_sum_sorted(int k){
    int i=0, j=length-1;
    while(i<j){
        if(A[i]+A[j] == k){
            printf("%d + %d = %d\n", A[i], A[j], k);
            i++;
            j--;
        } else if(A[i]+A[j] < k){
            i++;
        } else {
            j--;
        }
    }
}

int main() {
    int sz;
    printf("Enter size of Array: ");
    scanf("%d", &sz);
    Array arr(sz);
    arr.fill_values();
    arr.display();

    int k = 10;

    return 0;
}