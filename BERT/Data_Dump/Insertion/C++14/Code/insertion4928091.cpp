#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;

int main(){
    int n;
    cin >> n;
    int a[n];
    for(int i = 0;i < n; i++){
        cin >> a[i];
    }
    for(int i = 0; i < n; i++){
        int v = a[i];
        int j = i-1;
        while(j >= 0 && a[j] > v){
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = v;

        for(int x = 0; x < n-1; x++){
            cout << a[x] << " ";
        }
        cout << a[n-1] << endl; 

    }
    

    
    return 0;
}
