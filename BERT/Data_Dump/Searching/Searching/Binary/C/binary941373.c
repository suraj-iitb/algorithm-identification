#include <stdio.h>
#define N 100000

int main(){
int i,s,n1,t,n2,teto[N],teto2[N],count=0;
int lef,mid,ri;
scanf("%d",&n1);
for(i=0;i<n1;i++){
scanf("%d",&teto[i]);
}
scanf("%d",&n2);
for(i=0;i<n2;i++){
scanf("%d",&teto2[i]);
}
for(i=0;i<n2;i++){
ri=n1-1;
lef=0;
while(lef<ri){
mid=(lef+ri)/2;
if(teto[mid]==teto2[i]||teto[lef]==teto2[i]||teto[ri]==teto2[i]){
count++;
break;
}
else if(teto[mid]<teto2[i]){
lef=mid+1;
}
else{
ri=mid;
}
}
}



printf("%d\n",count);


return 0;
}
