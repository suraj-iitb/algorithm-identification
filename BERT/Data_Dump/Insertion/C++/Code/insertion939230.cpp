#include <iostream>

using namespace std;

int main(){
    int n;
    int A[100];
    int i, j, key;

    cin >> n;
    
    for(i=0; i<n; i++){
        cin >> A[i];
    }

    for(i=0; i<n; i++){
        key = A[i];
        j = i - 1;
        while(j>=0 && A[j] > key){
            A[j+1] = A[j];
            j = j - 1;
        }
        A[j+1] = key;
        for(j=0; j<n; j++){
            cout << A[j];
            if(j!=n-1){
                cout << ' ';
            }
        }
        cout << "\n";
    }
}
