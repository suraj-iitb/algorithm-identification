#include<iostream>
using namespace std;
int main(){
    int x,n,min;
    int c=0;
    cin >> n;
    int b[n];
    for(int i=0;i<n;i++){
        cin>>b[i];
    }
    for(int i=0;i<n;i++){
        min=i;
        for(int j=i;j<n;j++){
            if(b[j]<b[min]){
                min=j;
            }
        }
        if(min!=i){
            x=b[i];
            b[i]=b[min];
            b[min]=x;
            c++;
        }
            
    }for(int i=0;i<n;i++){
        cout << b[i];
        if(i!=n-1)cout <<" ";
    }
    cout << endl << c << endl;
}
