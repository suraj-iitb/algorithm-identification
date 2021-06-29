#include <iostream>
using namespace std;

void print(int n, int A[]){
    
    for(int i = 0; i < n; i++){
        cout << A[i] << (i != n-1 ? " " : "\n");
    }
    
}

void select_sort(int n, int A[]){
    
    
    int i = 0, j, count = 0, position = 0;
    
    while(i < n - 1){
        
        // 最小値を求める
        int min = 100;
        for(j = i; j < n; j++){
            if(min > A[j]){
                min = A[j];
                position = j;
            }
        }
        
        if(A[i] > A[position]){
            swap(A[i], A[position]);
            count++;
        }
        
        i++;
        
    }
        
    print(n, A);
    cout << count << endl;
    
}



int main(void){
    
    int n, A[100] = {};
    cin >> n;
    
    for(int i = 0; i < n; i++){
        cin >> A[i];
    }
    
    select_sort(n, A);
    
}

