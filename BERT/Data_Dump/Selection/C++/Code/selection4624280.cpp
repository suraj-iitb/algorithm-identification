#include <bits/stdc++.h>
using namespace std;
 
int selectionsort(vector<int> &a,int n){
    int cnt=0;
    for(int i=0;i<n;i++){
        int minj=i;
        for(int j=i;j<n;j++){
            if(a[j]<a[minj]){
                minj=j;
            }
        }
        if(a[i]==a[minj])cnt--;
        swap(a[i],a[minj]);
        cnt++;
    }
    return cnt;
}
int main(){
    int n;
    cin >> n;
    vector<int>a(n);
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    int ans=selectionsort(a,n);
    for(int i=0;i<n;i++){
        cout << a[i];
        if(i<n-1)cout << " ";
    }
    cout << endl << ans << endl;
}

