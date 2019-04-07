#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;
const int INF = 1000000000;
const int MAX = 100000;

struct Point
{
	int z, x, y;
	Point() {}
	Point(int z, int x, int y) :z(z), x(x), y(y) {}
};

char building[31][31][31];
int visit[31][31][31];
int dx[6] = { -1,0,0,1,0,0 };
int dy[6] = { 0,-1,1,0,0,0 };
int dz[6] = { 0,0,0,0,-1,1 };

int main()
{
	int L, R, C;
	while (scanf("%d %d %d", &L, &R, &C) == 3)
	{
		if (L == 0 && R == 0 && C == 0)
			break;
		Point start, end;
		for (int i = 0; i < L; i++)
		{
			for (int j = 0; j < R; j++)
			{
				for (int k = 0; k < C; k++)
				{
					scanf(" %1c", &building[i][j][k]);
					if (building[i][j][k] == 'S')
					{
						start = Point(i, j, k);
					}
					else if (building[i][j][k] == 'E')
					{
						end = Point(i, j, k);
					}
				}
			}
			getchar();
		}

		queue<Point> q;
		q.push(start);
		visit[start.z][start.x][start.y] = 1;
		while (!q.empty())
		{
			int cx = q.front().x;
			int cy = q.front().y;
			int cz = q.front().z;
			q.pop();
			for (int i = 0; i < 6; i++)
			{
				int nx = cx + dx[i];
				int ny = cy + dy[i];
				int nz = cz + dz[i];
				if (nx < 0 || ny < 0 || nz < 0 || nz >= L || nx >= R || ny >= C || visit[nz][nx][ny] || building[nz][nx][ny] == '#')
					continue;
				else
				{
					visit[nz][nx][ny] = visit[cz][cx][cy] + 1;
					q.push(Point(nz, nx, ny));
				}
			}
		}
		if (visit[end.z][end.x][end.y])
		{
			printf("Escaped in %d minute(s).\n", visit[end.z][end.x][end.y] - 1);
		}
		else
		{
			puts("Trapped!\n");
		}

		memset(visit, 0, sizeof(visit));
	}
	return 0;
}