#include <stdio.h>
#include <vector>

using namespace std;

#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)

int n;
int before, after;
int chk[201];
int nRet;

vector <int> vec;

typedef struct inf{
	int bef, aft;
};

vector <inf> vec_room;

int main()
{
	int t;
	int test_case;

	freopen("sample_input.txt", "r", stdin);
	scanf("%d", &t);

	for (test_case = 1; test_case <= t; ++test_case)
	{
		scanf("%d", &n);

		vec_room.clear();
		for (int i = 0; i < n; i++){
			scanf("%d %d", &before, &after);
			vec_room.push_back({ before, after });
		}
		
		for (int i = 0; i < 201; i++)
			chk[i] = 0;

		nRet = 1;
		for (int i = 0; i < vec_room.size(); i++){
			inf room = vec_room[i];

			int first_room;
			int second_room;

			if (room.bef % 2 == 0)
				first_room = room.bef / 2;
			else
				first_room = (room.bef / 2) + 1;

			if (room.aft % 2 == 0)
				second_room = room.aft / 2;
			else
				second_room = (room.aft / 2) + 1;

			int check = 1;
			if (first_room <= second_room){
				for (first_room; first_room <= second_room; first_room++){
					chk[first_room]++;
				}
			}
			else{
				for (second_room; second_room <= first_room; second_room++){
					chk[second_room]++;
				}
			}
		}
		int max = 0;
		for (int i = 0; i < 201; i++){
			if (max <= chk[i])
				max = chk[i];
		}
		nRet = max;

		printf("#%d %d\n", test_case, nRet);


	}

	return 0;
}