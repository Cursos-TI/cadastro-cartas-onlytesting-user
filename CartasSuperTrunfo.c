#include <stdio.h>
#include <string.h>

// Desafio Super Trunfo - Países
// Tema 4 - Comparando Cartas do Super Trunfo
// Objetivo: No nível novato você deve implementar a lógica para comparar duas cartas e determinar a vencedora com base em um único atributo numérico (como população, área, PIB, etc.).

// Declaração da função para criação de Cartas
void adicionar_carta(
    int num_carta,
    char *estado,
    char codigo_carta[4],
    char nome_cidade[50],
    unsigned long int *populacao,
    float *area,
    float *pib,
    int *num_pontos_turisticos)
{
  printf("\n------------------\nCadastro da Carta %d\n-------------------\n", num_carta);

  // Chamadas às funções responsáveis por ler o teclado do usuário
  printf("Estado (A-H): ");
  scanf(" %c", estado);

  printf("Código Carta (estado + 01 - 04): ");
  scanf("%3s", codigo_carta);

  // Para limpar o buffer
  scanf("%*c");

  printf("Nome Cidade: ");
  fgets(nome_cidade, 50, stdin);
  nome_cidade[strcspn(nome_cidade, "\n")] = 0;

  printf("População: ");
  scanf("%lu", populacao);

  printf("Área (km²): ");
  scanf("%f", area);

  printf("PIB: ");
  scanf("%f", pib);
  *pib = *pib * 1e9;

  printf("Número de Pontos Turísticos: ");
  scanf("%d", num_pontos_turisticos);

  // Exibição da Carta com todos os seus dados preenchidos
  printf("\nCarta %d:\n", num_carta);
  printf("Estado: %c\n", *estado);
  printf("Código: %s\n", codigo_carta);
  printf("Nome da Cidade: %s\n", nome_cidade);
  printf("População: %lu\n", *populacao);
  printf("Área: %.2f km^2\n", *area);
  printf("PIB: %.2f bilhões de reais\n", *pib / 1e9);
  printf("Número de Pontos Turísticos: %d\n", *num_pontos_turisticos);
}

