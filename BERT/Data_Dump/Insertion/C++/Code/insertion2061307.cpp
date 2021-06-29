#include<iostream>

using namespace std;

int main(){
        int n; cin >> n;
        int A[1000];
    
        for (int i = 0; i < n; i++){
                cin >> A[i];
        }   
    
        for ( int i = 1; i <= n; i++){
                for ( int k = 0; k < n; k++){
                        cout << A[k];
                        if ( k != n - 1){ 
                                cout << " ";
                        }   
                }   
                cout << endl;
                int v = A[i];
                int j = i - 1;
                while( j >= 0 and A[j] > v){ 
                        A[j+1] = A[j];
                        j--;
                }   
                A[j+1] = v;
        }   

return 0;
}
