#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main(int argc, char** argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int T, test_case;

	cin >> T;
	for (test_case = 0; test_case < T; test_case++)
	{
		int Answer = 0;
		int N; cin >> N;
		queue<int> A;
		int temp;

		for (int i = 0; i < N - 1; i++)
		{
			cin >> temp;
			A.push(temp);
		}
		int end; cin >> end;
		int K; cin >> K;

		int start = 0;
		int last = -1;
		int cnt = 0;

		while (1)
		{
			if (start + K >= A.front())
			{
				last = A.front();
				A.pop();
			}
			else
			{
				if (last == -1)
					break;

				start = last;
				cnt++;

				if (start + K < A.front())
					break;
			}
			
			if (A.empty())
			{
				if (start + K < end)
				{
					if (last + K >= end)
					{
						start = last;
						cnt++;
						break;
					}
				}
				else
					break;
			}
		}

		if (start + K >= end)
			Answer = cnt + 1;
		else
			Answer = -1;

		cout << "Case #" << test_case + 1 << endl;
		cout << Answer << endl;
	}

	return 0;//Your program should return 0 on normal termination.
}