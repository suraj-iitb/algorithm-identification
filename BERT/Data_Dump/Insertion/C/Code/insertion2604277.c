#include<stdio.h>

int main(void){

int o,n,k,i,j;

int key;
int a[1100];

scanf("%d",&n);

for(i=1;i<=n;i++)
scanf("%d",&a[i]);

for(j=1;j<=n;j++){

key = a[j];
i = j-1;

while(i>0 && a[i]>key){

a[i+1]=a[i];
i = i-1;

}

a[i+1] = key;

for(k=1;k<=n;k++){

if(k == n){
printf("%d\n",a[k]);
}

else{
printf("%d ",a[k]);
}

}

}

return 0;
}
