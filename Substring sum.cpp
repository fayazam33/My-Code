// substring sum 
#include<bits/stdc++.h>
using namespace std;
#define Fayaz() ios_base::sync_with_stdio(0);cin.tie(0); cout.tie(0);
const int MOD = 998244353;
typedef long long ll;
int todigit(char ch){
	return( ch-'0');
}

int sumsubstring(string s , int len){
	int dp[len];
	//memset(dp, -1 ,sizeof(dp));
	//cout<<s[0]<<endl;
	dp[0]=todigit(s[0]);
	int res =dp[0];
//	cout<<dp[0]<<endl;
	for(int i=1 ;i<len ; i++){
		int sum =0;
		int k = todigit(s[i]);
		//cout<<k<<endl;
		dp[i]=(i+1)*k+10*dp[i-1];
		res+=dp[i];
	}
	cout<<res<<endl;
	
	
}


int main(){

		string w;
		cin>>w;
		sumsubstring(w,w.size());	
}