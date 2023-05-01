#include<bits/stdc++.h>
using namespace std;
#define Fayaz() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
const int N=1e5+9;
void couting_divisor(int n)
{
	vector<int >v;
	for(int i=2;i*i<=n;i++)
	{
		if(n%i==0){
		v.push_back(i);
		if(i!=n/i)v.push_back(n/i);
		}
	}

	sort(v.begin(),v.end());
	for(auto x:v)cout<<x<<" ";
	cout<<endl;
}
void prime_factor(int n)
{
	vector<int >v;
	for(int i=2;i*i<=n;i++)
	{
		if(n%i==0){

			while(n%i==0)
			{
			v.push_back(i);
			n/=i;
			}

		}

	}
	if(n>1)v.push_back(n);

	for(auto x:v)
	{
		cout<<x<<" ";
	}
	cout<<endl;
}
bool f[N];
void prime_with_seieve(int n){

	vector<int >primes;
	f[1]=true;
	for(int i=2;i*i<=N;i++)
	{
		if(!f[i])
		{
			for(int j=i*i;j<=N;j+=i)
			{
				f[j]=true;
			}
		}
	}
	for(int i=2; i<=n; i++ )
	{
		if(!f[i])
		{
			primes.push_back(i);
		}
	}
	for(auto x:primes)
	{
		cout<<x<<" ";
	}
	cout<<endl;
}
int d[104];
void divisor_count_seieve(int n){
	
	for(int i=1;i<=n;i++)
	{
		
		for(int j=i;j<=n;j+=i)
		{
			d[j]++;
			
		}
		
		
	}
	
	for(int i=1;i<=n;i++)
	{
		cout<<d[i]<<" ";
	}
	
	
	
	
}
int main()
{
	auto st=clock();
	int n;
	cin>>n;

couting_divisor(n);

prime_factor(n);

prime_with_seieve(n);

divisor_count_seieve(n);// 1 to N

cerr<<(1.0*(clock()-st))/CLOCKS_PER_SEC<<endl;


}
