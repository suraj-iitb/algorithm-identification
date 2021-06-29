#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#define scani(x) scanf("%d",&x)
#define scanc(x) scanf("%s",x)
#define printi(x) printf("%d",x)
#define printin(x) printf("%d\n",x)
#define printc(x) printf("%s",x)
#define repd(i,n,m) for(int i = n; i > m; i--)
#define repu(i,n,m) for(int i = 0; i < m; i++)
#define allprintu(i,n,m,a) for(int i = n; i < m; i++){if(i != m-1){printf("%d ",a[i]);}else{printf("%d",a[i]);}}
#define allprintd(i,n,m,a) for(int i = n; i > m; i--){if(i != 0){printf("%d ",a[i]);}else{printf("%d\n",a[i]);}}
	
int main(void){
	int n,q;
	int mid,left,right;
	int s[100000],t[50000];
	int same = 0;

	scani(n);
	repu(i,0,n){
		scani(s[i]);
	}
	scani(q);
	repu(i,0,n){
		scani(t[i]);
	}
	repu(i,0,q){
		left = 0;
		right = n;
		while(left < right){
			mid = (left+right)/2;
			if(s[mid] == t[i]){
				same++;
				break;
			}else if(t[i] < s[mid]){
				right = mid;
			}else{
				left = mid + 1;
			}
		}
	}
	printin(same);
	return 0;
}
