#include<iostream>
using namespace std;
int main(){
    int n,v,j;
    cin >> n;
    int A[n+1];
    for(int i = 0; i < n; i++){
        cin >> A[i];
        if(i!= 0) cout << " ";
        cout << A[i];
    }
    cout << endl;
    
    for(int i = 1; i < n; i ++){
        v = A[i];
        j = i - 1;
        while(A[j] > v && j >= 0){
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = v;
        for(int k = 0; k < n; k++){
            if( k != 0){
            cout << " " ;
                
            }
            cout<< A[k];
        }
        
        cout << endl;
    }
    return 0;
}
