#include<stdio.h>

typedef struct {
	char mark;
	int num;
}card;

void swap(card *a,card *b);
int partition(card A[], int p, int r);
void quickSort(card A[], int p, int r);

int partition(card A[], int p, int r){
	int x=A[r].num;
	int i=p-1,j;
	for(j=p;j<r;j++){
		if(A[j].num<=x){
			i++;
			swap(&(A[i]),&(A[j]));
		}
	}
	swap(&(A[i+1]),&(A[r]));
	return i+1;
}

void swap(card *a,card *b){
	card tmp;
	tmp=*a;
	*a=*b;
	*b=tmp;
}

void quickSort(card A[],int p,int r){
	if(p<r){
		int q = partition(A,p,r);
		quickSort(A,p,q-1);
		quickSort(A,q+1,r);
	}
}

int main(void){
	static card A[100000],copy[100000];
	int n,base;
	int i,j;
	char mark_checker[4],checker_crt,check_num;
	int s_flag=1;
	scanf("%d%*c",&n);
	for(i=0;i<n;i++){
		scanf("%c%d%*c",&(A[i].mark),&(A[i].num));
	}
	for(i=0;i<n;i++){
		copy[i]=A[i];
	}
	quickSort(A,0,n-1);
	for(i=0;i<n-1;i++){
		if(A[i].num==A[i+1].num){
			base=A[i].num;
			mark_checker[0]=A[i].mark;
			mark_checker[1]=A[i+1].mark;
			if(i+2<n && base==A[i+2].num){
				mark_checker[2]=A[i+2].mark;
				if(i+3<n && base==A[i+3].num){
					mark_checker[3]=A[i+3].mark;
					i=i+3;
					check_num=3;
				}else{
					i=i+2;
					check_num=3;
				}
			}else{
				i=i+1;
				check_num=2;
			}
			checker_crt=0;
			for(j=0;j<n;j++){
				if(copy[j].num==base){
					if(mark_checker[checker_crt++]!=copy[j].mark){
						s_flag=0;
					}
					if(checker_crt>check_num-1){
						break;
					}
				}
			}
		}
	}		
	if(s_flag){
		printf("Stable\n");
	}else{
		printf("Not stable\n");
	}	
	for(i=0;i<n;i++){
		printf("%c %d\n",A[i].mark,A[i].num);
	}
	return 0;
}
