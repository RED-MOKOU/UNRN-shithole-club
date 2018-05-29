/*13) Escribir una función que tenga como argumento dos colas del mismo tipo y devuelva True si las colas son
idénticas, False caso contrario. NO acceder a la estructura, usar funciones del TAD.*/

/*Compara cola1 con cola2.
Si ambas tienen el mismo largo, y sus elementos son los mismos, entonces las colas son identicas.*/
int CompararColas(Cola_T *cola1, Cola_T *cola2) {
	int len1 = Longitud_Cola(*cola1);
	int len2 = Longitud_Cola(*cola2);
	int comparaciones;
	if( len1 == len2 ) {
		for (int i = 0; i < len1; ++i) {
			if( Q_Pop(cola1) == Q_Pop(cola2) )
				++comparaciones;
		}
		return ( comparaciones == len1 ) ? 1 : 0;
	}
	else
		return 0;
}
