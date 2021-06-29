#include<iostream>
using namespace std;
int main(){
    int b=0,n,i,minj,j,swap;
    int a[100];
    cin>>n;
    for(i=0;i<n;i++){
        cin>>a[i];
    }
    if(n>1){
        for(i=0;i<n-1;i++){
          
            minj=i+1;
            for(j=i+1;j<n;j++){
                if(a[minj]>a[j]){
                    
                    minj=j;
                }
            }
            if(a[minj]<a[i]){
                swap=a[i];
                a[i]=a[minj];
                a[minj]=swap;
                b++;
            }
            /*for(int k=0;k<n-1;k++){
                cout<<a[k]<<" "<<flush;
            }
            cout<<a[n-1]<<endl;*/
        }
    }
    else{
        cout<<a[0]<<endl;
        cout<<0<<endl;
        return 0;
    }
    for(i=0;i<n-1;i++){
        cout<<a[i]<<" "<<flush;
    }
    cout<<a[n-1]<<endl;
    cout<<b<<endl;
    return 0;
}
