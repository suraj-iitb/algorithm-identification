#include<iostream>
#include<string>
using namespace std;





void bubbleSort(int A[],int N){
    int flag = 1;
    int tmp;
    int count=0;
    while (flag){
        flag= 0;
        for ( int j = N-1; j>0; j--){
            if (A[j] < A[j-1]){
                tmp = A[j];
                A[j] = A[j-1];
                A[j-1] = tmp;
                flag = 1;
                count++;
            }
        }
    }
    for (int k=0; k < N-1; k++) cout << A[k] <<" ";
    cout << A[N-1] << endl;
    cout << count << endl;
}


int main(){
    int N;
    int A[100];
    
    cin >> N;
    for (int i = 0; i < N; i++) cin >> A[i];

    bubbleSort(A,N);  
    
    
}
