#include <stdio.h>
#include <string.h>
#include "pizza.h"

void removerPizza(Pizza *pizzas, int *count) {
    if (*count == 0) {
        printf("Nenhuma pizza cadastrada para remover.\n");
        return;
    }

    int id;
    printf("Digite o ID da pizza que deseja remover: ");
    scanf("%d", &id);

    // Verifica se o ID e valido
    if (id <= 0 || id > *count) {
        printf("Pizza com ID %d nao encontrada.\n", id);
        return;
    }

    // Remove a pizza deslocando os elementos
    for (int i = id - 1; i < *count - 1; i++) {
        pizzas[i] = pizzas[i + 1];
    }

    (*count)--; // Reduz o numero total de pizzas
    printf("Pizza removida com sucesso!\n");
}

