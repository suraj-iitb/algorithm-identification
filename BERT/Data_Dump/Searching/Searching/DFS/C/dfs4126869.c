#include <stdio.h>
#define whi 0
#define gry 1
#define bla 2
#define MAX 103
void dfs(void );
void sorry_visit(int );


int dt[MAX],ft[MAX],ho,cin,i,j,ku,ver,ru,chi,ko,ri,timeis;
int abc[MAX][MAX]={};
int color[MAX];



int main(){
  
  scanf("%d",&ko);
  for(i=1;i<=ko;i++){
    scanf("%d%d",&chi,&ru);
    for(j=1;j<=ru;j++){
      scanf("%d",&ri);
      abc[chi][ri]=1;
    }
  }
  dfs();
    for(i=1;i<=ko;i++){
      printf("%d %d %d\n",i,dt[i],ft[i]);
    }
    return 0;
    
}



void dfs(void ){
  int cou;
  for(cou=1;cou<=ko;cou++){
    color[cou]=whi;
  }
  timeis=0;
  for(cou=1;cou<=ko;cou++){
    if(color[cou]==whi){
      sorry_visit(cou);
	}
  }
}

void sorry_visit(int user){
  int roop;
  color[user]=gry;
  dt[user]=++timeis;
  for(roop=1;roop<=ko;roop++){
    if(abc[user][roop]==0){continue;}
    if(color[roop]==whi){
      sorry_visit(roop);
    }
  }
  color[user]=bla;
  ft[user]=++timeis;
}



  
      

