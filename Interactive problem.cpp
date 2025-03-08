/*
Problem link - https://codeforces.com/contest/1807/problem/E
*/

#include <bits/stdc++.h>
using namespace std;
#define Fayaz() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#include <cmath>
typedef long long ll;
typedef long double ld;

const int m = 1e9+7;
const int N = 1000003;
const int N1 = 1e4;

bitset<N> is_prime;

void hi_seive2() {
    is_prime[1] = false;
    for(int i = 2; i < N1; i++) {
        is_prime[i] = true;
    }
    for(int i = 2; i * i < N1; i++) {
        if(is_prime[i]) {
            for(int j = i * i; j < N1; j += i) {
                is_prime[j] = false;
            }
        }
    }
}

ll mul(ll a, ll b, ll p) {
    ll res = 0;
    a %= p;
    while (b) {
        if (b & 1) res = (res + a) % p;
        a = (2 * a) % p;
        b >>= 1;
    }
    return res;
}

ll power(ll a, ll b, ll p) {
    ll ans = 1 % p;
    while(b) {
        if(b & 1) ans = mul(ans, a, p);
        a = mul(a, a, p);
        b >>= 1;
    }
    return ans;
}

int fact[N];

void gen_factorial() {
    fact[0] = 1;
    for(int i = 1; i < N; i++) {
        fact[i] = (ll(i) * fact[i-1]) % m;
    }
}

int pow_fact(ll n, ll k) {
    int ans = 1 % m; 
    n %= m; 
    if(n < 0) n += m;
    while(k) {
        if(k & 1) ans = (ll(ans) * n) % m;
        n = (ll(n) * n) % m;
        k >>= 1;
    }
    return ans;
}

int invf[N];

void inv_f() {
    invf[N-1] = pow_fact(fact[N-1], m-2);
    for(int i = N-2; i >= 0; i--) {
        invf[i] = (ll(invf[i+1]) * (i+1)) % m;
    }
}

int nCr(int n, int r) {
    if(n < r || n < 0) return 0;
    return (ll(fact[n]) * invf[r] % m * invf[n-r] % m);
}

int nPr(int n, int r) {
    if(n < r || n < 0) return 0;
    return (ll(fact[n]) * invf[n-r] % m);
}

// int safe_route( ll p){
 	// int k  =sqrtl(p);
 	// while(1LL*k*k>p)k--;
 	// while(1LL*k*k<p)k++;
 	// return k;
 // }
 
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
bool ok(ll l, ll n , ll w , ll h ){
	if(n<=(l/w)*(l/h))return true;
	else return false;
}
ll binary_low(vector<ll>&v ,ll n ,ll x){
	//low
	ll lo =0 , hi =n-1;
	while(lo<hi){
		ll mid = (lo+hi)>>1;
		
		if(v[mid]>=x)hi=mid;//ans is here
		
		else lo = mid+1;
	}
	return hi;
	
}

ll binary_high(vector<ll>&v , ll n , ll x){
	//high
	ll lo =0 , hi = n;
	while(lo+1<hi){
		ll mid = (lo+hi)>>1;
		if(v[mid]<= x)lo = mid;
		else hi=mid;
	}
	return lo;
}

int32_t main() {
    Fayaz();
    int t = 1;
    scanf("%d", &t);

    while(t--) {
        ll n;
        scanf("%lld", &n);
        vector<ll> ar(n+1);

        for(int i = 1; i <= n; i++) {
            scanf("%lld", &ar[i]);
        }

        int ans;
        int low = 1, high = n;

        while(low <= high) {
            int mid = low + (high - low) / 2;
            int len = mid - low + 1;

            if(low == high) {
                ans = mid;
                break;
            }

            printf("? %d ", len);
            ll sum = 0;

            for(int i = low; i <= mid; i++) {
                printf("%d ", i);
                sum += ar[i];
            }
            printf("\n");
            fflush(stdout);

            ll res;
            scanf("%lld", &res);

            if(res > sum) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }

        printf("! %d\n", ans);
        fflush(stdout);
    }

    return 0;
}

/*
         Khela hobe kharaw aitesi abar
*/