// Função Principal - Para declaração e chamada de Cartas de forma centralizada
int main()
{
  // Declarações Carta 1
  char estado1;
  char codigo1[4];
  char nome_cidade1[50];
  unsigned long int populacao1;
  float area1;
  float pib1;
  int num_pontos_turisticos1;
  float densidade_populacional1;
  float pib_per_capita1;
  float super_poder1;

  // Declarações Carta 2
  char estado2;
  char codigo2[4];
  char nome_cidade2[50];
  unsigned long int populacao2;
  float area2;
  float pib2;
  int num_pontos_turisticos2;
  float densidade_populacional2;
  float pib_per_capita2;
  float super_poder2;

  // Chamada Carta 1
  adicionar_carta(
      1,
      &estado1,
      codigo1,
      nome_cidade1,
      &populacao1,
      &area1,
      &pib1,
      &num_pontos_turisticos1);

  // Cálculo e Exibição dos Atributos Calculados (Carta 1)
  densidade_populacional1 = (float)populacao1 / area1;
  pib_per_capita1 = pib1 / (float)populacao1;
  super_poder1 = (float)populacao1 + area1 + pib1 +
                 (float)num_pontos_turisticos1 + pib_per_capita1 +
                 (1.0f / densidade_populacional1);

  printf("Densidade Populacional: %.2f hab/km^2\n", densidade_populacional1);
  printf("PIB per Capita: %.2f reais\n", pib_per_capita1);
  printf("Super Poder: %.2f\n", super_poder1);

  // Chamada Carta 2
  adicionar_carta(
      2,
      &estado2,
      codigo2,
      nome_cidade2,
      &populacao2,
      &area2,
      &pib2,
      &num_pontos_turisticos2);

  // Cálculo e Exibição dos Atributos Calculados (Carta 2)
  densidade_populacional2 = (float)populacao2 / area2;
  pib_per_capita2 = pib2 / (float)populacao2;
  super_poder2 = (float)populacao2 + area2 + pib2 +
                 (float)num_pontos_turisticos2 + pib_per_capita2 +
                 (1.0f / densidade_populacional2);

  printf("Densidade Populacional: %.2f hab/km^2\n", densidade_populacional2);
  printf("PIB per Capita: %.2f reais\n", pib_per_capita2);
  printf("Super Poder: %.2f\n", super_poder2);

  /* Definição da constante e da variável responsáveis por definir o atributo a ser comparado e um valor indicativo da carta vencedora, respectivamente */
  const int ATRIBUTO_COMPARACAO = 6;
  int carta_vencedora = 0; // Se a Carta 1 vence = 1 : Se a Carta 2 vence = 2

  // if-else para comparar os valores do atributo escolhido pelo programa
  if (ATRIBUTO_COMPARACAO == 1)
  {
    // População (Maior valor ganha)
    printf("\nComparação de cartas (Atributo: População)\n");
    printf("\nCarta 1 - %s (%c): %lu\n", nome_cidade1, estado1, populacao1);
    printf("Carta 2 - %s (%c): %lu", nome_cidade2, estado2, populacao2);

    if (populacao1 > populacao2)
    {
      carta_vencedora = 1;
    }
    else if (populacao2 > populacao1)
    {
      carta_vencedora = 2;
    }
  }
  else if (ATRIBUTO_COMPARACAO == 2)
  {
    // Área (Maior valor ganha)
    printf("\nComparação de cartas (Atributo: Área)\n");
    printf("\nCarta 1 - %s (%c): %.2f km^2\n", nome_cidade1, estado1, area1);
    printf("Carta 2 - %s (%c): %.2f km^2", nome_cidade2, estado2, area2);

    if (area1 > area2)
    {
      carta_vencedora = 1;
    }
    else if (area2 > area1)
    {
      carta_vencedora = 2;
    }
  }
  else if (ATRIBUTO_COMPARACAO == 3)
  {
    // PIB (Maior valor ganha)
    printf("\nComparação de cartas (Atributo: PIB)\n");
    printf("\nCarta 1 - %s (%c): %.2f bilhões\n", nome_cidade1, estado1, pib1 / 1e9);
    printf("Carta 2 - %s (%c): %.2f bilhões", nome_cidade2, estado2, pib2 / 1e9);

    if (pib1 > pib2)
    {
      carta_vencedora = 1;
    }
    else if (pib2 > pib1)
    {
      carta_vencedora = 2;
    }
  }
  else if (ATRIBUTO_COMPARACAO == 4)
  {
    // Densidade Populacional (MENOR valor ganha)
    printf("\nComparação de cartas (Atributo: Densidade Populacional)\n");
    printf("\nCarta 1 - %s (%c): %.2f hab/km^2\n", nome_cidade1, estado1, densidade_populacional1);
    printf("Carta 2 - %s (%c): %.2f hab/km^2", nome_cidade2, estado2, densidade_populacional2);

    if (densidade_populacional1 < densidade_populacional2)
    {
      carta_vencedora = 1;
    }
    else if (densidade_populacional2 < densidade_populacional1)
    {
      carta_vencedora = 2;
    }
  }
  else if (ATRIBUTO_COMPARACAO == 5)
  {
    // PIB per Capita (Maior valor ganha)
    printf("\nComparação de cartas (Atributo: PIB per Capita)\n");
    printf("\nCarta 1 - %s (%c): %.2f reais\n", nome_cidade1, estado1, pib_per_capita1);
    printf("Carta 2 - %s (%c): %.2f reais", nome_cidade2, estado2, pib_per_capita2);

    if (pib_per_capita1 > pib_per_capita2)
    {
      carta_vencedora = 1;
    }
    else if (pib_per_capita2 > pib_per_capita1)
    {
      carta_vencedora = 2;
    }
  }
  else if (ATRIBUTO_COMPARACAO == 6)
  {
    // Super Poder (Maior valor ganha)
    printf("\nComparação de cartas (Atributo: Super Poder)\n");
    printf("\nCarta 1 - %s (%c): %.2f\n", nome_cidade1, estado1, super_poder1);
    printf("Carta 2 - %s (%c): %.2f", nome_cidade2, estado2, super_poder2);

    if (super_poder1 > super_poder2)
    {
      carta_vencedora = 1;
    }
    else if (super_poder2 > super_poder1)
    {
      carta_vencedora = 2;
    }
  }

  // Exibição do Resultado Final
  if (carta_vencedora == 1)
  {
    printf("\nResultado: Carta 1 (%s) venceu!\n", nome_cidade1);
  }
  else if (carta_vencedora == 2)
  {
    printf("\nResultado: Carta 2 (%s) venceu!\n", nome_cidade2);
  }
  else
  {
    /* Embora improvável, existe a chance de ambos digitarem valores iguais, o que ocasionaria em um empate */
    printf("\nResultado: empate!\n");
  }

  return 0;
}
