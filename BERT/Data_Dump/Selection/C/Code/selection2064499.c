#include<stdio.h>

int main (void){

	int i, j ,t ,n ,x=0 ,minj;
	int a[100]; 
	scanf("%d" ,&n);
for(i = 0; i < n; i++){
	scanf("%d" , &a[i]);
}

for(i = 0;i < n-1; i++){
	minj = i;
	for(j = i;j < n;j++){
	if(a[j] < a[minj])
	minj = j;
}
	t = a[i]; a[i] = a[minj]; a[minj] = t;
	if(i != minj)x++;
	}
for(i = 0; i < n; i++){
	if(i > 0)
	printf(" ");
	printf("%d", a[i]);
}
	printf("\n");
	printf("%d\n" ,x);
return 0;

}
