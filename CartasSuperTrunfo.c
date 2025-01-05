#include <stdio.h>
#include <string.h>

#define NUM_ESTADOS 8
#define NUM_CIDADES 4
#define MAX_CIDADES (NUM_ESTADOS * NUM_CIDADES)

// Definição da estrutura para armazenar os dados de uma cidade
typedef struct
{
    char codigo[5];               // Código da cidade (ex: A01, B02, ...)
    char nome[50];                // Nome da cidade
    unsigned int populacao;       // População
    float area;                   // Área (em km²)
    float pib;                    // PIB
    int pontos_turisticos;        // Número de pontos turísticos
    float densidade_populacional; // Calculado como PIB total da cidade dividido pela população
    float pib_per_capita;         // Soma de todas as propriedades, ajustada conforme a lógica do super poder
    float super_poder;            // Soma de todas as propriedades (super poder)
} Cidade;

// Função para calcular o super poder de uma cidade
float calcularSuperPoder(Cidade *cidade)
{
    return cidade->populacao + cidade->area + cidade->pib + cidade->pontos_turisticos + cidade->densidade_populacional + cidade->pib_per_capita;
}

// Função para cadastrar uma cidade
void cadastrarCidade(Cidade *cidade, char estadoLetra, int cidadeNumero)
{
    // Construir o código da cidade
    cidade->codigo[0] = estadoLetra;
    cidade->codigo[1] = '0';
    cidade->codigo[2] = '0' + cidadeNumero; // Converte o número para caractere (1 -> '1', 2 -> '2', ...)
    cidade->codigo[3] = '\0';               // Finaliza a string

    // Pedir as informações da cidade
    printf("Digite o nome da cidade: ");
    scanf("%49s", cidade->nome);

    printf("Digite a população: ");
    scanf("%d", &cidade->populacao);

    printf("Digite a área: ");
    scanf("%f", &cidade->area);

    printf("Digite o PIB: ");
    scanf("%f", &cidade->pib);

    printf("Digite o número de pontos turísticos: ");
    scanf("%d", &cidade->pontos_turisticos);

    cidade->densidade_populacional = (float)cidade->populacao / cidade->area;
    cidade->pib_per_capita = (float)cidade->pib / cidade->populacao;
    cidade->super_poder = (float)calcularSuperPoder(cidade);
}

// Função para exibir os dados de uma cidade
void exibirCidade(Cidade cidade)
{
    printf("\n--- Dados da Cidade %s ---\n", cidade.codigo);
    printf("Cidade: %s\n", cidade.nome);
    printf("População: %d\n", cidade.populacao);
    printf("Área: %.2f\n", cidade.area);
    printf("PIB: %.2f\n", cidade.pib);
    printf("Pontos Turísticos: %d\n", cidade.pontos_turisticos);
    printf("Densidade Populacional: %.2f\n", cidade.densidade_populacional);
    printf("PIB per capita: %.2f\n", cidade.pib_per_capita);
    printf("Super Poder: %.2f\n", cidade.super_poder);
}

