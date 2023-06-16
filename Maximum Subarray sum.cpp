#include <bits/stdc++.h>
using namespace std;
typedef long long int ll ;
const int N=1e5+7;
#define Fayaz() ios_base::sync_with_stdio(false) ;cin.tie(0);cout.tie(0);
const int INF= 1e9;

int cross_sum(int ar[], int low , int mid, int high){
	
int left_sum = -10000;
int right_sum = -10000;
int sum=0;
for(int i=mid; i>=low ; i--){
	sum+= ar[i];
	if( sum > left_sum ){
		left_sum = sum;
	}
	
}
sum =0;
for(int i =mid+1; i<=high ; i++){
	sum+=ar[i];
	if(right_sum < sum){
		right_sum=sum;
	}
}		
	return (left_sum + right_sum);
}

int max_sum(int ar[], int low, int high){
	
	if(low==high)return ar[high];
	
	int mid= (high+low)/2;
	int left_sum = max_sum(ar, low , mid);
	int right_sum = max_sum(ar, mid+1 , high );
	
	int cross_sum1 = cross_sum(ar, low , mid, high);
	 int w= max(left_sum, right_sum);
	return max(w, cross_sum1);
}



int main(){

	int n;
	cin>>n;
		int ar[n];
	for(int i=0;i<n;i++){
		cin>>ar[i];
	}
	int sum1=max_sum(ar,0,n);
	cout<<sum1<<endl;
	
	
	
	
}