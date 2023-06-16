#include<bits/stdc++.h>
using namespace std;
const int N=1e7+9;
int ar[N];
bool f[N];
int gcd(int  a,int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}
const int mod = 1e9+7;


// jodi mean heap hoi ar[left] < ar[largest] ar[right] < ar[largest] dilei hobe 
void heapify(int ar[], int n, int i){
	int largest = i;
	int left = 2*i + 1;
	int right = 2*i + 2;
	if(left<n && ar[left] > ar[largest] ){
		largest = left ;
	}
	
	if(right < n && ar[right] > ar[largest] ){
		largest = right ;
	}
	if(largest!= i){
		swap(ar[i] , ar[largest] );
		heapify(ar, n, largest);
		
	}
}

 void heapSort(int ar[], int n) {
    //max heap build kortesi 
    for (int i = n / 2 - 1; i >= 0; i--)
      {heapify(ar, n, i);}
    // Heap sort er asol function work
    for (int i = n - 1; i >= 0; i--) {
      swap(ar[0], ar[i]);// prottekbar ami top er max element er sathe interchange kortesi
      heapify(ar, i, 0);
    }
  }
int main(){
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>ar[i];
	}	
	heapSort(ar,n);
		for(int i=0;i<n;i++)
	{
		cout<<ar[i]<<" ";
	}
	
}
