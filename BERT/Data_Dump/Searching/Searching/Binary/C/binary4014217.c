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
   
    int mid;
    for(int i=0; i<q; i++){
        int left=0;
        int right=n;
      
        while(left<right){
            mid = (left + right) / 2;
            if(S[mid]==T[i]){
                count++;
               
                break;
            }
            else if(S[mid] > T[i]){
                right = mid;
            }
            else{
                left = mid + 1;
            }
        }
    }

     printf("%d\n",count);

     return 0;
 }

 
