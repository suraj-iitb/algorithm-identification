#include<iostream>

using namespace std;
int main(){
    int n,a[101],counter = 0;
    cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }
    for(int i = 0; i < n; ++i){
        for(int j = (n-1); j > i; --j){
            if(a[j-1]>a[j]){
                swap(a[j-1], a[j]);
                counter++;
            }
        }
    }
    for(int i = 0; i < n; ++i){
        cout << a[i];
        if(i == (n-1))cout << endl;
        else cout << " ";
    }
    cout << counter << endl;
}
