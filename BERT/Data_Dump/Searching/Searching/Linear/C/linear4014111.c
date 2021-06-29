 #include<stdio.h>
 
 int main(void){
     int n, q;
     scanf("%d", &n);
     int S[n];
     for(int i=0; i<n; i++){
         scanf("%d", &S[i]);
     }
     scanf("%d", &q);
     int T[q];
     for(int i=0; i<q; i++){
         scanf("%d", &T[i]);
     }
    int count = 0;
    int flag=1;
     for(int i=0; i<q; i++){
         
         for(int j=0; j<n; j++){
             if(S[j]==T[i] && flag==1){
                 count++;
                 flag=0;
                 
                 
             }
             
         }
     flag=1;
     }
     

     printf("%d\n",count);

     return 0;
 }

 
