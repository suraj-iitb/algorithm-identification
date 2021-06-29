#include <bits/stdc++.h>
using namespace std;

int bubbleSort(vector<int>&, int);

int main(){
    vector<int> A(100);
    int n, sw;
    cin >> n;
    for(int i = 0; i < n; i++) cin >> A.at(i);

    sw = bubbleSort(A, n);

    for(int i = 0; i < n; i++){
        if (i) cout << " ";
        cout << A.at(i);
    }
    cout << endl;
    cout << sw << endl;
}

int bubbleSort(vector<int>& A, int n){
    int sw = 0;
    bool flag = 1;
    for(int i = 0; flag; i++){
        flag = 0;
        for(int j = n - 1; j >= i + 1; j--){
            if(A.at(j) < A.at(j-1)){
                swap(A.at(j), A.at(j-1));
                flag = 1;
                sw++;
            }
        }
    }
    return sw;
}
