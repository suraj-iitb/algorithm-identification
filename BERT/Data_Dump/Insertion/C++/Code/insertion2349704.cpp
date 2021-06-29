/*
author:lingling
date:2017.06.01
description: ??°??????????????????????¢???????????????\??????
*/
#include<iostream> 
using namespace std;
void InsertSort(int a[],int n);
void PRINT(int a[],int n);
#define MAX 100
int main() {
    int N;
    int data[MAX];
    while(cin>>N) {
        for(int i=0;i<N;i++) cin>>data[i];
        InsertSort(data,N);
    }
    return 0;
}
void InsertSort(int a[],int n) {
    int key;
    int j;
    PRINT(a,n);
    cout<<endl;
    for(int i=1;i<n;i++) {
        key=a[i];//?????????????´?
        j=i-1;
        while(j>=0&&a[j]>key) {
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=key;
        PRINT(a,n);
       // if(i<n-1) cout<<endl;
       cout<<endl;
    }
}
void PRINT(int a[],int n) {
    for(int i=0;i<n;i++) {
        cout<<a[i];
        if(i<n-1) cout<<' ';
    }
 //  cout<<endl;
}
