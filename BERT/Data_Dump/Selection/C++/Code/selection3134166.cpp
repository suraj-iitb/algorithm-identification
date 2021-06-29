#include <iostream>

using namespace std;

int main(){
    int n, count, minj, A[100];
    count = 0;
    
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> A[i];
    }
    
    for(int i = 0; i < n; i++){
        int flag = 0;
        minj = i;
        for(int j = i; j < n; j++){
            if(A[j] < A[minj]){
                minj = j;
                flag = 1;
            }
        }
        if(flag){
            int temp;
            temp = A[i];
            A[i] = A[minj];
            A[minj] = temp;
            count++;
        }
        
    }
    
    cout << A[0];
    for(int i = 1; i < n; i++){
        cout << " " << A[i];
    }
    cout << endl << count << endl;
    
    return 0;
    
}

