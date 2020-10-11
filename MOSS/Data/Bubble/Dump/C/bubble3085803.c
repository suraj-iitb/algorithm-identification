#include <stdio.h>

void outputArray(int arr[], int s){
	int i;
	for(i=0;i<s;i++){
		printf("%d",arr[i]);
		if(i!=s-1){putchar(' ');}
		else      {putchar('\n');}
	}
}

int main(){
	int n, i, v, swipes = 0;
	int flag = 1;
	scanf("%d", &n);
	int a[n];
	for(i=0;i<n;i++){
		scanf("%d", &a[i]);
	}

	//bubble sort
	while(flag){
		flag = 0;

        for(i=n-1;i>=1;i--){
            if(a[i-1]>a[i]){

				v = a[i-1];
				a[i-1] = a[i];
				a[i] = v;
				swipes++;
				flag = 1;
            }
        }

	}
	outputArray(a, n);
	printf("%d",swipes);
	putchar('\n');

}

