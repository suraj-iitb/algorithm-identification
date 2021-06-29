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
    for(int i=0;i<n;i++){
        int tmpj = i;
        for(int j=i+1;j<n;j++){
            if(A[tmpj] > A[j]){
                tmpj = j;
            }
        }
        swap(A[tmpj],A[i]);
        if(!(tmpj == i)) num++;
    }

    cout << A[0];
    for(int j=1;j<n;j++){
        cout << " " << A[j];
    }
    cout << endl;
    cout << num << endl;
}
