 #include <stdio.h>
 
 
//selection sort
void Selection_sort(int str[],int n){
	int i,j;
	int temp; 
	int mini;
	int sum=0;
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

int  main(int argc, char *argv[]) {
	int i,n;
	int newStr[100];
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&newStr[i]);
	} 		
	Selection_sort(newStr,n);
	return 0;
}
