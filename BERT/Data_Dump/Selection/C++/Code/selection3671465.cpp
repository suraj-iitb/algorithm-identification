#include <iostream>
using namespace std;
int main(void){    // selectionSort
    // Your code here!
    
    int n,A[101],minj,count=0;  //nは個数
    
    cin >> n;
    
    for(int i = 0;i < n; i++){
        cin >> A[i];
        //cout << A[i] << " ";
    }
    
    
    
     // selectionSort
     for(int i = 0; i <= n-1; i++){
         minj = i;
         
         for(int j = i; j < n; j++){
             
             if(A[j] < A[minj]) minj = j;
             //cout << "minj" << A[minj] << endl;
            
         }
         
         if(A[i] != A[minj]) swap(A[i], A[minj]), count++;
         
         //cout << "A[" << i << "]" << A[i] << endl;
     }
     
     
     for(int k = 0; k < n; k++){
         if(k == n-1) cout << A[k];
         else cout << A[k] << " ";
     }
     
    cout <<endl << count << endl;
    
}
