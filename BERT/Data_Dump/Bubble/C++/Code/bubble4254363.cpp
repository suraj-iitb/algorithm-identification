#include<iostream>
#include <algorithm>
using namespace std;

int main(){
    int n;
    cin >> n;
    int A[n];
    for(int i = 0; i < n; i++) cin >> A[i];
    
    bool flag = true;
    int count = 0;
    while(flag){
        flag = false;
        for(int i = n-1; i > 0; i--){
            if(A[i] < A[i-1]){
                swap(A[i-1], A[i]);
                flag = true;
                count++;
            }
        }
    }
    
    cout << A[0];
    for(int i = 1; i < n; i++) cout << " " <<A[i];
    cout << endl << count << endl;
}
