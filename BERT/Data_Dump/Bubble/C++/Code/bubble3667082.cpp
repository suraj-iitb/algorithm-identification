#include <iostream>
using namespace std;
int main(void){
    bool flag = true;
    int n, A[100],count = 0,tmp;
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> A[i];
    }
    while(flag){
        flag = false;
        for (int j = n - 1; j >= 1; j--){
            if (A[j] < A[j-1]){
                tmp = A[j];
                A[j] = A[j-1];
                A[j-1] = tmp;
                flag = true;
                count += 1;
            }
        }
    }
    for (int i = 0; i < n; i++){
        cout << A[i];
        if (i != n - 1){
            cout << " ";
        }
    }
    cout << endl;
    cout << count << endl;
}
