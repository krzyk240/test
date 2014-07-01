#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int main(){
	int n, m, x, y;
	scanf("%i%i", & n, & m);
	char s[n][m + 1];
	for(int i = 0;
	i < (n);
	++i) scanf("%s", s[i]);
	int a[n][m], b[n][m];
	b[0][0] = a[0][0] = 1;
	for(int i = 1;
	i < (m);
	++i) a[0][i] = (s[0][i - 1] != s[0][i] ? a[0][i - 1] + 1 : 1), b[0][i] = 1;
	for(int j = 1;
	j < (n);
	++j){
		b[j][0] = (s[j - 1][0] != s[j][0] ? b[j - 1][0] + 1 : 1);
		a[j][0] = 1;
		for(int i = 1;
		i < (m);
		++i) a[j][i] = (s[j][i - 1] != s[j][i] ? a[j][i - 1] + 1 : 1), b[j][i] = (s[j - 1][i] != s[j][i] ? b[j - 1][i] + 1 : 1);
	} ;
	long long res = 0;
	for(int i = 0;
	i < (n);
	++i){
		for(int j = 0;
		j < (m);
		++j){
			x = a[i][j];
			y = b[i][j];
			if(x < y) for(int k = 0;
			k < (x);
			++k){
				y = min(y, b[i][j - k]);
				res += y;
			}
			else for(int k = 0;
			k < (y);
			++k){
				x = min(x, a[i - k][j]);
				res += x;
			} ;
		} ;
	}
	printf("%lli\n", res);
	return 0;
}
