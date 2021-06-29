#include <iostream>

using namespace std;

int main(){
    int n, i;
    cin >> n;
    int a[n];

    for(i = 0; i < n; ++i){
        cin >> a[i];
    }

    for(i = 0; i < n; ++i){
        if(i) cout << " ";
        cout << a[i];
    }
    cout << endl;
 
    for(i = 1; i < n; ++i){
        int key = a[i], j = i;
        while(j > 0 && a[j - 1] > key){
            a[j] = a[j - 1];
            --j;
        }
        a[j] = key;

        for(j = 0; j < n; ++j){
            if(j) cout << " ";
            cout << a[j];
        }
        cout << endl;
    }
}
