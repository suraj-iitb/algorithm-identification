#include<stdio.h>


int linia(int *, int, int );

int main(){
  int s_num,s[10000+1],t_num,t,i,cnt=0;

  scanf("%d",&s_num);
  for(i=0; i<s_num; i++){
  scanf("%d",&s[i]);
}

  scanf("%d",&t_num);
  for(i=0; i<t_num; i++){
  scanf("%d",&t);
  if(linia(s,s_num,t)) cnt++;

}
 printf("%d\n",cnt);
  return 0;
}


int linia(int *s, int s_num,int t){
  int i=0;
  s[s_num] = t;
  while(s[i] != t) i++;
  return i != s_num;
}

