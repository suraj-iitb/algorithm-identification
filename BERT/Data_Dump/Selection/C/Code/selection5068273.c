#include <stdio.h>
int main(){
    int num[100],n,i,j,position,swap,cnt=0;
    scanf("%d",&n);
    for(i=0;i<n;i++) scanf("%d",&num[i]);
    for(i=0;i<n-1;i++){
        position=i;
        for(j=i+1;j<n;j++){
            if(num[position]>num[j])
            position=j;
            }
            if(position!=i){
            swap=num[i];
            num[i]=num[position];
            num[position]=swap;
            cnt++;
            }
        }
    for(i=0;i<n-1;i++) printf("%d ",num[i]);
    printf("%d\n",num[n-1]);
    printf("%d\n",cnt);
}

