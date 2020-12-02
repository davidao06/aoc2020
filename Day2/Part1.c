#include <stdio.h>
#include <stdlib.h>


int ocorrencia (char *s,char c) {
	int i = 0,r=0;
	for (i = 0;s[i] != '\0';i++)
		if (s[i] == c) r++;
	return r;
}

int main () {
	int r = 0, min,max,x;
	char c;
	char pal[20];
	FILE *fp;
	fp = fopen ("input.txt", "r");
	while (fscanf (fp,"%d-%d %c: %s",&min,&max,&c,pal) == 4) {
		x = ocorrencia (pal,c);
		if (x >=min && x <= max) r++;
	}
	printf ("%d\n",r);
}