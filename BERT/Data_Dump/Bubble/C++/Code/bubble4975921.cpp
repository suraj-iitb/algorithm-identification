#include<iostream>
#include<cstdio>
using namespace std;

void BubbleSort(int a[], int n){
    bool flag=true;
    int c=0;
    while(flag){
        flag=false;
        for(int j=n-1; j>0; j--){
            if(a[j-1]>a[j]){
                swap(a[j-1],a[j]);
                flag=true;
                c++;
            }
        }
    }
    
    for(int i=0; i<n; i++){
        if(i!=n-1) cout << a[i] << " ";
        else cout << a[i] <<endl;
    }
    printf("%d\n",c);
}

int main(){
    int n;
    cin >> n;
    int a[110]={};
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    
    BubbleSort(a,n);
}
