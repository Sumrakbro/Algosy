#include <iostream>

using namespace std;
long long n, x[100005], y[100005], sum_x=0, sum_y=0;

int cmp(const void * x1, const void * x2) { return (*(long*)x1 - *(long*)x2); }

int main()
{
	cin >> n;
	for (long i = 0; i < n; i++)
		cin >> x[i] >> y[i];

	qsort(x, n, sizeof(long long), cmp);
	qsort(y, n, sizeof(long long), cmp);

	for (long i=1; i<n; i++)
	{
		sum_x += (x[i] - x[i - 1]) * i * (n - i) * 2;
		sum_y += (y[i] - y[i - 1]) * i * (n - i) * 2;
	}

	cout << (sum_x + sum_y) / (n*(n - 1));
	return 0;
}

