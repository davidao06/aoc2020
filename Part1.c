#include <stdio.h>
#include <stdlib.h>

int main () {
	int v[128][8];
	int i , j , c , l, cMax = 127,lMax = 7;
	for (i = 0; i < 128;i++)
		for (j = 0;j < 8;j++)
			v[i][j] = 0;
	FILE *fp;
	fp = fopen ("input.txt","r");
	char buffer[11];
	while (fgets (buffer,20,fp) != NULL) {
		c = l = 0;
		for (i = 0;i < 7;i++) {
			if (buffer[i] == 'B') c = c + (cMax-c)/2;
			else cMax = c + (cMax-c)/2; 
		}
		for (j = 7;j < 10;j++) {
			if (buffer[j] == 'R') l = l + (lMax -l)/2;
			else lMax = l + (lMax -l)/2;
		}
		v[c][l] = c*8+l;
	}
	for (i = 0; i < 128;i++)
		for (j = 0;j < 8;j++)
			printf ("%d ",v[i][j]);
	return 0;
}