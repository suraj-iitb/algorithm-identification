#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
	int n,i,j,min,a[100],tmp,count=0;
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
	
	for(i=0;i<n;i++){
		min=i;
		for(j=i;j<n;j++){
			if(a[min]>a[j]){
				min=j;
			}
		}
		if(min!=i){
			tmp=a[i];
			a[i]=a[min];
			a[min]=tmp;
			count++;
		}
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
