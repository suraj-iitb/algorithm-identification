#include<iostream>
using namespace std;
int main(){
    int n, cnt = 0;
    cin >> n;
    int R[n];
    for(int i = 0; i < n; i++){
        cin >> R[i];
    }
    for(int i = 0; i < n; i++){
        int minj = i;
        for(int j = i; j < n; j++){
            if(R[j] < R[minj]){
                minj = j;
            }
        }
        swap(R[i], R[minj]);
        if(i != minj)cnt++;
    }
    for(int i = 0; i < n; i++){
        if(i == n - 1){
            cout << R[i] << endl;
        }else{
            cout << R[i] << " ";
        }
    }
    cout << cnt << endl;
    return 0;
}
