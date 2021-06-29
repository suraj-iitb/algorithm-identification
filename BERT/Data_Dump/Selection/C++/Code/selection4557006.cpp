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
    
    //選択ソート O(n**2)
    for (int i = 0; i < n-1; i++){
        int minj = i;
        for (int j = i; j < n; j++){
            if (A[minj] > A[j]) minj = j;
        }
        if (i != minj){
            swap(A[i], A[minj]);
            times++;
        }
    }

    cout_array(n, A);
    cout << times << endl;
    return 0;
}
