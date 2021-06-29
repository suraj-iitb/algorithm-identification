void intsertionSort(int *a,int n);

int main(){
	int a[1000],n,i;
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d",a+i);
	
	intsertionSort(a,n);
	
	//output
	for(i=0;i<n;i++){
		printf("%d",a[i]);
		if(i!=(n-1))
			printf(" ");
	}
	printf("\n");
	return 0;
}

void intsertionSort(int *a,int n){
	int i,j,k;
	int v;
	
	for(i=1;i<=n-1;i++){
		
		//output
		for(k=0;k<n;k++){
		printf("%d",a[k]);
		if(k!=(n-1))
			printf(" ");
		}
		printf("\n");
		
		//sort
		v=a[i];
		j=i-1;
		while((j>=0)&&(v<a[j])){
			a[j+1]=a[j];
			j--;
		}
		a[j+1]=v;
	}
}
