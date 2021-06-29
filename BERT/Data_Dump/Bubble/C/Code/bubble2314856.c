 #include<stdio.h>
 #define MAX 100
 int main()
 {
     int a[MAX];
     int n, i, j, flag, count=0, temp;

     scanf("%d", &n);
     for(i=0;i<n;i++)
        scanf("%d", &a[i]);

     flag=1;
     for(i=0;flag!=0;i++)
     {
         flag=0;
         for(j=n-1;j>=i+1;j--)
         {
             if(a[j]<a[j-1])
             {
                 temp=a[j];
                 a[j]=a[j-1];
                 a[j-1]=temp;
                 count++;
                 flag=1;
             }
         }
     }

     for(i=0;i<n-1;i++)
        printf("%d ", a[i]);
     printf("%d\n", a[i]);
     printf("%d\n", count);

     return 0;
 }
