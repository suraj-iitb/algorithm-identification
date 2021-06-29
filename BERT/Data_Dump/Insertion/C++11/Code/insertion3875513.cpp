#include <iostream>
#include <stdio.h>
using namespace std;
int main()
{
    int n;
    int data[101];
    cin>>n;
    for(int i=0;i<n;i++){
        scanf("%d",&data[i]);
    }
    for(int i=0;i<n-1;i++){
        printf("%d ",data[i]);
    }printf("%d\n",data[n-1]);
    
    for(int i=1;i<n;i++){
        int v = data[i];
        int j = i-1;
        while(j >= 0 && data[j] > v){
            data[j+1] = data[j];
            j--;
        }
        data[j+1]=v;
        for(int i=0;i<n-1;i++){
            printf("%d ",data[i]);
        }printf("%d\n",data[n-1]);
    }
}
