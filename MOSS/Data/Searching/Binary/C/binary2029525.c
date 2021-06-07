#include <stdio.h>
#define buf 1000001

int main(void){
	int i,j,a,c,d,cnt=0,b[buf],left,right,mid,key;
	scanf("%d",&a);
	for(i=0;i<a;i++)
		scanf("%d",&b[i]);
	scanf("%d",&c);
	for(j=0;j<c;j++){
		scanf("%d",&d);
		left = 0;
		right = a;
		while(left < right){
			mid = (left + right)/2;
			if(b[mid] == d){
				cnt++;
				break;
			}
        		else if(d < b[mid])
            			right = mid;
        		else if(d > b[mid])
            			left = mid+1;
    		}
	}
	printf("%d\n",cnt);
	return 0;
}
 

 
		
