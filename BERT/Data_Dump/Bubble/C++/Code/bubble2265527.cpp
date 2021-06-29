#include <iostream>
using namespace std;

static int count = 0;

void bubbleSort(int A[], int n){
    bool flag = 1;
    int i = 0;
    while(flag){
        flag = 0;
        for(int j = n - 1; j > i; j--){
            if(A[j] < A[j-1]){
                swap(A[j], A[j-1]);
                flag = 1;
                count++;
            }
        }
        i++;
    }
    
}

int main(void){
    int n;
    cin >> n;
    int A[n];
    for(int i = 0; i < n; i++) cin >> A[i];
    bubbleSort(A, n);
    for(int i = 0; i < n; i++){
        if(i > 0) cout << " ";
        cout << A[i];
    }
    cout << endl;
    cout << count << endl;
    
}
