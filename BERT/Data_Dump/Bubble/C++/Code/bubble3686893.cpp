#include<iostream>
using namespace std;

int main(){
    
    int N, v;
    cin >> N;
    int A[N];
    
    for(int i=0; i<N; i++){
        cin >> A[i];
    }
    
    bool flag = 1;
    int count =0;
    for(int i=0; flag; i++){
        flag = 0;
        for(int j = N-1; j>= i+1; j--){
            if(A[j] < A[j-1]){
                
                int x= A[j];
                A[j] = A[j-1];
                A[j-1] = x;
                
                count++;
            }
            flag = 1;
            
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

