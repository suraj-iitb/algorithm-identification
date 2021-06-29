#include <iostream>
using namespace std;
int main(void){
    int N;
    cin >> N;
    int a[101];
    for(int i = 0; i < N; i++){
        cin >> a[i];
    }
    int cnt = 0;
    int tmp;
    int i = 0;
    int flag = 1;
    while(flag){
        flag = 0;
        for(int j = N - 1; j >= i + 1; j--){
            if(a[j] < a[j - 1]){
                tmp = a[j];
                a[j] = a[j - 1];
                a[j - 1] = tmp;
                flag = 1;
                cnt++;
            }
        }
        i++;
    }
    for(int i = 0; i < N; i++){
        cout << a[i];
        if(i < N - 1)   cout << " ";
        else    cout << endl;
    }
    cout << cnt << endl;
    
}

