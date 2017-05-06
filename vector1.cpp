#include<vector>
#include<string>
#include<iostream>

using namespace std;

int main() {
	vector<int> v(7);
	v.assign({ 2,4,6,8,10 });
	for (auto &i : v) {
		cout << i << endl;
	}
	return 0;
}