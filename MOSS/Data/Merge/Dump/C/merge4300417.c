#include<stdio.h>


int L[500010],time=0;
int temp[500000];
void merge_me(int L[],int L1,int R1,int L2,int R2){
	int i=L1,j=L2,index=0;
	for( ;i<=R1&&j<=R2;)
		if(L[i]<=L[j]) {temp[index++]=L[i++];time++;}
		else {temp[index++]=L[j++];time++;}
	while(i<=R1) {temp[index++]=L[i++];time++;}
	while(j<=R2) {temp[index++]=L[j++];time++;}//完成合并
	for(i=0,j=L1;i<index;++i)//{
		L[j++]=temp[i];
		//printf("%d ",temp[i]);}
} 
void mergesort_me(int L[],int L0,int R0){
	if(L0<R0){
		int t=(L0+R0)/2;
		mergesort_me(L,L0,t); //在这里犯了低级错误，以为L0和R0没有改变，果然还是没理解递归
		mergesort_me(L,t+1,R0); //其实把它当做左右子树处理来理解很清晰
		merge_me(L,L0,t,t+1,R0);}
} 

int main(){
	int n,l,r;
	scanf("%d",&n);
	if(n>5.e5) n=5.e5;
	for(int i=0;i<n;++i)
		scanf("%d",L+i);
	l=0,r=n-1;
	mergesort_me(L,l,r);
	for(int i=0;i<n;++i)
		if(i) printf(" %d",L[i]);
		else printf("%d",L[i]);
	printf("\n%d\n",time);

	return 0;
}
