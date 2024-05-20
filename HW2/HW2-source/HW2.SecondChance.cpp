#include <bits/stdc++.h>
using namespace std;

bool present(char table_frame[], int rf_bit[], int nf, char page) {
    for (int i = 0; i < nf; ++i) {
        if (table_frame[i] == page) {
            rf_bit[i] = 1; 
            return true;
        }
    }
    return false;
}

void printtable(char table_frame[], int nf) {
    for (int i = 0; i < nf; ++i) {
        if (table_frame[i] == ' ') {
            printf("-- ");
        } else {
            printf("%c ", table_frame[i]);
        }
    }
    printf("||");
}

int main() {
    int nf;
    cout << "Enter number of frames" << endl;
    cin >> nf;
    char table_frame[nf];
    int rf_bit[nf];
    for (int i = 0; i < nf; ++i) {
        table_frame[i] = ' ';
        rf_bit[i] = 0;
    }

    int np;
    cout << "Enter number of pages" << endl;
    cin >> np;
    char pages[np];
    cout << "Enter page requests" << endl;
    for (int i = 0; i < np; ++i) {
        cin >> pages[i];
    }

    int pos = 0, count = 0;
    printf("Position of frame table after each request\n");

    for (int i = 0; i < np; ++i) {
        printf("Page table after request from %c || ", pages[i]);
        if (!present(table_frame, rf_bit, nf, pages[i])) {
            while (rf_bit[pos] == 1) {
                rf_bit[pos] = 0;  
                pos = (pos + 1) % nf; 
            }
            table_frame[pos] = pages[i];
            rf_bit[pos] = 1;  
            pos = (pos + 1) % nf;  
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
