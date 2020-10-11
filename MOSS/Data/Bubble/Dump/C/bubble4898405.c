   
#include<stdio.h>
int main(){

int i,j,n,c=0;
scanf("%d",&n);
int s[n];

for(i=0;i<n;i++){
    scanf("%d",&s[i]);


}

for(i=1;i<n;i++)
for(j=0;j<n-1;j++){
    if(s[j]>s[j+1]){
        int temp =s[j];
        s[j]=s[j+1];
        s[j+1]=temp;
        c++;

    }



}


for(i=0;i<n;i++)
    if(i==n-1)
printf("%d\n",s[i]);
else
    printf("%d ",s[i]);


printf("%d\n",c);


}
