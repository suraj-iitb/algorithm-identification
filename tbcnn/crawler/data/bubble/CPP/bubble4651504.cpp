#include<iostream>
#include<cstdio>
using namespace std;

int main(){
    int n,A[100];
    cin >> n;

    for(int i=0;i<n;i++) cin >> A[i];

    int flag = 1;
    int x=0;
    while(flag){
        flag = 0;
        for(int j=n-1;j>0;j--){
            int v = A[j];
            if(A[j]<A[j-1]) {
              swap(A[j],A[j-1]);
              flag = 1;
              x++;
        }
    }

    }
    for(int i=0;i<n;i++){
        if(i==0)cout << A[i];
        else cout << " " << A[i];
    }
    cout << endl;
    cout << x << endl;
}
