#include <iostream>
using namespace std;
int main (){
    int n, key, flag = 1, flagflag = 0;
    cin  >> n; 
    int a[n];
    for (int k = 0; k < n; k++ ){
        cin >> a[k];
    }
    while (flag){
        flag = 0;
        for (int j = (n - 1); j > 0; j --){
            if (a[j] < a[j - 1]){
                key = a[j - 1] ;
                a[j - 1] = a[j];
                a[j] = key;
                flagflag += 1;
                flag = 1;
            }
        }
    }
    for (int k = 0; k < n; k ++ ){
        if (k == 0) cout << a[k];
        else cout << " " << a[k];
    }
    cout << endl;
    cout << flagflag << endl;
}
