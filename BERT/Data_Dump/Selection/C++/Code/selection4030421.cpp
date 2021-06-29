#include <iostream>
#define rep(i,n) for(int i=0;i<(n);++i)
using namespace std;

int selectionSort(int A[],int n){
    int count = 0;
    rep(i,n){      
        int minj = i;
        for(int j=i;j<n;j++){
            if(A[j]<A[minj]) minj = j;
        }
        if(minj != i) {
            swap(A[i],A[minj]);
            count++;
        }
    }
    return count;
}

int main(){
    int N,count,A[100];
    cin >> N;
    rep(i,N) cin >> A[i];
    count = selectionSort(A,N);
    rep(i,N){
        if(i>0) cout << ' ';
        cout << A[i];
    }
    cout << endl << count << endl;
    return 0;
}
