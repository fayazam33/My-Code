/*
Dp problem Link- https://lightoj.com/problem/coin-change-i


*/

#include <bits/stdc++.h>
#define Fayaz() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
const int maxN = 1001;
const int N= 55, mod=100000007, W=105;
typedef long long ll;
int k  = 105,n;
int a[N] , c[N];
ll dp[N][W];
ll f(int i , int curr_v){
	if(curr_v>k) return 0;
	if(i==n+1){
		if(curr_v==k)return 1;// jodi seikhane giyee k hoye jaai tar mane ami 
		// sheshe jawar ekta poth already peye gesi 
		return 0;
	}
     ll &ans= dp[i][curr_v];
     if(ans!=-1)return ans;
     
     ans =0;//-1 theke 0 kore niee asha jatee sum korte suvida hoi 
     
     for(int co = 0 ; co <= c[i] ; co++){
     	ans+= f(i+1 ,curr_v+co*a[i]);
     	ans%=mod;
     }
     return ans ;
}
int main(){
	Fayaz();
	int t; 
	cin>>t ;
	int ca=0;
	 while(t--){
	 	 cin>> n >> k;
	 	 memset(dp,-1,sizeof dp);
	 	 for(int i =1 ; i<=n ; i++){
	 	 	cin>>a[i];
	 	 }
	 	 for(int i =1 ; i<=n ; i++){
	 	 	cin>>c[i];
	 	 }
	 	 cout<<"Case "<<++ca<<": "<<f(1 , 0)<<endl;
	 	
	 	
    }
}

