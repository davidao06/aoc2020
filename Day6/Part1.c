#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main () {
	FILE *fp;
	fp= fopen ("input.txt","r");
	char string[26];
	int count = 0, resp[26],i, k,r = 0;
	for (i = 0;i < 26;i++)
				resp[i] = 0;
	while (fgets (string,30,fp) != NULL) {
		if (strcmp (string,"\n") == 0) {
			r += count;
			count = 0;
			for (i = 0;i < 26;i++) {
				resp[i] = 0;
			}
		}
		else  {
			for (i = 0;string[i] >= 'a' && string[i] <= 'z';i++) {
				k = string[i] - 97;
				if ( resp[k] == 0)  {
					resp[k] = 1;
					count++;
				}
			}
		}
	}
	r += count;
	printf("%d\n",r );
}