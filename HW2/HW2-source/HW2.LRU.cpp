#include<bits/stdc++.h>

// 프레임의 수 만큼 반복 후 페이지가 테이블 프레임과 같으면 1 아니면 0 반환
int present(int table_frame[], int nf, int page){
	for(int i=0; i<nf; i++){
		if(page == table_frame[i])
			return 1;
	}
	return 0;
}

// 테이블 프레임 내용 출력 비어있으면 '--', 아니면 값 출력
void printtable(int table_frame[], int nf){
	for(int i=0; i<nf; i++){
		if(table_frame[i] == -1){
			printf("-- ");
		}
		else{
			printf("%2d ", table_frame[i]);
		}
	}
	printf("||");
}


// 
int findpos(int table_frame[], int nf, int pages[], int curr, int np){
	// 테이블 중 비어있는 값의 인덱스를 반환
	for(int i=0; i<nf; i++){
		if(table_frame[i] == -1){
			return i;
			}
		}

	int pos[nf] = {0};

	// 뭐하는 과정이지?
	for(int i=0; i<nf; i++){
		pos[i] = -1e9;
		// 현재 인덱스 - 1부터 0까지 뒤로 탐색
		for(int j=curr-1; j>=0; j--){
			// 요청 페이지와 테이블의 페이지가 같으면 pos값을 j로 변경 후 정지
			if(pages[j] == table_frame[i]){
				pos[i] = j;
				break;
			}
		}
	}

	int min1 = 1000000, retPos = -1;
	// pos 배열에서 최소값과 최소값을 가진 인덱스 찾기
	for(int i=0; i<nf; i++){
		if(min1 > pos[i]){
			min1 = pos[i];
			retPos = i;
		}
	}
	return retPos;
}

int main(){
    //nf-number of frames
    int n,nf,i,pos=0;

	// 프레임의 수 입력받기
    printf("enter number of frames\n");
    scanf("%d",&nf);
	// 프레임이 있는 테이블 값 초기화
    int table_frame[nf];
    for(i=0;i<nf;i++){
        table_frame[i]=-1;
    }

	// 페이지 요청 수 입력받기
    printf("enter total number of page requests\n");
    scanf("%d",&n);
    
	// 요청 페이지 입력 받기
	int pages[n];
    printf("enter pages\n");
    for(i=0;i<n;i++){
        scanf("%d",&pages[i]);
    }

    int count1=0;
    printf("position of frame table after each request\n");

    for(i=0;i<n;i++){
        printf("page table after request from %2d || ",pages[i]);
		
		//  요청 페이지와 테이블의 페이지가 일치하면 1을 반환, 일치하는 상황(!1)은 거짓이므로 패스
        if(!present(table_frame,nf,pages[i])){

			// pos값은 
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