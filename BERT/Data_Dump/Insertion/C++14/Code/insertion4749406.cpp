#include<iostream>
using namespace std;

int main(){
    int n,i,s,v,j,c[101];
    cin >> n;
    
    for(i=0; i<n; i++)cin >> c[i];
    for(s=0; s<n-1; s++)cout << c[s] << " ";
    cout << c[n-1] << endl;

    for(i=1; i<n; i++){
        v=c[i];
        j=i-1;
    while(j>=0&&c[j]>v){
        c[j+1]=c[j];
        j--;
    }
    c[j+1]=v;
    for(s=0;s<n-1;s++) cout << c[s] << " ";
    cout << c[n-1] << endl;
    }
    return 0;
}
