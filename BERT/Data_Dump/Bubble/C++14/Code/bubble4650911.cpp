#include <iostream>
#include <cstdio>
using namespace std;

int main(){
    int n, i, j, f, p, c;
    int list[100] = {};
    f = 1;
    c = 0;
    
    cin >> n;
    
    for(i = 0; i < n; i++){
        cin >> list[i];
    }
    

    while(f == 1){
        f = 0;
        for(j = n-1; j > 0; j--){
            if(list[j] < list[j-1]){
                swap(list[j], list[j-1]);
                f = 1;
                c++;
            }
        }
    }

    
    for(i = 0; i < n-1; i++){
        cout << list[i] << " ";
    }
    cout << list[i] << endl;
    cout << c << endl;
    
}
