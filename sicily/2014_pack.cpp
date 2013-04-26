#include <iostream>
#include <cstring>
using namespace std;

int f[301];
int n, c;

int main() {
	while(cin >> n >> c) {
		memset(f, 0, sizeof(f));
		f[0] = 1;
		for(int i = 0; i < c; i++){
			int tmp;
			cin >> tmp;
			for(int j = tmp; j <= n; j++) {
				f[j] += f[j - tmp];
			}
		}
		cout << f[n] << endl;
	}
	return 0;
}
