#include <iostream>
using namespace std;
int main(void){
    int n,i;
    cin >> n;
    int A[n];
    for(i=0;i<n;i++){
        cin >> A[i];
    }

    int iCount=0;
    int j,minj;
    int swap;
    for(i=0;i<n;i++){
        minj=i;
        for (j=i;j<n;j++){
            if (A[j]<A[minj]){
                minj=j;
            }
        }
            if (minj!=i){
                swap=A[i];
                A[i]=A[minj];
                A[minj]=swap;
                iCount+=1;
            }
        
    }
    
    for(i=0;i<n;i++){
        if (i!=0){
            cout << ' ';
        }
        cout << A[i];
    }
    cout << endl;
    cout << iCount <<endl;
}
