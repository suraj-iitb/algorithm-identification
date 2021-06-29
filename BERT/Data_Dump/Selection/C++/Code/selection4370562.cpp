#include <iostream>
#include <cmath>
using namespace std;

int selection(int A[],int N){
    int i,j,t,sw=0,minj;
    for(i=0;i<N;i++){
        minj = i;
        for(j=i;j<N;j++){
            if(A[j]<A[minj]) minj=j;
        }
        swap(A[i],A[minj]);
        if(i!=minj) sw++;
    }
    return sw;
}
int main(){
    int A[100],N,i,sw;
    cin >> N;
    for(i=0;i<N;i++) cin >> A[i];

    sw = selection(A,N);
    for(i=0;i<N;i++){
        if(i) cout << " ";
        cout << A[i];
    }
    cout << endl;
    cout << sw << endl;

    return 0;
}
