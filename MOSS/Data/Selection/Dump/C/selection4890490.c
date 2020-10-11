#include <stdio.h>
//selection sort
void Selection_sort(int str[],int n){
	int i,j,temp,sum=0;
	int mini;
	for(i=0;i<n;i++){
		mini = i;
		for(j=i;j<n;j++){
			if(str[j]<str[mini]){
				mini = j;
				
			}
				
		}
		if(mini != i){
			temp = str[i];
		str[i]= str[mini];
		str[mini] =temp;
		sum++;
		}
		
		
	} 
	for(i = 0; i<n-1;i++){
		printf("%d ",str[i]);
	} 
	printf("%d\n",str[i]);
	printf("%d\n",sum);
	
}

int main(int argc, char *argv[]) {
	int i,str[200005],n;
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d",&str[i]);
	Selection_sort(str,n);
	return 0;
}

