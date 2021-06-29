#include <iostream>
using namespace std;
int main(void){
    int n = 0;
    cin >> n;
    int A[100];
    for(int i = 0; i < 100; i++){
        A[i] = 0;
    }
    for(int i = 0; i < n; i++){
        cin >> A[i];
    }
    int count = 0;
    for(int i = 0; i < n; i++){
        int minj = i;
        for(int j = i; j < n; j++){
            if(A[j] < A[minj]){
                minj = j;
            }
        }
        if(minj != i){
            int temp = A[i];
            A[i] = A[minj];
            A[minj] = temp;
            count++;
        }
    }
    for(int i = 0; i < n-1; i++){
        cout << A[i] << " ";
    }
    cout << A[n-1] << endl;
    cout << count << endl;
    return 0;
}

