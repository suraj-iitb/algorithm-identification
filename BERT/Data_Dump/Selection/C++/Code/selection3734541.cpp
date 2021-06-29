#include<iostream>
using namespace std;
static const int MAX = 100;
int selectionSort(int A[],int N);
int main()
{
    int A[MAX],N;
    cin >> N;
    
    for(int i=0; i<N; i++){
        cin >> A[i];
    }
    selectionSort(A,N);
    return 0;
}




int selectionSort(int A[], int N){
    int count = 0;
    for(int i=0; i<=N-1; i++){
        
         int minj = i;
         
         for(int j=i; j<=N-1; j++){
             
            if(A[j] < A[minj]) minj =j;
         }
         if(A[i]!=A[minj]) count++;
             
            int v;
            v = A[i];
            A[i] = A[minj];
            A[minj] = v;

         
         
    }
    for(int i=0; i<N; i++){
        if(i>0) cout<<" ";
        cout<<A[i];
    }
    cout<<"\n";
    cout << count<< endl;
    return 0;
}
