#include <iostream>
using namespace std;

void kaidaharu(int a[100], int n){
    for (int i = 1; i <= n-1; i++){
        for (int j = 0; j < n-1; j++){
       cout << a[j] << " ";
   }
    cout << a[n-1] << endl;
    
        int v = a[i];
        int j = i-1;
        while (j >= 0 && a[j] > v){
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = v;
    }
}    

int main(void){
   int n;
   cin >> n;
   int a[100];
   for (int i = 0; i < n; i++){
       cin >> a[i];
   }
   
   kaidaharu (a, n);
   
   for (int i = 0; i < n-1; i++){
       cout << a[i] << " ";
   }
    cout << a[n-1] << endl;
}

