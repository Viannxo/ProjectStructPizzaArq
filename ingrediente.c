#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ingrediente.h"

void adicionarIngrediente(Ingrediente *ingredientes, int *count) {
    Ingrediente novoIngrediente;
    novoIngrediente.id = *count + 1;
    printf("Digite o nome do ingrediente: ");
    getchar();  // Limpar buffer
    fgets(novoIngrediente.nome, 50, stdin);
    novoIngrediente.nome[strcspn(novoIngrediente.nome, "\n")] = 0;
    printf("Digite o preco do ingrediente: ");
    scanf("%f", &novoIngrediente.preco);

    ingredientes[*count] = novoIngrediente;
    (*count)++;
    printf("Ingrediente adicionado com sucesso!\n");
}

void visualizarIngredientes(Ingrediente *ingredientes, int count) {
    if (count == 0) {
        printf("Nenhum ingrediente cadastrado.\n");
        return;
    }
    printf("\nLista de Ingredientes:\n");
    for (int i = 0; i < count; i++) {
        printf("ID: %d | Nome: %s | Preco: %.2f\n", ingredientes[i].id, ingredientes[i].nome, ingredientes[i].preco);
    }
}

void editarIngrediente(Ingrediente *ingredientes, int count) {
    int id;
    printf("Digite o ID do ingrediente que deseja editar: ");
    scanf("%d", &id);

    if (id <= 0 || id > count) {
        printf("Ingrediente nao encontrado!\n");
        return;
    }

    printf("Digite o novo nome do ingrediente: ");
    getchar();
    fgets(ingredientes[id - 1].nome, 50, stdin);
    ingredientes[id - 1].nome[strcspn(ingredientes[id - 1].nome, "\n")] = 0;

    printf("Digite o novo preco do ingrediente: ");
    scanf("%f", &ingredientes[id - 1].preco);

    printf("Ingrediente atualizado com sucesso!\n");
}

void removerIngrediente(Ingrediente *ingredientes, int *count) {
    int id;
    printf("Digite o ID do ingrediente que deseja remover: ");
    scanf("%d", &id);

    if (id <= 0 || id > *count) {
        printf("Ingrediente nao encontrado!\n");
        return;
    }

    for (int i = id - 1; i < *count - 1; i++) {
        ingredientes[i] = ingredientes[i + 1];
    }
    (*count)--;
    printf("Ingrediente removido com sucesso!\n");
}

void exportarIngredientes(Ingrediente *ingredientes, int count, const char *filename) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        printf("Erro ao abrir o arquivo para exportacao.\n");
        return;
    }

    fwrite(&count, sizeof(int), 1, file);
    fwrite(ingredientes, sizeof(Ingrediente), count, file);
    fclose(file);
    printf("Ingredientes exportados com sucesso!\n");
}

void importarIngredientes(Ingrediente *ingredientes, int *count, const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        printf("Erro ao abrir o arquivo para importacao.\n");
        return;
    }

    fread(count, sizeof(int), 1, file);
    fread(ingredientes, sizeof(Ingrediente), *count, file);
    fclose(file);
    printf("Ingredientes importados com sucesso!\n");
}

