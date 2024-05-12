//표준 라이브러리가 아니라서 따로 설치 후 설정/c_cpp/include path에 bits/stdc++.h 경로 추가
#include<bits/stdc++.h>
using namespace std;

// 프레임의 수 만큼 반복 후 페이지가 테이블 프레임과 같으면 1 아니면 0 반환
int present(int table_frame[], int nf, int page){
	for(int i=0; i<nf; i++){
		if(page == table_frame[i]){
			return 1;
        }
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


int main(){
    //nf-number of frames
    int n,nf,i,pos=0;

    // 프레임의 수 입력받기
    printf("enter number of frames\n");
    scanf("%d",&nf);

    // 프레임의 수만큼 테이블 값 -1로 초기화
    int table_frame[nf];
    for(i=0;i<nf;i++){
        table_frame[i]=-1;
    }

    // 페이지 요청의 수 입력받기
    printf("enter total number of page requests\n");
    scanf("%d",&n);
    int pages[n];
    printf("enter reference string\n");
    // 요청할 페이지 입력
    for(i=0;i<n;i++){
        scanf("%d",&pages[i]);
    }

    int count1=0;
    printf("position of frame table after each request\n");
    for(i=0;i<n;i++){
        printf("page table after request from %2d || ",pages[i]);
        
        //  요청 페이지와 테이블의 페이지가 일치하면 1을 반환, 일치하는 상황(!1)은 거짓이므로 패스
        if(!present(table_frame,nf,pages[i])){
            // 마지막으로 입력한 인덱스에 요청한 페이지 추가 
            table_frame[pos] = pages[i];
            // 현재 인덱스+1 하고 프레임의 수 만큼 나눈 나머지 (인덱스를 순환시키기 위해서)
            pos = (pos+1)%nf ;//considering it as a queue
            printtable(table_frame,nf);
            printf("page fault\n");

            // 페이지 요청에 따라 추가되었으면 count1 1 증가시키기
            count1++;
            continue;
        }
        printtable(table_frame,nf);
		printf("\n");
    }
    printf("\nNumber of page faults : %d\n\n", count1);
}