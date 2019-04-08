#include <iostream>
#include <string>
#include <vector>
using namespace std;

// �� �׽�Ʈ ���̽��� ���...
// ��� Ʋ�� �ɱ�..
int N, M;

class Pos {
public:
	int y;
	int x;
	Pos(int y, int x) : y(y), x(x) {}
};

class Answer {
public:
	int y;
	int x;
	char a;
	Answer(int y, int x, char a) : y(y), x(x), a(a) {}
};

vector< vector<char> > map;
vector< vector< char> > s;
vector< vector<int> > visited;
vector< Pos > city;

char pipe[] = { '|', '-','+','1','2','3','4' };
  
//�� �� �� ��
int dx[] = { 0, 0, -1 , 1 };
int dy[] = { -1, +1 , 0, 0 };

void MakeMap() {
	
	map.resize(N);
	visited.resize(N);
	for (int i = 0; i < N; i++) {
		string  input;
		cin >> input;
		for (int j = 0; j < M; j++) {

			visited[i].push_back(0);

			map[i].push_back(input[j]);
			if (input[j] == 'M') {
				city.push_back(Pos(i, j));
			}
			if (input[j] == 'Z') {
				city.push_back(Pos(i, j));
			}
		}
	}

	s = map;
}

bool Check(int y, int x, int currentState) {

	//�ڽ��� ��Ȳ�� ���� �� �� �ִ� ���� ������ ���� �ִ��� �Ǵ�.
	//cout << y << "  " << x << endl; 
	if (!(y == city[0].y && x == city[0].x)) 
		for (int i = 0; i < 4; i++) {

			int ay = y + dy[i];
			int ax = x + dx[i];

			if (ay < 0 || ay >= N || ax < 0 || ax >= M)
				continue;

			if (currentState == 1) {

				if (i == 0) {

					if (ay == city[1].y && ax == city[1].x) {
						return true;
					}
				}
			}
			else if (currentState == 2) {
				if (i == 1) {
					if (ay == city[1].y && ax == city[1].x) {
						return true;
					}
				}
			}
			else if (currentState == 3) {
				if (i == 2) {
					if (ay == city[1].y && ax == city[1].x) {
						return true;
					}
				}
			}
			else if (currentState == 4) {
				if (i == 3) {
					if (ay == city[1].y && ax == city[1].x) {
						return true;
					}
				}
			}
		}
	

	return false;
}
//char pipe[] = { '|', '-','+','1','2','3','4' };

vector<Answer> answer;

