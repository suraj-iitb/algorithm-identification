#include<iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    int a[n];
    for(int i=0; i<n; i++)cin >> a[i];

    int sw=0;
    for(int i=0; i<n-1; i++){
        int mini=i;
        for(int j=i; j<n; j++){
            if(a[mini]>a[j])mini=j;
        }
        int t=a[i];
        a[i]=a[mini];
        a[mini]=t;
        if(mini != i)sw++;
    }
    
    for(int i=0; i<n; i++){
        if(i>0)cout << " ";
        cout << a[i];
    }
    cout << endl;
    cout << sw << endl;
    return 0;
}
