#include <bits/stdc++.h>
using namespace std;
typedef long long int ll ;
const int N=1e3+9;
const int mod = 1e9+7;
#define Fayaz() ios_base::sync_with_stdio(false) ;cin.tie(0);cout.tie(0);
int regularkina( string b){
	int count = 0 ; 
	for(int i =0 ; i < b.size() ; i++)
	{
		if(b[i] =='(' ){
			count++;
			
		} 
		else if( b[i] == ')' ){
			count--;
			if(count < 0 ) return 0;
		}
	}
	if(count > 0 )return 0;
	 return 1;
	
	
}
int main(){
 int t; cin>> t;
 string s;
 
 while(t--){
 	cin>> s;
 	string b="";

//( ( )
 	for( int i =0 ; i < s.size() ; i++)
 	{
 		if(s[i] == 'A' || s[i] == 'B'){
 			b+='(';
 		}
 		else {
 			b+=')';
 		}
 	}
 	if(regularkina(b) == 1){
 	  cout<< "YES" << endl ;
 	  continue;
 	}
 	b="";	
// ( ) (
 	for( int i =0 ; i < s.size() ; i++)
 	{
 		if(s[i] == 'A' || s[i] == 'C'){
 			b+='(';
 		}
 		else {
 			b+=')';
 		}
 	}
 	if(regularkina(b) == 1){
 	  cout<< "YES" << endl ;
 	  continue;
 	}	
 	b="";	
 	// ( ) )
 	 	for( int i =0 ; i < s.size() ; i++)
 	{
 		if(s[i] == 'B' || s[i] == 'C'){
 			b+=')';
 		}
 		else {
 			b+='(';
 		}
 	}
 	if(regularkina(b) == 1){
 	  cout<< "YES" << endl ;
 	  continue;
 	}	
 	b="";	
 	
 	// )( )
 	for( int i =0 ; i < s.size() ; i++)
 	{
 		if(s[i] == 'A' || s[i] == 'C'){
 			b+=')';
 		}
 		else {
 			b+='(';
 		}
 	}
 	if(regularkina(b) == 1){
 	  cout<< "YES" << endl ;
 	  continue;
 	}	
 	b="";	
 	// ) ) (
 	for( int i =0 ; i < s.size() ; i++)
 	{
 		if(s[i] == 'A' || s[i] == 'B'){
 			b+=')';
 		}
 		else {
 			b+='(';
 		}
 	}
 	if(regularkina(b) == 1){
 	  cout<< "YES" << endl ;
 	  continue;
 	}
 	b="";		
 	//) ( (
 	 	for( int i =0 ; i < s.size() ; i++)
 	{
 		if(s[i] == 'B' || s[i] == 'C'){
 			b+='(';
 		}
 		else {
 			b+=')';
 		}
 	}
 	if(regularkina(b) == 1){
 	  cout<< "YES" << endl ;
 	  continue;
 	}
 	
 	cout<< "NO" << endl;
 		
 }
}

