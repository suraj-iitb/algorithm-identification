#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a.at(i);
    }
    int counter=0;
    for(int i=0;i<n;i++){
        int minj=i;
        int flag=0;
        for(int j=i+1;j<n;j++){
            if(a.at(minj)>a.at(j)){
                minj=j;
                flag=1;
            }
        }
        if(flag){
        swap(a.at(i),a.at(minj));
        counter++;
        }
    }
    for(int i=0;i<n-1;i++){
        cout<<a.at(i)<<' ';
    }
    cout<<a.at(n-1)<<endl<<counter<<endl;
}
