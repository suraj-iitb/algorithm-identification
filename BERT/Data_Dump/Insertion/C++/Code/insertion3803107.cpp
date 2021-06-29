#include <iostream>
#include <algorithm>

using namespace std;
int main() {
    int n;
    cin >> n; 
    int a[103];
    for (int i=0;i<n;i++){
        cin >>a[i];
    }
    for(int j=1;j<n;j++){
        int k=j-1;
        int v=a[j];
         for (int i=0;i<n-1;i++){
        cout << a[i]<<" ";
    }
    cout <<a[n-1]<<endl;
    while (1){
        if(k<0){
            break;
        }
        if(a[k]>v){
            a[k+1]=a[k];
            a[k]=v;
            }
        k--;
        v=a[k+1];
        } 
    }
         
    for (int i=0;i<n-1;i++){
        cout << a[i]<<" ";
    }
    cout <<a[n-1]<<endl;
    return 0;
}
