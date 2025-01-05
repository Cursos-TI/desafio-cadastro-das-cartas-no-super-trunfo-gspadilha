#include <stdio.h>
#include <string.h>

#define NUM_ESTADOS 8
#define NUM_CIDADES 4

// Definição da estrutura para armazenar os dados de uma cidade
typedef struct
{
    char codigo[5];        // Código da cidade (ex: A01, B02, ...)
    float populacao;       // População
    float area;            // Área (em km²)
    float pib;             // PIB (em bilhões)
    int pontos_turisticos; // Número de pontos turísticos
} Cidade;

// Função para cadastrar uma cidade
void cadastrarCidade(Cidade *cidade, char estadoLetra, int cidadeNumero)
{
    // Construir o código da cidade
    cidade->codigo[0] = estadoLetra;
    cidade->codigo[1] = '0';
    cidade->codigo[2] = '0' + cidadeNumero; // Converte o número para caractere (1 -> '1', 2 -> '2', ...)
    cidade->codigo[3] = '\0';               // Finaliza a string

    // Pedir as informações da cidade
    printf("Digite a população: ");
    scanf("%f", &cidade->populacao);

    printf("Digite a área: ");
    scanf("%f", &cidade->area);

    printf("Digite o PIB: ");
    scanf("%f", &cidade->pib);

    printf("Digite o número de pontos turísticos: ");
    scanf("%d", &cidade->pontos_turisticos);
}

// Função para exibir os dados de uma cidade
void exibirCidade(Cidade cidade)
{
    printf("\n--- Dados da Cidade %s ---\n", cidade.codigo);
    printf("População: %.3f\n", cidade.populacao);
    printf("Área: %.2f\n", cidade.area);
    printf("PIB: %.2f\n", cidade.pib);
    printf("Pontos Turísticos: %d\n", cidade.pontos_turisticos);
}

// Função para exibir o menu
void menu()
{
    printf("\n1. Cadastrar Cidade\n");
    printf("2. Exibir Dados de uma Cidade\n");
    printf("3. Sair\n");
}

int main()
{
    Cidade cidades[NUM_ESTADOS][NUM_CIDADES]; // Matriz para armazenar as cidades dos 8 estados
    int opcao;
    char codigoCidade[4];
    int estado, cidade, i, j;
    char estadoLetra; // Variável para armazenar a letra do estado

    // Inicialização
    for (i = 0; i < NUM_ESTADOS; i++)
    {
        for (j = 0; j < NUM_CIDADES; j++)
        {
            strcpy(cidades[i][j].codigo, "000");
        }
    }

    while (1)
    {
        menu();
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            printf("Cadastro de Cidade\n");
            printf("Digite a letra do estado (A a H): ");
            scanf(" %c", &estadoLetra); // O espaço antes de %c é para consumir qualquer caractere de nova linha
            printf("Digite o número da cidade (1 a 4): ");
            scanf("%d", &cidade);

            // Verificar se a letra do estado está dentro do intervalo de A a H
            if (estadoLetra >= 'A' && estadoLetra <= 'H' && cidade >= 1 && cidade <= NUM_CIDADES)
            {
                estado = estadoLetra - 'A'; // Converter a letra para índice de 0 a 7
                cadastrarCidade(&cidades[estado][cidade - 1], estadoLetra, cidade);
            }
            else
            {
                printf("Estado ou cidade inválido.\n");
            }
            break;

        case 2:
            printf("Exibir Dados de Cidade\n");
            printf("Digite o código da cidade (ex: A01, B02, ...): ");
            scanf("%s", codigoCidade);

            // Buscar cidade correspondente ao código
            int encontrado = 0;
            for (i = 0; i < NUM_ESTADOS; i++)
            {
                for (j = 0; j < NUM_CIDADES; j++)
                {
                    if (strcmp(cidades[i][j].codigo, codigoCidade) == 0)
                    {
                        exibirCidade(cidades[i][j]);
                        encontrado = 1;
                        break;
                    }
                }
                if (encontrado)
                    break;
            }
            if (!encontrado)
            {
                printf("Cidade não encontrada.\n");
            }
            break;

        case 3:
            printf("Saindo do sistema...\n");
            return 0;

        default:
            printf("Opção inválida! Tente novamente.\n");
        }
    }

    return 0;
}
