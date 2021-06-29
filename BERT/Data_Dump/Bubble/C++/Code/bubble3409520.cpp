#include<iostream>
using namespace std;
int main(){
    int n;
    int count=0;
    cin>>n;
    int a[n];
    for(int i=0; i<n; i++)  cin>>a[i];
    for(int j=1; j<n; j++){
        for(int i=n-1; i>=j; i--){
            if(a[i]<a[i-1]){
                int memo=a[i];
                a[i]=a[i-1];
                a[i-1]=memo;
                count++;
            }
        }
    }
    for(int i=0; i<n-1; i++)  cout<<a[i]<<" ";
    cout<<a[n-1]<<endl<<count<<endl;
}
