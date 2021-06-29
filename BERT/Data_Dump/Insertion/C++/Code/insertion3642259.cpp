#include<iostream>
using namespace std;
int main(){
    int n,j,v;
    int s[100]={};
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>s[i];
        if(i==0) cout<<s[i];
        else  cout<<" "<<s[i];
    }
    cout<<endl;
    for(int i=1;i<n;i++){
        v=s[i];
        j=i-1;
        while(j>=0&&s[j]>v){
            s[j+1]=s[j];
            j--;
        }
        s[j+1]=v;
    for(int x=0;x<n;x++){
        if(x==0) cout<<s[x];
        else  cout<<" "<<s[x];
    }
    cout<<endl;
    }
}

