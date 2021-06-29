#include<iostream>
#include<vector>

using namespace std;
int main(){
    int n,i,k;
    int num=0;
    vector<int> a;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>k;
        a.push_back(k);
    }
    for(int i=0;i<n;i++){
        for(int j=n-1;j>=i+1;j--){
            if(a[j]<a[j-1]){
                num+=1;
                k=a[j];
                a[j]=a[j-1];
                a[j-1]=k;
            }
        }
    }
    for(int i=0;i<a.size();i++){
        if(i) cout<<' ';
        cout<<a[i];
    }
    cout<<endl<<num<<endl;
    return 0;
}

