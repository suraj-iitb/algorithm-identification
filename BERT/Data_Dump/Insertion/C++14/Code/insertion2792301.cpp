#include <iostream>

using namespace std;

void putarray(int a[100],int n){
    for(int i=0;i<n;i++){
        cout << a[i] ;
        if (i!=n-1){
            cout << " ";
        }
    }
    cout << endl;
}
int main(){
    int n;
    cin >> n;
    int a[100];
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    for(int i=1;i<n;i++){
        putarray(a,n);
        int v=a[i];
        int j=i-1;
        while(j>=0 && a[j]>v){
            a[j+1]=a[j];
            j--;
            a[j+1]=v;
        }
    }
    putarray(a,n);
    return 0;
}
