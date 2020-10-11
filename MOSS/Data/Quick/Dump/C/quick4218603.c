#include <stdio.h>
#define m 100000
struct Card{
	char c;int v;
};
struct Card L[m/2+2],R[m/2+2];
void swap(struct Card A,struct Card B){
	struct Card t = A;
	A = B;
	B = t;
}
void merge(struct Card a[],int left,int mid,int right){
	int i,j,k;
	int n1 = mid - left;
	int n2 = right - mid;
	for(i=0;i<n1;i++) L[i] = a[left+i];
	for(i=0;i<n2;i++) R[i] = a[mid+i];
	i = j = 0;
	L[n1].v = R[n2].v = 2000000000;
	for(k=left;k<right;k++){
		if(L[i].v<=R[j].v) a[k] = L[i++];
		else a[k] = R[j++];
	}
}
void mergeSort(struct Card a[],int left,int right){
	if(left+1<right){
		int mid = (left+right)/2;
		mergeSort(a,left,mid);
		mergeSort(a,mid,right);
		merge(a,left,mid,right);
	}
}
int partition(struct Card a[],int left,int right){
	struct Card x,t;
	x = a[right];
	int i = left - 1;
	for(int j=left;j<right;j++){
		if(a[j].v<=x.v){
			i++;
			t = a[i];a[i] = a[j];a[j]=t;
		}
	}
	t = a[i+1];a[i+1] = a[right];a[right]=t;
	return i+1;
} 
void quickSort(struct Card a[],int left,int right){
	if(left<right){
		int p = partition(a,left,right);
		quickSort(a,left,p-1);
		quickSort(a,p+1,right);
	}
}
int main(){
	struct Card A[m],B[m];
	int n,i,num;
	char s[10]; 
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%s %d",s,&num);
		A[i].c=B[i].c=s[0];
		A[i].v=B[i].v=num;
	}
	mergeSort(A,0,n);
	quickSort(B,0,n-1);
	int flag = 1;
	for(i=0;i<n;i++){
		if(A[i].c != B[i].c){
			flag = 0;
			break;
		}
	}
	if(flag) printf("Stable\n");
	else printf("Not stable\n");
	for(i=0;i<n;i++){
		printf("%c %d\n",B[i].c,B[i].v);
	}
	return 0;
}
