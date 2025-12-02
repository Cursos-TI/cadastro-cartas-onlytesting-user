#include <stdio.h>
#include <string.h>

// Desafio Super Trunfo - Países
// Tema 2 - Calculando Densidade Populacional e PIB per Capita
// Objetivo: No nível aventureiro você deve implementar a lógica para calcular e exibir duas novas propriedades importantes para cada cidade: a densidade populacional e o PIB per capita.

// Declaração da função para criação de Cartas
void adicionar_carta(
    int num_carta,
    char *estado,
    char codigo_carta[4],
    char nome_cidade[50],
    int *populacao,
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
  fgets(nome_cidade, 100, stdin);
  nome_cidade[strcspn(nome_cidade, "\n")] = 0;

  printf("População: ");
  scanf("%d", populacao);

  printf("Área (km²): ");
  scanf("%f", area);

  printf("PIB: ");
  scanf("%f", pib);
  *pib = *pib * 1e9;

  printf("Número de Pontos Turísticos: ");
  scanf("%d", num_pontos_turisticos);

  // Cálculo de Densidade populacional e PIB per Capita
  float densidade_populacional = *populacao / *area;
  float pib_per_capita = *pib / *populacao;

  // Exibição da Carta com todos os seus dados preenchidos
  printf("\nCarta %d:\n", num_carta);
  printf("Estado: %c\n", *estado);
  printf("Código: %s\n", codigo_carta);
  printf("Nome da Cidade: %s\n", nome_cidade);
  printf("População: %d\n", *populacao);
  printf("Área: %.2f km^2\n", *area);
  printf("PIB: %.2f bilhões de reais\n", *pib / 1e9);
  printf("Número de Pontos Turísticos: %d\n", *num_pontos_turisticos);
  printf("Densidade Populacional: %.2f hab/km^2\n", densidade_populacional);
  printf("PIB per Capita: %.2f reais\n", pib_per_capita);
}

// Função Principal - Para declaração e chamada de Cartas de forma centralizada
int main()
{
  // Declarações Carta 1
  char estado1;
  char codigo1[4];
  char nome_cidade1[50];
  int populacao1;
  float area1;
  float pib1;
  int num_pontos_turisticos1;

  // Declarações Carta 2
  char estado2;
  char codigo2[4];
  char nome_cidade2[50];
  int populacao2;
  float area2;
  float pib2;
  int num_pontos_turisticos2;

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

  return 0;
}
