#include<bits/stdc++.h>


int present(char table_frame[], int nf, char page){
    for(int i = 0; i < nf; i++){
        if(page == table_frame[i])
            return 1;
    }
    return 0;
}

void printtable(char table_frame[], int nf){
    for(int i = 0; i < nf; i++){
        if(table_frame[i] == ' '){
            printf("-- ");
        }
        else{
            printf("%c  ", table_frame[i]);
        }
    }
    printf("||");
}

int findpos(char table_frame[], int nf, char pages[], int curr, int n){
    int i, j;

    for(i = 0; i < nf; i++){
        if(table_frame[i] == ' '){
            return i;
        }
    }

    int pos[nf];
    for(i = 0; i < nf; i++){
        pos[i] = INT_MAX;
        for(j = curr + 1; j < n; j++){
            if(pages[j] == table_frame[i]){
                pos[i] = j;
                break;
            }
        }
    }

    int max1 = -1, returnpos = -1;
    for(i = 0; i < nf; i++){
        if(pos[i] > max1){
            max1 = pos[i];
            returnpos = i;
        }
    }
    return returnpos;
}

int main(){
    int n, nf, i, pos = 0;

    printf("Enter number of frames\n");
    scanf("%d", &nf);
    char table_frame[nf];
    for(i = 0; i < nf; i++){
        table_frame[i] = ' ';
    }

    printf("Enter total number of page requests\n");
    scanf("%d", &n);
    char pages[n];
    printf("Enter pages\n");
    for(i = 0; i < n; i++){
        scanf(" %c", &pages[i]);
    }

    int count = 0;
    printf("Position of frame table after each request\n");
    for(i = 0; i < n; i++){
        printf("Page table after request from %c || ", pages[i]);
        if(!present(table_frame, nf, pages[i])){
            int pos = findpos(table_frame, nf, pages, i, n);
            table_frame[pos] = pages[i];

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