#include<stdio.h>

int n;

int change_count(int a[n][n],int b[n], int c[n], int k, int deep);

int main(void)
{
	scanf("%d",&n);
	
	int i,j;
	
	int a[n][n];
	
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			a[i][j] = 0;
		}
	}
	
	int u,k,v;
	
	for(i=0;i<n;i++){
		scanf("%d %d",&u,&k);
		
		for(j=0;j<k;j++){
			scanf("%d",&v);
			
			a[u-1][v-1] =1;
		}
	}
	
	int b[n];
	
	for(i=0;i<n;i++){
		b[i] = -1;
	}
	
	b[0] = 0;
	
	int c[n];
	
	int count = 0;
	
	int deep = 1;
	
	for(i=0;i<n;i++){
		if(a[0][i] == 1){
			c[count] = i;
			b[i] = deep;
			count++;
			
			for(k=0; k<n; k++){
				a[k][i] = 0;
			}
		}
	}
	
	while(count != 0){
		deep++;
		count = change_count(a,b,c,count,deep);
	}
	
	for(i=0;i<n;i++){
		printf("%d %d\n",i+1,b[i]);
	}
	
	return 0;
}

int change_count(int a[n][n],int b[n], int c[n], int k, int deep)
{
	int count=0;
	int x;
	int i,j,y;
	int d[n];
	
	for(j=0;j<k;j++){
		x= c[j];
		for(i=0;i<n;i++){
			if(a[x][i] == 1){
				if(b[i] == -1){
					d[count] = i;
					b[i] = deep;
					count++;
					a[x][i] = 0;
					for(y=0;y<n;y++){
						a[y][i] = 0;
					}
				}
				
			}
		}
	}
	
	for(i=0;i<count;i++)
	{
		c[i] = d[i];
	}
	
	return count;
}