// Função para comparar o super poder de duas cidades, considerando a nova regra
void compararCartas(Cidade cidade1, Cidade cidade2)
{
    printf("\nComparando %s e %s:\n", cidade1.codigo, cidade2.codigo);

    // Comparação da densidade populacional (vence a cidade com menor densidade)
    if (cidade1.densidade_populacional < cidade2.densidade_populacional)
    {
        printf("A cidade %s tem uma densidade populacional menor (%.2f) que a cidade %s (%.2f).\n", cidade1.codigo, cidade1.densidade_populacional, cidade2.codigo, cidade2.densidade_populacional);
    }
    else if (cidade1.densidade_populacional > cidade2.densidade_populacional)
    {
        printf("A cidade %s tem uma densidade populacional menor (%.2f) que a cidade %s (%.2f).\n", cidade2.codigo, cidade2.densidade_populacional, cidade1.codigo, cidade1.densidade_populacional);
    }
    else
    {
        printf("As cidades %s e %s têm a mesma densidade populacional (%.2f).\n", cidade1.codigo, cidade2.codigo, cidade1.densidade_populacional);
    }

    // Comparação das outras propriedades (vence a cidade com maior valor)
    if (cidade1.populacao > cidade2.populacao)
    {
        printf("A cidade %s tem uma população maior (%d) que a cidade %s (%d).\n", cidade1.codigo, cidade1.populacao, cidade2.codigo, cidade2.populacao);
    }
    else if (cidade1.populacao < cidade2.populacao)
    {
        printf("A cidade %s tem uma população maior (%d) que a cidade %s (%d).\n", cidade2.codigo, cidade2.populacao, cidade1.codigo, cidade1.populacao);
    }
    else
    {
        printf("As cidades %s e %s têm a mesma população (%d).\n", cidade1.codigo, cidade2.codigo, cidade1.populacao);
    }

    if (cidade1.area > cidade2.area)
    {
        printf("A cidade %s tem uma área maior (%.2f) que a cidade %s (%.2f).\n", cidade1.codigo, cidade1.area, cidade2.codigo, cidade2.area);
    }
    else if (cidade1.area < cidade2.area)
    {
        printf("A cidade %s tem uma área maior (%.2f) que a cidade %s (%.2f).\n", cidade2.codigo, cidade2.area, cidade1.codigo, cidade1.area);
    }
    else
    {
        printf("As cidades %s e %s têm a mesma área (%.2f).\n", cidade1.codigo, cidade2.codigo, cidade1.area);
    }

    if (cidade1.pib > cidade2.pib)
    {
        printf("A cidade %s tem um PIB maior (%.2f) que a cidade %s (%.2f).\n", cidade1.codigo, cidade1.pib, cidade2.codigo, cidade2.pib);
    }
    else if (cidade1.pib < cidade2.pib)
    {
        printf("A cidade %s tem um PIB maior (%.2f) que a cidade %s (%.2f).\n", cidade2.codigo, cidade2.pib, cidade1.codigo, cidade1.pib);
    }
    else
    {
        printf("As cidades %s e %s têm o mesmo PIB (%.2f).\n", cidade1.codigo, cidade2.codigo, cidade1.pib);
    }

    if (cidade1.pontos_turisticos > cidade2.pontos_turisticos)
    {
        printf("A cidade %s tem mais pontos turísticos (%d) que a cidade %s (%d).\n", cidade1.codigo, cidade1.pontos_turisticos, cidade2.codigo, cidade2.pontos_turisticos);
    }
    else if (cidade1.pontos_turisticos < cidade2.pontos_turisticos)
    {
        printf("A cidade %s tem mais pontos turísticos (%d) que a cidade %s (%d).\n", cidade2.codigo, cidade2.pontos_turisticos, cidade1.codigo, cidade1.pontos_turisticos);
    }
    else
    {
        printf("As cidades %s e %s têm o mesmo número de pontos turísticos (%d).\n", cidade1.codigo, cidade2.codigo, cidade1.pontos_turisticos);
    }

    if (cidade1.pib_per_capita > cidade2.pib_per_capita)
    {
        printf("A cidade %s tem um PIB per capita maior (%.2f) que a cidade %s (%.2f).\n", cidade1.codigo, cidade1.pib_per_capita, cidade2.codigo, cidade2.pib_per_capita);
    }
    else if (cidade1.pib_per_capita < cidade2.pib_per_capita)
    {
        printf("A cidade %s tem um PIB per capita maior (%.2f) que a cidade %s (%.2f).\n", cidade2.codigo, cidade2.pib_per_capita, cidade1.codigo, cidade1.pib_per_capita);
    }
    else
    {
        printf("As cidades %s e %s têm o mesmo PIB per capita (%.2f).\n", cidade1.codigo, cidade2.codigo, cidade1.pib_per_capita);
    }

    // Comparação do super poder (vence a cidade com maior valor)
    if (cidade1.super_poder > cidade2.super_poder)
    {
        printf("A cidade %s tem um super poder maior (%.2f) que a cidade %s (%.2f).\n", cidade1.codigo, cidade1.super_poder, cidade2.codigo, cidade2.super_poder);
    }
    else if (cidade1.super_poder < cidade2.super_poder)
    {
        printf("A cidade %s tem um super poder maior (%.2f) que a cidade %s (%.2f).\n", cidade2.codigo, cidade2.super_poder, cidade1.codigo, cidade1.super_poder);
    }
    else
    {
        printf("As cidades %s e %s têm o mesmo super poder (%.2f).\n", cidade1.codigo, cidade2.codigo, cidade1.super_poder);
    }
}

