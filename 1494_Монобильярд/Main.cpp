#include <iostream>
using namespace std;

long n, x[100001], stack[100001];

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> x[i];

	bool flag = true;
	int pos = 0, pos2 = 0, sz = 0;

	while (flag && pos < n)
		if (sz > 0 && stack[sz - 1] == x[pos])
		{
			--sz;
			++pos;
		}
		else if (pos2 < n)
		{
			stack[sz] = ++pos2;
			++sz;
		}
		else flag = false;


	if (flag)
		cout << "Not a proof" << endl;
	else
		cout << "Cheater" << endl;
	return 0;
}
