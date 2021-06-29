#include <iostream>
#include <algorithm>
using namespace std;

int selection_sort(int A[], int n){
    int i,j,minj,sw=0;
    for (i=0; i<n-1; i++){
        minj = i;
        for (j=i+1; j<n; j++){
            if (A[j] < A[minj]) minj = j;
        }
        swap(A[i],A[minj]);
        if (i!=minj) sw++;
    }
    return sw;
}
int main(){
    int A[100], n, i, sw;
    cin >> n;
    for (i=0; i<n; i++) cin >> A[i];

    sw = selection_sort(A,n);

    for (i=0; i<n; i++){
        if (i>0) cout << " ";
        cout << A[i];
    }
    cout << endl;
    cout << sw << endl;
}
