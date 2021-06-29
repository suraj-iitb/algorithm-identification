#include <iostream>
#include <vector>
using namespace std;

int N;
vector<int> A(100);

void print(){
    for(int i = 0; i < N; i++){
        cout << A[i] << (i != N-1 ? " " : "\n");
    }
}

void insertion_Sort(){
    
    for(int i = 1; i < N; i++){
        
        print();
        
        int v = A[i];
        int sort_Already = i - 1;
        while(sort_Already >= 0 && A[sort_Already] > v){
            A[sort_Already + 1] = A[sort_Already];
            A[sort_Already] = v;
            sort_Already--;
        }
    }
    
    print();
}


int main(void){
    
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> A[i];
    }
    
    insertion_Sort();
    
}

