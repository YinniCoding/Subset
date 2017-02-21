#include <stdio.h>  
int M,n;  
int w[100];  
int x[100];  
void SumOfSub(int s, int k, int r)  
{  
     //s=w[1]*x[1]+...+w[k-1]*x[k-1]  
     //r=w[k]+...w[n]   
     //w[i]需要按非降次序排列   
    int i;  
    x[k]=1;  
    for(i=1; i<=k; i++)  
       printf("%d", x[i]);  
    printf("/n");  
    if(s+w[k]==M) //子集找到  
    {  
        printf("ans:");  
        for(i=1; i<=k; i++)  
            printf("%d", x[i]);  
        printf("/n");  
    }else if(s+w[k]+w[k+1]<=M)  
        SumOfSub(s+w[k], k+1, r-w[k]);  
      
    if(s+r-w[k]>=M && s+w[k+1]<=M)  
    {  
        x[k]=0;  
        SumOfSub(s, k+1, r-w[k]);  
    }  
}   
int main()  
{  
    int s,k,r;  
    n=4;  
    w[1]=7;  
    w[2]=11;  
    w[3]=13;  
    w[4]=24;  
    M=31;  
      
    s=0;  
    k=1;  
    r=55;  
      
    SumOfSub(s, k, r);  
    getchar();  
    return 0;  
}  

