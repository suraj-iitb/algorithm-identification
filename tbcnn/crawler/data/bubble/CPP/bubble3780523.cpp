#include "iostream"
#include "algorithm"
using namespace std;

int bubbleSort(int A[], int n){
    int sw = 0;
    for(int i = 0; i < n; i++){
        for(int j = n-1; j >= i+1; j--){
            if(A[j] < A[j-1]){
                swap(A[j], A[j-1]);
                sw++;
            }

        }
    }
    return sw;
}
int main(){
    int A[100], n, sw;
    cin >> n;
    for(int i=0; i<n; i++) cin >> A[i];
    sw = bubbleSort(A, n);
    for(int i = 0; i < n; i++){
        if(i > 0) cout << " ";
        cout << A[i];
    }
    cout << endl;
    cout << sw << endl;
    return 0;
}
