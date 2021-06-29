#include<iostream>
using namespace std;

int ssort(int A[],int n){
    int minj, s=0;

    for(int i=0; i<n-1; i++){
        minj = i;
        for(int j=i+1; j<n; j++){
            if(A[j] < A[minj]){
                minj = j;
            }
        }
        swap(A[i], A[minj]);
        if(i != minj) s++;
    }
    return s;
}

int main(){
    int A[100], s, n;
    cin >> n;

    for(int i=0; i<n; i++)
        cin >> A[i];

    s = ssort(A, n);

    for(int i=0; i<n; i++){
        if(i) cout << ' ';
        cout << A[i];
    }

    cout << endl;
    cout << s << endl;
}
