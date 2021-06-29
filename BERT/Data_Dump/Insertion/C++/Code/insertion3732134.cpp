#include <iostream>
using namespace std;
int insertionSort(int A[], int N);
static const int MAX = 100; 
int main()
{
    int A[MAX],N;
    cin >> N ;
    
    for(int i=0; i<N; i++){
        cin >> A[i];
        if (i>0) cout << " ";
        cout << A[i] ;
    }
    cout << "\n";
    
    insertionSort(A,N);
    return 0;
}
    
int insertionSort(int A[],int N){
    
    for(int i=1; i<N; i++){
        
        int v = A[i];
        int j = i-1;
        
            
        while(j >= 0 && A[j] > v){
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = v;
        
        for(int k=0; k<N; k++){
            if(k > 0) cout << " ";
            cout << A[k];
            if(k==N-1) cout << "\n";
            
        }
        
            
    }
    return 0;
}
