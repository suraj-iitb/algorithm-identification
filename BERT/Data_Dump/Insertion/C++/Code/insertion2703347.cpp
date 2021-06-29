#include<iostream>
using namespace std;

void dispCurState(int n, int a[]){
    for(int i = 0; i < n; i++){
        if(i) cout << " ";
        cout << a[i];
    }
    cout << endl;
}

int main(void){
    int n, a[100], cur, j;
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
    dispCurState(n, a);

    for(int i = 1; i < n; i++){
        cur = a[i];
        j = i - 1;
        while(j >= 0 && a[j] > cur){
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = cur;
        dispCurState(n, a);
    }
    return 0;
}
