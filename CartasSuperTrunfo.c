#include <stdio.h>
#include <string.h>

// Desafio Super Trunfo - Países
// Tema 3 - Batalha de Cartas no Super Trunfo
// Objetivo: No nível mestre você deve implementar a lógica de comparação entre duas cartas do Super Trunfo, determinando a vencedora de cada atributo e introduzindo o conceito de "Super Poder".

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

  // Comparações para saber quem ganhou!
  int venceu1;

  // População (Maior valor ganha)
  venceu1 = (populacao1 > populacao2);
  printf("\nPopulação: Carta %d venceu (%d)\n", venceu1 ? 1 : 2, venceu1);

  // Área (Maior valor ganha)
  venceu1 = (area1 > area2);
  printf("Área: Carta %d venceu (%d)\n", venceu1 ? 1 : 2, venceu1);

  // PIB (Maior valor ganha)
  venceu1 = (pib1 > pib2);
  printf("PIB: Carta %d venceu (%d)\n", venceu1 ? 1 : 2, venceu1);

  // Pontos Turísticos (Maior valor ganha)
  venceu1 = (num_pontos_turisticos1 > num_pontos_turisticos2);
  printf("Pontos Turísticos: Carta %d venceu (%d)\n", venceu1 ? 1 : 2, venceu1);

  // Densidade Populacional (MENOR valor ganha)
  venceu1 = (densidade_populacional1 < densidade_populacional2);
  printf("Densidade Populacional: Carta %d venceu (%d)\n", venceu1 ? 1 : 2, venceu1);

  // PIB per Capita (Maior valor ganha)
  venceu1 = (pib_per_capita1 > pib_per_capita2);
  printf("PIB per Capita: Carta %d venceu (%d)\n", venceu1 ? 1 : 2, venceu1);

  // Super Poder (Maior valor ganha)
  venceu1 = (super_poder1 > super_poder2);
  printf("Super Poder: Carta %d venceu (%d)\n", venceu1 ? 1 : 2, venceu1);

  return 0;
}
