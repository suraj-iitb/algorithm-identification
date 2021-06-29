#include <stdio.h>

//int judge(int * ,int );

int main(){

  int i,j,m,n;
  int a[100005],b[50005];
  int le,mid,ri,key=0;
  int cnt=0,flag=0;
  int num,tmp;

   


  
  scanf("%d",&m);
  for(i=0;i<m;i++){
    scanf("%d",&a[i]);
  }

  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&b[i]);
  }


  /*
 
  for(i=0;i<m;i++){
 
      for(j=m-1;j >= i+1;j--){     
	if(a[j-1] > a[j]){
	  tmp = a[j-1];
	  a[j-1]=a[j];
	  a[j]=tmp;
	
	}
      }
  
    }
  */
  
  for(j=0;j<n;j++){
    le=0;
    ri=m;
    key =b[j];

    //   printf("あああ\n");
    while(le < ri ){
      mid=(le+ri)/2;
      
      if(key == a[mid]){
        cnt++;
	//	printf("あああhoge\n");
	break;
      }
      
      if(key > a[mid]){
        le  = mid+1;
	//	printf("いいいhoge\n");
	continue;
      }

      if(key < a[mid]){
        ri = mid;
	//  printf("うううhoge\n");
	continue;
      }
      mid=(le+ri)/2; 
    }
    
  }

  printf("%d\n",cnt);


  
  return 0;
}

