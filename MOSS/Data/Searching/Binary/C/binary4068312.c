#include <stdio.h>

int S1[1000000],f;

int binary_s(int z){
  int lef_s=0,rig_s=f;
  int o;
  while(lef_s<rig_s){
    o=(lef_s+rig_s)/2;
    if(z==S1[o]) return 1;
    if(z>S1[o]) lef_s=o+1;
    else if(z<S1[o]) rig_s=o;
  }
  return 0;
}

int main(){
  int i,g,z,match=0;
  
  scanf("%d",&f);
  for(i=0;i<f;i++){
    scanf("%d",&S1[i]);
      }
  
  scanf("%d",&g);
  for(i=0;i<g;i++){
    scanf("%d",&z);
    if(binary_s(z)) match++;
  }

    printf("%d\n",match);

    return 0;
} 
  

