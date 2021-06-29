#include <iostream>
using namespace std;
int main(void){
    int N;
    cin >> N;
    int a[101];
    for(int i = 0; i < N; i++){
        cin >> a[i];
    }
    int minj, tmp;
    int cnt = 0;
    for(int i = 0; i < N; i++){
        minj = i;
        for(int j = i; j < N; j++){
            if(a[j] < a[minj]){
                minj = j;
            }
        }
        if(a[i] != a[minj]){
            tmp = a[i];
            a[i] = a[minj];
            a[minj] = tmp;
            cnt++;
        }
    }
    
    for(int i = 0; i < N; i++){
        if(i < N - 1)   cout << a[i] << " ";
        else    cout << a[i] << endl;
    }
    cout << cnt<< endl;
    
    return 0;
}

