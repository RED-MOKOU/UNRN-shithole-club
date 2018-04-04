#define SIZE 100

void swap(int *x, int *y) {
	int aux = *x;
	*x = *y;
	*y = aux;
}

void BubbleSort(int vector[size]) {
	int i, j, aux;
	for(i=0; i < SIZE; i++) {
		for(j=i+1; j < SIZE; j++) {
			if (vector[j] < vector[i])
				swap(&vector[i], &vector[j]);
		}
	}
}

void InsertionSort(int vector[SIZE]) {
	int i, j, aux;
	for(i=0; i < SIZE; i++) {
		aux = vector[i];
		j = i - 1;
		while ((j>=0) && (vector[j] > aux)) {
			vector[j+1] = vector[j];
			j--;
		}
		vector[j+1] = aux;
	}
}

void SelectionSort(int vector[SIZE]) {
	int i, j, k, p, aux, limite = SIZE-1;
	for(k=0; k <  limite; k++) {
		p = k;
		for (i = k + 1; i <= limite; i++) {
			if (vector[i] < vector[p])
				p = i
		}
		if (p != k)
			swap (&vector[p], &vector[k]);
		}
}

void ShellSort(int vector[SIZE]) {
	int i, j,aux, incr = SIZE;
	do {
		for (i = incr; i < SIZE; i++) {
			for (j = i; (j>=incr) && (vector[j-incr]>vector[j]); j -= incr)
				swap(&vector[j], &vector[j-incr]);
		}
		incr = incr / 2;
	} while (incr >0);
}

void quicksort(int a[], int primero, int ultimo) {
	int i, j, central, aux;
	int pivote;
	central = (primero + ultimo) / 2;
	pivote = a[central];
	i = primero;
	j = ultimo;
	do {
		while (a[i] < pivote) i++;
		while (a[j] >pivote) j--;
		if (i <= j) {
			swap(&a[i], &a[j]);
			i++;
			j--;
		}
	} while (i <= j);
	if (primero < j)
		quicksort(a, primero, j); /* llamada recursiva con sublista izquierda */
	if (i < ultimo)
		quicksort(a, i, ultimo); /* llamada recursiva con sublista derecha */
}