#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int a[n];

    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    int count = 0;
    
    int flag = 1;
    while(flag){
        flag = 0;
        for(int j = n-1; j >= 1; j--){
            if(a[j] < a[j-1]){
                int tmp;
                tmp = a[j];
                a[j] = a[j-1];
                a[j-1] = tmp;
                flag = 1;
                count++;
            }
        }
    }
    
    for(int i = 0; i < n-1; i++){
        cout << a[i] << " ";
    }

    cout << a[n-1] << endl;
    cout << count << endl;
}
