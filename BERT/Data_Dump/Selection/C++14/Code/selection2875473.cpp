#include<iostream>
using namespace std;

int main(){
    int n, x=0;
    cin >> n;
    int A[n];
    for(int i=0 ; i<n ; i++){
        cin >> A[i];
    }
    for(int j=0 ; j<n ; j++){
        int mink=j;
        for(int k=j ; k<n ; k++){
            if(A[k]<A[mink]){
                mink = k;
            }
        }
        if(A[j]!=A[mink]){
            x++;
        }
        int l=A[j];
        A[j]=A[mink];
        A[mink]=l;
    }
    for(int m=0 ; m<n-1 ; m++){
        cout << A[m] << " ";
    }
    cout << A[n-1] << endl << x << endl;
    return 0;
}
