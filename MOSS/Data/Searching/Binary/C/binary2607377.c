#include <stdio.h>
int main()
{
int n,S[100000]={-1},q,t,a=0;
scanf("%d",&n);
int i;
for(i=0;i<n;i++)
scanf("%d",&S[i]);
scanf("%d",&q);
 
for(int i=0;i<q;i++){
scanf("%d",&t);
int left=0,right=n-1;
while(left<=right){
int mid=(left+right)/2;
if(t==S[mid]){
right=-1;
break;
}
else if(t>S[mid])
left=mid+1;
else
right=mid-1;
}
if(right==-1)
a++;
    }
printf("%d\n",a);
    
return 0;
}
