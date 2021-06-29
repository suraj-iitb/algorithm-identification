#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void output(int *a,int n){
	int i;
	for(i=0;i<n;i++){
		printf("%d",a[i]);
		if(i!=n-1){
			printf(" ");
		}
	}
	printf("\n");
}

int main(){
	int n,s[100],i,j,v,tmp;
	char input[5*100+1],*p;
	
	fgets(input,sizeof input,stdin);
	sscanf(input,"%d",&n);
	
	fgets(input,sizeof input,stdin);
	
	p=strtok(input," ");
	s[0]=atoi(p);
	
	for(i=1;i<n;i++){
		p=strtok(NULL," ");
		s[i]=atoi(p);
	}
	output(s,n);
	for(i=1;i<n;i++){
		v=s[i];
		j=i-1;
		while(1){
			if(j<0||s[j]<=v){
				break;
			}
			s[j+1]=s[j];
			j--;
		}
		s[j+1]=v;
		output(s,n);
	}
	
	
	return 0;
}
