#include<stdio.h>
int fib(int n)
{
    if(n==0)
        return 0;
    else if(n==1)
        return 1;
    else
        return fib(n-1)+fib(n-2);
}
int main()
{
    int k,result;
    scanf("%d",&k);
printf("%dth term of fibonacci series",k);
printf(" 0 ");
    for(int i=1;i<=k-1;i++)
    {
        result=fib(i);
    printf("%d ",result);
    }
    return 0;
}
