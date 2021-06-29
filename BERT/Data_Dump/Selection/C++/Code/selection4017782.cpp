#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,count = 0;
    cin >> n;
    vector<int> A(n);
    for(int i = 0; i < n; i++){
        cin >> A[i];
    }
    for(int i = 0; i < n; i++){
        int minj = i;
        for(int j = i; j < n; j++){
            if(A[j] < A[minj]){
            minj = j;
            }
        }
        if(i != minj){
        int b = A[i];
        A[i] = A[minj];
        A[minj] = b;
        count++;
        }
        }
for(int i =0; i< n; i++){
    if(i < n -1)
    cout << A[i] << " ";
    if(i == n - 1)
    cout << A[i] << endl;
}
cout << count << endl;
}
