#include<bits/stdc++.h>
using namespace std;

int present(char a[],int nf,char page,int rf_bit[]){
    for(int i=0;i<nf;i++){
        if(a[i]==page){
          rf_bit[i]=1;
          return 1;
        }
    }
    return 0;
}

void printtable(char table_frame[], int nf){
	for(int i=0; i<nf; i++){
		if(table_frame[i] == ' '){
			printf("-- ");
        }
		else{
			printf("%c ", table_frame[i]);
        }
	}
	printf("||");
}


int main(){
    int nf;
    cout<<"enter number of frames"<<endl;
    cin>>nf;
    char a[nf];
    int rf_bit[nf];
    for(int i=0;i<nf;i++){
        a[i]= ' ';
        rf_bit[i]=0;
    }

    int np;
    cout<<"enter number of pages"<<endl;
    cin>>np;
    char b[np];
    cout<<"enter page requests"<<endl;
    for(int i=0;i<np;i++){
        cin>>b[i];
    }
    int pos=0,count1=0;

    for(int i=0;i<np;i++){
        printf("page table after request from %c || ",b[i]);
        // 요청 페이지와 일치하면 rf_bit[] 값 1로 수정하고 1 반환, 아니면 수정없이 그냥 0 반환
        if(!present(a,nf,b[i],rf_bit)){
            //int pos=findpos(a,nf,b,i,np);
            pos=(pos+1)%nf;
            // 요청 페이지의 다음 인덱스 값부터 rf_bit[]가 1인 경우 0으로 변경하고 pos에 값 1 추가(순환)
            while(rf_bit[pos]==1){
                rf_bit[pos]=0;
                pos=(pos+1)%nf;
            }

            a[pos]=b[i];
            printtable(a,nf);
            printf("page fault\n");
            count1++;
            continue;
        }

        printtable(a,nf);
		printf("\n");
    }

     printf("\nNumber of page faults : %d\n\n", count1);
}