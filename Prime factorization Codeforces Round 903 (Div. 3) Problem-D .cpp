#include<bits/stdc++.h>
using namespace std;
#define Fayaz() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
typedef long long ll;
#define loop(n,i) for(lld i=0;i<n;i++)
#define lop(n,i,start) for(lld i=start;i<n;i++)
#define lld long long int
#define lf double
#define nline cout<<"\n"

    
                /* BISMILLAHIR RAHMANIR RAHIM */
const int N = 1e7;

int spf[N];
vector<int>fa;
map<int, int>freq;
void seive_prime(){
	for(int i =2 ; i<N;i++){
		spf[i]=i;
			}
			for(int i=2; i<N; i++){
				for(int j=i ; j<N ; j+=i){
					spf[j] = min(spf[j], i);
				}
			}
	
}
void fact(int n){
	while(n>1){
		
		freq[spf[n]]++;
		n=n/spf[n];
	}
	if(n>1)freq[spf[n]]++;
	
}
int main() {
	Fayaz();
	seive_prime();
	int t ; cin>> t;
	
	while(t--){
		freq.clear();
		int a ; cin >> a;
		int ar[a];
		for(int i =0 ; i<a ; i++){
			cin>>ar[i];
			fact(ar[i]);
			
		}
		int flag=0;
		for(auto it:freq){
			 if(it.second%a!=0)flag=1;
		//cout<<it.first<<" "<<it.second<<endl;
		}
		//cout<<endl;
		
		 if(flag==0)cout<<"YES"<<endl;
		 else cout<<"NO"<<endl;
	}
	
	
 return 0;
}

	






