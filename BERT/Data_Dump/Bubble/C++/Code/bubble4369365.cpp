#include <bits/stdc++.h>
using namespace std;

int bubblesort (int a[], int n){
    int flag = 1;
    int i = 0;
    int count = 0;
    while(flag){
        flag=0;
        for(int j=n-1;j>i;j--){
            if(a[j]<a[j-1]){
                swap(a[j], a[j-1]);
                flag=1;
                count += 1;
            }
        }
        i++;
    }
    return count;
}

int main(){
    int n; cin >> n;
    int a[n];
    
    for (int i=0;i<n;i++)cin >> a[i];

    int count = bubblesort(a, n);

    for(int i=0;i<n;i++){
        cout << a[i];
        if(i<n-1)cout << " ";
        else cout << endl;
    }

    cout << count << endl;

}
