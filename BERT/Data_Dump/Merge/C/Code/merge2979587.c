#include<stdio.h>
#include<math.h>
void merge(int [],int,int,int);
void mergesort(int [],int, int);

int t;
int main() {
	int n,i;
	int s[500000];
	
	scanf("%d",&n);
	
	for(i=0;i<n;i++) {
		scanf("%d",&s[i]);
		}
		
		mergesort(s,0,n);
		
		for(i=0;i<n;i++) {
			printf("%d",s[i]);
			if(i!=n-1) printf(" ");
			
		}
		 printf("\n");
		printf("%d\n",t);
		return 0;
		
		
}
		
		void merge(int s[],int left, int mid, int right) {
			int n1,n2,i ,j,k;
			n1=mid-left;
			n2=right-mid;
			int L[n1],R[n2];
			for(i=0;i<n1;i++)
				L[i]=s[left+i];

			for(i=0;i<n2;i++)
			R[i]=s[mid+i];
			
			L[n1]=INFINITY;
					R[n2]=INFINITY;
					
						
			i=0;
			j=0;
			
			
			for(k=left;k<right;k++) {
				 if (L[i] <= R[j]) {
				 	t++;
      s[k] = L[i];
      i +=1;
		      }
    else {
    	t++;
      s[k] = R[j];
      j +=1;
      }
      
      }
      }
      
      
      
      void mergesort(int s[],int left, int right) {
      	int mid;
      	if (left+	1 < right) {
    mid = (left	 + right)/2;
    mergesort(s,left, mid);
    mergesort(s,mid, right);
   merge(s,left, mid, right);
    }
    }
			
			
			
