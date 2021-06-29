#include<iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    int a[n] = {};
    for (int i=0;i<n;i++){
        cin >> a[i];
    }
    int b;
    int count = 0;
    for (int j=n-1;j>-1;j--){
        for (int k=0;k<j;k++){
            if (a[k] > a[k+1]){
              b = a[k];
              a[k] = a[k+1];
              a[k+1] = b;
              count +=1;    
            }
        }
    }
    for (int l=0;l<n;l++){
        cout <<a[l];
        if (l!=n-1) cout << " ";
    }
    cout << endl << count <<endl;
    return 0;
}
