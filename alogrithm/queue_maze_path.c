#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int Map[10][10] = {
					{1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
					{1, 0, 0, 1, 0, 0, 0, 1, 0, 1},
					{1, 0, 0, 1, 0, 0, 0, 1, 0, 1},
					{1, 0, 0, 0, 0, 1, 1, 0, 0, 1},
					{1, 0, 1, 1, 1, 0, 0, 0, 0, 1},
					{1, 0, 0, 0, 1, 0, 0, 0, 0, 1},
					{1, 0, 1, 0, 0, 0, 1, 0, 0, 1},
					{1, 0, 1, 1, 1, 0, 1, 1, 0, 1},
					{1, 1, 0, 0, 0, 0, 0, 0, 0, 0},
					{1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
					};
					

int front = 0, rear = 0;
struct Node{
	int parent_id;
	int node_id;
	int x, y;
}Q[10*10];

int GetNextPos(int *i, int *j, int count){
	switch(count){
		case 1:(*j)++;return 1;
		case 2:(*i)++;return 1;
		case 3:(*j)--;return 1;
		case 4:(*i)--;return 1;
		default: return 0;
	}
}

void EnQueue(int i, int j, int k){
    /*data enqueue.
    store value in array, where value is zero.
    */
	Q[rear].x = i;
	Q[rear].y = j;
	Q[rear].parent_id = k;
	Q[rear].node_id = rear;
	rear++;
}

void DeQueue(int *i, int *j, int *k){
    /*data dequeue
    extract value from array for search path.
    */
	*i = Q[front].x;
	*j = Q[front].y;
	*k = Q[front].node_id;
	front++;
} 

void ShortestPath_BFS(int i, int j){
	int count, m, n, k;
	EnQueue(i, j, -1);
    // Marking start point with 1.
	Map[i][j] = 1;
	while(1){
		count = 1;
		DeQueue(&i, &j, &k);
//		printf("(%d,%d)", i,j);
		n = i;
		m = j;
		while(GetNextPos(&i, &j, count)){
			count++;
			if(!Map[i][j]){
				EnQueue(i, j, k);
				Map[i][j] = 1;
				if(i == 8 && j == 9) return;
			}
			i = n;
			j = m;
		}
	}
}

void ShortestPath(){
	int i,j,k,sum=0;
	k = rear - 1;
	while(k!=-1){
		i = Q[k].x;
		j = Q[k].y;
		Map[i][j] = 2;
		k = Q[k].parent_id;
	}
	printf("  0 1 2 3 4 5 6 7 8 9\n");
	for(i=0;i<10;i++){
		printf(" %d", i);
		for(j=0;j<10;j++){
			if(Map[i][j]==2){
				sum++;
				printf("□");
			}
			else{
				printf("■");
			} 
		}
		printf("\n");
	}
}
/**/
void Print(){
	int i, j;
	printf("  0 1 2 3 4 5 6 7 8 9\n");
	for(i=0;i<10;i++){
		printf(" %d",i);
		for(j=0;j<10;j++){
			if(Map[i][j]){
				printf("■");
			}
			else{
				printf("□");
			}
		}
		printf("\n");
	}
}

int main(int argc, char *argv[]) {
	printf(" 初始地图：\n");
//	void Print();
	Print();
//	Q[0].node_id = 10;
//	printf("Q:%d",Q[0].node_id);
	int i=1, j=1;
	ShortestPath_BFS(i, j);
    printf("此时坐标:(%d, %d)", i, j);
	printf(" 最短路径之一：\n");
	ShortestPath();
	system("pause");
//	return 0;
}
