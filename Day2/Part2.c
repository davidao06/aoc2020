#include <stdio.h>
#include <stdlib.h>



int main () {
	int r = 0, min,max,x;
	char c;
	char pal[20];
	FILE *fp;
	fp = fopen ("input.txt", "r");
	while (fscanf (fp,"%d-%d %c: %s",&min,&max,&c,pal) == 4) {
		if (pal[min-1] == c && pal[max-1] != c || pal[min-1] != c && pal[max-1] == c) r++;
		else;
	}
	printf ("%d\n",r);
}