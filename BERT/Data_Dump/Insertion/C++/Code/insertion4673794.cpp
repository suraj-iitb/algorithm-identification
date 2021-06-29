#include <bits/stdc++.h>
#include <string>
using namespace std;
static const int MAX = 100;

int main(){
    int n, A[MAX];
    cin >> n;
    for (int i = 0; i < n; i++) cin >> A[i];

        for (int k = 0; k < n; k++){
            cout << A[k];
            if(k < n-1){
                cout << " ";
            }else{
            cout << endl;
            }
        }

    for (int i = 1; i < n; i++){
        int v = A[i];
        int j = i - 1;
        while(j >= 0 && A[j] > v){
            A[j + 1] = A[j];
            j--;
        }
        A[j + 1] = v;

        for (int k = 0; k < n; k++){
            cout << A[k];
            if(k < n-1){
                cout << " ";
            }else{
            cout << endl;
            }
        } 
    }
}
