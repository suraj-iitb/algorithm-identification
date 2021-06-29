#include<bits/stdc++.h>
using namespace std;

int bubblesort(int a[],int n){
    int sn = 0;
    int flag =1;
    for(int i = 0 ; flag;i++){
        flag = 0;
        for(int j = n - 1;j >= i + 1;j--){
            if(a[j] < a[j - 1]){
                swap(a[j],a[j - 1]);
                sn++;
                flag = 1;
            }
        }
    }
    return sn;
}

int main()
{
    int n;
    int a[105];
    cin >> n;
    for(int i = 0 ; i < n;i++){
        cin >> a[i];
    }
    int sn = bubblesort(a,n);
    for(int i = 0 ; i < n;i++){
        if(i) cout << " ";
        cout << a[i];
    }
    cout << endl << sn << endl;
    return 0;
}

