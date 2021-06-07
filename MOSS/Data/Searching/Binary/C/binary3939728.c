#include<stdio.h>
int main(){
int ans=0,min,mid,max,i,n,q,s[101010],t[50010];
scanf("%d\n",&n);
for(i=0;i<n;i++){
scanf("%d",&s[i]);
}
s[i]=1000000010;
scanf("\n%d\n",&q);
for(i=0;i<q;i++){
scanf("%d",&t[i]);
}
for(i=0;i<q;i++){
min=0,max=n;
while(min<max){
mid=(min+max)/2;
if(s[mid]==t[i]){
ans++;
break;
}
else if(s[mid]<t[i]){
min=mid+1;
}
else{
max=mid;
}
}
}
printf("%d\n",ans);
return 0;
}
