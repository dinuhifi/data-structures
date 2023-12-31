#include <iostream>
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
        void fill_values();
        int max();
        void find_duplicates_sorted();
        void find_duplicates_sorted_hashtable();
        void find_duplicates_unsorted();
        void find_duplicates_unsorted_hashtable();
};

void Array::display(){
    printf("Elements are: ");
    for(int i=0; i<length; i++){
        printf("%d ", A[i]);
    }
    printf("\n");
}

void Array::fill_values(){
    cout << "Enter number of elements: ";
    cin >> length;
    cout << "Enter elements: ";
    for(int i=0; i<length; i++){
        cin >> A[i];
    }
}

int Array::max(){
    int max = A[0];
    for(int i=1; i<length; i++){
        if(A[i] > max) max = A[i];
    }
    return max;
}

// Hashtable method gives a sorted resultant array.
// Hashtable takes up lot of space but is efficient in terms of time complexity.
// Hashtable can be used for searching algorithms like this.

// Works only for sorted array

void Array::find_duplicates_sorted(){
    int last = 0;
    int count=0;
    for(int i=0;i<length-1;i++){
        if(A[i] == A[i+1]){
            count=i+1;
            if(A[i] != last){
                printf("Duplicate element is: %d\n", A[i]);
                last = A[i];
            }
            while(A[i] == A[count]) count++;
            printf("%d is appearing %d times\n", A[i], count-i);
            i = count-1;
        }
    }
}

void Array::find_duplicates_sorted_hashtable(){
    int H[A[length-1]];
    for(int i=0; i<A[length-1]; i++){
        H[i] = 0;
    }
    for(int i=0;i<length;i++){
        H[A[i]]++;
    }
    for(int i=0; i<A[length-1]; i++){
        if(H[i] > 1) printf("%d is duplicate element and is appearing %d times\n", i, H[i]);
    }
}

// Works for unsorted array

void Array::find_duplicates_unsorted(){
    int count = 1;
    for(int i=0;i<length-1;i++){
        count = 1;
        if(A[i] != -1){
            for(int j=i+1;j<length;j++){
                if(A[i]==A[j]){
                    count++;
                    A[j] = -1;
                }
            }
            if(count > 1) printf("%d is a duplicate and is appearing %d times\n", A[i], count);
        }
    }
}

void Array::find_duplicates_unsorted_hashtable(){
    int m = max();
    int * H = new int[m];
    for(int i=0; i<m; i++){
        H[i] = 0;
    }
    for(int i=0; i< length; i++){
        H[A[i]]++;
    }
    for(int i=0; i<m; i++){
        if(H[i] > 1) printf("%d is a duplicate and is appearing %d times\n", i, H[i]);
    }
}

int main() {
    int sz;
    printf("Enter size of array: ");
    scanf("%d", &sz);
    Array arr(sz);
    arr.fill_values();
    arr.display();

    return 0;
}