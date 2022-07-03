#include <iostream>
#include <vector>
#include <string>

using namespace std;

typedef struct pos {
	int x;
	int y;
	int dir;
}pos;

pos temp;

void next_pos(int cur)
{
	if (cur == 0)
		temp.x++;
	else if (cur == 1)
		temp.y--;
	else if (cur == 2)
		temp.x--;
	else
		temp.y++;
}

void next(pos cur, char mirror)
{
	temp = cur;

	if (mirror == '1')
	{
		if (cur.dir == 0)
			temp.dir = 1;
		else if (cur.dir == 1)
			temp.dir = 0;
		else if (cur.dir == 2)
			temp.dir = 3;
		else
			temp.dir = 2;
	}

	else if(mirror == '2')
	{
		if (cur.dir == 0)
			temp.dir = 3;
		else if (cur.dir == 1)
			temp.dir = 2;
		else if (cur.dir == 2)
			temp.dir = 1;
		else
			temp.dir = 0;
	}

	next_pos(temp.dir);
}

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
		vector<string> arr(N);
		vector<vector<bool>> visited(N, vector<bool>(N, false));
		for (int i = 0; i < N; i++)
			cin >> arr[i];

		pos cur = { 0, 0, 3 };
		while (1)
		{
			if(cur.x < 0 || cur.x >= N || cur.y < 0 || cur.y >= N)
				break;

			if (!visited[cur.x][cur.y] && arr[cur.x][cur.y] != '0')
			{
				visited[cur.x][cur.y] = true;
				Answer++;
			}

			next(cur, arr[cur.x][cur.y]);
			cur = temp;
		}

		cout << "Case #" << test_case + 1 << endl;
		cout << Answer << endl;
	}

	return 0;
}