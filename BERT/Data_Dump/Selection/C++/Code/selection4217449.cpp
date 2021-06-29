#include<iostream>
#include <cstdio>
#include<algorithm>
using namespace std;

int Print(int a[], int p){
    for(int i=0;i<p;i++){
        if(i>0)printf(" ");
        printf("%d",a[i]);
    }
	printf("\n");
}

int main(){
    int n;
    int a[100];
    cin >> n ;
    for(int i=0;i<n;i++)cin >> a[i] ;
    int count = 0 ;
    
    for(int i=0;i<n-1;i++){
        int ind = i ;
        for(int j=i;j<n;j++){
            if(a[j]<a[ind]){
                ind = j ;
            }
        }
        int tmp = a[i];
        a[i] = a[ind];
        a[ind] = tmp;
        if(i!=ind)count++;
    }
    Print(a,n);
    cout << count << endl;

    return 0 ;
}

