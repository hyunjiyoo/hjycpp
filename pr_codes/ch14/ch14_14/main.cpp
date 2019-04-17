#include <iostream>
using namespace std;
void UsingArray(char* arr);
int main() {
	char array[20] = "Hello, World!";
	UsingArray(array);

	cout << "In main(): " << array << endl;
	return 0;
}
void UsingArray(char* arr) {
	cout << "In UsingArray(): " << arr << endl;
	*(arr + 12) = '?';
}