#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
using namespace std;

#define FOI(i, A, B) for(i=A; i<=B; i++)
#define FOD(i, A, B) for(i=A; i>=B; i--)
#define MAX	1000000

bool prime[MAX + 5];
vector<int> P;

void seive(){
	memset(prime, true, sizeof prime);
	prime[0] = false; prime[1] = false;
	int i, j;
	FOI(i, 2, MAX)
		if( prime[i] ){
			P.push_back(i);
			for (j = 2*i; j <= MAX; j += i)
				prime[j] = false;
		}
}

int main(){
	//freopen("testI.txt", "r", stdin);
	//freopen("testO.txt", "w", stdout);
	seive();
	int M = P.size();
	while( true ){
		int N, i;
		cin >> N;
		if( N == 0 )
			break;
		cout << N << ":" << endl;
		bool gold = false;
		FOI(i, 0, M-1){
			if( P[i] > N )
				break;
			if( prime[N - P[i]] ){
				cout << P[i] << "+" << N - P[i] << endl;
				gold = true;
				break;
			}
		}
		if( !gold )
			cout << "NO WAY!" << endl;
	}
	return 0;
}
