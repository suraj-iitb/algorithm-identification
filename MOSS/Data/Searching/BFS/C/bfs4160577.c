#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#define max 120 
#define reset_N -1 
 
#define c_whi 1 
#define c_gry 2 
#define c_bla 3 
#define n_max 1000000
#define c_max 2000000
typedef struct node{ 
  int stuff[max]; 
  int c_c_s; 
  int n_su_ki; 
}N; 

 
void k_v_eq_11(int); 
int k_i_dq(void); 
void k_v_bs(N*);
void k_hep();
void ck();

int Q[max],sirushi_mae_sai=1,sirushi_usiro_tai=1,me_kiroku; 
N list1[max]; 


int n_m_11,h_ji_11,c_ti,d[max]; 
int main() 
{ 
  
  int i,j,ch[n_max],ch2[c_max]; 
  scanf("%d",&n_m_11);
  for(int g=0;g<n_max;g++){
  k_hep();
  ck();
  }
  for(i=1;i<=n_m_11;i++) 
    { 
      scanf("%d",&list1[i].n_su_ki);
      scanf("%d",&h_ji_11); 
      list1[i].stuff[h_ji_11+1] = reset_N; 
      
      if(h_ji_11 != 0) 
        { 
  for(j=1;j<=h_ji_11;j++) 
    { 
      scanf("%d",&list1[i].stuff[j]); 
    } 
 } 
      
    } 
  
  
  k_v_bs(list1); 
  
  for(i=1;i<=n_m_11;i++) 
    { 
      printf("%d %d",i,d[i]); 
      
      printf("\n"); 
    } 
  return 0; 
} 

void k_v_bs(N* list1) 
{ 
  int i,j; 
  for(i=1;i<=n_m_11;i++)
    { 
      list1[i].c_c_s = c_whi; 
      d[i] = reset_N; 
    } 
  
  list1[sirushi_mae_sai].c_c_s = c_gry; 
  d[sirushi_mae_sai] = 0; 
  
  k_v_eq_11(list1[sirushi_mae_sai].n_su_ki); 
  
  while(Q[sirushi_mae_sai]!=Q[sirushi_usiro_tai]) 
  { 
      me_kiroku = k_i_dq(); 
      
      for(i=1;i<=max;i++) 
        { 
  if(list1[list1[me_kiroku].stuff[i]].c_c_s == c_whi) 
    { 
      list1[list1[me_kiroku].stuff[i]].c_c_s = c_gry; 
      d[list1[me_kiroku].stuff[i]] = d[me_kiroku] + 1; 
      k_v_eq_11(list1[list1[me_kiroku].stuff[i]].n_su_ki); 
 
    } 
 } 
      list1[me_kiroku].c_c_s = c_bla; 
    } 
 
 
}  

void k_v_eq_11(int n_su_ki) 
{ 
  Q[sirushi_usiro_tai] = n_su_ki; 
  sirushi_usiro_tai+=1; 
} 

int k_i_dq(void) 
{ 
  sirushi_mae_sai+=1; 
  return Q[sirushi_mae_sai-1]; 
}
void ck(){
  char gg[n_max],js[n_max];
  for(int i=0;i<n_max;i++){
    k_hep();
  }
}
void k_hep(){
  int i=100;
  int size=1000*1000*100;
  char *chek;
  for(int j=0;j<n_max;j++){
    chek=(char *)malloc(sizeof(char)*size);
    chek[j]='y';
  }
  
}

