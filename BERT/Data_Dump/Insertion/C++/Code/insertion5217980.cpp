#include<iostream>
using namespace std;
#define N 100

void insertion_sort(int [], int);
void print_int_array(int [], int);

int main(){
    int i, n;
    int A[N] = { 0 };
    
    std::cin >> n;
    for(i=0;i<n;i++){
        std:cin >> A[i];
    }
    
    insertion_sort(A, n);
    
    return 0;
}


void insertion_sort(int A[], int n){
    int i, j, buf;
    
    for(i=1;i<n;i++){
        print_int_array(A, n);
        buf = A[i];
        j = i - 1;
        while(j >= 0 && buf < A[j]){
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = buf;
    }
    print_int_array(A, n);
    
}

void print_int_array(int A[], int n){
    for(int i=0;i<n-1;i++){
        std::cout << A[i] << " ";
    }
    std::cout << A[n-1] << std::endl;
}

