#include <stdio.h>
#include <stdlib.h>
#include "ingrediente.h"
#include "pizza.h"

int main() {
    Ingrediente ingredientes[100];
    Pizza pizzas[100];
    int count_ingredientes = 0, count_pizzas = 0;
    int opcao;

    while (1) {
        printf("\nMenu Principal\n");
        printf("1. CRUD de Ingredientes\n");
        printf("2. CRUD de Pizzas\n");
        printf("3. Exportar Dados\n");
        printf("4. Importar Dados\n");
        printf("5. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("\nCRUD de Ingredientes\n");
                printf("1. Adicionar\n2. Visualizar\n3. Editar\n4. Remover\nEscolha: ");
                scanf("%d", &opcao);
                if (opcao == 1) adicionarIngrediente(ingredientes, &count_ingredientes);
                else if (opcao == 2) visualizarIngredientes(ingredientes, count_ingredientes);
                else if (opcao == 3) editarIngrediente(ingredientes, count_ingredientes);
                else if (opcao == 4) removerIngrediente(ingredientes, &count_ingredientes);
                break;

            case 2:
                printf("\nCRUD de Pizzas\n");
                printf("1. Adicionar\n2. Visualizar\n3. Editar\n4. Remover\nEscolha: ");
                scanf("%d", &opcao);
                if (opcao == 1) adicionarPizza(pizzas, &count_pizzas, ingredientes, count_ingredientes);
                else if (opcao == 2) visualizarPizzas(pizzas, count_pizzas);
                else if (opcao == 3) editarPizza(pizzas, count_pizzas, ingredientes, count_ingredientes);
                else if (opcao == 4) removerPizza(pizzas, &count_pizzas);
                break;

            case 3:
                exportarIngredientes(ingredientes, count_ingredientes, "ingredientes.dat");
                exportarPizzas(pizzas, count_pizzas, "pizzas.dat");
                break;

            case 4:
                importarIngredientes(ingredientes, &count_ingredientes, "ingredientes.dat");
                importarPizzas(pizzas, &count_pizzas, "pizzas.dat");
                break;

            case 5:
                printf("Saindo...\n");
                exit(0);

            default:
                printf("Opcao invalida!\n");
        }
    }
    return 0;
}
