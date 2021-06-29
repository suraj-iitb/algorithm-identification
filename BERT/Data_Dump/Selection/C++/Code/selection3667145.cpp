#include <iostream>
using namespace std;
int main(void){
    int n,kari,count = 0,minj;
    cin >> n;
    int l[n];
    for(int i = 0; i < n; i++){
        cin >> l[i];
    }
    
    for(int i = 0; i <= n - 1 ; i++){
        minj  = i;
        for(int j = i; j <= n - 1; j++){
            if(l[j] < l[minj]){
                minj = j;
            }
        }
        kari = l[i];
        l[i] = l[minj];
        l[minj] = kari;
        if(i != minj){
            count++;
        }
    }
    
    for(int k = 0; k < n-1; k++){
        cout << l[k] << " ";
    }
    cout << l[n-1] << endl;
    cout << count << endl;
}
    

