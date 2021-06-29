#include<iostream>
#include<algorithm>
using namespace std;

int main(){
    int n;
    cin >> n;
    int A[n];
    for( int k=0 ; k<n ; k++){
        cin >> A[k];
    }
    for( int k=0 ; k<n-1 ; k++){
        cout << A[k]<< " ";
    }
    cout << A[n-1] << endl;

    for( int i=1 ; i<n ; i++ ){
        int j,v;
        v = A[i];
        j = i-1;
        while( j>= 0 && A[j]>v){
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = v;
        for( int k=0 ; k<n-1 ; k++){
            cout << A[k]<< " ";
        }
        cout << A[n-1] << endl;
    }
}
