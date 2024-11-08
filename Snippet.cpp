#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

template <typename T> using o_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define ordered_multiset tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> //multiset

#define Fayaz() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
typedef long long ll;
const int m = 1e9+7;

 //o_set<int> se;order_of_key(); find_by_order()
 
vector <int> primes;
const int N = 1e5+9;
const int N1 = 1e8;
 bitset<N>is_prime;
 int f[N];
 // void divisor(int n ){
	// vector<int>divisor;
	// for(int i =	1; i*i<=n ; i++){
		// if(n%i==0){
			// divisor.push_back(i);
			// if(i!=n/i)divisor.push_back(n/i);
		// }
	// }
// 	
	// }
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
int Bigmod(int base , int power , int m ){
	if(power == 0)return 1;
	else if(power%2==1){
		int a = base%m;
		int b = Bigmod(base , power-1 , m);
		return mod_mul(a,b,m);
	}
	else if(power %2==0){
		int a = Bigmod(base , power/2 , m);
		return mod_mul(a , a,m);
	}
}
int mod_inverse(int a , int power ){
	return Bigmod(a , power , m);
}
int mod_div(int a , int b , int m){
	return mod_mul(a , mod_inverse(b , m-2) , m);
}
int safe_route( ll p){
 	int k  =sqrtl(p);
 	while(1LL*k*k>p)k--;
 	while(1LL*k*k<p)k++;
 	return k;
 }
 int fact[N];
void gen_factorial(){
	
	fact[0]=1;
	for(int i =1 ; i<N; i++){
		fact[i] = 1LL * i* fact[i-1]  % m; 
	}
}
int pow_fact(ll n , ll k ){
	int ans =1%m ; n%=m ; if(n<0)n+=m;
	while(k){
		if(k&1)ans = (long long) ans*n %m;
		n= (long long)n*n %m;
		k>>=1;
		
	}
	return ans;
	
}
int invf[N];

void inv_f(){
	invf[N-1] = pow_fact(fact[N-1], m-2);
	for(int  i=N-2 ; i>=0; i--){
		invf[i] = 1LL*invf[i+1]*(i+1)%m;
	}
}
int nCr(int n , int r){
	
	if(n<r or n<0 ) return 0;
	return 1LL*fact[n]* invf[r]%m * invf[n-r]%m;
	//return 1LL*fact[n]* pow_fact(fact[r],m-2)%m *pow_fact(fact[n-r],m-2) %m; 
}
int nPr(int n , int r){
	
	if(n<r or n<0 ) return 0;
	return 1LL*fact[n]* invf[n-r]%m;
}
 // Sets the kth bit of x to 1 
int set_kth_bit(int x, int k) {
  return x | (1 << k);
}

// Sets the kth bit of x to 0 
int unset_kth_bit(int x, int k) {
  return x & (~(1 << k));
}

// Toggles kth bit of x 
int toggle_kth_bit(int x, int k) {
  return x ^ (1 << k);
}
 

int a[N],count1[N];
// memset(count , 0 , sizeof (count));
ll tree[4*N];
void build(int node , int st , int end) {
	if(st==end){
		tree[node] = a[st];
		//count[node]++;
		return;
	}
	int mid = (st+end)/2;
	int left = 2*node;
	int right = 2*node+1;
	
	build(left , st , mid);
	build(right , mid+1 , end);
	
	tree[node] = min(tree[left],tree[right]);
	
	//change korte hobe
	
	
}
ll query(int node , int st , int end  , int i , int j ) {
	if(st >j || end<i) return LLONG_MAX;//change korte hobe 
	if(i<=st && j>=end)return tree[node];
	int mid = (st + end ) / 2;
	int left = 2*node ;
	int right = 2*node + 1;
    ll q1 = query(left , st , mid , i ,j) ;
	ll q2 =  query(right , mid + 1 , end , i , j);
	count1[q1]++;
	count1[q2]++;
	
	/*change korte hobe*/
	return min(q1 ,q2);
	  
}
void upd(int node , int st , int end , int i , int x) {
	if(st>i || end<i)return ;
	if(st == end && st == i){
		a[st]=x;
		tree[node]= x;
		return;
	} 
	int mid = (st + end)/2;
	int left = 2*node ;
	int right = 2*node + 1;
	upd(2*node , st , mid , i , x);
	upd(2*node +1 , mid+1 , end , i  , x);
	/*change korte hobe*/
		tree[node] =min(tree[left] , tree[right]);
}
void inout()
{	
	#ifndef ONLINE_JUDGE
		freopen("input.txt" ,"r" , stdin);
		freopen("output.txt" , "w" ,stdout);
		cerr << "Time : " << (double)clock() / (double)CLOCKS_PER_SEC << "s\n" ;
	#endif
}

int main()
{
	Fayaz() ;
   int t ; cin>> t; 
   while(t--){
   
  string s= "12345";
  int k = stoi(s.substr(3,1));cout<<k<<endl;
  
   }
   }
   

    	
