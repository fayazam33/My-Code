/*
I have an Ifter party at the 5th day of Ramadan for the contestants. For this reason I have invited C contestants and arranged P piaju's (some kind of food, specially mader for Ifter). Each contestant ate Q piaju's and L piaju's were left (L < Q).

Now you have to find the number of piaju's each contestant ate.

Input
Input starts with an integer T (≤ 325) denoting the number of test cases.

Each case contains two non-negative integers P and L (0 ≤ L < P < 231).

Output
For each case, print the case number and the number of possible integers in ascending order. If no such integer is found print impossible.

Sample
Input
10 0
13 2
300 98
1000 997

Output
Case 1: 1 2 5 10
Case 2: 11
Case 3: 101 202
Case 4: impossible

*/
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll ;
const ll N=1e7+9;

#define Fayaz() ios_base::sync_with_stdio(false) ;cin.tie(0);cout.tie(0);

bool f[N];

vector<ll >counting_divisor(ll n, ll k)
{
	vector<ll >v;
	for(ll i=1;i*i<=n;i++)
{
	if(n%i==0){
		if(i>k){
		v.push_back(i);}

		if(i!=n/i&&(n/i)>k){v.push_back(n/i);}
	}

}
	sort(v.begin(),v.end());
	return v;
 }

int spf[N];
ll prime_generator(ll n)
{
	vector<ll>v;
for(int i=2;i<=n;i++)
{
	spf[i]=i;
}
for(int i=2;i<n;i++){
	for(ll j=i;j<n;j+=i)
	{
		spf[j]=min(spf[j],i);
	}
}
}


int main() {
	Fayaz();

ll t;
cin>>t;
for(ll i=1;i<=t;i++)
{
	ll p,l;
	cin>>p>>l;

	ll w= p-l;

	vector<ll >v1=counting_divisor(w,l);



if(v1.size()==0){cout<<"Case "<< i<<": impossible" <<endl;}
else{
cout<<"Case "<< i<<": ";
for(auto x:v1)
{
	cout<<x<< " ";
}
cout<<endl;
}
		//	cout<<"Case "<< i<<": impossible" <<endl;

	}
}

