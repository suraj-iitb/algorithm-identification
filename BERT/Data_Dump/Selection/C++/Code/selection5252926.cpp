#include <iostream>
#include <algorithm>
using namespace std;
void trace(int A[],int N){
    for (int i = 0; i < N; i++)
    {
        
        if(i==N-1){
            cout << A[i] << endl;

        }
        else{
            cout << A[i]  << " ";
        }
    }
    
}
void selectionSort(int A[],int N){
    int minj;
    int count=0;

    for (int i = 0; i < N; i++)
    {
        minj=i;
        for (int j = i; j < N; j++)
        {
            if (A[j]<A[minj])
            {
                minj =j;
            }
            
        }
        if(A[minj]<A[i]){
            swap(A[i],A[minj]);
            count++;
        }
        
    }
    trace(A,N);
    cout << count << endl;

}



int main(){
    int N;
    int A[100];
    cin >> N;
    for(int i=0;i<N;i++){
        cin >> A[i];
    }
    selectionSort(A,N);
    


}
