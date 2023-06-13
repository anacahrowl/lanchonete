#include <stdio.h>
#include <string.h>

// Tabela de produtos e preços
typedef struct {
    char nome[20];
    float preco;
} Produto;

Produto produtos[] = {
    {"Hamburger", 5.00},
    {"Misto Quente", 4.00},
    {"Refrigerante", 2.00},
    {"Salgadinho", 3.00},
    {"Bolo", 3.50}
};

int main() {
    // Variáveis
    char nome_cliente[50];
    int quantidade_pessoas, quantidade_produto;
    char produto[20];
    char forma_pagamento[20];
    float total_consumido = 0.0;
    float total_final, desconto, acrescimo;
    float valor_medio;

    // WHILE para atender 5 clientes
    int cliente = 1;
    while (cliente <= 5) {
        printf("\nCliente %d\n", cliente);

        // pede o nome do cliente
        printf("Digite o nome do cliente: ");
        fgets(nome_cliente, sizeof(nome_cliente), stdin); //fgets lê uma linha de texto digitada pelo usuário no teclado, armazena-a na variável nome e inclui o caractere de nova linha ('\n') no final da string.
        nome_cliente[strcspn(nome_cliente, "\n")] = '\0';

        // pede a quantidade de pessoas
        do {
            printf("Digite a quantidade de pessoas: ");
            scanf("%d", &quantidade_pessoas);
            getchar();  // lê apenas um caractere por vez. Ela espera até que o usuário pressione a tecla Enter após digitar o caractere. 
            if (quantidade_pessoas <= 0) {
                printf("Quantidade invalida. Digite um valor maior que zero.\n");
            }
        } while (quantidade_pessoas <= 0);

        // pede o produto e a quantidade
        int produto_valido = 0;
        do {
            printf("Digite o nome do produto que deseja adquirir: ");
            fgets(produto, sizeof(produto), stdin);
            produto[strcspn(produto, "\n")] = '\0';

            // Verificar se o produto é válido
            for (int i = 0; i < sizeof(produtos) / sizeof(produtos[0]); i++) {
                if (strcmp(produto, produtos[i].nome) == 0) { //  é usada para comparar duas strings e exibir uma mensagem com base no resultado da comparação
                    produto_valido = 1;
                    break;
                }
            }

            if (!produto_valido) {
                printf("Produto invalido. Escolha um produto que esteja na lista e digite corretamente.\n");
            }
        } while (!produto_valido);

        do {
            printf("Digite a quantidade de produtos que deseja adquirir: ");
            scanf("%d", &quantidade_produto);
            getchar();  // Limpar o caractere de nova linha do buffer
            if (quantidade_produto <= 0) {
                printf("Quantidade invalida. Por favor, um numero maior que zero.\n");
            }
        } while (quantidade_produto <= 0);

        // Cálculo do total da compra
        float preco_unitario;
        for (int i = 0; i < sizeof(produtos) / sizeof(produtos[0]); i++) {
            if (strcmp(produto, produtos[i].nome) == 0) {
                preco_unitario = produtos[i].preco;
                break;
            }
        }

        float total_produto = quantidade_produto * preco_unitario;

        // Pedir a forma de pagamento
        printf("Forma de pagamento (a vista ou cartao de credito): ");
        fgets(forma_pagamento, sizeof(forma_pagamento), stdin);
        forma_pagamento[strcspn(forma_pagamento, "\n")] = '\0';

        // Cálculo do valor final com desconto ou juros
        if (strcmp(forma_pagamento, "a vista") == 0) {
            desconto = total_produto * 0.07;
            total_final = total_produto - desconto;
        }
        else if (strcmp(forma_pagamento, "cartao de credito") == 0) {
            acrescimo = total_produto * 0.09;
            total_final = total_produto + acrescimo;
        }
        else {
            printf("Forma de pagamento invalida. Digite 'a vista' ou 'cartao de credito'.\n");
            continue;
        }

        // Exibir total do produto com desconto/juros
        printf("Total do produto: R$ %.2f\n", total_final);

        //total consumido
        total_consumido += total_final;

        // Próximo cliente
        cliente++;
    }

    // Cálculo do valor médio por pessoa
    valor_medio = total_consumido / 5;

    // Exibir valor total consumido e valor médio por pessoa
    printf("\nValor total consumido: R$ %.2f\n", total_consumido);
    printf("Valor medio por pessoa: R$ %.2f\n", valor_medio);

    return 0;
}




