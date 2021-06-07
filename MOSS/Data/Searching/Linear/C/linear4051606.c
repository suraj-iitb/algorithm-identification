#include<stdio.h>
#include<stdlib.h>
#define NOTFOUND -100
int counter(int *,int *);
int linearSearch(int [],int);
int n=0,m=0;
int main(){
  //int *p,*q;
  int cnt=0,key=0,i=0,p[10000],q[500];
    scanf("%d",&n);
    //p = (int *)malloc(n*sizeof(int));
    for(i=0;i<n;i++)scanf("%d",&p[i]);
    scanf("%d",&m);
    //q = (int *)malloc(m*sizeof(int));
    for(i=0;i<m;i++)scanf("%d",&q[i]);
	/*
	for(i=0;i<m;i++){ 
	 if(linearSearch(p,q[i])){
		printf("q[%d] cnt :%d\n",i,cnt);
		cnt++;
	 } 
	}
	*/
	i=0;
	while(i<m){
		if((linearSearch(p,q[i])) != NOTFOUND) cnt++;
		i++;
	}
    //cnt = counter(&p,&q);
    printf("%d\n",cnt);
    return 0;
}

int linearSearch(int p[],int key){
		int j=0;
		//la :p
		p[n] = key;
		//printf("key = %d\n",p[n]);
		while(p[j] != key){
			//printf("p[%d] = %d\n",j,p[j]);
			j++;
			if(j == n) return NOTFOUND;
		}
		return j;		
}

/*
int counter(int *la,int *sm){
  int i,cnt=0,j;
  for(i=0;i<n;i++){
    for(j=0;j<m;j++){
      if(la[i] == sm[j]) cnt++;
    }
  }
  return cnt;
}
*/
