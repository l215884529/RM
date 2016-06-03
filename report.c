#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUF_SIZE 1000
#define GRAPH_SIZE 99

typedef struct line_t {
	int enable;
	int cost;
} line_t;

line_t graph[GRAPH_SIZE][GRAPH_SIZE];

int main(int argc, char *argv[]) {
	int start, end;
	if (argc != 2) {
		printf("Usage: ./a.out start end < graph\n");
		exit(1);
	}
	start = atoi(argv[1]);
	end = atoi(argv[2]);
	char buf[BUF_SIZE];
	int i, j;
	for (i = 0; i < GRAPH_SIZE; i++) {
		for (j = 0; j < GRAPH_SIZE; j++) {
			graph[i][j].enable = 0;
			graph[i][j].cost = 0;
		}
	}
	
	while (fgets(buf, BUF_SIZE, stdin) != NULL) {
		buf[strlen(buf) - 1] = '\0';
		const int node1 = atoi(strtok(buf, ","));
		const int node2 = atoi(strtok(NULL, ","));
		const int cost = atoi(strtok(NULL, ","));
		graph[node1][node2].enable = 1;
		graph[node1][node2].cost = cost;
		graph[node2][node1].enable = 1;
		graph[node1][node2].cost = cost;
	}

	
}
