#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <utime.h>
#include <string.h>
#include <dirent.h>
#include <math.h>
#include <sys/un.h>

int* GetVisibleLines(int* m,int* b,int n){
	int lines[n];

	lines[0]=lines[1]=1;//y1 and y2 are visible lines when we only get 2 lines
	for (int i = 2; i < n; ++i)
	{
		printf("add line y%d\n",i );
		for (int j = 0; j < i-1; ++j)
		{
			if(lines[j]==1){
				for (int i = 0; i < count; ++i)
				{
					/* code */
				}
			}
			printf("check intersections y%d and y%d\n", j,j+1);

			if(((b[j]-b[j+1])*m[j]+b[j]*(m[j+1]-m[j]))<(m[i]*(b[j]-b[j+1])+b[i]*(m[j+1]-m[j])))
					{
						lines[j+1]=0;//not visible
						printf("j+1=%d not visible\n",j+1);
						while(j<i-1){
							++j;
							lines[j]=0;//following lines also invisible
						}
						break;
					}
		}
		lines[i]=1;// yi is visible

	}
	return lines;
}

int main(){
	//int lines[5][3];//lines[i][0]->mi, lines[1]->bi,lines[][2]=1/visible
	printf("How many lines?\n");
	int count;
	scanf("%d",&count);

	//int* m=m[count];
	//int* b=b[count];
	int m[count];
	int b[count];
	printf("Please enter integers value for m:\n");
	for (int i = 0; i < count; ++i)
	{
		scanf("%d",&m[i]);
	}



	printf("Please enter integers value for b:\n");
	for (int i = 0; i < count; ++i)
	{
		scanf("%d",&b[i]);
	}

	int*  l=GetVisibleLines(m,b,count);
	//GetVisibleLines(lines,count);
	printf("Those are visible lines:\n");
	for (int i = 0; i < count; ++i)
	{
		//if(lines[i]==1)
			printf("%d  \n", l[i]);
	}

	//FreeArray(lines,count);

}
