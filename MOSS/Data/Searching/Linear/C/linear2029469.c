#include <stdio.h>

int main(void){
	int i,j,a,c,d,cnt,sum=0,b[10001];
	scanf("%d",&a);
	for(i=0;i<a;i++)
		scanf("%d",&b[i]);
	scanf("%d",&c);
	for(i=0;i<c;i++){
		cnt=0;
		scanf("%d",&d);
		b[a]=d;
		for(j=0;j<=a;j++){
			if(b[j]==d)
				cnt++;
		}
		if(cnt>=2)
			sum++;
	}
	printf("%d\n",sum);
	return 0;
}
		
		
	



		
