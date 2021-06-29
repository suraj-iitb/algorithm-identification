#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int a[n];
    int cnt = 0;
    int minj;

    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    for(int i = 0; i < n; i++){
        minj = i;
        for(int j = i; j < n; j++){
            if(a[j] < a[minj]){
                minj = j;
            }    
        }
        if(a[i] > a[minj])
            cnt++;
        int tmp = a[i];
        a[i] = a[minj];
        a[minj] = tmp;
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
