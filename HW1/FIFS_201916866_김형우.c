#include<stdio.h>
#include<ncurses.h>
#include<unistd.h>
#include<stdlib.h>


int main() {
    int n, b[10], w[10], i, j, h, idx;
    float avg = 0;
	int arrive[10];

    printf("\n\tJOB SCHEDULING ALGORITHM[FCFS]");
    printf("\n\t*****************************************************\n");
    printf("\nEnter how many jobs:");
    scanf("%d", &n);

    printf("\nEnter burst time for corresponding job....\n");

    w[0] = 0;
    
    for (i = 0; i < n; i++) {
        printf("\nProcess Time %d:", i + 1);
        scanf("%d", &b[i]);

		printf("\nArrival Time %d:", i + 1);
		scanf("%d", &arrive[i]);
    }


    printf("\nprocess 1 waiting time is 0");
    for (i = 1; i < n; i++) {
        w[i] = b[i-1] + w[i-1] + arrive[i-1] - arrive[i];
        printf("\nProcess %d waiting time: %d", i + 1, w[i]);
        avg += w[i];
    }

    printf("\ntotal waiting time:%f", avg);

    printf("\n\nthe average waiting time is:%f\n", avg / n);
    printf("\nGantt Chart\n***************************************\n\n\t");
    h = 22;

// 프로세스 수행시간 그래프 그리기
    printf("\t\t");

    for (i = 0; i < n; i++) {
        printf("P%d(%d)\t\t\t",i + 1, b[i]);
    }
    printf("\n그래프\t\t");

    for (i = 0; i < n; i++) {
        for (j = 0; j < b[i]; j++) {
            printf("-");
        }
        printf("|");
    }    

    printf("\n도착시간\t");

// 프로세스 도착 시간 표시
    for (i = 0; i < n; i++){
        for (j =1; j < arrive[i]-arrive[i-1]-1; j++){
            printf(" ");
        }
        printf("%d", arrive[i]);
    }

    printf("\n대기시간\t");

// 프로세스 대기 시간 표시
    for (i = 0; i < n; i++) {
        for (j = 0; j < b[i]-1; j++) {
            printf(" ");
        }
        if(i+1 < n){
            printf("%d", w[i+1]);  
        }

        for (j = 1; j <= w[i]; j++) {
            printf("%c", h);
			sleep(1);
		}
        // printf("\n\t");
    }
    printf("\n");
    getchar();
}
