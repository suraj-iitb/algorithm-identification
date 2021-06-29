#include <bits/stdc++.h>
using namespace std;

int r[500000];
int a[500000];
int cnt = 0;
void merge_sort(int s,int t){
    if(s == t) return ;
    int mid = (s + t) /2;
    merge_sort(s,mid);
    merge_sort(mid+1,t);
    
    int k = s;
    int i = s;
    int j = mid + 1;
    while(i <= mid && j <= t){
        if(a[i] <= a[j]){
            r[k] = a[i];
            i++;
            k++;
            cnt++;
        }else{
            r[k] = a[j];
            j++;
            k++;
            cnt++;
        }
    }
    while(i <= mid){
        r[k] = a[i];
        i++;
        k++;
        cnt++;
    }
    while(j <= t){
        r[k] = a[j];
        j++;
        k++;
        cnt++;
    }
    for(int i = s;i <= t;i++){
        a[i] = r[i];
    }
}
int main(){
    int n;
    cin >> n;
    for(int i = 0;i<n;i++){
        scanf("%d",&a[i]);
    }
    merge_sort(0,n-1);
    for(int i = 0;i<n;i++){
        if(i!=n-1) cout << a[i] << " ";
        else cout << a[i] << endl;
    }
    cout << cnt << endl;
    return 0;
}
