#include<bits/stdc++.h>                                                                                                                
using namespace std;
void trace(int a[],int n){ 
    for(int i=0;i<n;i++){
        if( i > 0 ) cout << ' ';
        cout << a[i];
    }   
    cout << '\n';
}

void insertionsort(int a[],int n){ 
    int j,v;
    for(int i=1;i<n;i++){
        v = a[i];
        j = i - 1;
        while(j >= 0 && a[j] > v){ 
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = v;
        trace(a,n);
    }   
}

int main(){
    int n;
    int a[100];
    cin >> n;
    for(int i=0;i<n;i++) cin >> a[i];

    trace(a,n);
    insertionsort(a,n);

    return 0;  
}
