#include<iostream>
using namespace std;

int main(){
    int n,i,j,swap=0,minj,count=0;
    cin >> n;
    int a[n];

    for(i=0;i<n;i++) cin >> a[i];

    for(i=0;i<n-1;i++){
        minj = i;
        for(j=i;j<n;j++){
            if(a[j]<a[minj]) minj = j;
        }
        if(minj != i){
            swap = a[minj];
            a[minj] = a[i];
            a[i] = swap;
            count++;
        }
    }
    for(i=0;i<n;i++){
        cout << a[i];
        if(i!=n-1) cout << " ";
    }
    cout << endl;
    cout << count << endl;
    return 0;

}

