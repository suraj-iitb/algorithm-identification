#include <iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int a[n];
    for (int i=0;i<n;i++){
        cin>>a[i];
    }
    int count=0;
    for (int i=0;i<n;i++){
        int min =i;
        for(int j=i;j<n;j++){
            if(a[j]<a[min]){
                min=j;
            }
        }
        if(min!=i){
            int ans=a[i];
            a[i]=a[min];
            a[min]=ans;
            count++;
        }
        
    }
    for (int i=0;i<n-1;i++){
        cout<<a[i]<<" ";
    }cout<<a[n-1]<<endl;
    cout<<count<<endl;
    return 0;
}
