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
    
    int flag= 1;
    while(flag){
        flag = 0;
        for(int j=n-1;j>0;j--){
            if(a[j]<a[j-1]){
                int tmp = a[j-1];
                a[j-1] = a[j];
                a[j] = tmp ;
                count++;
                flag = 1;
            }
        }
    }
    
    Print(a,n) ;
    cout << count << endl;

    return 0 ;
}

