#include <stdio.h>

#define MAX 100000

int linearSearch(int*,int,int);

int main(){

int n,s[MAX],q,t[MAX],i,j,count=0;

scanf("%d",&n);
for(i=0;i<n;i++) scanf("%d",&s[i]);
scanf("%d",&q);
for(i=0;i<q;i++) scanf("%d",&t[i]);

/*for(i=0;i<n;i++){
for(j=0;j<q;j++){

if(s[i]==t[j]) count++;

}
}*/

for(i=0;i<q;i++){

if(linearSearch(&s[0],n,t[i])==1) count++;

}

printf("%d\n",count);

return 0;

}

int linearSearch(int A[], int n, int key){

int i;

for(i=0;i<n;i++){

if(A[i]==key) return 1;

} 

return 0;

}
