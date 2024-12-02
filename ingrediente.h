#ifndef INGREDIENTE_H
#define INGREDIENTE_H

typedef struct Ingrediente {
    int id;
    char nome[50];
    float preco;
} Ingrediente;

// Funções CRUD para Ingredientes
void adicionarIngrediente(Ingrediente *ingredientes, int *count);
void visualizarIngredientes(Ingrediente *ingredientes, int count);
void editarIngrediente(Ingrediente *ingredientes, int count);
void removerIngrediente(Ingrediente *ingredientes, int *count);

// Funções para exportar/importar ingredientes
void exportarIngredientes(Ingrediente *ingredientes, int count, const char *filename);
void importarIngredientes(Ingrediente *ingredientes, int *count, const char *filename);

#endif

