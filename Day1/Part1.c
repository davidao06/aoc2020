#include <stdio.h>
#include <stdlib.h>
/*
// O(N²)

int Solucao (int v[],int N) {
	int i ,j,r = 0;
	for (i = 0; i < N-1;i++)
		for (j = 0;j < N;j++)
			if (v[j]+v[i] == 2020) r = v[j] * v[i];
	return r;
}
*/
// O (Nlog N)

void swap (int v[],int i ,int j) {
	int k = v[i];
	v[i] = v[j];
	v[j] = k;
}

int partition (int v[],int N) {
	//ultimo elemento como pivot
	int pivot = N-1,i,j;
	for (i = 0,j=0;j < N-1;j++) {
		if (v[j] <= v[pivot]) {
			swap (v,j,i);
			i++;
		}
	}
	swap (v,pivot,i);
	return i;
}

int quickSort (int v[],int N) {
	if (N>1) {
		int p = partition (v,N);
		quickSort (v,p);
		quickSort (v+p+1,N-p-1);
	}
	return 0;
}

int binary_search (int v[],int N,int x) {
	int i = 0,s = N-1;
	while (i < s) {
		int m = i+(s-i)/2;
		if (v[m] == x) return m;
		if (v[m] > x) s = m-1;
		if (v[m] < x) i = m+1;
	}
	if (i >= s && v[i] != x) return -1;
	else return i;
}

int Solucao (int v[],int N) {
	int i;
	for (i = 0;i < N;i++){
		int x = 2020-v[i];
		int j = binary_search (v,N,x);
		if (j != -1 && j != i) return (v[j]*v[i]);
	}

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
	j = quickSort (values,i);
	r = Solucao (values,i);
	printf("%d\n", r);
	return 0;
}
