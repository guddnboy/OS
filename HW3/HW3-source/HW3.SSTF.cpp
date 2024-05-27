#include<bits/stdc++.h>
using namespace std;

int main(){
    int head;
    printf("enter head position\n");
    cin>>head;

    int n,i;
    cout<<"enter total requets"<<endl;
    cin>>n;
    int queue1[n],done[n];
    printf("enter requests\n");

    for(i=0;i<n;i++){
        scanf("%d",&queue1[i]);
        done[i]=0;
    }
    done[0] == 1;

    printf("%d->",head);

    int temp1=head;
    int count1=0,j,sum=0;
    int min = INT_MAX;
    int min_i = 0;

    while(count1 != n-1){
        min = INT_MAX;

        for(int i = 1; i < n; i++){
            if (min > abs(temp1 - queue1[i]) && done[i] == 0 ){
                min = abs(temp1 - queue1[i]);
                min_i = i;
            }
        }
    
        done[min_i] = 1;
        sum += min;
        printf("%d->",queue1[min_i]);
        count1++;
        temp1 = queue1[min_i];
        cout<<endl;
        cout<<"total head movement is "<<sum<<endl;
    }
}