/*3) Explique: ¿que diferencia hay entre las operaciones malloc(), calloc() y realloc()?. Explique para cada
una el tipo retornado y cada uno de los parametros que recibe.*/

/*Suponiendo que hay un pointer llamado *p.
1)- malloc() aloca un tamaño determinado (pasado como argumento, en bytes) de memoria para almacenar datos, y le pasa la direccion inicial a *p
sin importar que clase de infomacion haya existido en ese espacio.

2)- calloc() hace exactamente lo mismo, pero inicializa todos los valores de memoria alocados a cero.

3)- realloc() toma un pointer y su memoria alocada previamente por malloc() o calloc(), y le asigna un espacio nuevo con otro tamaño diferente.
Asi, por ejemplo, si se tiene a int *p almacenando 20 bytes en memoria y se quiere expandir este tamaño, se llama a realloc(p, nuevo_tamaño_en_bytes).
Esta funcion copiara todos los datos en *p a un nuevo espacio en memoria con el tamaño determinado por nuevo_tamaño_en_bytes.*/
