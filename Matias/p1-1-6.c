#include <stdio.h>
#include <string.h>

#define CANTIDAD_PERSONAS 20

typedef struct
{
	int dni, matricula;
} persona_t;

int persona_limpia_p(const persona_t *persona)
{
	return !persona->dni && !persona->matricula;
}

void eliminar_persona(persona_t *personas, int id)
{
	int i;
	for (i = id; i < CANTIDAD_PERSONAS - 1; i++)
		personas[i] = personas[i+1];

	personas[CANTIDAD_PERSONAS - 1].dni = 0;
	personas[CANTIDAD_PERSONAS - 1].matricula = 0;
}

void agregar_persona(persona_t *personas, const persona_t *persona, int id)
{
	if (!persona_limpia_p(&personas[id]))
	{
		int i;
		for (i = CANTIDAD_PERSONAS - 1; i >= id; i--)
			personas[i] = personas[i - 1];
	}

	personas[id] = *persona;
}

void leer_persona(persona_t *persona)
{
	printf("DNI: ");
	scanf("%d", &persona->dni);

	printf("Matrícula: ");
	scanf("%d", &persona->matricula);
}

void dump_personas(const persona_t *personas)
{
	int i;
	for (i = 0; i < CANTIDAD_PERSONAS; i++)
		printf("Persona %d: %d (%d)\n", i, personas[i].dni, personas[i].matricula);
	printf("\n");
}

int main(int argc, char **argv)
{
	char op = 0;
	persona_t personas[CANTIDAD_PERSONAS];

	memset(personas, 0, sizeof(personas));

	while ('q' != op)
	{
		int id;
		persona_t persona;

		printf("Ingrese operación:\n"
		       "\t(q) -> Salir.\n"
		       "\t(m) -> Mostrar personas.\n"
		       "\t(a) -> Agregar persona.\n"
		       "\t(e) -> Eliminar persona.\n\n");
		scanf("%s", &op);

		switch (op)
		{
			case 'q':
				break;

			case 'm':
				dump_personas(personas);
				break;

			case 'a':
				printf("Ingrese número de registro: ");
				scanf("%d", &id);
				leer_persona(&persona);
				agregar_persona(personas, &persona, id);
				break;

			case 'e':
				printf("Ingrese número de registro a eliminar: ");
				scanf("%d", &id);
				eliminar_persona(personas, id);
				break;

			default:
				printf("Comando '%c' desconocido :)\n", op);
				break;
		}
	}

	return 0;
}
