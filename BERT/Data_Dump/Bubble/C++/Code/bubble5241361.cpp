#include <iostream>
#include <algorithm>
using namespace std;
void trace(int A[],int N){
    for (int i = 0; i < N; i++)
    {
        if(i==N-1){
            cout<<A[i]<<endl;
        }
        else{
            cout<<A[i]<< " ";
        }
    }
    
}
void bubbleSort(int A[],int N){
    int flag;
    int count;
    count=0;
    flag=1;
    while (flag)
    {
        flag=0;
        for(int j=N-1;j>0;j--){
            if(A[j]<A[j-1]){
                swap(A[j],A[j-1]);
                flag=1;
                count++;
            }
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
     bubbleSort(A,N);
     

 }
