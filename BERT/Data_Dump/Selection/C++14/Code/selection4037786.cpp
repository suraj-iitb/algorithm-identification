#include <bits/stdc++.h>
using namespace std;

int main(){
    int count=0;
    int A[100],n;
    cin >> n;
    for (int i=0;i<n;i++){
        cin >> A[i];
    }
    
    for (int i=0;i<n;i++){
        int minj = i;
        for (int j=i;j<n;j++){
            if (A[j] < A[minj]){
                minj = j;
            }
        }
        if (i!=minj){
                swap(A[i],A[minj]);
                count++;
        }
    }
    for (int i=0;i<n;i++){
        if (i!=0){cout << " ";};
        cout << A[i];
    }
    cout << endl;
    cout << count << endl;
}


