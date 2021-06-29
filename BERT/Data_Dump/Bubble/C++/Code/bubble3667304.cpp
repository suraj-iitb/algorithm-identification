#include<iostream>
using namespace std;
int main(){
    int x,y,n;
    int c=0;
    cin >> n;
    int b[n];
    for(int i=0;i<n;i++){
        cin>>b[i];
    }
    int flag=1;
    while(flag==1){
        flag=0;
        for(int j=0;j<n;j++){
            if(b[j]<b[j-1]){
                x=b[j];
                y=b[j-1];
                b[j]=y;
                b[j-1]=x;
                flag=1;
                c++;
            }
        }
        
    }for(int i=0;i<n;i++){
        cout << b[i];
        if(i!=n-1)cout <<" ";
    }cout<<endl << c <<endl;
}
