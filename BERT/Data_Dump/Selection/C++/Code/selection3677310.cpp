#include<iostream>
using namespace std;

int main(){
    int n;
    int A[1000];
    int y, minj;
    int count = 0;
    cin >> n;
    
    for(int i = 0; i < n; i++){
        cin >> A[i];
        //cout << A[i];
    }
    for(int i = 0; i < n - 1; i++){
        minj = i;
        for(int j = i; j < n; j++){
            
            if(A[j] < A[minj]){
                minj = j;
                
            
            } 
            
        }
        //cout << minj << endl;
        if(i != minj){
            y = A[i];
            A[i] = A[minj];
            A[minj] = y;
            count += 1;
        }
        //A[i] = A[j + 1];
        //A[j + 1] = y;
        
        
    }
    
    for(int i = 0; i < n; i++){
        //cin >> A[i];
        if(i != 0) cout << " ";
        cout << A[i];
    }
    cout << endl;
    cout << count << endl;
    
    
    return 0;
}

