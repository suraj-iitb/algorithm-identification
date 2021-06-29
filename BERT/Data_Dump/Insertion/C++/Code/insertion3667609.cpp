#include<iostream>
using namespace std;

int main(){
    int n;
    int A[1000];
    int y,j;
    cin >> n;
    
    for(int i = 0; i < n; i++){
        cin >> A[i];
        //cout << A[i];
    }
    for(int i = 1; i < n ; i++){
        y = A[i];
        j = i- 1;
        for(int k = 0; k < n; k++){
            if (k != 0){
                cout << " ";
            }
            cout << A[k];
        }
        cout << endl;
        while(j >= 0 && A[j] > y){
            A[j + 1] = A[j];
            j = j - 1;
        }
        //A[i] = A[j + 1];
        A[j + 1] = y;
        
        
    }
    for(int k = 0; k < n; k++){
            if (k != 0){
                cout << " ";
            }
            cout << A[k];
        }
        cout << endl;
    
    return 0;
}
