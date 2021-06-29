#include <iostream>
using namespace std;

void print(int A[],int N){
    for(int i=0; i < N;i++){
        if(i != N-1)cout << A[i] << " ";
        else cout << A[i];   
    }
    cout << endl;
}

int  BubbleSort(int A[],int N){
    int sw = 0;
    int j,i = 0;
    bool flag = 1;
    for(i = 0;flag;i++){
        flag = 0;
        for(int j = N-1;j>= i+1;j--){
            if(A[j-1] > A[j]){
                swap(A[j-1],A[j]);
                flag = 1;
                sw++;
            }
        }
        //print(A,N);
    }
    print(A,N);
    return sw;
}

int main(void){
    // Your code here!
    int A[1001];
    int n;
    
    cin >> n;
    for(int i = 0;i < n; i++)cin >> A[i];
    
    int cnt = BubbleSort(A,n);
    cout << cnt << endl;
    return 0;
}


