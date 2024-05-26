#include <bits/stdc++.h>

int present(char table_frame[], int nf, char page) {
    for(int i = 0; i < nf; i++) {
        if(page == table_frame[i]) {
            return 1;
        }
    }
    return 0;
}

void printtable(char table_frame[], int nf) {
    for(int i = 0; i < nf; i++) {
        if(table_frame[i] == ' ') {
            printf("-- ");
        } else {
            printf("%c ", table_frame[i]);
        }
    }
    printf("||");
}

int main() {
    int n, nf, i;

    printf("Enter number of frames\n");
    scanf("%d", &nf);

    char table_frame[nf];
    for(i = 0; i < nf; i++) {
        table_frame[i] = ' ';
    }

    printf("Enter total number of page requests\n");
    scanf("%d", &n);

    char pages[n];
    printf("Enter reference string\n");
    for(i = 0; i < n; i++) {
        scanf(" %c", &pages[i]);
    }

    int count = 0;
    printf("Position of frame table after each request\n");

    for(i = 0; i < n; i++) {
        printf("Page table after request from %c || ", pages[i]);

        if(!present(table_frame, nf, pages[i])) {
            for(int j = nf - 1; j > 0; j--) {
                table_frame[j] = table_frame[j - 1];
            }
            table_frame[0] = pages[i];
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