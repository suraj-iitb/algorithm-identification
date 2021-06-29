#include <iostream>
using namespace std;

void bubbleSort(int A[], int N){
    int j,flag = 1, count=0;
    while(flag){
        flag = 0;
        for(j=N-1;j>0;j--){
            if(A[j]<A[j-1]){
                swap(A[j],A[j-1]);
                flag = 1;
                count++;
            }
        }
    }
    for(int i=0;i<N;i++){
        if(i>0) cout << " ";
        cout << A[i];
    }
    
    cout << endl;
    cout << count << endl;
}

int main() {
    int N;
    int A[100];
    cin>>N;
    for(int i=0;i<N;i++) cin>>A[i];
    bubbleSort(A,N);
}
