#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >>n;
    int a[n];
    for(int i=0;i<n;i++)cin >> a[i];
    int count=0;
    int tmp;
    for(int i=0;i<n;i++){
        int mini=i;
        for(int j=i;j<n;j++){
            if(a[j]<a[mini]){
                mini=j;
            }
            }
        if(mini!=i){
                tmp=a[i];
                a[i]=a[mini];
                a[mini]=tmp;
                count++;
        }
    }
    for(int i=0;i<n;i++){
        if(i!=n-1)printf("%d ",a[i]);
        else{
            printf("%d\n",a[i]);
        }
    }
    cout << count << endl;
}
