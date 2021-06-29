#include<iostream>
using namespace std;

int main(){
    int N, temp;
    cin >> N;
    
    int A[N];
    for(int i = 0; i < N; i++) cin >> A[i];
    
    cout << A[0];
    for(int i = 1; i < N; i++) cout << " " << A[i];
    cout << endl;
    
    for(int i = 1; i < N; i++){
        temp = A[i];
        int j = i - 1;
        
        while(j >= 0 && A[j] > temp){
            A[j+1] = A[j];
            j--;
        }
        
        A[j+1] = temp;
        
        cout << A[0];
        for(int i = 1; i < N; i++) cout << " " << A[i];
        cout << endl;
    }
}
