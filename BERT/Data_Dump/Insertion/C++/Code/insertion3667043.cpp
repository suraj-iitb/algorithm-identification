#include<iostream>
using namespace std;
int main(){
    int n;
    int a;
    int j;
    int x;
    cin >> n;
    int b[n];
    for(int i=0;i<n;i++){
        b[i]=0;
    }
    for(int i=0;i<n;i++){
        cin>>b[i];
    }
    for(int i=0;i<n;i++){
        a=b[i];
        j=i-1;
        while(j>=0 && b[j]>a){
            b[j+1]=b[j];
            j--;
        }
        b[j+1]=a;
        for(int j=0;j<n;j++){
            if(j!=n-1){
                cout << b[j] <<" ";
            }else{
                cout << b[j];
            }
        }cout <<endl;
        
    }
}
