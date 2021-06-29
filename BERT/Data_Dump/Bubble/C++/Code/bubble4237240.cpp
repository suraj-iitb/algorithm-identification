#include<bits/stdc++.h>
using namespace std;
//#define int long long
#define debug(x) cout<<#x<<"->"<<x<<endl
#define sz(data) sizeof(data)/sizeof(data[0])

int cnt;

void bubbleSort(int a[],int n){

    for(int i=0;i<n-1;i++){
        for(int j=n-1;j>=i+1;j--){
            if(a[j]<a[j-1]){
                int temp=a[j];
                a[j]=a[j-1];
                a[j-1]=temp;
                cnt++;
            }
        }
    }

}


int main(){
   //freopen("input.txt" ,"r", stdin);

    int n; cin>>n;
    int a[n];
    for(int i=0;i<n;i++) cin>>a[i];

    bubbleSort(a,n);
    for(int i=0;i<n;i++){
            if(i==n-1) cout<<a[i]<<endl;
    else
            cout<<a[i]<<' ';
    }
    cout<<cnt;
    cout<<endl;



}

