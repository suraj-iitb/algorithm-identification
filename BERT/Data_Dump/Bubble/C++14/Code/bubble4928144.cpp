#include <iostream>
using namespace std;

int bubbleSort(int A[], int N){
    int count = 0;
    bool flag = 1;
    for(int i=0; flag; i++){
        flag = 0;
        for(int j=N-1; j >=1; j--){
            if (A[j] < A[j-1]){
                swap(A[j], A[j-1]);
                count++;
                flag = 1;
            }
        }
    }
    return count;
}

int main(){
    int N, count = 0;
    bool flag = 1;
    cin >> N;
    int A[100];
    for(int i=0; i<N; i++) cin >> A[i];
    
    for(int i=0; flag; i++){
        flag = 0;
        for(int j=N-1; j >=1; j--){
            if (A[j] < A[j-1]){
                swap(A[j], A[j-1]);
                count++;
                flag = 1;
            }
        }
    }
    for(int i=0; i<N-1; i++){
        cout << A[i] << " ";
    }
    cout << A[N-1] << endl;
    cout << count << endl;
    return 0;
}
