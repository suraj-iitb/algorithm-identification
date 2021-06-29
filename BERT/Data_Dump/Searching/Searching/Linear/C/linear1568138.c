#include<stdio.h>
#include<string.h>

int main (void){
	
	int s[100000]={0};
	int t[100000]={0};
	int a,b,i,j,n1,n2,count=0;
	int left=0,right,mid,m,l,min=10000,minb,box;

	scanf("%d",&n1);
	
	for(i=0;i<n1;i++){
		scanf("%d",&s[i]);
	}
	
	
	for(a=0;a<n1;a++){
		min=1000000001;
		minb=a;
		for(b=a;b<n1;b++){
			if(min>s[b]){
				min = s[b];
				minb=b;
			}
		}
		box = s[a];
		s[a] = s[minb];
		s[minb] = box;
		
	}
	
		
	right=n1-1;
	m=right;
	scanf("%d",&n2);
	for(j=0;j<n2;j++){
		//printf("-------------for ?????\????????? j = %d--------------\n",j);
		l=count;
		left=0;
		right=m;
		//printf(" for s[0]=%d\n",s[0]);
		scanf("%d",&t[j]);
		//printf(" for s[0]=%d\n",s[0]);
		//printf("left=%d,right=%d,l=%d\n",left,right,l);
		
		while(left<=right){
			//printf("-------------while ?????\????????? j = %d--------------\n",j);
			mid = ((left+right)/2);
			//printf("left=%d right=%d mid=%d\n",left,right,mid);
			//printf("t[%d]=%d s[%d]=%d\n",j,t[j],mid,s[mid]);
			if(s[mid]==t[j]){
				//printf("-------------s[mid]==t[%d] ?????\????????? --------------\n",j);
				count++;
				left=mid;
				right=mid;
				//printf("s[0]=%d s[1]=%d s[2]=%d s[3]=%d s{4}=%d\n",s[0],s[1],s[2],s[3],s[4]);
				//printf("count=%d\n",count);
			}else if(s[mid]<t[j]){
				//printf("-------------s[mid]<t[%d] ?????\????????? --------------\n",j);
				left=mid+1;
				//printf("s[0]=%d s[1]=%d s[2]=%d s[3]=%d s{4}=%d\n",s[0],s[1],s[2],s[3],s[4]);
				//printf("left=%d\n",left);
			}else{
				//printf("-------------s[mid]>t[%d] ?????\????????? --------------\n",j);
				right = mid-1;
				//printf("s[0]=%d s[1]=%d s[2]=%d s[3]=%d s{4}=%d\n",s[0],s[1],s[2],s[3],s[4]);
				//printf("right=%d\n",right);
			}
			//printf("last while s[0]=%d\n",s[0]);
		if(l<count)break;
		}
	}
	//printf("-------\n");
	printf("%d\n",count);
	//printf("-------\n");
return 0;
}
