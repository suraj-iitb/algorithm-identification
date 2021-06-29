#include<iostream>
using namespace std;

void output(int A[],int n){
    for (int i = 0;i < n;i++){
        if (i > 0) cout << " ";
        cout << A[i];
    }
    cout << endl;
}

void insertion (int A[],int n){
    int i,v,j;
    for (i = 0;i < n;i++){
        v = A[i];
        j = i -1;
        while (j >= 0 && A[j] > v){
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = v;
        output(A,n);
    }
}

int main(){
    int n,i,j,A[100];
    cin >> n;
    for (i = 0;i < n;i++) cin >> A[i];
    insertion(A,n);
    return 0;
}

