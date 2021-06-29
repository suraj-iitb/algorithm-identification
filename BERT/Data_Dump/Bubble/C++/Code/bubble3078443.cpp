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
    int flag = 1;
    while(flag != 0){
        for(int i = n-1; i > 0; i--){
            if(A[i] < A[i-1]){
                int temp = A[i];
                A[i] = A[i-1];
                A[i-1] = temp;
                flag++;
                count++;
            }
        }
        if(flag == 1){
            flag = 0;
        }
        else{
            flag = 1;
        }
    }
    for(int i = 0; i < n-1; i++){
        cout << A[i] << " ";
    }
    cout << A[n-1] << endl;
    cout << count << endl;
    return 0;
}

