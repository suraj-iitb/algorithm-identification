#include <iostream>
using namespace std;
int bubbleSort(int A[], int N);
static const int M = 100;
int main()
{
    int A[M] ,N;
    cin >> N;
    for(int i=0; i<N; i++){
        cin >> A[i];
    }
    bubbleSort(A, N);
    return 0;
}


int bubbleSort(int A[], int N){
    bool flag  = 1;
    int count = 0;
    
    while(flag){
        flag  = 0;
        
        
        for(int j = N-1; j>=1; j--){
        
            
            if( A[j] < A[j-1] ) {
                
                int v  = A[j];
                A[j]   = A[j-1];
                A[j-1] = v;
                flag = 1;
                count++;
            }
        }
    }
    for(int i = 0; i<N; i++) {
        
        if(i>0) cout <<" ";
        cout << A[i]; 
        if(i==N-1) cout <<"\n";
    }
    cout << count << endl;
    return 0;
}
