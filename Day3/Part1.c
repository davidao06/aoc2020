#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main () {
	FILE *fp;
	int l = 0,c = 0,i= 0,j,k = 0,r = 0;
	fp = fopen ("input.txt","r");
	char buffer [100];
	while (fgets (buffer,100,fp) != NULL) {
		l++;
		if (i == 0) {
			i++;
			c = strlen (buffer);
		}
	}
	rewind (fp);
	int size = l * c;
	char *trajeto =  (char*) malloc (size*sizeof(char));
	while (fgets (buffer,100,fp) != NULL){
		i = 0;
		while (buffer[i] != '\0') {
			trajeto[k] = buffer[i];
			i++;
			k++;
		}
	}
	i = j = 0;
	while (i <= l-1) {
		i++;
		j = j +3 ;
		if (j >= c-1) j = j+1-c;
		if (trajeto[i*c+j] == '#') trajeto[i*c+j] = 'X';
		else trajeto[i*c+j] = 'O';
	}
	for (i = 0;i < k;i++) if (trajeto[i] == 'X') r++;
	printf("%d\n",r );
	fclose (fp);
	return r;
}