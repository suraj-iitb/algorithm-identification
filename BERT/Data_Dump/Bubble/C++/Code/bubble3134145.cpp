#include <iostream>

using namespace std;

int main(){
    int n, count, flag, A[100];
    count = 0;
    
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> A[i];
    }
    
    flag = 1;
    while(flag){
        flag = 0;
        for(int j = n - 1; j > 0; j--){
            if(A[j] < A[j-1]){
                int temp;
                temp = A[j];
                A[j] = A[j-1];
                A[j-1] = temp;
                flag = 1;
                count++;
            }
        }
    }
    
    cout << A[0];
    for(int i = 1; i < n; i++){
        cout << " " << A[i];
    }
    cout << endl << count << endl;
    
    return 0;
    
}

