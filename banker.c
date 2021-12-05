#include<stdio.h>

int main(){

	int r=0,p=0,i=0,j=0,k=0,t=0;
	
	printf("\nenter the no.of resources:");
	scanf("%d",&r);
	printf("\nenter the no.of processes:");
	scanf("%d",&p);
	
	int max[p][r],allo[p][r],avail[r];
	
	for(i=0;i<p;i++){
		for(j=0;j<r;j++){
			max[i][j]=0;
			allo[i][j]=0;
		}
	}
	
	for(i=0;i<r;i++){
		avail[i]=0;
	}
	
	printf("\nenter the values for the max matrix:");
	for(i=0;i<p;i++){
		for(j=0;j<r;j++){
			printf("\nenter element max[%d][%d]:",i,j);
			scanf("%d",&max[i][j]);
		}
	}
	printf("\nenter the values for the allocation matrix:");
	for(i=0;i<p;i++){
		for(j=0;j<r;j++){
			printf("\nenter element allocation[%d][%d]:",i,j);
			scanf("%d",&allo[i][j]);
		}
	}
	printf("\nenter the values for available matrix:");
	for(i=0;i<r;i++){
		printf("\nenter element avail[%d]:",i);
		scanf("%d",&avail[i]);
	}
	
	int f[p];
	
	for(i=0;i<p;i++){
		f[i]=0;
	}
	int need[p][r],ans[p],ind=0;
	
	for(i=0;i<p;i++){
		for(j=0;j<r;j++){
			need[i][j]=max[i][j]-allo[i][j];
		}
	}
	
	for(i=0;i<p;i++){
		for(j=0;j<p;j++){
			if(f[j]==0){
				int flag=0;
				for(k=0;k<r;k++){
					if(need[j][k]>avail[k]){
						flag=1;
						break;
					}
				}
				if(flag==0){
					ans[ind++]=j;
					for(t=0;t<r;t++){
						avail[t]+=allo[j][t];
					}
					f[j]=1;
				}
			}
		}
	}
	printf("\nthe required safe sequence is :\n");
	for(i=0;i<(p-1);i++){
		printf("P%d->",ans[i]);
	}
	printf("P%d->",ans[i]);
}
