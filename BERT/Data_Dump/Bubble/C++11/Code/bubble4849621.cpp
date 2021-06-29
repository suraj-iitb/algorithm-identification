#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<int> A;
    int a;
    for(int i=0;i < n;i++){
        cin >> a;
        A.push_back(a);
    }
    int num = 0;
    int flag = 1;
    int i = 0;
    while (flag){
        flag = 0;
        for(int j= n-1; j != i; j--){
            if(A[j] < A[j-1]) {
                swap(A[j], A[j-1]);
                flag=1;
                num++;
            }
        }
        i++;
    }
    cout << A[0];
    for(int j=1;j<n;j++){
        cout << " " << A[j];
    }
    cout << endl;
    cout << num << endl;
}
