/*
   h1011
   Problem Description:
   You, the leader of Starship Troopers, are sent to destroy a base of the bugs. The base is built underground. It is actually a huge cavern, which consists of many rooms connected with tunnels. Each room is occupied by some bugs, and their brains hide in some of the rooms. Scientists have just developed a new weapon and want to experiment it on some brains. Your task is to destroy the whole base, and capture as many brains as possible.

   To kill all the bugs is always easier than to capture their brains. A map is drawn for you, with all the rooms marked by the amount of bugs inside, and the possibility of containing a brain. The cavern's structure is like a tree in such a way that there is one unique path leading to each room from the entrance. To finish the battle as soon as possible, you do not want to wait for the troopers to clear a room before advancing to the next one, instead you have to leave some troopers at each room passed to fight all the bugs inside. The troopers never re-enter a room where they have visited before.

   A starship trooper can fight against 20 bugs. Since you do not have enough troopers, you can only take some of the rooms and let the nerve gas do the rest of the job. At the mean time, you should maximize the possibility of capturing a brain. To simplify the problem, just maximize the sum of all the possibilities of containing brains for the taken rooms. Making such a plan is a difficult job. You need the help of a computer.


  Input
  The input contains several test cases. The first line of each test case contains two integers N (0 < N <= 100) and M (0 <= M <= 100), which are the number of rooms in the cavern and the number of starship troopers you have, respectively. The following N lines give the description of the rooms. Each line contains two non-negative integers -- the amount of bugs inside and the possibility of containing a brain, respectively. The next N - 1 lines give the description of tunnels. Each tunnel is described by two integers, which are the indices of the two rooms it connects. Rooms are numbered from 1 and room 1 is the entrance to the cavern.

  The last test case is followed by two -1's.

  Output
  For each test case, print on a single line the maximum sum of all the possibilities of containing brains for the taken rooms.

  Sample Input
  5 10
  50 10
  40 10
  40 20
  65 30
  70 30
  1 2
  1 3
  2 4
  2 5
  1 1
  20 7
  -1 -1

  Sample Output
  50
  7

  Status:
  Ongoning

  */
#include<stdio.h>
#define MAX_ROM 100
#define MAX_TRA 100
int dp[MAX_ROM][MAX_TRA] = {0};
int room[MAX_ROM][MAX_ROM] = {0};
//int tper[MAX_ROM];
int bugs[MAX_ROM];
int posb[MAX_ROM];
int max_posb = 0;
int visited[MAX_ROM];
int room_num;
int all_tper_num;
int room_idx;
#define max(a, b) (a > b ? a : b)
/*
void debug_all()
{
	int i =0;
	int j =0;
	for(i; i<= room_num; i++)
	{
		printf("room %d ", i);
		for (j = 0; j <= all_tper_num; j++)
			printf("%d ", dp[i][j]);
		printf("\n");
	}

}
void debug_visit()
{
	int i =0;
	for(i;i<=room_num;i++)
		printf("room %d: %d ", i, visited[i]);
	printf("\n");
}
*/
void cal_max(int parent_idx)
{
	int tper_required; 
	int room_idx = 1;
	int tper_num;

	for (; room_idx <= room_num; room_idx ++) {
		if (!room[parent_idx][room_idx] || visited[room_idx] )
			continue;

		tper_required = bugs[room_idx] % 20 ? bugs[room_idx] / 20 + 1: bugs[room_idx] / 20;

		for (tper_num = 0; tper_num <= all_tper_num; tper_num++) {
			if (tper_num < tper_required)
				dp[room_idx][tper_num] = dp[parent_idx][tper_num];
			else {
				dp[room_idx][tper_num] = max(dp[room_idx][tper_num], dp[parent_idx][tper_num - tper_required] + posb[room_idx]);
			}
			max_posb = max(max_posb, dp[room_idx][tper_num]);
		}
		visited[room_idx] = 1; 
		//debug_visit();
		cal_max(room_idx);
		visited[room_idx] = 0;
	}
}

int main()
{
	int room_idx;
	int x,y;

	while(scanf("%d %d", &room_num, &all_tper_num) && (room_num != -1) && (all_tper_num != -1)) {
		max_posb = 0;
		room_idx = 1;
		while(room_idx <= room_num) {
			scanf("%d %d", &bugs[room_idx], &posb[room_idx]);
			room_idx ++;
		}


		room_idx = 1;
		/* room_num -1 tunnel */
		for(;room_idx < room_num; room_idx ++) {
			scanf("%d %d", &x, &y);
			room[x][y] = 1;
		}

		room_idx = 0;
		for(; room_idx <= room_num; room_idx ++) {
			room[room_idx][0] = 1;
			room[0][room_idx] = 1;
		}

		room_idx = 0;
		visited[room_idx] = 1; 
		cal_max(room_idx);
		printf("%d\n", max_posb);
		//debug_all();
	}
	return 0;
}
