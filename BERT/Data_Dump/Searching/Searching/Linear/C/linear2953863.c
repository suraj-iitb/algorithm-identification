#include<stdio.h>
int ls(int s[],int key,int n){
    int i=0;
    s[n]=key;
    while(s[i]!=key)
        i++;
    if(i==n)
        return 0;
    return 1;
}
int main(void){
    int n,q,s[10000],t[500],i,c=0;
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%d",&s[i]);
    scanf("%d",&q);
    for(i=0;i<q;i++){
        scanf("%d",&t[i]);
        if(ls(s,t[i],n)){c++;}
    }
    printf("%d\n",c);
	return 0;		
}
