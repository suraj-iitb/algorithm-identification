#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int bubble_sort(vector<int> &a,int n){
    int m=0;
    bool f=1;
    for(int i=0;f==true;i++){
        f=0;
        for(int j=n-1;j>=i+1;j--){
            if(a[j]<a[j-1]){
                
                swap(a[j],a[j-1]);
                m++;
                f=1;
            }
        }
        
    }
    return m;
}
int main(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int m=bubble_sort(a,n);
    for(int i=0;i<n;i++){
        if(i!=0)cout<<' ';
        cout<<a[i];
    }
    cout<<endl;
    cout<<m<<endl;
    
}
