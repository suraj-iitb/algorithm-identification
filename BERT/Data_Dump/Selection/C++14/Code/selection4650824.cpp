#include <iostream>
#include <cstdio>
using namespace std;

int main(){
    int n, i, j, c, minj, tmp;
    int list[100] = {};
    c = 0;
    
    cin >> n;
    
    for(i = 0; i < n; i++){
        cin >> list[i];
    }
    
    for(i = 0; i < n; i++){
        minj = i;
        for(j = i; j < n; j++){
            if(list[j] < list[minj]){
                minj = j;
            }
        }
        if(i != minj){
            swap(list[i], list[minj]);
            c++;
        }
    }
    
    for(i = 0; i < n; i++){
        cout << list[i];
        if(i == n-1) cout << endl;
        else cout << " ";
    }
    
    cout << c << endl;
}
