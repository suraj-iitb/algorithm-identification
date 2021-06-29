#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int a[n];
    int cnt = 0;

    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    for(int i = 0; i < n; i++){
        for(int j = n - 1; j >= i + 1; j--){
            if(a[j] < a[j - 1]){
                int tmp = a[j];
                a[j] = a[j - 1];
                a[j - 1] = tmp;
                cnt++;
            }
        }
    }
    
    for(int i = 0; i < n; i++){
        if(i < n - 1){
            cout << a[i] << ' ';
        }else{
            cout << a[i] << endl;
        }
    }
    cout << cnt << endl;
}

