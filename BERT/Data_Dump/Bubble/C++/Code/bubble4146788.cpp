#include <iostream>
using namespace std;

int main(){
    int n;
    cin >> n;

    int A[n];
    int i,j,tmp;

    for(i=0; i<n; i++){
        cin >> A[i];
    }

    int flag = 1;
    int counter = 0;

    while(flag){
        flag=0;
        for(j=n-1; j>0; j--){
            if(A[j]<A[j-1]){
                tmp = A[j];
                A[j] = A[j-1];
                A[j-1] = tmp;
                flag = 1;
                counter++;
            }
        }
    }

    for(i=0; i<n-1; i++){
        cout << A[i] <<' ';
    }
    cout << A[n-1] << endl;
    cout << counter << endl;

}
