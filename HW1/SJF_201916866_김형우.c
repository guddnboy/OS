#include<stdio.h>
#include<ncurses.h>
#include<unistd.h>
#include<stdlib.h>

void main(){
    int n,b[10],w[10],i,j,h,t,tt;
    int stime[10],a[10];
    int tmp;
    int b_sum = 0;
    float avg=0;

    printf("\n\tJOB SCHEDULING ALGORITHM[SJF]");
    printf("\n\t*****************************************************\n");
    printf("\nEnter howmany jobs:");
    scanf("%d",&n);
    printf("\nEnter burst time for corresponding job....\n");

    for(i = 1; i <= n; i++){
        printf("\nProcess %d:",i);
        scanf("%d", &b[i]);
        a[i]=i;
    }

    for (i = 1; i <= n; i++){
        printf("\nP%d 도착시간: ", i);
        scanf("%d", &stime[i]);
    }

    for(i = 1; i <= n; i++){
        for(j = i; j <= n; j++){
            if (i!=1){
                if(b[i] > b[j]){
                    // 수행시간 정렬
                    t=b[i];
                    b[i]=b[j];
                    b[j]=t;

                    // 프로세스 순번 정렬
                    tt=a[i];
                    a[i]=a[j];
                    a[j]=tt;

                    // 프로세스 도착시간 정렬
                    tmp = stime[i];
                    stime[i] = stime[j];
                    stime[j] = tmp;
                    }
                }
            }
        }
    w[1]=0;

    printf("\nprocess %d waiting time is 0",a[1]);
// 프로세스별 대기시간 계산하기
    for(i = 2; i <= n; i++){
        w[i] = b[i-1] + w[i-1] + stime[i-1] - stime[i];
        printf("\nProcess %d waiting time: %d",a[i],w[i]);
        avg += w[i];
    }

    printf("\ntotal waiting time:%f",avg);
    printf("\n\nthe average waiting time is:%f\n",avg/n);

    printf("\nGaunt Chart\n***************************************\n\n");

    h=22;
    
// 프로세스 수행시간 그래프 그리기
    
    printf("\n");
    printf("수행시간\t");

    for(i = 1; i <= n; i++){
        for (int k =0; k < b[i]; k++){
            printf("-");
        }
        printf("|");

        for(j = 1; j <= b[i]; j++){
            printf("%c",h);
        }
    }


    printf("\n시간  \t\t");
    for(i = 0; i <= n; i++){
        for(int k = 0; k < b[i]; k++){
            printf(" ");
        }
        b_sum += b[i];

        if (i != n){
            printf("%d", b_sum);
        }
        
    }

    printf("\n대기시간\t");

    for(i = 1; i <= n; i++){
        for (int k = 0; k < b[i]; k++){
            printf(" ");
        }
        if(i<n){
            printf("%d",w[i+1]);
        }
    
        for(j = 1; j <= w[i]; j++){
            printf("%c",h);
            sleep(1);
        }
    }
    printf("\n");
    getchar();

}