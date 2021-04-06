#include <iostream>

using namespace std;

typedef struct {
	long count;
	long index;
} sign;

long k, min_c=LONG_MAX, max_c=LONG_MIN, kol_sign, first_sign, second_sign;
sign n[10000];

int main()
{
	cin >> k;
	for (long i=0; i<k; i++)
	{
		cin >> n[i].count;
		n[i].index = i+1;
		kol_sign += n[i].count;
		if (n[i].count >= max_c)
			{ max_c = n[i].count; second_sign = i; }
		if (n[i].count < min_c && i != second_sign)
			{ min_c = n[i].count; first_sign = i; }
	}
	
	while (kol_sign > 0)
	{
		if (n[second_sign].count > 0)
		{
			cout << n[second_sign].index << " ";
			n[second_sign].count--;
			kol_sign--;
		}
		if (n[first_sign].count > 0)
		{
			cout << n[first_sign].index << " ";
			n[first_sign].count--;
			kol_sign--;
		}

		min_c = LONG_MAX; max_c = LONG_MIN;
		for(long i=0; i < k; i++) if (n[i].count > 0)
		{
			if (n[i].count >= max_c) 
				{ max_c = n[i].count; second_sign=i; }
			if (n[i].count < min_c) 
				{ min_c = n[i].count; first_sign=i; }
		}
	}

	return 0;
}
