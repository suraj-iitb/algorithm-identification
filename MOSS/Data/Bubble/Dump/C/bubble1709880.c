#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
	int n,i,j,k,a[100],tmp,count=0;
	char input[4001],*p;
	
	fgets(input,sizeof input,stdin);
	sscanf(input,"%d",&n);
	
	fgets(input,sizeof input,stdin);
	p=strtok(input," ");
	a[0]=atoi(p);
	
	for(i=1;i<n;i++){
		p=strtok(NULL," ");
		a[i]=atoi(p);
	}
	
	k=n-1;
	for(i=0;i<n-1;i++){
		for(j=0;j<k;j++){
			if(a[j]>a[j+1]){
				tmp=a[j];
				a[j]=a[j+1];
				a[j+1]=tmp;
				count++;
			}
		}
		k--;
	}
	for(i=0;i<n;i++){
		printf("%d",a[i]);
		if(i!=n-1){
			printf(" ");
		}
	}
	printf("\n%d\n",count);
	
	
	
	
	return 0;
}
