#include <iostream>
using namespace std;

int main(void){
    int n, j;
    cin >> n;
    int x[n];
    for (int i = 0; i < n; i++){
        cin >> x[i];
    }
    
    for (int k = 0; k < n; k++){
            cout << x[k];
            if (k != n - 1){
                cout << " ";
            }else{
                cout << endl;
            }
    }
    
    int v = 0;
    
    for (int i = 1; i < n; i++){
        if (x[i - 1] > x[i]){
            j = i - 1;
            v = x[i];
            while(x[j] > v and j >= 0){
                x[j + 1] = x[j];
                j--;
            }
            x[j + 1] = v;
        }
        
        for (int k = 0; k < n; k++){
            cout << x[k];
            if (k != n - 1){
                cout << " ";
            }else{
                cout << endl;
            }
        }
    }
}
