#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n, i, p, j, k;
    cin >> n;
    
    int list[101] = {};
    
    for(i = 0; i < n; i++){
        cin >> p;
        list[i] = p;
    }
    
    for(i = 0; i < n; i++){
        p = list[i];
        j = i - 1;
        while(j >= 0 && list[j] > p){
            list[j+1] = list[j];
            j--;
        }
        list[j+1] = p;
        for(k = 0; k < n; k ++){
            cout << list[k];
            if(k == n-1) cout << endl;
            else cout << " " ;
        }
    }
    
}

