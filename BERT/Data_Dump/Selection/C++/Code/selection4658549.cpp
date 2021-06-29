#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,a[101];
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int at=0;
    for(int i=0;i<n;i++){
        int minj=i;
        for(int j=i;j<n;j++){
            if(a[j]<a[minj]){
                minj=j;
            }
        }
            if(minj!=i){
                swap(a[i],a[minj]);
                at++;
            }
            
    }
    for(int i=0;i<n;i++){
        cout<<(i==0?"":" ")<<a[i];
    }
    cout<<endl<<at<<endl;
    
}
