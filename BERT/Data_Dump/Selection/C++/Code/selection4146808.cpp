#include <iostream>
using namespace std;

int main(){
    int n;
    cin >> n;

    int i,j,tmp,minj;
    int A[n];
    int counter = 0;

    for(i=0; i<n; i++){
        cin >> A[i];
    }

    for(i=0; i<n-1; i++){
        minj = i;
        for(j=i; j<n; j++){
            if(A[j]<A[minj]) minj = j;
        }
        if(i!=minj){
            tmp = A[i];
            A[i] = A[minj];
            A[minj] = tmp;
            counter++;
        }
    }

    for(i=0; i<n-1; i++){
        cout << A[i] << ' ';
    }
    cout << A[n-1] << endl;
    cout << counter << endl;

    return 0;
}
