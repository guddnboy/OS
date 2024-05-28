#include<bits/stdc++.h>

int find(int d[],int n,int disk){
  for(int i=0;i<n-1;i++){
    if(d[i]>disk){
      return i;
      break;
    }
  }
  return n;
}

int main(){
  int i,j,n;
  int disk;   //loc of head
  int temp,max;
  int dloc;   //loc of disk in array
  int no_t;

  printf("enter total number of tracks\n");
  scanf("%d",&no_t);

  printf("enter number of location\n");
  scanf("%d",&n);

  int d[n+1]; //disk queue

  printf("enter position of head\n");
  scanf("%d",&disk);

  printf("enter elements of disk queue\n");

  for(i=0;i<n;i++){
    scanf("%d",&d[i]);
  }

  for(i=0;i<n-1;i++){    // sorting disk locations
    for(j=i+1;j<n;j++){
      if(d[i]>d[j]){
        temp=d[i];
        d[i]=d[j];
        d[j]=temp;
      }
    }
  }

  printf("elements after sorting\n");

  for(i=0;i<n;i++){
    printf("%d ",d[i]);
  }
  printf("\n");
  int sum=0;

//go towards left
  int previous = find(d,n,disk);
  previous = previous-1;
  sum+=abs(disk-d[previous]);

  for(i=previous;i>=0;i--){
    printf("%d ->",d[i]);

    if(i!=0){
      int dr=abs(d[i]-d[i-1]);
      sum+=dr;
    }
    else if(i == 0){
      sum += d[n-1] - d[i]; 
    }
  }

  for(i=n-1;i>=previous+1;i--){
    printf("%d ->",d[i]);

    if(i!=previous+1){
      int dr=abs(d[i]-d[i-1]);
      sum+=dr;
    }
  }
  printf("\nmovement of total cylinders %d\n",sum);
}