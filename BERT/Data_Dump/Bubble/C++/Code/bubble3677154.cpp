#include<iostream>
using namespace std;

int main(){
    int n;
    int A[1000];
    int y,j;
    int count = 0;
    cin >> n;
    
    for(int i = 0; i < n; i++){
        cin >> A[i];
        //cout << A[i];
    }
    for(int i = 0; i < n ; i++){
        j = n- 1;
        
        while(j >= i + 1 ){
            
            if(A[j] < A[j - 1]){
                y = A[j];
                A[j] = A[j - 1];
                A[j - 1] = y;
                count += 1;
                
            }
            //A[j + 1] = A[j];
            j = j - 1;
            continue;
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

