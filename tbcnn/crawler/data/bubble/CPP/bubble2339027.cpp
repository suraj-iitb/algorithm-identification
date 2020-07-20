#include<bits/stdc++.h>
using namespace std;
int main(){
int x,y[1000],z=0;
scanf("%d",&x);
for(int i=0;i<x;i++){
    scanf("%d",&y[i]);
}
for(int i=0;i<x;i++){
    for(int j=0;j<x-1;j++){
        if(y[j]>y[j+1]){
            int h;
            h=y[j];
            y[j]=y[j+1];
            y[j+1]=h;
            z++;
        }
    }
}
for(int i=0;i<x;i++){
        if(i==x-1){
            printf("%d\n",y[i]);
        }else{
            printf("%d ",y[i]);
        }
}
printf("%d\n",z);
}
