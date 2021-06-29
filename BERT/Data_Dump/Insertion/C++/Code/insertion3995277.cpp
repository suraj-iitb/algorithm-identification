#include <iostream>
using namespace std;

void print(int n, int A[]){
    
    for(int i = 0; i < n; i++){
        cout << A[i] << (i != n-1 ? " " : "\n");
    }
    
}

void insert_sort(int n, int A[]){
    
    for(int i = 1; i < n; i++){
        int memory = A[i];
        int count = i;
        for(int j = i - 1; j >= 0; j--){
            if(memory < A[j]){
                A[j + 1] = A[j];
            }
            else{
                break;
            }
            count--;
        }
        A[count] = memory;
        print(n, A);
    }
    
}

int main(void){
    
    int n, A[100] = {};
    cin >> n;
    
    for(int i = 0; i < n; i++){
        cin >> A[i];
    }
    
    print(n, A);
    insert_sort(n, A);
    
    
}

