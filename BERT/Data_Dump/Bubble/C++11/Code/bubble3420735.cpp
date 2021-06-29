#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    vector<int>a;
    cin>>n;
    int cnt=0;
    a.resize(n);
    for(int i=0;i<n;i++)
        cin>>a[i];
    for(int i=1;i<n;i++)
        for(int j=0;j<n-i;j++){
            if(a[j]>a[j+1]){
                int t=a[j];
                a[j]=a[1+j];
                a[j+1]=t;
                cnt++;
            }
        }
    for(int i=0;i<n;i++){
        if(i>0)
            cout<<" ";
        cout<<a[i];
    }
    cout<<endl<<cnt<<endl;
    return 0;
}

