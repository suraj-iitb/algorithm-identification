#include<iostream>
using namespace std;
int main(){
    int N;
    cin >> N;
    
    int A[N];
    for(int i = 0; i < N; i++){
        cin >> A[i];
    }
    
    int flag = 1;
    int count = 0;
    
    while(flag){
        flag = 0;
        for(int j = (N - 1); j > 0; j--){
            if(A[j] < A[j - 1]){
                int B = A[j - 1];
                A[j - 1] = A[j];
                A[j] = B;
                count++;
                flag = 1;
            }
        }
    }
    
    for(int i = 0; i < (N - 1); i++){
        cout << A[i] << " ";
    }   
    cout << A[N - 1] << endl;
    cout << count << endl;
}
