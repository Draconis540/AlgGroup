#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <utime.h>
#include <string.h>
#include <dirent.h>
#include <math.h>
#include <sys/un.h>


int main(){
//number of lines
// int n=5;
// Current length of sub array or visible lines
 int curr_sub;
 int i, j, k, ii;
 int m[5] = {-2, -1, 0, 1, 2};
 int b[5] = {9, 27, 54, 95, 96};
 int v[5] = {0, 0, 0, 0, 0};
 int sub[5] = {0, 0, 0, 0, 0};

 sub[0] = 0;
 sub[1] = 1;
 curr_sub = 1;

 for(i=2; i<5; i++){
     curr_sub++;
     sub[curr_sub] = i;
     k = curr_sub;
     for(ii=1; ii<curr_sub; ii++){
         for(j=0;j<ii;j++){
             if(m[sub[j]]*(b[sub[j]]-b[i])+b[sub[j]]*(m[ii]-m[sub[j]])>m[ii]*(b[j]-b[i])+b[ii]*(m[i]-m[j])){
                 //line is not visible
                 sub[ii] = i;
                 curr_sub = ii;
                 break;
             }
        }
        if(sub[ii] == i){
            break;
        }
     }
 }

 //update Visibility array
 for(i=0; i<=curr_sub; i++){
     v[sub[i]]=1;
 }

 printf("Visible Lines:");
 for(i=0;i<5;i++){
     printf(" %d,", v[i]);
 }
printf("\n");
return(0);
}
