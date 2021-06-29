#include<bits/stdc++.h>

using namespace std;

int bubbleSort(int A[],int N){
    int flag = 1;
    int count=0;
    while(flag){
        flag=0;
        for(int j=N-1;j>=1;j--){
            if(A[j] < A[j-1]){
                int tmp = A[j];
                A[j] = A[j-1];
                A[j-1] = tmp;
                flag=1;
                count++;
            }
        }
    }
    for(int i=0;i<N;i++){
        cout << A[i];
        if(i!=N-1)cout << " ";
    }
    cout << endl;
    return count;
}

int main(){
    int N;
    cin >> N;
    int A[N];
    for(int i=0;i<N;i++)cin >> A[i];
    int count = bubbleSort(A,N);
    cout << count << endl;
}
