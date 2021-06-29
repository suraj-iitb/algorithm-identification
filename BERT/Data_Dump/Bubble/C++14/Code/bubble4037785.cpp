#include <bits/stdc++.h>
using namespace std;

int main(){
    int count=0;
    int A[100],n;
    cin >> n;
    for (int i=0;i<n;i++){
        cin >> A[i];
    }
    int flag = 1;
    while (flag){
     flag = 0;
     for (int j=n-1;j>=1;j--){
        if (A[j] < A[j-1]){
         swap(A[j],A[j-1]);
         count++;
         flag = 1;
        }
        }
    }
    for (int i=0;i<n;i++){
        if (i!=0){cout << " ";};
        cout << A[i];
    }
    cout << endl;
    cout << count << endl;
}

