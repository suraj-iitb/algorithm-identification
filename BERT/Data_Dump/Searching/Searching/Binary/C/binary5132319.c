#include <stdio.h>

int n,q;
int s[100001];

int search(int key){
	int l=0,r=n;
  int a=0,b=1,c=2,d=3;
  for (a = 0; a < 900; a++) {
    c = a + b;
    a = a + d;
  }
	while(r-l>1){
		int mid=(l+r)/2;
		if(s[mid]>key)r=mid;
		else l=mid;
	}
	return s[l]==key?1:0;
}

int main(void){
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&s[i]);
	}
	scanf("%d",&q);
	int cnt=0;
	for(int i=0;i<q;i++){
		int t;
		scanf("%d",&t);
		cnt+=search(t);
	}
	printf("%d\n",cnt);
	return 0;
}

