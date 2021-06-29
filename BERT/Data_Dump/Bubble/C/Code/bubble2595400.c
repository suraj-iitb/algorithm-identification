#include<stdio.h>
int main (void){

int a[100], b[2], n = 0, m, i, j, k, l, f = 1;//a ??°??????b ????????¨???n ???????????° m ??°????????????

scanf("%d",&m);


for(i = 1; i <= m; i++){
	scanf("%d",&a[i]);
}

while(f != 0){   

	for( k = 1; k < m; k++){
		if( a[k] > a[k + 1]){

			b[1] = a[k];
			b[2] = a[k + 1];
			a[k] = b[2];
			a[k + 1] = b[1];
			
			n++;
		}

	}
	f = 0;

	for( j = 1; j < m; j++ ){
		if( a[j] > a[j + 1]){
			f++;
		}	
	}

}

for( l = 1; l < m; l++ ){
	printf("%d ",a[l]);
}

printf("%d\n",a[m]);

printf("%d\n",n);

return 0;
}