void DFS(int y, int x, int currentState, int count) {

	//cout << y << "  " << x << " " << currentState << " " << map[y][x] <<endl;
	if (Check(y,x,currentState)) {
		
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {

				if (map[i][j] != s[i][j]) {

					answer.push_back(Answer(i + 1, j + 1, map[i][j]));
					return;
				}
			}
		}
	}
	else {
		//4����
		for (int i = 0; i < 4; i++) {
			
			int ay = y + dy[i];
			int ax = x + dx[i];

			if (ay < 0 || ay >= N || ax < 0 || ax >= M)
				continue;

			//visited[y][x] += 1;

			//�湮�� �����ϰ�, '.' �� �ƴ� ��

				//��
				if (i == 0) {

					// ���� ���� ��� �鼭 �̵��� ������ ��
					if (currentState == 0 || currentState == 1) {

						if (map[ay][ax] == '|' && visited[ay][ax] == 0) {
							DFS(ay, ax, 1, count);
						}
						else if (map[ay][ax] == '+' && visited[ay][ax] <= 1) {
							DFS(ay, ax, 1, count);
						}
						else if (map[ay][ax] == '1'  && visited[ay][ax] == 0) {
							DFS(ay, ax, 4, count);
						}
						else if (map[ay][ax] == '4' && visited[ay][ax] == 0) {
							DFS(ay, ax, 3, count);
						}
						else if (map[ay][ax] == '.' ) {

							if (count == 0) {

								for (int j = 0; j < 7; j++) {
									
									if (pipe[j] == '|') {
										map[ay][ax] = '|';
										DFS(ay, ax, 1, count + 1);
										map[ay][ax] = '.';
									}
									if (pipe[j] == '+') {
										map[ay][ax] = '+';
										DFS(ay, ax, 1, count + 1);
										map[ay][ax] = '.';
									}
									if (pipe[j] == '1') {
										map[ay][ax] = '1';
										DFS(ay, ax, 4, count + 1);
										map[ay][ax] = '.';
									}
									if (pipe[j] == '4') {
										map[ay][ax] = '4';
										DFS(ay, ax, 3, count + 1);
										map[ay][ax] = '.';
									}
								}
							}
						}
					}
				}
				//��
				else if (i == 1) {

					//�Ʒ��� ���� ��� �鼭 �̵��� ������ ��
					if (currentState == 0 || currentState == 2) {

						if (map[ay][ax] == '|'&& visited[ay][ax] == 0) {
							DFS(ay, ax, 2, count);
						}
						else if (map[ay][ax] == '+'&& visited[ay][ax] <= 1) {
							DFS(ay, ax, 2, count);
						}
						else if (map[ay][ax] == '2'&& visited[ay][ax] == 0) {
							DFS(ay, ax, 4, count);
						}
						else if (map[ay][ax] == '3'&& visited[ay][ax] == 0) {
							DFS(ay, ax, 3, count);
						}
						else if (map[ay][ax] == '.') {

							if (count == 0) {

								for (int j = 0; j < 7; j++) {

									if (pipe[j] == '|') {
										map[ay][ax] = '|';
										DFS(ay, ax, 2, count + 1);
										map[ay][ax] = '.';
									}
									if (pipe[j] == '+') {
										map[ay][ax] = '+';
										DFS(ay, ax, 2, count + 1);
										map[ay][ax] = '.';
									}
									if (pipe[j] == '2') {
										map[ay][ax] = '2';
										DFS(ay, ax, 4, count + 1);
										map[ay][ax] = '.';
									}
									if (pipe[j] == '3') {
										map[ay][ax] = '3';
										DFS(ay, ax, 3, count + 1);
										map[ay][ax] = '.';
									}
								}
							}
						}
					}
				}
				//��
				else if (i == 2) {

					if (currentState == 0 || currentState == 3) {

						if (map[ay][ax] == '-'&& visited[ay][ax] == 0) {
							DFS(ay, ax, 3, count);
						}
						else if (map[ay][ax] == '+'&& visited[ay][ax] <= 1) {
							DFS(ay, ax, 3, count);
						}
						else if (map[ay][ax] == '1'&& visited[ay][ax] == 0) {
							DFS(ay, ax, 2, count);
						}
						else if (map[ay][ax] == '2'&& visited[ay][ax] == 0) {
							DFS(ay, ax, 1, count);
						}
						else if (map[ay][ax] == '.') {

							if (count == 0) {

								for (int j = 0; j < 7; j++) {

									if (pipe[j] == '-') {
										map[ay][ax] = '-';
										DFS(ay, ax, 3, count + 1);
										map[ay][ax] = '.';
									}
									if (pipe[j] == '+') {
										map[ay][ax] = '+';
										DFS(ay, ax, 3, count + 1);
										map[ay][ax] = '.';
									}
									if (pipe[j] == '1') {
										map[ay][ax] = '1';
										DFS(ay, ax, 2, count + 1);
										map[ay][ax] = '.';
									}
									if (pipe[j] == '2') {
										map[ay][ax] = '2';
										DFS(ay, ax, 1, count + 1);
										map[ay][ax] = '.';
									}
								}
							}
						}
					}

				}
				//��
				else if (i == 3) {

					if (currentState == 0 || currentState == 4) {

						if (map[ay][ax] == '-'&& visited[ay][ax] == 0) {
							DFS(ay, ax, 4, count);
						}
						else if (map[ay][ax] == '+'&& visited[ay][ax] <= 1) {
							DFS(ay, ax, 4, count);
						}
						else if (map[ay][ax] == '3'&& visited[ay][ax] == 0) {
							DFS(ay, ax, 1, count);
						}
						else if (map[ay][ax] == '4'&& visited[ay][ax] == 0) {
							DFS(ay, ax, 2, count);
						}
						else if (map[ay][ax] == '.') {

							if (count == 0) {

								for (int j = 0; j < 7; j++) {

									if (pipe[j] == '-') {
										map[ay][ax] = '-';
										DFS(ay, ax, 4, count + 1);
										map[ay][ax] = '.';
									}
									if (pipe[j] == '+') {
										map[ay][ax] = '+';
										DFS(ay, ax, 4, count + 1);
										map[ay][ax] = '.';
									}
									if (pipe[j] == '3') {
										map[ay][ax] = '3';
										DFS(ay, ax, 1, count + 1);
										map[ay][ax] = '.';
									}
									if (pipe[j] == '4') {
										map[ay][ax] = '4';
										DFS(ay, ax, 2, count + 1);
										map[ay][ax] = '.';
									}
								}
							}
						}
					}
					
				}
			}
		
	}
}

int main() {


	cin >> N >> M;

	MakeMap();
	//�� ������ ��ġ�� �� ���� �Ϸ�

	//DFS�� �ؾ� �� ��?
	//���� ��
	DFS(city[0].y, city[0].x, 0 ,0);

	if (answer.size() == 1) {
		cout << answer[0].y << " " << answer[0].x << " " << answer[0].a << endl;
	}
	else {
		for (int i = 0; i < answer.size(); i++) {
			if (answer[i].a != '+') {
				cout << answer[i].y << " " << answer[i].x << " " << answer[i].a << endl;
			}
		}
	}
	
}