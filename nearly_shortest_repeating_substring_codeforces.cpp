/*
Author - Fayaz Ali Muktadir
Always code with easy syntax 
Problem -E Codeforces Round 937 (Div. 4)
*/
#include<bits/stdc++.h>
using namespace std;
#define Fayaz() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
typedef long long ll;
const int MOD = 1e9+7;

//const ll N1 = 1e14;
const int N=1e6+9;
 int f[N];
// bitset<N>is_prime;
bool is_prime[N];
 vector<int>primes;
// void hi_seive(){
	// f[1]=1;
	// for(int i =2; i*i<=N; i++){
		// if(f[i]==0){
			// for(int j =i*i; j<=N ; j+=i){
				// f[j]=1;
			// }
		// }
	// }
	// for(int i =2; i<=N ; i++){
		// if(f[i]==0){primes.push_back(i);}
	// }
//}
void hi_seive2(){
	is_prime[1]=false;
	for(int i=2 ; i<N ; i++){
		is_prime[i]=true;
		
	}
	for(int i=2 ; i*i<N ; i++){
		if(is_prime[i])
		{	
	       for(int j = i +i  ; j<N ; j+=i){
		    is_prime[j]=false;
		
		}
		}
	}
	for(int i =2; i<N ; i++){
		if(is_prime[i]==true){primes.push_back(i);}
	}
}

// vector<int>divisor;
// void divisor(int n ){
	// for(int i =	2; i*i<=n ; i++){
		// if(n%i==0){
			// divisor.push_back(i);
			// if(i!=n/i)divisor.push_back(n/i);
		// }
	// }
	// }
ll safe_route( ll p){
 	ll k  =sqrtl(p);
 	while(1LL*k*k>p)k--;
 	while(1LL*k*k<p)k++;
 	return k;
 }
// bool valid[N];
// int prefix_sum[N];
// ll multi(ll b, ll lc){
	// return b/lc;
// }
// ll solve(ll lc , ll l,ll r ){
	// //cout<<multi(1,r,lc)<<" "<<multi(1,l,lc)<<endl;
	// return multi(r,lc)-multi(l-1,lc);
// }
int spf[N];
int spf1(){
	for(int i =0 ; i<=N;i++ ){
		spf[i]=0;
	}
	 for (int i = 2; i <= N; ++i) {
        if (spf[i] == 0) {
            for (int j = i; j <= N; j += i) {
                spf[j] = i;
            }
        }
    }
} 
   int main() {
    
    Fayaz();
	 int t ; 
   cin>>t;
    
   int case1= 0;
   while(t--){
    int n;
    cin>>n;
    string s;
    cin>>s;
    
    vector<int>divs;
    for(int i =1; i*i<=n; i++){
    	if(n%i==0){
    		divs.push_back(i);
    		if(i!=n/i)divs.push_back(n/i);
    	}
    }
    sort(divs.begin(), divs.end());
    int max1=INT_MAX,max2=INT_MAX;
for(int i =0 ; i<divs.size();i++){
	
string w ;
string o ;
int k = divs[i];

int len=0,len1=0;
//cout<<s.substr(s.size()-k,k)<<endl;
while(1){
	w+=s.substr(0,k);
	len=w.size();
	if(len==s.size())break;
}
while(1){
	o+=s.substr(s.size()-k,k);
	len1=o.size();
	if(len1==s.size())break;
}

int dif=0,dif1=0;
for(int i1 =0 ;  i1<w.size() ; i1++){
	if(s[i1]!=w[i1])dif++;
}
for(int i1 =0 ;  i1<w.size() ; i1++){
	if(s[i1]!=o[i1])dif1++;
}

if(dif<=1){
	max1=min(max1, k);
}
if(dif1<=1){
	max2=min(max2, k);
}
  
       	  }
       	 cout<<min(max1,max2)<<endl;
}
}