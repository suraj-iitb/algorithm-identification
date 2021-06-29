#include <iostream>
using namespace std;

#define MAX 101
int main(){
    int n, A[MAX], tem, last, j, z;
    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> A[i];
    }
    for(int i = 0; i < n; i++){
        if(i != n - 1)
            cout << A[i] << " ";
    }
    cout << A[n - 1] << endl;

    for(int i = 1; i < n; i++){
        last = A[i];
        j = i - 1;
        while(j >= 0 && A[j] > last){
            A[j + 1] = A[j];
            j--;
        }
        A[j + 1] = last;
        
        for(z = 0; z < n; z++){
            if(z != n - 1){
                cout << A[z] << " ";
            }
        }
        cout << A[z - 1] << endl;
    }
}
