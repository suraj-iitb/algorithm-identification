#include <bits/stdc++.h>
using namespace std;

int selectionsort(int a[], int n){
    int count=0;

    for(int i=0;i<n;i++){
        int minj=i;
        for(int j=i;j<n;j++){
            if(a[j]<a[minj])minj=j;
        }
        swap(a[i], a[minj]);
        if(i!=minj)count += 1;
    }

    return count;
}

int main(){
    int n, count; cin >> n;
    int a[n];

    for(int i=0;i<n;i++)cin >> a[i];

    count = selectionsort(a, n);

    for(int i=0;i<n;i++){
        if(i)cout << " ";
        cout << a[i];
    }

    cout << endl << count << endl;;
}

