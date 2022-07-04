#define MAX 1000000000

#include <iostream>
#include <algorithm>

using namespace std;

bool IS_SAME_NUM(int n, int b) {

	int temp = n % b;
	n /= b;

	for (; n != 0; n /= b)
		if (temp != n % b)
			return false;

	return true;
}

int main(int argc, char** argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int T, test_case;

	cin >> T;
	for (test_case = 0; test_case < T; test_case++)
	{
		int Answer = MAX;
		
		int N; cin >> N;

		if (N <= 2)
			Answer = N + 1;

		else
		{
			for (int i = 2; i * i <= N; i++)
			{
				if (IS_SAME_NUM(N, i))
				{
					Answer = min(i, Answer);
				}

				if (N % i != 0)
					continue;

				int temp = N / i - 1;

				if (temp > i)
					Answer = min(temp, Answer);
			}

			if (Answer == MAX)
				Answer = N - 1;
		}
		cout << "Case #" << test_case + 1 << endl;
		cout << Answer << endl;
	}

	return 0;
}