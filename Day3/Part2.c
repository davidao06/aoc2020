#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void limparMapa (char *trajeto) {
	int i = 0;
	for (i = 0;trajeto[i] != '\0';i++) {
		if (trajeto[i] == 'X') trajeto[i] = '#';
		if (trajeto[i] == 'O') trajeto[i] = '.';
	}
}

int slope11 (char *trajeto,int l,int c,int k) {
	int r = 0,i = 0,j = 0;
	while (i <= l-1) {
		i++;
		j++;
		if (j >= c-1) j = j+1-c;
		if (trajeto[i*c+j] == '#') trajeto[i*c+j] = 'X';
		else trajeto[i*c+j] = 'O';
	}
	for (i = 0;i < k;i++) if (trajeto[i] == 'X') r++;
	return r;
}

int slope13 (char *trajeto,int l,int c,int k) {
	int i = 0,j = 0,r = 0;
	while (i <= l-1) {
		i++;
		j = j +3 ;
		if (j >= c-1) j = j+1-c;
		if (trajeto[i*c+j] == '#') trajeto[i*c+j] = 'X';
		else trajeto[i*c+j] = 'O';
	}
	for (i = 0;i < k;i++) if (trajeto[i] == 'X') r++;
	return r;
}

int slope15 (char *trajeto,int l,int c,int k) {
	int i = 0,j = 0,r = 0;
	while (i <= l-1) {
		i++;
		j = j +5 ;
		if (j >= c-1) j = j+1-c;
		if (trajeto[i*c+j] == '#') trajeto[i*c+j] = 'X';
		else trajeto[i*c+j] = 'O';
	}
	for (i = 0;i < k;i++) if (trajeto[i] == 'X') r++;
	return r;
}

int slope17 (char *trajeto,int l,int c,int k) {
	int i = 0, j= 0,r = 0;
	while (i <= l-1) {
		i++;
		j = j +7 ;
		if (j >= c-1) j = j+1-c;
		if (trajeto[i*c+j] == '#') trajeto[i*c+j] = 'X';
		else trajeto[i*c+j] = 'O';
	}
	for (i = 0;i < k;i++) if (trajeto[i] == 'X') r++;
	return r;
}


int slope21 (char *trajeto,int l,int c,int k) {
	int i= 2, j= 0,r = 0;
	while (i <= l-1) {
		j++ ;
		if (j >= c-1) j = j+1-c;
		if (i >= l) i = l-1;
		if (trajeto[i*c+j] == '#') trajeto[i*c+j] = 'X';
		else trajeto[i*c+j] = 'O';
		i = i+2;
	}
	for (i = 0;i < k;i++) if (trajeto[i] == 'X') r++;
	return r;
}


int main () {
	FILE *fp;
	int l = 0,c = 0,i=0,j,k = 0,r1 = 0,r2,r3,r4,r5;
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
	printf("%d\n",size );
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
	r1 = slope11(trajeto,l,c,k);
	limparMapa (trajeto);
	r2 = slope13 (trajeto,l,c,k);
	limparMapa (trajeto);
	r3 = slope15 (trajeto,l,c,k);
	limparMapa (trajeto);
	r4 = slope17 (trajeto,l,c,k);
	limparMapa (trajeto);
	r5 = slope21 (trajeto,l,c,k);
	printf("%d\n",r1*r2*r3*r4*r5);
	fclose (fp);
	return 0;
}