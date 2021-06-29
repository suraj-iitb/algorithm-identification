#include<iostream>
using namespace std;

int main(){
    
    int N;
    cin >> N;
    int A[N];
    
    for(int i=0; i<N; i++){
        cin >> A[i];
    }
    
    int count = 0;
    for(int i=0; i<N-1; i++){
        int minj =i;
        
        for(int j=i; j<N; j++){
            if(A[j] < A[minj]){
                minj =j;
            }
        }
        int x = A[i];
        A[i] = A[minj];
        A[minj] = x;
        
        if(minj != i){
            count++;
        }
    }
    
    for(int k=0; k<N; k++){
        if(k != 0){
            cout << " ";
        }
        cout << A[k];
    }
    cout << endl;
    
    cout << count << endl;
    
    return 0;
}
