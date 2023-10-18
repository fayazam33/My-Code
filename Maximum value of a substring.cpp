/*Printing the maximum
 value of all substrings of a string representing a number*/
 
#include<bits/stdc++.h>
using namespace std;
#define Fayaz() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
typedef long long ll;
#define loop(n,i) for(lld i=0;i<n;i++)
#define lop(n,i,start) for(lld i=start;i<n;i++)
#define lf double
#define nline cout<<"\n"
using namespace std;
                   /* BISMILLAHIR RAHMANIR RAHIM */
void maxSubstringValue(string s ,int n) {
    int maxVal = s[0] - '0';
    int currentVal = maxVal;
    int dp[12];
    dp[0]=INT_MIN;
    for (int i = 1; i < n; i++) {
        currentVal = max(currentVal + s[i] - '0', s[i] - '0');
      //  cout<<currentVal<<endl;
    
        maxVal = max(maxVal, currentVal);
    }

    cout << maxVal << endl;
}
int main(){
	string s ;
	cin>>s;
	
    maxSubstringValue(s,s.size());
}