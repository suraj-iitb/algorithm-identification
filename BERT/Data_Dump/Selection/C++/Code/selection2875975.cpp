#include <iostream>
#include <algorithm>
using namespace std;
static const int MAX = 1000;

void trace(int A[], int N){ 
    int i;
    for (i=0;i<N;i++){
        if(i>0) cout << " ";
        cout << A[i];
    }   
    cout << endl;
}

void selectionSort(int A[],int N){ 
    int sw = 0;
    for (int i=0;i<N;i++){
        int minj = i;
        for (int j=i;j<N;j++){
            if (A[j] < A[minj]){
                minj = j;
            }
        }
        if (i != minj) {
            swap(A[i],A[minj]);
            sw++;
        }
    }   
    trace(A,N);
    cout << sw << endl;
}
int main(){
    int n,A[MAX];
    cin >> n;
    for (int i=0;i<n;i++) cin >> A[i];
    selectionSort(A,n);
    return 0;
}

