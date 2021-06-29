#include<iostream>
using namespace std;

int selectionsort(int A[],int N){
    int minj,sw=0;
    for (int i=0;i<N-1;i++){
        minj = i;
        for (int j=i;j<N;j++){
            if (A[minj]>A[j]) minj = j;
        }
        swap(A[i],A[minj]);
        if (i!=minj) sw++;
    }
    return sw;
}

int main(){
    int N,A[101],sw=0;
    
    cin >> N;
    for (int i=0;i<N;i++) cin >> A[i];

    sw = selectionsort(A,N);

    for (int i=0;i<N;i++){
        if (i>0) cout << " ";
        cout << A[i];
    }
    cout << endl << sw << endl;

    return 0;
}
