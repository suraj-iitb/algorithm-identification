#include <bits/stdc++.h>
using namespace std;

int bubblesort(vector<int>& A,int N){
    int s = 0;
    bool flag = true;
    int i = 0;
    vector<int> B = A;
    while(flag){
        flag = false;
        for(int j=N-1;j>=i+1;j--){
            if(B[j]<B[j-1]){
                int temp = B[j];
                B[j] = B[j-1];
                B[j-1] = temp;
                flag =true;
                s++;
            }
        }
        i++;
    }
    A = B;
    return s;
}
int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    for(int i=0;i<N;i++){
        cin >> A[i];
    }
    vector<int>& B = A;
    int sw = bubblesort(B,N);
    for(int i=0;i<N;i++){
        cout << A[i];
        if(i==N-1){
            cout << endl;
        }else{
            cout << " ";
        }
    }
    cout << sw << endl;
    return 0;
}
