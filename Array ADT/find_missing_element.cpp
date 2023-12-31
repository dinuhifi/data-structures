
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

class Array {
    private:
        int *A;
        int size;
        int length;
    public:
        Array() {
            size = 10;
            length = 0;
            A = new int[size];
        }
        Array(int sz) {
            length = 0;
            A = new int[sz];
        }
        ~Array() {
            delete []A;
        }
        void fill_values();
        void display();
        int max();
        void find_one_missing_sorted();
        void find_many_missing_sorted();
        void find_missing_hashtable();
};

void Array::fill_values(){
    cout << "Enter number of elements: ";
    cin >> length;
    cout << "Enter elements: ";
    for(int i=0; i<length; i++){
        cin >> A[i];
    }
}

void Array::display(){
    cout << "Elements are: ";
    for(int i=0; i<length; i++){
        cout << A[i] << " ";
    }
    cout << endl;
}

int Array::max(){
    int max = A[0];
    for(int i=1; i<length; i++){
        if(A[i] > max) max = A[i];
    }
    return max;
}

// Works only for sorted array

void Array::find_one_missing_sorted(){
    int diff = A[0];
    int diff1 = 0;
    for(int i=0; i<length-1;i++){
        diff1 = A[i] - i;
        if(diff1 != diff){
            cout << "Missing element is: " << i+diff << endl;
            break;
        }
    }
}

void Array::find_many_missing_sorted(){
    int diff = A[0];
    int diff1 = 0;
    for(int i=0; i<length-1;i++){
        diff1 = A[i] - i;
        if(diff1 != diff){
            while(diff<diff1){
                cout << "Missing element is: " << i+diff << endl;
                diff++;
            }
        }
    }
}

// Works for both sorted and unsorted array

void Array::find_missing_hashtable(){
    int m = max();
    int * H = new int[m];
    for(int i=0; i<m; i++){
        H[i] = 0;
    }
    for(int i=0;i<length;i++){
        H[A[i]] += 1;
    }
    for(int i=1; i<m; i++){
        if(H[i] == 0){
            cout << "Missing element is: " << i << endl;
        }
    }
}

int main(){
    int n,sz;
    cout << "Enter size of array: ";
    cin >> sz;
    Array arr(sz);
    arr.fill_values();
    arr.display();
    arr.find_one_missing_sorted();
    cout << endl;
    arr.find_many_missing_sorted();
    cout << endl;
    arr.find_missing_hashtable();
    cout << endl;

    return 0;
}