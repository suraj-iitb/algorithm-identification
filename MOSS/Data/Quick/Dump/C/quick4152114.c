#include<stdio.h>
#define INFTY 1000000001
struct card{
	int num;
	char suit;
};//定义扑克牌结构体 
void merge(struct card s[],int left,int mid,int right){
	int n1=mid-left;
	int n2=right-mid;
	struct card l[n1+1],r[n2+1];
	int i,j,k;
	for(i=0;i<n1;i++)
	l[i]=s[left+i];
	for(i=0;i<n2;i++)
	r[i]=s[mid+i];
	l[n1].num =INFTY;
	r[n2].num =INFTY;
	i=0;
	j=0;
	for(k=left;k<right;k++){
		if(l[i].num<=r[j].num){
			s[k]=l[i];
			i++;
		}
		else{
			s[k]=r[j];
			j++;
		}
	}
}
void mergeSort(int s[],int left,int right){
	if(left+1<right){
		int mid=(left+right)/2;
		mergeSort(s,left,mid);
		mergeSort(s,mid,right);
		merge(s,left,mid,right);
	}
}//归并排序 
int partition(struct card a[],int p,int r) {
	int x=a[r].num;
	int i=p-1,j;
	struct card mid;
	for(j=p; j<r; j++) {
		if(a[j].num<=x) {
			i++;
			mid=a[i];
			a[i]=a[j];
			a[j]=mid;
		}
	}
	mid=a[i+1];
	a[i+1]=a[r];
	a[r]=mid;
	return i+1;
}
void quickSort(struct card a[],int p,int r){
	if(p<r){
		int q=partition(a,p,r);
		quickSort(a,p,q-1);
		quickSort(a,q+1,r);
	}
}//快速排序 
int main(){
	int n,i,t=1;
	scanf("%d",&n);
	getchar();
	struct card a[n],s[n];
	for(i=0;i<n;i++){
		scanf("%c%d",&a[i].suit,&a[i].num);
		if(i!=n-1)
		getchar();
	}//输入
	for(i=0;i<n;i++)
	s[i]=a[i];
	quickSort(a,0,n-1);
	mergeSort(s,0,n);
	for(i=0;i<n;i++){
		if(s[i].suit!=a[i].suit){
			printf("Not stable\n");
			t=0;
			break;
		}
	}
	if(t)
	printf("Stable\n");
	 for(i=0;i<n;i++){
		printf("%c %d\n",a[i].suit,a[i].num);
	}//输出 
}
