#include<stdio.h>
#include<string.h>
void quicksort(int*,char *,int,int);
int partition(int *,char *,int,int);
int main(){
	int i,j,f=0,n,count=0;
	char g;
	scanf("%d",&n);
	int N[n],M[n];
	char T[n],Y[n],B[n];
	for(i=0;i<n;i++){
		scanf("%c%c %d",&g,&T[i],&N[i]);
		M[i]=N[i];
		Y[i]=T[i];
		}
	quicksort(N,T,0,n-1);
	
	for(i=0;i<n;i++){
		if(i==0){
			for(j=0;j<n;j++){
				if(N[i]==M[j]) {
					B[count]=Y[j];
					count++;
					}
			}
		}
		else if(N[i-1]<N[i]){
			for(j=0;j<n;j++){
				if(N[i]==M[j]) {
					B[count]=Y[j];
					count++;
					}
			}
		}
	}
	
	for(i=0;i<n;i++){
		//printf("%c ",B[i]);
		if(B[i]==T[i]) f++;
		}
		//printf("\n");
		if(f!=n) printf("Not stable\n");
	if(f==n) printf("Stable\n");
	for(i=0;i<n;i++){
		printf("%c %d\n",T[i],N[i]);
	}
	return 0;
}

void quicksort(int *a,char *t,int p,int r){
	int q;
	int i;
	if(p<r){
	q = partition(a,t,p, r);
   	quicksort(a,t,p,q-1);
   	quicksort(a,t,q+1,r);
   		}
}
int partition(int *a,char *t,int p,int r){
	int x,i,j,k;
	char v;
	x=a[r];
	i=p-1;
	for(j=p;j<r;j++){
		if(a[j]<=x){
			i=i+1;
			k=a[i];
			a[i]=a[j];
			a[j]=k;
			v=t[i];
			t[i]=t[j];
			t[j]=v;

		}
	}
	v=t[r];
	t[r]=t[i+1];
	t[i+1]=v;

	a[r]=a[i+1];
	a[i+1]=x;
	return i+1;
}
