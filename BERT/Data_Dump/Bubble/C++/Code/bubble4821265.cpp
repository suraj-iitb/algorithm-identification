#include <iostream>
using namespace std;

//使用flag的冒泡排序 升序
int bubbleSort(int A[], int N){
    bool flag  = true;
    int sw = 0;
    for(int i = 0; flag; i++){
        flag = false;
        for(int j = N-1; j >= i + 1; j--){
            if(A[j] < A[j-1]){
                swap(A[j], A[j-1]);
                sw++;
                flag = true;
            }
        }
    }
    return sw;
}

int main(){
    int A[100], N;
    cin>>N;
    for(int i = 0; i < N; i++) cin>>A[i];
    int sw = bubbleSort(A, N);
    for(int i = 0; i < N; i++){
        if(i != N -1)
            cout << A[i] << " ";
        else
            cout << A[i] << endl;
    }
    cout << sw << endl;
}
