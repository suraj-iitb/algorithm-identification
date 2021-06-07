#include <stdio.h>
#define MAX 100000
int main(){
	int n1,n2,cnt=0,i=0,j=0;
	int s[MAX],key;
	int right,left,mid;
	
	
	scanf("%d",&n1);
	
	for(i=0;i<n1;i++){
		scanf("%d",&s[i]);
	}
	
	scanf("%d", &n2);
	

	for(j=0;j<n2;j++){
		scanf("%d",&key);
		left = 1;
		right = n1;
		while(left < right){
			mid = (left+right)/2;
			//printf("left:%d\nmiddle:%d\nright:%d\n\ncnt:%d\n",left,mid,right,cnt);
			if( s[mid] > key ) right = mid;
			
			else if( s[mid] < key ) left = mid + 1;
			
			else if(s[mid]==key){
				cnt++;
				break;
			}
		}
	}
	printf("%d\n",cnt);
	return 0;
}
		