// Função para mostrar todas as cidades cadastradas
void mostrarTodasAsCartas(Cidade cidades[], int numCidadesCadastradas)
{
    if (numCidadesCadastradas == 0)
    {
        printf("Nenhuma cidade cadastrada.\n");
        return;
    }

    printf("\n--- Todas as Cartas Cadastradas ---\n");
    for (int i = 0; i < numCidadesCadastradas; i++)
    {
        exibirCidade(cidades[i]);
    }
}

// Função para exibir o menu
void menu()
{
    printf("\n1. Cadastrar Cidade/Carta\n");
    printf("2. Exibir dados de uma Cidade/Carta\n");
    printf("3. Comparar Cidades/Cartas\n");
    printf("4. Mostrar todas as Cidades/Cartas\n");
    printf("5. Sair\n");
}

int main()
{
    Cidade cidades[MAX_CIDADES]; // Array para armazenar todas as cidades cadastradas
    int opcao;
    char codigoCidade[4];
    int estado, cidade, i, j;
    char estadoLetra; // Variável para armazenar a letra do estado
    int numCidadesCadastradas = 0;

    while (1)
    {
        menu();
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            if (numCidadesCadastradas < MAX_CIDADES)
            {
                printf("Cadastro de Cidade\n");
                printf("Digite a letra do estado (A a H): ");
                scanf(" %c", &estadoLetra); // O espaço antes de %c é para consumir qualquer caractere de nova linha
                printf("Digite o número da cidade (1 a 4): ");
                scanf("%d", &cidade);

                // Verificar se a letra do estado está dentro do intervalo de A a H
                if (estadoLetra >= 'A' && estadoLetra <= 'H' && cidade >= 1 && cidade <= NUM_CIDADES)
                {
                    estado = estadoLetra - 'A'; // Converter a letra para índice de 0 a 7
                    cadastrarCidade(&cidades[numCidadesCadastradas], estadoLetra, cidade);
                    numCidadesCadastradas++;
                }
                else
                {
                    printf("Estado ou cidade inválido.\n");
                }
            }
            else
            {
                printf("Número máximo de cidades cadastradas atingido.\n");
            }
            break;

        case 2:
            printf("Exibir Dados de Cidade\n");
            printf("Digite o código da cidade (ex: A01, B02, ...): ");
            scanf("%s", codigoCidade);

            // Buscar cidade correspondente ao código
            int encontrado = 0;
            for (i = 0; i < numCidadesCadastradas; i++)
            {
                if (strcmp(cidades[i].codigo, codigoCidade) == 0)
                {
                    exibirCidade(cidades[i]);
                    encontrado = 1;
                    break;
                }
            }
            if (!encontrado)
            {
                printf("Cidade não encontrada.\n");
            }
            break;

        case 3:
            printf("Comparar Cartas\n");
            printf("Digite o código da primeira cidade (ex: A01): ");
            scanf("%s", codigoCidade);

            Cidade *cidade1 = NULL;
            for (i = 0; i < numCidadesCadastradas; i++)
            {
                if (strcmp(cidades[i].codigo, codigoCidade) == 0)
                {
                    cidade1 = &cidades[i];
                    break;
                }
            }

            if (cidade1 == NULL)
            {
                printf("Primeira cidade não encontrada.\n");
                break;
            }

            printf("Digite o código da segunda cidade (ex: A02): ");
            scanf("%s", codigoCidade);

            Cidade *cidade2 = NULL;
            for (i = 0; i < numCidadesCadastradas; i++)
            {
                if (strcmp(cidades[i].codigo, codigoCidade) == 0)
                {
                    cidade2 = &cidades[i];
                    break;
                }
            }

            if (cidade2 == NULL)
            {
                printf("Segunda cidade não encontrada.\n");
                break;
            }

            compararCartas(*cidade1, *cidade2);
            break;

        case 4:
            mostrarTodasAsCartas(cidades, numCidadesCadastradas);
            break;

        case 5:
            printf("Saindo do sistema...\n");
            return 0;

        default:
            printf("Opção inválida! Tente novamente.\n");
        }
    }

    return 0;
}
