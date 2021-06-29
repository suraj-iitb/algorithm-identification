#include <iostream>
using namespace std;
int main(void){
    int n;
    cin >> n;
    int A[n];
    for(int i=0;i<n;i++){
        cin >> A[i];
    }
    
    int count = 0;
    for(int i=0;i<n;i++){
        for(int j=n-1;j>=0;j--){
            if(A[j] < A[j-1]){
                count++;
                int tmp;
                tmp = A[j];
                A[j] = A[j-1];
                A[j-1] = tmp;
            }
        }
    }
  
    for(int i=0;i<n;i++){
        cout << A[i];
        if(i==n-1){
            cout << endl;
        }else{
            cout << " ";
        }
    }    
    cout << count << endl;

    return 0;
}

