#include<bits/stdc++.h>

// 프레임의 수 만큼 반복 후 페이지가 테이블 프레임과 같으면 1 아니면 0 반환
int present(char table_frame[], int nf, char page){
	for(int i=0; i<nf; i++){
		if(page == table_frame[i])
			return 1;
    }
	return 0;
}

// 테이블 프레임 내용 출력 비어있으면 '--', 아니면 값 출력
void printtable(char table_frame[], int nf){
	for(int i=0; i<nf; i++){
		if(table_frame[i] == ' '){
			printf("-- ");
        }
		else{
			printf("%c  ", table_frame[i]);
        }
	}
	printf("||");
}


int findpos(char table_frame[],int nf,char pages[],int curr,int np){
    int i,j;
    // 테이블의 값이 비어있으면 해당 인덱스 반환
    for(i=0;i<np;i++){
        if(table_frame[i] == ' '){
            return i;
        }
    }

    int pos[nf];

// 앞으로의 요청들 중에서 다시 호출되기까지의 시간이 긴 요청 찾기
    for(i=0;i<nf;i++){
        pos[i]=1e9;
        for(j=curr+1;j<nf;j++){
            if(pages[j]==table_frame[i]){
                pos[i]=j;
                break;
            }
        }
    }

// 값이 가장 큰 페이지, 교체할 공간을 결정
    int max1=-1;
    int returnpos=-1;
    for(i=0;i<nf;i++){
        if(pos[i]>max1){
            max1=pos[i];
            returnpos=i;
        }
    }

    return returnpos;
}

int main(){
    //nf-number of frames
    int n,nf,i,pos=0;

    printf("enter number of frames\n");
    scanf("%d",&nf);
    char table_frame[nf];
    for(i=0;i<nf;i++){
        table_frame[i]=' ';
    }

    printf("enter total number of page requests\n");
    scanf("%d",&n);
    char pages[n];
    printf("enter pages\n");
    for(i=0;i<n;i++){
        scanf(" %c",&pages[i]);
    }

    int count1=0;
    printf("position of frame table after each request\n");
    for(i=0;i<n;i++){
        printf("page table after request from %c || ",pages[i]);
        if(!present(table_frame,nf,pages[i])){
             int pos = findpos(table_frame,nf,pages,i,n);
             table_frame[pos]=pages[i];

             printtable(table_frame,nf);
             printf("page fault\n");
             count1++;
             continue;
        }
        printtable(table_frame,nf);
		printf("\n");

    }
    printf("\nNumber of page faults : %d\n\n", count1);
}