#include <stdio.h>
#include <string.h>

// Desafio Super Trunfo - Países
// Tema 6 - Implementando Comparações Avançadas com Atributos Múltiplos em C
// Objetivo: No nível aventureiro você deve implementar menus dinâmicos com switch e permitir que o jogador escolha dois atributos para comparar as cartas de países.

/* Função responsável por apresentar o display do menu através de seu ID, removendo da exibição todo aquele que já tenha sido escolhido. Caso nenhum tenha sido escolhido ainda, exibe o menu completo */
void menu(int atributo_escolhido)
{
  const int ID_POPULACAO = 1;
  const int ID_AREA = 2;
  const int ID_PIB = 3;
  const int ID_DENSIDADE_POPULACIONAL = 4;
  const int ID_PONTOS_TURISTICOS = 5;
  const int ID_PIB_PER_CAPITA = 6;

  printf("\n--------------------------------------------\nEscolha o Atributo para Comparação\n--------------------------------------------\n");

  // if-else para exibir apenas as opções não escolhidas
  if (atributo_escolhido != ID_POPULACAO)
  {
    printf("%d. População\n", ID_POPULACAO);
  }
  if (atributo_escolhido != ID_AREA)
  {
    printf("%d. Área\n", ID_AREA);
  }
  if (atributo_escolhido != ID_PIB)
  {
    printf("%d. PIB\n", ID_PIB);
  }
  if (atributo_escolhido != ID_DENSIDADE_POPULACIONAL)
  {
    printf("%d. Densidade Populacional\n", ID_DENSIDADE_POPULACIONAL);
  }
  if (atributo_escolhido != ID_PONTOS_TURISTICOS)
  {
    printf("%d. Pontos Turísticos\n", ID_PONTOS_TURISTICOS);
  }
  if (atributo_escolhido != ID_PIB_PER_CAPITA)
  {
    printf("%d. PIB per Capita\n", ID_PIB_PER_CAPITA);
  }

  printf("--------------------------------------------\n");
  printf("Digite um número da lista acima: \n");
}

// Função para obter o atributo e validar o valor passado
int escolha_atributo(int atributo_escolhido)
{
  int escolha;

  const int MENOR_ATRIBUTO = 1;
  const int MAIOR_ATRIBUTO = 6;

  menu(atributo_escolhido);

  /* Trata erros na passagem de valores incorretos e utiliza recursividade para que a função seja chamada até que um valor válido seja passado */
  if (scanf("%d", &escolha) != 1)
  {
    printf("\nOpção Inválida. Por favor, digite um NÚMERO válido!\n");
    getchar();
    getchar();
    return escolha_atributo(atributo_escolhido);
  }

  /* Validação com if-else utilizando de recursividade para que a própria função seja chamada até que um valor válido seja passado */
  if (escolha >= MENOR_ATRIBUTO && escolha <= MAIOR_ATRIBUTO)
  {
    if (escolha != atributo_escolhido)
    {
      return escolha;
    }
    else
    {
      printf("\nOpção Inválida. Este atributo já foi escolhido. Escolha outro!\n");
      return escolha_atributo(atributo_escolhido);
    }
  }
  else
  {
    printf("\nOpção Inválida. O número deve estar entre 1 e 6.\n");
    return escolha_atributo(atributo_escolhido);
  }
}

