#include <stdio.h>
#include <stdlib.h>

// O(N³)

int Solucao (int v[],int N) {
	int i ,j,k,r = 0;
	for (i = 0; i < N-2;i++)
		for (j = 0;j < N-1;j++)
			for (k = 0;k < N;k++)
			if (v[j]+v[i]+v[k] == 2020) r = v[j] * v[i] * v[k];
	return r;
}


int main () {
	FILE *fp;
	char num[10];
	int valor,i = 0,N = 5,j = 0, r;
	int *values = (int*) malloc(N*(sizeof (int)));
	fp = fopen ("input.txt", "r");
	while (fgets (num,10,fp) != NULL) {
		valor = atoi (num);
		if (i >= N) {
			N = N*2;
			values = realloc (values,N*(sizeof(int)));
		}
		values[i] = valor;
		i++;
	}
	r = Solucao (values,i);
	printf("%d\n",r);
	return 0;
}
