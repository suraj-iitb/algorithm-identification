#include <iostream>
using namespace std;

void print(int n, int A[]){
    
    for(int i = 0; i < n; i++){
        cout << A[i] << (i != n-1 ? " " : "\n");
    }
    
}

void bubble_sort(int n, int A[]){
    
   int i = n - 1, count = 0, position = 0;
   
   while(i > position){
       
       int j = i;
       
       while(j > position){
           if(A[j] < A[j - 1]){
               swap(A[j], A[j - 1]);
               count++;
           }
            j--;
        }
        
        position++;
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
    
    bubble_sort(n, A);
    
    
}