// Declaração da função para criação de Cartas
void adicionar_carta(
    int num_carta,
    char estado[3],
    char codigo_carta[5],
    char nome_cidade[50],
    unsigned long int *populacao,
    float *area,
    float *pib,
    int *num_pontos_turisticos)
{
  printf("\n------------------\nCadastro da Carta %d\n-------------------\n", num_carta);

  // Chamadas às funções responsáveis por ler o teclado do usuário
  printf("Estado: ");
  scanf("%2s", estado);

  printf("Código Carta (estado + 01 - 04): ");
  scanf("%4s", codigo_carta);

  // Para limpar o buffer
  scanf("%*c");

  printf("Nome Cidade: ");
  fgets(nome_cidade, 50, stdin);
  nome_cidade[strcspn(nome_cidade, "\n")] = 0;

  printf("População: ");
  scanf("%lu", populacao);

  printf("Área (km²): ");
  scanf("%f", area);

  printf("PIB (em bilhões de reais): ");
  scanf("%f", pib);
  *pib = *pib * 1e9;

  printf("Número de Pontos Turísticos: ");
  scanf("%d", num_pontos_turisticos);

  // Exibição da Carta com todos os seus dados preenchidos
  printf("\nCarta %d:\n", num_carta);
  printf("Estado: %s\n", estado);
  printf("Código: %s\n", codigo_carta);
  printf("Nome da Cidade: %s\n", nome_cidade);
  printf("População: %lu\n", *populacao);
  printf("Área: %.2f km^2\n", *area);
  printf("PIB: %.2f bilhões de reais\n", *pib / 1e9);
  printf("Pontos Turísticos: %d\n", *num_pontos_turisticos);
}

// Função que retorna o valor de um atributo (no formato float)
float valor_atributo(
    int id_atributo,
    unsigned long int populacao, float area, float pib,
    int num_pontos_turisticos, float densidade_populacional, float pib_per_capita)
{
  switch (id_atributo)
  {
  case 1:
    return (float)populacao;
  case 2:
    return area;
  case 3:
    return pib;
  case 4:
    return densidade_populacional;
  case 5:
    return (float)num_pontos_turisticos;
  case 6:
    return pib_per_capita;
  default:
    return 0.0f;
  }
}

// Função que retorna o nome de um atributo com base em seu ID
const char *obter_nome_atributo(int id_atributo)
{
  switch (id_atributo)
  {
  case 1:
    return "População";
  case 2:
    return "Área";
  case 3:
    return "PIB";
  case 4:
    return "Densidade Populacional";
  case 5:
    return "Pontos Turísticos";
  case 6:
    return "PIB per Capita";
  default:
    return "Inválido";
  }
}

/* Função que retorna a regra de vitória de um atributo
(1 se o Maior Valor Ganha : 0 se o Menor Valor Ganha) */
int regra_para_vitoria(int id_atributo)
{
  int ID_DENSIDADE_POPULACIONAL = 4;

  /* Se for 0, o MENOR ganha
  Caso contrário, o MAIOR vence
  A Densidade Populacional (ID n° 4) é o único atributo que ganha se seu valor for o MENOR */
  if (id_atributo == ID_DENSIDADE_POPULACIONAL)
  {
    return 0;
  }
  else
  {
    return 1;
  }
}

