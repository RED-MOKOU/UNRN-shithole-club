/*2) ¿Como implementaría el TAD lista de enteros con arreglos? Para cada operación implementada en 1) explique
cómo lo implementaría con arreglos. Compare ambas implementaciones desde el punto de vista de memoria
utilizada. Para cada uno, defina si la operación es más simple o más costosa a nivel de cantidad de operaciones
que debe realizar (comparaciones, corrimientos, etc).
*/

/*
Con un array de enteros alocado en memoria, el cual crecería dinámicamente mediante calloc(). Dado que es
un array lineal en memoria, utilizaria menos memoria, puesto que solo utiliza el espacio para guardar ints
(y no ints + pointer a ints, como cuando se usa listas). Sin embargo, la eliminación de datos requiere muchas
más operaciones que el TAD lista, por lo que al manejar un gran numero de datos su tiempo de ejecución se
vuelve ineficiente.*/

Lista_T crearLista();
/*Esta función sería innecesaria, dado que se puede crear un pointer para alocar un int en el main,
el cual sera el primer elemento de la lista (head).*/

int InsertarPrimero(Lista_T *l, int x );
int InsertarUltimo(Lista_T *l, int x );
/*Estas funciones se vuelven algo innecesarias al utilizar arrays (es trivial cambiar el elemento en X posicion).
Puede generalizarse a una funcion general InsertarElemento().*/

int RecorrerLista(Lista_T l );
/*Un "for" que recorre la lista e imprime sus valores.*/

int EstaVacia(Lista_T l);
int LongitudLista(Lista_T l);
/*Puede eliminarse estas funciones y en cambio utilizar un contador global.*/

int VaciarLista(Lista_T *l);
/*Se vuelve innecesaria ya que es trivial desalocar la memoria almacenada para un array mediante free(arr).*/

int SuprimirDato(Lista_T *l, int x);
int SuprimirNodo(Lista_T *l, int pos);
/*Estas son las funciones donde se puede observar por qué el TAD lista es más conveniente que utilizar un array.
Para suprimir un nodo, o dato, es necesario mover todos los elementos a la derecha del eliminado un espacio hacia
la izquierda, y disminuir en 1 el tamaño del array. Todas estas operaciones llevan muchísimo más tiempo de ejecución
con arrays que con el TAD lista.*/

int DevolverDatoPosicion(Lista_T l, int pos);
/*Se vuelve trivial, ya que puede dereferenciarse un array mediante corchetes (arr[pos]).*/