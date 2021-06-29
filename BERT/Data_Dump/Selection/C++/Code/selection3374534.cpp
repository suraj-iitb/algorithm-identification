#include <iostream>
using namespace std;

int selectionSort(int* A,int N){
    int i,j,minj,tmp,count=0;
    for(i=0;i<N;i++){
        minj = i;
        for(j=i;j<N;j++){
            if(A[j]<A[minj]){
                minj = j;
            }
        }
        if(i!=minj){
            tmp = A[i];
            A[i] = A[minj];
            A[minj] = tmp;
            count++;
        }
    }
    return count;
}

int main(){
    int N,*A,i,cnt;
    cin >> N;
    A = new int[N];
    for(i=0;i<N;i++){
        cin >> A[i];
    }
    cnt = selectionSort(A,N);
    for(i=0;i<N;i++){
        if(i!=0){
            cout << " ";
        }
        cout << A[i];
    }
    cout << endl << cnt << endl;
    return 0;
}
