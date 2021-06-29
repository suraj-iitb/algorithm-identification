#include <iostream>
using namespace std;

void bubbleSort(int* A,int N){
    int flag=1,j,tmp,count=0;
    while(flag){
        flag = 0;
        for(j=N-1;j>0;j--){
            if(A[j]<A[j-1]){
                tmp = A[j];
                A[j] = A[j-1];
                A[j-1] = tmp;
                count++;
                flag = 1;
            }
        }
    }
    for(j=0;j<N;j++){
        cout << A[j];
        if(j!=N-1){
            cout << " ";
        }
    }
    cout << endl << count << endl;
}

int main(){
    int N,*A,i;
    cin >> N;
    A = new int[N];
    for(i=0;i<N;i++){
        cin >> A[i];
    }
    bubbleSort(A,N);
    return 0;
}
