#include<iostream>
#include<algorithm>
using namespace std;

int fuc(int n,int a[]){
    int flag=1;
    int ans=0;
    int j=0;
    while (flag!=0) {
        flag=0;
        for(int i=n-1;i>j;i--){
            if (a[i]<a[i-1]) {
                swap(a[i], a[i-1]);
                flag=1;
                ans++;
            }
        }
        j++;
    }
    for (int i=0; i<n-1; i++) {
        cout<<a[i]<<" ";
    }
    cout<<a[n-1]<<endl;
    return ans;
}

int main(){
    int n,a[100];
    cin>>n;
    for (int i=0; i<n; i++) {
        cin>>a[i];
    }
    cout<<fuc(n,a)<<endl;
    return 0;
}
