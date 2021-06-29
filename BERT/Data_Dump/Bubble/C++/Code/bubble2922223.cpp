#include <iostream>
using namespace std;
int bubbleSort(int A[], int N){
    int s = 0;
    bool flag = 1;
    for(int i=0; flag; i++){
        flag = 0;
        for(int j=N-1; j>=i+1; j--){
            if(A[j] < A[j-1]){
                swap(A[j], A[j-1]);
                flag=1;
                s++;
            }
        }
    }
    return s;
}

int main(void){
    int N, s;
    int A[101];
    
    cin >> N;
    for(int i=0; i<N; i++) cin >> A[i];
    
    s = bubbleSort(A, N);
    
    for(int i=0; i<N; i++){
        if(i>0) cout << " ";
        cout << A[i];
    }
    cout << endl;
    cout << s << endl;
    
    return 0;
}

