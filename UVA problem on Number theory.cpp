/* 
			12216 - How Many bases? --->:UVA 
*/

#include<bits/stdc++.h>
using namespace std;
#define Fayaz() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
typedef long long ll;
const int m = 1e9+7;
vector <int> primes;
const int N = 1e5+9;
const int N1 = 1e8;
 bitset<N>is_prime;
 int f[N];
 void divisor(int n ){
	vector<int>divisor;
	for(int i =	1; i*i<=n ; i++){
		if(n%i==0){
			divisor.push_back(i);
			if(i!=n/i)divisor.push_back(n/i);
		}
	}
	
	}
void hi_seive(){
	f[1]=1;
	for(int i =2; i*i<=N; i++){
		if(f[i]==0){
			for(int j =i*i; j<=N ; j+=i){
				f[j]=1;
			}
		}
	}
	for(int i =2; i<=N ; i++){
		if(f[i]==0){primes.push_back(i);}
	}
}
void hi_seive2(){
	is_prime[1]=false;
	for(int i=2 ; i<N1 ; i++){
		is_prime[i]=true;
		
	}
	for(int i=2 ; i*i<N1 ; i++){
		if(is_prime[i])
		{	
	       for(int j = i *i  ; j<N1 ; j+=i){
		    is_prime[j]=false;
		
		}
		}
	}
}
int gcdm(int m1 ,  int n){
	if(m1==n)return m1 ;
	else if(m1>n) return gcdm(m1-n,n);
	else return gcdm(m1 , n-m1);
}
int mod_add(int a,int b,int m){
	return (a%m+b%m)%m;
}
 
int mod_sub(int a,int b,int m){
	return (a%m-b%m+m)%m;
}
 
int mod_mul(int a,int b,int m){
	return (a%m*b%m)%m;
}
// ll mul(ll a, ll b, ll p){
	// return __int128(a)*b%p;
// }
// ll power(ll a , ll b , ll p){   *******Bigmod and mulmod ll******
	// ll ans =1%p;
	// while(b){
		// if(b&1)ans = mul(ans , a , p);
		// a= mul(a,a ,p);
		// b>>=1;
	// }
	// return ans;
// }
// int Bigmod(int base , int power , int m ){
	// if(power == 0)return 1;
	// else if(power%2==1){
		// int a = base%m;
		// int b = Bigmod(base , power-1 , m);
		// return mod_mul(a,b,m);
	// }
	// else if(power %2==0){
		// int a = Bigmod(base , power/2 , m);
		// return mod_mul(a , a,m);
	// }
// }
// int mod_inverse(int a , int power ){
	// return Bigmod(a , power , m);
// }
// int mod_div(int a , int b , int m){
	// return mod_mul(a , mod_inverse(b , m-2) , m);
// }
// int safe_route( ll p){
 	// int k  =sqrtl(p);
 	// while(1LL*k*k>p)k--;
 	// while(1LL*k*k<p)k++;
 	// return k;
 // }
void inout()
{	
	#ifndef ONLINE_JUDGE
		freopen("input.txt" ,"r" , stdin);
		freopen("output.txt" , "w" ,stdout);
		cerr << "Time : " << (double)clock() / (double)CLOCKS_PER_SEC << "s\n" ;
	#endif
}


const int mod = 1e8+7;
int s( vector<int>e1 , int t){
	int ans =1 ;
	for(int i =0; i<e1.size() ; i++){
		ans =1LL*ans*((e1[i]/t +1))%mod;
	}
	return ans;
}
int ans(vector<int> e , int t){
	return (s(e, t)-s(e , t+1)+mod)%mod;
}


int main() {
    
    Fayaz();
     //sp();

	
    //cin >> t;
    
    int case1=0;
    int n , m , t;
    
    
    while(cin >> n >> m >> t && n>0){
    	vector<int>e_power;
    	for(int i =2 ; i*i<=n  ; i++){
    		
    		if(n%i==0){
    			int count=0;
    			while(n%i==0){
    				count++;
    				n/=i;
    			}
    			e_power.push_back(count*m);
    		}
    			
    	}
    	if(n>1)e_power.push_back(1*m);
    	cout<< "Case "<<++case1<<": "<< ans(e_power , t) <<endl;
    }
  
      
      
       
    
}