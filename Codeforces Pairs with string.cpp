/*
B. Count the Number of Pairs
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
Kristina has a string s
 of length n
, consisting only of lowercase and uppercase Latin letters. For each pair of lowercase letter and its matching uppercase letter, Kristina can get 1
 burl. However, pairs of characters cannot overlap, so each character can only be in one pair.

For example, if she has the string s
 = "aAaaBACacbE", she can get a burl for the following character pairs:

s1
 = "a" and s2
 = "A"
s4
 = "a" and s6
 = "A"
s5
 = "B" and s10
 = "b"
s7
= "C" and s9
 = "c"
Kristina wants to get more burles for her string, so she is going to perform no more than k
 operations on it. In one operation, she can:

either select the lowercase character si
 (1≤i≤n
) and make it uppercase.
or select uppercase character si
 (1≤i≤n
) and make it lowercase.
For example, when k
 = 2 and s
 = "aAaaBACacbE" it can perform one operation: choose s3
 = "a" and make it uppercase. Then she will get another pair of s3
 = "A" and s8
 = "a"

Find maximum number of burles Kristina can get for her string.

Input
The first line of input data contains a single integer t
 (1≤t≤104
) — the number of test cases.

The description of the test cases follows.

The first line of each test case contains two integers n
 (1≤n≤2⋅105
) and k
 (0≤k≤n
) — the number of characters in the string and the maximum number of operations that can be performed on it.

The second line of each test case contains a string s
 of length n
, consisting only of lowercase and uppercase Latin letters.

It is guaranteed that the sum of n
 over all test cases does not exceed 2⋅105
.

Output
For each test case, print exactly one integer on a separate line: the maximum number of burles that Kristina can get for her string s
.

Example
inputCopy
5
11 2
aAaaBACacbE
2 2
ab
4 1
aaBB
6 0
abBAcC
5 3
cbccb
outputCopy
5
0
1
3
2




*/


#include<bits/stdc++.h>
using namespace std;

bool is_subset(vector<int>arr1, vector<int> arr2) {
    sort(arr1.begin(), arr1.end()); 
    sort(arr2.begin(), arr2.end()); 

    int i = 0, j = 0;
    while (i < arr1.size() && j < arr2.size()) {
        if (arr1[i] < arr2[j]) {
            i++;
        }
        else if (arr1[i] == arr2[j]) {
            i++;
            j++;
        }
        else {
            j++;
        }
    }

    if (i < arr1.size()) {
        return false;
    }
    else {
        return true;
    }
}

int main() {
	int a,b;
	cin>>a;
	
    vector<int> arr1 ;
    vector<int> arr2 ;
for(int i=0;i<a;i++)
{
	int k;
	cin>>k;
	arr1.push_back(k);
}
cin>>b;
for(int i=0;i<b;i++)
{
	int k;
	cin>>k;
	arr2.push_back(k);
}

// for(int i=0;i<arr1.size();i++)
// {
	// cout<<arr1[i]<<" ";
// }
    if (is_subset(arr1, arr2)) {
        cout << "YES" << endl;
    }
    else {
        cout << "NO" << endl;
    }

    return 0;
}