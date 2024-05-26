#include <bits/stdc++.h>

int present(char table_frame[], int nf, char page, int cnt[], int time) {
    for (int i = 0; i < nf; i++) {
        if (page == table_frame[i]) {
            cnt[i] = time;
            return 1;
        }
    }
    return 0;
}

void printtable(char table_frame[], int nf) {
    for (int i = 0; i < nf; i++) {
        if (table_frame[i] == ' ') {
            printf("-- ");
        } else {
            printf("%c  ", table_frame[i]);
        }
    }
    printf("||");
}

int findpos(int cnt[], int nf) {
    int min1 = INT_MAX;
    int retPos = -1;
    for (int i = 0; i < nf; i++) {
        if (cnt[i] < min1) {
            min1 = cnt[i];
            retPos = i;
        }
    }
    return retPos;
}

int main() {
    int n, nf, i;

    printf("Enter number of frames\n");
    scanf("%d", &nf);

    char table_frame[nf];
    int cnt[nf];
    for (i = 0; i < nf; i++) {
        table_frame[i] = ' ';
        cnt[i] = 0;
    }

    printf("Enter total number of page requests\n");
    scanf("%d", &n);

    char pages[n];
    printf("Enter pages\n");
    for (i = 0; i < n; i++) {
        scanf(" %c", &pages[i]);
    }

    int count = 0;
    printf("Position of frame table after each request\n");

    for (i = 0; i < n; i++) {
        printf("Page table after request from %c || ", pages[i]);

        if (!present(table_frame, nf, pages[i], cnt, i + 1)) {
            int pos = findpos(cnt, nf);
            table_frame[pos] = pages[i];
            cnt[pos] = i + 1;
            printtable(table_frame, nf);
            printf(" page fault\n");
            count++;
        } else {
            printtable(table_frame, nf);
            printf("\n");
        }
    }
    printf("\nNumber of page faults: %d\n\n", count);

    return 0;
}