/* The universe is a coordinate plane. We know the coordinate plane is a two-dimension surface formed by two number lines.

Natalia and Patrick think about the Coordinate plane as they are very fond of geometry. They imagine that they are standing on (xn, yn) and (xp, yp) on the coordinate plane respectively, where both their locations are lattice points (the coordinates are integers).

Though they are very good at geometry, they want to test your geometrical knowledge. They have given you multiple positions of their friend Jennifer.

So you have to determine how many times Jennifer is on the straight path between Natalia and Patrick.

Input
The first line of the input contains an integer T (T <= 20) - the number of test cases.

The first line of each test case contains two integers N and M (1 <= N, M <= 50). N means the number of given position of Jennifer and M means the number of standing position of Natalia and Patrick in that test case.

In the next n lines, two integers xi and yi(0 <= xi, yi <= 100)denoting Jennifer position.

After that, the next m lines, four integers xn, yn and xp, yp(0 <= xn, yn,xp, yp <= 100) denoting Natalia and Patrick position respectively

It is guaranteed that all points are integers

Output
For each position of Natalia and Patrick, print how many times Jennifer are on the straight path between them.

Example
Input:
1
4 3
1 1
2 2
3 3
4 4

0 0 5 5
3 3 4 4
0 0 1 0

Output:
4
2
0




*/


#include<bits/stdc++.h>
using namespace std;
#define Fayaz() ios_base::sync_with_stdio(false) ;cin.tie(0);cout.tie(0);
using namespace std;
int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}
int main() {
 Fayaz();
       int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;

        vector<pair<int, int>> jennifer(n);
        // or duita duita input nilam
        for (int i = 0; i < n; i++) {
            cin >> jennifer[i].first >> jennifer[i].second;
        }

        vector<pair<pair<int, int>, pair<int, int>>> natpat(m);
        
        
        //natalia r patrick er ta nilam
        for (int i = 0; i < m; i++) {
            cin >>natpat[i].first.first >> natpat[i].first.second >> natpat[i].second.first >> natpat[i].second.second;
        }

        for (int i = 0; i < m; i++) {
            int count = 0;
            for (int j = 0; j < n; j++) {
            	
                //co-ordiante dhorlam
                int x = jennifer[j].first, y = jennifer[j].second;
                
                //duitar min r maximum er moddhe point ta ache kina 
                if ((x >= min(natpat[i].first.first,natpat[i].second.first)) && 
                (x <= max(natpat[i].first.first,natpat[i].second.first)) &&
                    (y >= min(natpat[i].first.second, natpat[i].second.second))
                     && (y <= max(natpat[i].first.second,natpat[i].second.second))) 
                     
                     {
                     	// sorolrekhar sutro korte hobe 
                    if ((natpat[i].second.first - natpat[i].first.first) * (y - natpat[i].first.second) == (natpat[i].second.second - natpat[i].first.second) * (x - natpat[i].first.first)) {
                        count++;
                    }
                }
            }
            cout << count << endl;
        }
    }
    return 0;
}