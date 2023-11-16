// Game with String Codeforces

#include<bits/stdc++.h>
using namespace std;
#define Fayaz() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
typedef long long ll;
const int MOD = 1e9+7;
 
vector <int> primes;
const int N = 1e5+9;
 int f[N];
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
int gcdm(int m ,  int n){
	if(m==n)return m ;
	else if(m>n) return gcdm(m-n,n);
	else return gcdm(m , n-m);
}




int main()
{
	Fayaz() ;
     string s;
      cin >> s;
      stack<char >  q;
      q.push(s[0]);
      int count =0 ;
    
       for(int i =1 ; i<s.size();i++){
      
         if(!q.empty()&&q.top() == s[i]){q.pop();count++;}

       	else {q.push(s[i]);}
      
       }
       
       if((count)%2==1&&count!=0)cout<<"YES"<<endl;
       else cout<<"NO"<<endl;

}