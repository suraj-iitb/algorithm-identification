#include <bits/stdc++.h>
using namespace std;

int selectionSort(vector<int>&, int);

int main(){
vector<int> A(100);
    int n, sw;
    cin >> n;

    for(int i = 0; i < n; i++) cin >> A.at(i);

    sw = selectionSort(A, n);

    for(int i = 0; i < n; i++){
        if(i) cout << " ";
        cout << A.at(i);
    }
    cout << endl;
    cout << sw << endl;
}

int selectionSort(vector<int>& A, int n){
    int sw = 0;
    for(int i = 0; i < n - 1; i++){
        int minj = i;
        for(int j = i; j < n; j++){
            if(A.at(j) < A.at(minj)) minj = j;
        }
        int t = A.at(i);
        A.at(i) = A.at(minj);
        A.at(minj) = t;
        if(i != minj) sw++;
    }
    return sw;
}

