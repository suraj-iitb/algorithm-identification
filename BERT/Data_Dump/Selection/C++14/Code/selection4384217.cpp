#include <bits/stdc++.h>
using namespace std;

int main(){
//srandom((unsigned long)time(NULL));

int n;
cin>>n;
int a[n];
for(int i=0;i<n;i++){
    cin>>a[i];
}
int cnt=0;
for(int i=0;i<n;i++){
    int minj = i;
    for(int j=i;j<n;j++){
        if(a[j] < a[minj]){
            minj=j;
            
        }
    }
    if(i!=minj){
            cnt++;
            int tmp=a[i];
            a[i]=a[minj];
            a[minj]=tmp;
    }
    
}
for(int i=0;i<n-1;i++){
    cout<<a[i]<<" ";
}
cout<<a[n-1]<<endl;
cout<<cnt<<endl;

return 0;
}


