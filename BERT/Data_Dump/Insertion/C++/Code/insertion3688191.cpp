#include<iostream>
using namespace std;
int main(){
    int n;
    cin >> n;
    int A[n];
    
    for(int h = 0; h < n; h++){
        int m;
        cin >> m;
        A[h] = m;
    }
    
    for(int i = 0; i < n; i++){
        int v = A[i];
        int j = i - 1;
        while(j >= 0 && A[j] > v){
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = v;
        
        for(int k = 0; k < n; k++){
            if(k != n-1){
                cout << A[k] << " ";
            } else {
                cout << A[k] << endl;
            }
        }
        
    }
    
    return 0;
}
