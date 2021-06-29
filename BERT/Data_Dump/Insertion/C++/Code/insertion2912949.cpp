#include<bits/stdc++.h>
using namespace std;
void trace(int a[],int n){
    for(int i = 0 ; i < n;i++){
        if(i)   cout << " ";
        cout << a[i];
    }
    cout << endl;
}
///插入排序
void insertSort(int a[],int n){
    int i,j,v;
    for(int i = 1 ; i < n;i++){
        v = a[i];
        j = i - 1;
        while(j>=0 && a[j] > v){
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = v;
        trace(a,n);
    }
}
int main()
{
    int n;
    int a[1005];
    cin >> n;
    for(int i = 0 ;i < n;i++)cin >> a[i];

    trace(a,n);
    insertSort(a,n);

    return 0;
}

