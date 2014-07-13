#include <cstdio>
#include <vector>
#include <utility>
#include <functional>
#include <set>
#include <map>
#include <string>
#include <cstring>
#include <queue>
#include <algorithm>
#include <cmath>
#include <stack>
#include <iostream>
#include <list>

using namespace std;

#define FOR(x,b,e) for(int x = b; x < (e); ++x)
#define FOR2(x,b,e) for(int x = b; x <= (e); ++x)
#define FORD(x,b,e) for(int x = b; x >= (e); --x)
#define REP(x,n) for(int x = 0; x < (n); ++x)
#define REP2(x,n) for(int x = 0; x <= (n); ++x)
#define VAR(v,n) typeof(n) v = (n)
#define ALL(x) x.begin(), x.end()
#define ALL2(x) x.rbegin(), x.rend()
#define FOREACH(i,c) for(VAR(i, (c).begin()); i != (c).end(); ++i)
#define FOREACH2(i,c) for(VAR(i, (c).rbegin()); i != (c).rend(); ++i)
#define PB push_back
#define ST first
#define ND second
#define PF push_front
#define MP make_pair
#define I(x) static_cast<int>(x)
#define U(x) static_cast<unsigned>(x)
#define eprint(...) fprintf(stderr, __VA_ARGS__)

typedef unsigned char uchar;
typedef long long LL;
typedef unsigned long long ULL;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<LL> VLL;
typedef vector<string> VS;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLLLL;
typedef vector<PII> VPII;
typedef vector<PLLLL> VPLLLL;
typedef vector<VPII> VVPII;

template<class T>
inline T abs(T x)
{return x<T() ? -x : x;}

#define MOD(x, mod_val) {if(x >= mod_val) x %= mod_val; else if(x < 0){x %= mod_val;if(x < 0) x += mod_val;}}

#ifdef DEBUG
#include <iostream>

#define D(...) __VA_ARGS__
#define E(...) eprint(__VA_ARGS__)
#define LOG(x) cerr << #x << ": " << x << flush
#define LOGN(x) cerr << #x << ": " << x << endl

ostream& operator<<(ostream& os, const PII& _)
{return os << "(" << _.ST << "," << _.ND << ")";}

template<class T>
ostream& operator<<(ostream& os, const vector<T>& _)
{
	os << "{";
	if(_.size())
	{
		os << *_.begin();
		for(typename vector<T>::const_iterator i=++_.begin(); i!=_.end(); ++i)
			os << ", " << *i;
	}
	return os << "}";
}

template<class T>
ostream& operator<<(ostream& os, const deque<T>& _)
{
	os << "{";
	if(_.size())
	{
		os << *_.begin();
		for(typename deque<T>::const_iterator i=++_.begin(); i!=_.end(); ++i)
			os << ", " << *i;
	}
	return os << "}";
}

template<class T, class K>
ostream& operator<<(ostream& os, const set<T, K>& _)
{
	os << "{";
	if(_.size())
	{
		os << *_.begin();
		for(typename set<T>::const_iterator i=++_.begin(); i!=_.end(); ++i)
			os << ", " << *i;
	}
	return os << "}";
}

template<class Iter>
void out(ostream& os, Iter begin, Iter end)
{
	os << "{";
	if(begin != end)
	{
		os << *begin;
		for(Iter i = ++begin; i != end; ++i)
			os << ", " << *i;
	}
	os << "}";
}

#define OUT(a, b) cerr << #a << ": ", out(cerr, a, b), eprint("\n")

#else
#define D(...)
#define E(...)
#define LOG(x)
#define LOGN(x)
#define OUT(...)
#endif

uint ceil2(uint x)
{return x&(x-1) ? 1 << (sizeof(uint)*8 - __builtin_clz(x)) : x;}

int main()
{
	int n, m, x, y;
	scanf("%i%i", &n, &m);
	char s[n][m+1];
	REP(i, n)
		scanf("%s", s[i]);
	int a[n][m], b[n][m];
	//   -->       ^
	//             |
	//             |
	b[0][0] = a[0][0] = 1;
	FOR(i, 1, m)
		a[0][i] = (s[0][i-1] != s[0][i] ? a[0][i-1]+1 : 1),
		b[0][i] = 1;
	FOR(j, 1, n)
	{
		b[j][0] = (s[j-1][0] != s[j][0] ? b[j-1][0]+1 : 1);
		a[j][0] = 1;
		FOR(i, 1, m)
			a[j][i] = (s[j][i-1] != s[j][i] ? a[j][i-1]+1 : 1),
			b[j][i] = (s[j-1][i] != s[j][i] ? b[j-1][i]+1 : 1);
	}
	D(
	REP(i, n)
	{
		REP(j, m)
			printf("%i ", a[i][j]);
		printf("\n");
	}
	printf("\n");
	REP(i, n)
	{
		REP(j, m)
			printf("%i ", b[i][j]);
		printf("\n");
	});
	LL res = 0;
	REP(i, n)
	{
		REP(j, m)
		{
			x = a[i][j];
			y = b[i][j];
			if(x < y)
				FOR(k, 0, x)
				{
					y = min(y, b[i][j-k]);
					res += y;
				}
			else
				FOR(k, 0, y)
				{
					x = min(x, a[i-k][j]);
					res += x;
				}
			E("%lli ", res);
		}
		E("\n");
	}
	printf("%lli\n", res);
	return 0;
}
