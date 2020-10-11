#include<stdio.h>
#include<math.h>
#include<string.h>

#define MAX 100000

typedef struct Card{
	int number;
	char soot[10];
}card;

int partition(card A[], int p, int r){
	int x = A[r].number;
	card nu;
	int i = p - 1;
	for(int j = p; j < r; j++){
		if(A[j].number <= x){
			i = i + 1;
			nu = A[i];
			A[i] = A[j];
			A[j] = nu;
		}
	}
	nu = A[i + 1];
	A[i + 1] = A[r];
	A[r] = nu;
	return i + 1;
}

int quickSort(card A[], int p, int r){
	if(p < r){
		int q = partition(A, p, r);
		quickSort(A, p, q-1);
		quickSort(A, q+1, r);
	}
}

int isStable(card be_val[],card af_val[],int n){
	int lastNo = 0;
	int lastval = 0;
	for(int i = 0; i < n; i++){
		if(lastNo != af_val[i].number){
			lastNo = af_val[i].number;
			lastval = 0;
		}
		int u = lastval;
		for(; u < n;u++){
			if(af_val[i].number == be_val[u].number){
				if(strcmp(af_val[i].soot, be_val[u].soot) == 0){
					lastval = u + 1;
					u = n + 1000000;
				}else{
					return 0; //false
				}
			}
		}
		if(u < n + 1000000){
			return 0; //false
		}
	}
	return 1; //true
}


int main(){
	int n;
	card val[MAX];
	card valfirst[MAX];
	
	scanf("%d",&n);
	for(int i = 0; i < n; i++){
		scanf("%s",val[i].soot);
		scanf("%d",&val[i].number);
		valfirst[i].number = val[i].number;
		strcpy(valfirst[i].soot,val[i].soot);
	}

	quickSort(val,0,n-1);
	
	if(isStable(valfirst,val,n)){
		printf("Stable\n");
	}else{
		printf("Not stable\n");
	}
	
	for(int i = 0;i < n; i++){
		printf("%s %d\n",val[i].soot,val[i].number);
	}
	return 0;
}


