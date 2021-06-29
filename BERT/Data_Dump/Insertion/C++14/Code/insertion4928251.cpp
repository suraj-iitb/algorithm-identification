#include <iostream>
using namespace std;
int main (){
    int n, key, j;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (i == 0) cout << a[i];
        else {
            cout << " " <<a[i];
        }
    } 
    cout << endl;

    for (int i = 1; i < n; i++){
        key = i;
        j = i - 1;
        while ((j >= 0) && (a[j] > a[key])){
            swap(a[j], a[key]);
            key -= 1;
            j -= 1;
        }
        
        for (int i = 0; i < n; i++){
           if (i == 0){ 
               cout << a[i];
            }
           else {
               cout << ' ' << a[i];
           }
           
        }
        cout << endl;            
    }
    
}
