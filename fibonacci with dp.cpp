#include<bits/stdc++.h>
using namespace std;
typedef long long int ll ;
const int N=1e6+9;
#define Fayaz() ios_base::sync_with_stdio(false) ;cin.tie(0);cout.tie(0);
using namespace std;
int gcd(int  a,int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}
int dp[N];
int fib(int n){
	if(n==1)return 0;
	if(n==2)return 1;
	if(dp[n]!=-1)return dp[n];
	return dp[n] = fib(n-1)+fib(n-2);
}
int main(){

int n;
cin>>n;
for(int i=1;i<=n;i++){
	dp[i]=-1;
}
dp[1]=0;
dp[2]=1;
fib(n);
	cout<<dp[n]<<endl;
	
	for(int i=1;i<=n;i++)
	{
		cout<<dp[i]<<" ";
	}
	
	
	
}

