#include <iostream>
using namespace std;

int main(void){
    int n,i,j,minj,tmp,count,k, c[101];
    cin >> n;
    for(i = 0; i < n; i++){
        cin >> c[i];
    }
    i = 0;
    count = 0;
    for(i = 0; i < n; i++){
        minj = i;
        for(j = i; j < n; j++){if(c[j] < c[minj]) minj = j;}
        if(c[minj] == c[i]) continue;
        tmp = c[i];
        c[i] = c[minj];
        c[minj] = tmp; 
        count++;
    }
    for(k = 0; k < n; k++){
        cout << c[k];
        if(k == n - 1) {cout << endl;}
        else{ cout << " ";}
    }
    cout << count << endl;
}


