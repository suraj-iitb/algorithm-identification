#include <iostream>
using namespace std;
int main(){
    int n;cin>>n;
    int a[n];
    for(int i = 0; n > i; i++){
        cin>>a[i];
        cout << a[i];
        if(i+1!=n)cout << " ";
    }
    cout << endl;
    for(int i = 1; n > i; i++){
        int v = a[i];
        int j = i-1;
        while(j >= 0 && a[j] > v){
          a[j+1]=a[j];
          j--;
        }
        a[j+1]=v;
        for(int j = 0; n > j; j++){
          cout << a[j];
          if(j+1!=n)cout << " ";
        }
        cout << endl;
    }
}
