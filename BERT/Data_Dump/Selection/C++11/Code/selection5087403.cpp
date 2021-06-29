#include<iostream>                                                                                                                       
#include<algorithm>                                                                                                                      
using namespace std;                                                                                                                     
                                                                                                                                         
                                                                                                                                         
void printA(int A[], int N) {                                                                                                            
    for (int i = 0; i < N; i++) {                                                                                                        
        if (i != N-1) cout << A[i] << " ";                                                                                               
        else cout << A[i] << endl;                                                                                                       
    }                                                                                                                                    
    return ;                                                                                                                             
}                                                                                                                                        
int selectionSort(int A[], int N) {                                                                                                      
                                                                                                                                         
    int minj = 0;                                                                                                                        
    int cnt = 0;                                                                                                                         
    for (int i = 0; i < N; i ++) {                                                                                                       
        minj = i;                                                                                                                        
        for (int j = i; j < N; j++) {                                                                                                    
            if (A[j] < A[minj]) minj = j;                                                                                                
        }                                                                                                                                
        if (minj != i) {swap(A[i], A[minj]); cnt++;}                                                                                     
    }                                                                                                                                    
                                                                                                                                         
    return cnt;                                                                                                                          
}                                                                                                                                        
                                                                                                                                         
int main(void) {                                                                                                                         
                                                                                                                                         
    int N = 0;                                                                                                                           
    int A[100];                                                                                                                          
    int cnt = 0;                                                                                                                         
    cin >> N;                                                                                                                            
    for (int i = 0; i < N; i++) {                                                                                                        
        cin >> A[i];                                                                                                                     
    }                                                                                                                                    
                                                                                                                                         
    cnt = selectionSort(A, N);                                                                                                           
    printA(A, N);                                                                                                                        
    cout << cnt << endl;                                                                                                                 
                                                                                                                                         
    return 0;                                                                                                                            
}                                                                                                                                        
                                                                                                                                         
                       
