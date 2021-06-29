#include <iostream>
using namespace std;

int main(){
    int x;
    cin >> x;
    int a[x];
    for(int i=0; i<x; i++){
        cin >> a[i];
    }
    //プリント
        for(int k=0; k<x-1; k++){
            cout << a[k] << " ";
        }
        cout << a[x-1] << endl;
    //ソート
    for(int i=1; i<x; i++){
        int v = a[i];
        int j = i-1;
        while(j>=0 && a[j]>v){
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = v;
        //プリント
        for(int k=0; k<x-1; k++){
            cout << a[k] << " ";
        }
        cout << a[x-1] << endl;
    }

    return 0;
}
