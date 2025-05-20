#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <stdlib.h>

typedef struct ocorrencia
{
    int cdx;
    int cdy;
    float area;
    char data[10];
    int gravidade;
    struct ocorrencia *next;
}oc;

oc *head, *aux;

void nova_ocorrencia(){
    oc *novo = malloc(sizeof(oc));
    printf("\nCoordenada X:");
    scanf("%d", &novo->cdx);
    printf("Coordenada Y:");
    scanf("%d", &novo->cdy);
    printf("Área Desmatada (hectares):");
    scanf("%f", &novo->area);
    printf("Data da Detecção (AAAA-MM-DD):");
    scanf("%s", novo->data);
    printf("Gravidade (1-Baixa, 2-Média, 3-Alta):");
    scanf("%d", &novo->gravidade);

    if (head == NULL)
    {
        novo->next = NULL;
        head = novo;
    } else {
        aux = head;
        while (aux->next != NULL)
        {
            aux = aux->next;
        }
        aux->next = novo;
        novo->next = NULL;
    }
    
    puts("Ocorrência registrada com sucesso!");
}

void exibir_ocorrencias(){
    puts("\nOcorrências Registradas");
    aux = head;
    while (aux != NULL){
        printf("Coordenada X: %d, Coordenada Y: %d, Área: %.2f ha, Data: %s, Gravidade: %d\n", aux->cdx, aux->cdy, aux->area, aux->data, aux->gravidade);
        aux = aux->next;
    }
}

void filtrar_ocorrencias(){
    int esc;
    printf("\nDigite o código de gravidade para filtrar (1-3):");
    scanf("%d", &esc);
    printf("Ocorrências com Gravidade %d\n", esc);

    aux = head;
    while (aux != NULL){
        if (aux->gravidade == esc)
        {
            printf("Coordenada X: %d, Coordenada Y: %d, Área: %.2f ha, Data: %s, Gravidade: %d\n", aux->cdx, aux->cdy, aux->area, aux->data, aux->gravidade);
        }
        aux = aux->next;
    }
}

void calcular_area(){
    float total;
    aux = head;
    while (aux != NULL){
        total += aux->area;
        aux = aux->next;
    }
    printf("Área Total Desmatada:%.2f hectares\n", total);
}

void main(){
    setlocale(LC_ALL, "Portuguese");

    int op;
    head = NULL;

    puts("Bem-vindo ao Monitor de Desmatamento em Terras Indígenas!");
    puts("\n1. Registrar Ocorrência");
    puts("2. Listar Ocorrências");
    puts("3. Filtrar por Gravidade");
    puts("4. Calcular Área Total Desmatada");
    puts("5. Sair");

    do
    {
        printf("\nEscolha uma opção:");
        scanf("%d", &op);

        switch (op)
        {
        case 1:
            nova_ocorrencia();
            break;
        case 2:
            exibir_ocorrencias();
            break;
        case 3:
            filtrar_ocorrencias();
            break;
        case 4:
            calcular_area();
            break;
        case 5:
        while (head != NULL){
                aux = head;
                head = head->next;
                free(aux);
            }
            puts("Encerrando o programa.");
            op = 6;
            break;
        }
    }
    while (op < 6);
}