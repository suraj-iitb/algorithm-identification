
  
  #include<stdio.h>
#define N 100000
#define Q 50000

int  binarySearch(int);
  int n,s[N];  
int main(){
  int i,q,l,cnt = 0;
  int t[Q];
  
  scanf("%d",&n);

  for(i=0;i<n;i++){
      scanf("%d",&s[i]);
  }
  scanf("%d",&q);

  for(i=0;i<q;i++){
      scanf("%d",&t[i]);
  }
  for(i=0;i<q;i++){
  l = binarySearch(t[i]);
  if(l > 0) cnt++;
  }
  printf("%d\n",cnt);

  return 0;
}
int  binarySearch(int key){
  int left,right,mid;
  left = 0;
  right = n;
  while(left < right){
    mid = (left + right) / 2;
    if(s[mid] == key) return mid;
    else if(key < s[mid]) right = mid;
    else left = mid +1;
  }
    return 0;
  }
    
 

  
