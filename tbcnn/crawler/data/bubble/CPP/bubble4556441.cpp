#include <iostream>
#include <cmath>
using namespace std;

void cout_array(int n,int a[]){
    for(int i = 0; i < n; i++){
        cout << a[i];
        if(i < n-1) cout << ' ';
    }
    cout << endl;
}

int main(){
    int n, A[100], times = 0;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> A[i];
    
    int flag = 1;
    int i = 0;//未ソート部分の先頭インデクス
    while(flag){
        flag = 0;
        for(int j = n-1; j >= i+1 ; j--){
            if(A[j] < A[j-1]){
                swap(A[j], A[j-1]);
                flag = 1;
                times++;
            }
        }
        i++;
    }
    cout_array(n, A);
    cout << times << endl;
    return 0;
}
