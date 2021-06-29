#include<iostream>
#include<algorithm>
using namespace std;

int main(){

    int n, flag=1, count=0;
    cin >> n;
    int A[n];
    for( int i=0 ; i<n ; i++){
        cin >> A[i];
    }

    while(flag){
        flag = 0;

        for( int j=n-1 ; j>=1 ; j-- ){
            if(A[j]<A[j-1]){
                int a;
                a = A[j];
                A[j] = A[j-1];
                A[j-1] = a;
                flag = 1;
                count++;
            }
        }
    }
    for( int k=0 ; k<n-1 ; k++){
        cout << A[k] << " ";
    }
    cout << A[n-1] << endl;
    cout << count << endl;

    return 0;
}
