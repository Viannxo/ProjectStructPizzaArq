#ifndef PIZZA_H
#define PIZZA_H

#include "ingrediente.h"

typedef struct Pizza{
    int id;
    char nome[50];
    char tamanho; // 'P', 'M', 'G'
    float preco;
    Ingrediente ingredientes[10];
    int num_ingredientes;
} Pizza;

// Funcoes CRUD para Pizzas
void adicionarPizza(Pizza *pizzas, int *count, Ingrediente *ingredientes, int num_ingredientes);
void visualizarPizzas(Pizza *pizzas, int count);
void editarPizza(Pizza *pizzas, int count, Ingrediente *ingredientes, int num_ingredientes);
void removerPizza(Pizza *pizzas, int *count);

// Funcoes para exportar/importar pizzas
void exportarPizzas(Pizza *pizzas, int count, const char *filename);
void importarPizzas(Pizza *pizzas, int *count, const char *filename);

#endif