/* Função responsável pela comparação dos valores de cada carta e exibição do resultado final do duelo entre ambas */
void duelo_de_cartas(
    int atributo1_id, int atributo2_id,
    char *estado1, char *estado2,
    char *nome_cidade1, char *nome_cidade2,
    unsigned long int populacao1, unsigned long int populacao2,
    float area1, float area2,
    float pib1, float pib2,
    int num_pontos_turisticos1, int num_pontos_turisticos2,
    float densidade_populacional1, float densidade_populacional2,
    float pib_per_capita1, float pib_per_capita2)
{
  // Obter Valores do Atributo 1
  float val1_atributo1 = valor_atributo(atributo1_id, populacao1, area1, pib1, num_pontos_turisticos1, densidade_populacional1, pib_per_capita1);
  float val2_atributo1 = valor_atributo(atributo1_id, populacao2, area2, pib2, num_pontos_turisticos2, densidade_populacional2, pib_per_capita2);

  // Obter Valores do Atributo 2
  float val1_atributo2 = valor_atributo(atributo2_id, populacao1, area1, pib1, num_pontos_turisticos1, densidade_populacional1, pib_per_capita1);
  float val2_atributo2 = valor_atributo(atributo2_id, populacao2, area2, pib2, num_pontos_turisticos2, densidade_populacional2, pib_per_capita2);

  const char *nome_atributo1 = obter_nome_atributo(atributo1_id);
  const char *nome_atributo2 = obter_nome_atributo(atributo2_id);

  // Obtém as regras de vitória (> ou <) para cada atributo
  int regra_atributo1 = regra_para_vitoria(atributo1_id);
  int regra_atributo2 = regra_para_vitoria(atributo2_id);

  // Soma dos Valores de cada Atributo
  float soma1 = val1_atributo1 + val1_atributo2;
  float soma2 = val2_atributo1 + val2_atributo2;

  // Determinação do Vencedor na somatória final
  int carta_vencedora = (soma1 > soma2) ? 1 : ((soma2 > soma1) ? 2 : 0);

  // Exibição Atributo 1
  printf("\nAtributo 1: %s\n", nome_atributo1);
  printf("   %s: %.2f vs %s: %.2f\n", nome_cidade1, val1_atributo1, nome_cidade2, val2_atributo1);

  // if-else para determinar o vencedor individual do Atributo 1
  if (val1_atributo1 == val2_atributo1)
  {
    printf("   Resultado: Empate!\n");
  }
  else if (regra_atributo1 == 1)
  {
    if (val1_atributo1 > val2_atributo1)
    {
      printf("   Resultado: %s (%s) venceu!\n", nome_cidade1, estado1);
    }
    else
    {
      printf("   Resultado: %s (%s) venceu!\n", nome_cidade2, estado2);
    }
  }
  else
  {
    if (val1_atributo1 < val2_atributo1)
    {
      printf("   Resultado: %s (%s) venceu!\n", nome_cidade1, estado1);
    }
    else
    {
      printf("   Resultado: %s (%s) venceu!\n", nome_cidade2, estado2);
    }
  }

  // Exibição Atributo 2
  printf("\nAtributo 2: %s\n", nome_atributo2);
  printf("   %s: %.2f vs %s: %.2f\n", nome_cidade1, val1_atributo2, nome_cidade2, val2_atributo2);

  // if-else para determinar o vencedor individual do Atributo 2
  if (val1_atributo2 == val2_atributo2)
  {
    printf("   Resultado: Empate!\n");
  }
  else if (regra_atributo2 == 1)
  {
    if (val1_atributo2 > val2_atributo2)
    {
      printf("   Resultado: %s (%s) venceu!\n", nome_cidade1, estado1);
    }
    else
    {
      printf("   Resultado: %s (%s) venceu!\n", nome_cidade2, estado2);
    }
  }
  else
  {
    if (val1_atributo2 < val2_atributo2)
    {
      printf("   Resultado: %s (%s) venceu!\n", nome_cidade1, estado1);
    }
    else
    {
      printf("   Resultado: %s (%s) venceu!\n", nome_cidade2, estado2);
    }
  }

  printf("--------------------------------------------\n");

  // Resultado Final (Soma)
  printf("Soma dos Atributos:\n");
  printf("   %s: %.2f vs %s: %.2f\n", nome_cidade1, soma1, nome_cidade2, soma2);

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
    printf("\nResultado: Empate!\n");
  }
}

// Função Principal
int main()
{
  // Declarações Carta 1
  char estado1[3];
  char codigo1[5];
  char nome_cidade1[50];
  unsigned long int populacao1;
  float area1;
  float pib1;
  int num_pontos_turisticos1;
  float densidade_populacional1;
  float pib_per_capita1;
  float super_poder1;

  // Declarações Carta 2
  char estado2[3];
  char codigo2[5];
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
      estado1,
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
      estado2,
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

  // Escolha do Primeiro Atributo
  int escolha_usuario1 = escolha_atributo(0);

  // Escolha do Segundo Atributo (não inclui o atributo escolhido anteriormente)
  int escolha_usuario2 = escolha_atributo(escolha_usuario1);

  duelo_de_cartas(
      escolha_usuario1, escolha_usuario2,
      estado1, estado2,
      nome_cidade1, nome_cidade2,
      populacao1, populacao2,
      area1, area2,
      pib1, pib2,
      num_pontos_turisticos1, num_pontos_turisticos2,
      densidade_populacional1, densidade_populacional2,
      pib_per_capita1, pib_per_capita2);

  return 0;
}
