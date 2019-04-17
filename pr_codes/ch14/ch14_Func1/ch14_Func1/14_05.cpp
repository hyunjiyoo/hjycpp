#include <iostream>
using namespace std;
int Three() {
	return 3;
}
int main() {
	int ret;
	ret = Three();
	cout << "ret: " << ret << endl;
	return 0;
}