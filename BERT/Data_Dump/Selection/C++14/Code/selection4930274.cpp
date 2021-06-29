#include<iostream>
using namespace std;

void output(int A[],int n){
    for (int i = 0;i < n;i++){
        if (i > 0) cout << " ";
        cout << A[i];
    }
    cout << endl;
}

int selection(int A[],int n){
    int count = 0;
    int minj;
    for (int i = 0;i < n -1;i++){
        minj = i;
        for (int j = i;j <= n - 1;j++){
            if (A[j] < A[minj]) minj = j;
        }
        swap(A[i],A[minj]);
        if (i != minj) count += 1;
    }
    return count;
}

int main(){
    int A[100],n,count;
    cin >> n;
    for (int i = 0;i < n;i++) cin >> A[i];
    count = selection(A,n);
    output(A,n);
    cout << count << endl;
    return 0;
}
