//vector 때문에 시간 초과.... ㅂㄷㅂㄷ
//vector의 생성과 clear 가 시간을 많이 잡아 먹을 수 있다는 생각

#include <iostream>
#include <vector>
using namespace std;

int gue[10] = { 0 };
int inyoung[10] = { 0 };
int visited[10] = { 0 };

int win = 0;
int lose = 0;

bool NotFoundInGue(int in) {

	for (int i = 0; i < 9; i++) {
		if (gue[i] == in) {
			return false;
		}
	}
	return true;
}

void BruteForce(int gue_score, int inyoung_score,int g_i) {

	if (g_i == 9) {

		if (gue_score > inyoung_score) {
			win++;
		}
		else if (gue_score < inyoung_score) {
			lose++;
		}
		return;
	}

	for (int i = 0; i < 9; i++) {

		if (visited[i] == 0) {
			visited[i] = 1;
			int score_g = gue_score;
			int score_i = inyoung_score;
			if (gue[g_i] > inyoung[i]) {
				score_g += gue[g_i] + inyoung[i];
				BruteForce(score_g, score_i, g_i + 1);
			}

			if (gue[g_i] < inyoung[i]) {
				score_i += gue[g_i] + inyoung[i];
				BruteForce(score_g, score_i, g_i + 1);
			}
			visited[i] = 0;
		}
	}
	

}

int main() {

	int testCase;
	cin >> testCase;

	for (int t = 1; t <= testCase; t++) {

		for (int i = 0; i < 9; i++) {
			int input;
			scanf("%d", &input);
			gue[i] = input;
		}

		int index = 0;
		for (int i = 1; i <= 18; i++) {

			if (NotFoundInGue(i))
				inyoung[index++] = i;
		}
	
		BruteForce(0, 0, 0);
		

		cout << "#" << t << " " << win << " " << lose << endl;
		win = 0;
		lose = 0;
	}
}