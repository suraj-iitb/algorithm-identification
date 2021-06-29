#include<stdio.h>
int search(int s[],int n,int key){
	int i=0;
	s[n]=key;
	while(s[i]!=key){
		i++;
	}
	return i!=n;
}
int main(){
	int n,s[10000+1],q,i,key,sum=0;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&s[i]);
	}
	scanf("%d",&q);
	for(i=0;i<q;i++){
		scanf("%d",&key);
		if(search(s,n,key)){
			sum++;
		}
	}
	printf("%d\n",sum);
	return 0;
}
