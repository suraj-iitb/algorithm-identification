#include <bits/stdc++.h>
using namespace std;

int main(void){
    int n;
    cin>>n;
    vector<int> vec(n);
    int i,j,v;
    for(i=0;i<n;i++){
        cin>>vec[i];
        if(i<n-1)cout<<vec[i]<<" ";
        if(i==n-1)cout<<vec[i]<<endl;
    }
    for(i=1;i<n;i++){
        v=vec[i];
        j=i-1;
        while(j>=0&&vec[j]>v){
            vec[j+1]=vec[j];
            j--;
            vec[j+1]=v;
        }
        for(j=0;j<n-1;j++){
            cout<<vec[j]<<" ";
        }
        cout<<vec[n-1]<<endl;
    }
}
