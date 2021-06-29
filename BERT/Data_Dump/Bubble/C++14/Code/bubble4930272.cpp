#include<iostream>
using namespace std;

void output(int A[],int n){
    for (int i = 0;i < n;i++){
        if (i > 0) cout << " ";
        cout << A[i];
    }
    cout << endl;
}

int bubble(int A[],int n){
    int count = 0;
    bool flag = 1;
    while (flag){
        flag = 0;
        for (int j = n - 1;j >= 1;j--){
            if (A[j] < A[j-1]){
                swap(A[j],A[j-1]);
                count += 1;
                flag = 1;
            }
        }
    }
    return count;
}

int main(){
    int A[100],n,count;
    cin >> n;
    for (int i = 0;i < n;i++) cin >> A[i];
    count = bubble(A,n);
    output(A,n);
    cout << count << endl;
    return 0;
}

