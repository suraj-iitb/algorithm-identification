#include<iostream>
using namespace std;
int main(){
    int a=0,n;
    int bubble[100];
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>bubble[i];
    }
    for(int i=0;i<n;i++){
        for(int j=n-1;j>=i+1;j--){
            if(bubble[j]<bubble[j-1]){
                int swap=bubble[j];
                bubble[j]=bubble[j-1];
                bubble[j-1]=swap;
                a++;
            }
        }
    }
    for(int i=0;i<n-1;i++){
        cout<<bubble[i]<<" "<<flush;
    }
    cout<<bubble[n-1]<<endl;
    cout<<a<<endl;
    return 0;
}
