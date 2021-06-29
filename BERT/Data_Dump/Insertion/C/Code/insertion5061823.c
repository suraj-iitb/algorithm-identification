#include<stdio.h>
int main(){
    int i,j,cnt,temp,num[100];
    scanf("%d",&cnt);
    for(i=0;i<cnt;i++) scanf("%d",&num[i]);
    for(i=0;i<cnt;i++){
        for(j=0;j<cnt;j++){
            if(j==cnt-1) printf("%d\n",num[j]);
            else printf("%d ",num[j]);
        }
        temp=num[i+1];
        j=i;
        while((temp<num[j])&&(j>=0)){
            num[j+1]=num[j];
            j=j-1;
        }
        num[j+1]=temp;
    }
}
