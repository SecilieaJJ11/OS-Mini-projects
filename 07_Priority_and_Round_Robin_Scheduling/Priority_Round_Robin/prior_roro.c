#include <stdio.h>
int main() {
    char id[4][3]={"A1","A2","A3","A4"}; int b[4]={5,3,7,4}, p[4]={2,1,3,2}, r[4]={5,3,7,4};
    int o[4]={0,1,2,3}, t=0;
    for(int i=0;i<3;i++) for(int j=0;j<3-i;j++) if(p[o[j]]>p[o[j+1]]){int tmp=o[j];o[j]=o[j+1];o[j+1]=tmp;}
    printf("=== Priority Scheduling ===\n");
    for(int i=0;i<4;i++){int k=o[i],s=t;t+=b[k];printf("%s|pri %d|%d-%d\n",id[k],p[k],s,t);}
    printf("=== Round Robin (TQ=2) ===\n"); t=0;
    int q[100],front=0,rear=4; for(int i=0;i<4;i++) q[i]=i;
    while(front<rear){int k=q[front++],run=r[k]<2?r[k]:2; t+=run; r[k]-=run;
        printf("t=%d|%s|rem %d\n",t,id[k],r[k]); if(r[k]>0) q[rear++]=k;}
    return 0;
}
