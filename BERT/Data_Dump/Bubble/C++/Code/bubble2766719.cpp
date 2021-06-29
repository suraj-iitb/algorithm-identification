#include<iostream>
using namespace std;

int main(){
    int n, t, m = 0;
    int a[100] = {};
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    int flag = 1;

    while(flag){
        flag = 0;
        for (int j = n-1; j > 0; j--){
            if (a[j] < a[j-1]){
                t = a[j];
                a[j] = a[j-1];
                a[j-1] = t;
                flag = 1;
                m++;
            }
        }
    }
    for (int k = 0; k < n; k++){
        cout << a[k];
        if (k != n-1) cout << " "; 
    }
    cout << "\n";
    cout << m << endl;
    return 0;

}
