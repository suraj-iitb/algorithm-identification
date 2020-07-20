#include <iostream>
using namespace std;

int bubble_sort(int A[], int N){
    int flag = 1,cnt = 0;
    while(flag){
        flag = 0;
        for(int j = N-1; j >= 1; j--){
            if(A[j] < A[j-1]){
                int tmp = A[j];
                A[j] = A[j-1];
                A[j-1] = tmp;
                cnt++;
                flag = 1;
            }
        }
    }
    return cnt;
}

void print(int A[], int n){
    for(int i = 0; i < n; i++){
        cout << A[i];
        if(i != n-1) cout << " ";
        else cout << endl;
    }
}

int main(){
    int n;
    cin >> n;
    int A[n];
    for(int i = 0; i < n; i++){
        cin >> A[i];
    }
    int cnt = bubble_sort(A,n);
    print(A,n);
    cout << cnt << endl;
}
