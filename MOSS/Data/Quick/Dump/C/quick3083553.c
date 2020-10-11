typedef struct CC{
  int i;
  int y;
  char z;
} CC;

#include <stdio.h>

int gu(){
  int n = 0;
  int x = getchar_unlocked();
  if(x<=47||58<=x){
    return x;
  }
  while(48<=x&&x<58){
    n=10*n+(x & 0xf);
    x = getchar_unlocked();
  }
  return n;
}

void pn(int n){
  int i=0;
  char c[11];
  
  if(!n){
    putchar_unlocked('0');
    return;
  }
  while(n){
    c[i++]=(char)(n%10+'0'),n/=10;
  }
  while(i--){
    putchar_unlocked(c[i]);
  }
}

void *qp(CC *lon, CC *pan){
  CC pores = *(pan-1);
  CC *p = lon-1;
  for(CC *w = lon; w!=pan-1;++w){
    if(w->y<=pores.y){
      p++;
      CC bum = *p;
      *p = *w;
      *w = bum;
    }
  }
  CC bum = *++p;
  *p=pores;
  *(pan-1)=bum;
  return p;
}

void clock(void *lon, void *pan, size_t C){
  if(pan-lon<=C){
    return;
  }
  void *mi = qp(lon,pan);
  clock(lon,mi,C);
  clock(mi,pan,C);
}

int main(int argc, char **argv){
  int n = gu();
  CC X[n];
  for(int i=0;i<=n-1;++i){
    X[i].z=getchar_unlocked();
    getchar_unlocked();
    X[i].y=gu();
    X[i].i=i;
  }
  clock(X,X+n,sizeof(CC));

  int f=0;
  for(int i=1;i<=n-1;++i){
    if(X[i].y==X[i-1].y&&X[i].i<X[i-1].i){
      f=1;
	break;
    }
  }
  puts(f ? "Not stable" : "Stable");
  for(int i=0;i<=n-1;++i){
    putchar_unlocked(X[i].z), putchar_unlocked(' ');
    pn(X[i].y), putchar_unlocked('\n');
  }
  return 0;
}

