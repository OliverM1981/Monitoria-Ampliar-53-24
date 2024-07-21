#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <locale.h>

#define ACELERATION_G 9.81

// Defini��o do enum cores
enum cores {
    RED = 0,
    GREEN = 1,
    BLUE = 2
};

// Fun��o para verificar se a acelera��o � alta
bool is_high_acceleration(double acceleration) {
    // Define uma acelera��o alta se for maior que a constante ACELERATION_G
    return acceleration > ACELERATION_G;
}

// Fun��o para retornar a cor associada com base na acelera��o
enum cores get_color_based_on_acceleration(double acceleration) {
    if (acceleration < ACELERATION_G) {
        return GREEN; // Acelera��o baixa � associada � cor GREEN
    } else if (acceleration == ACELERATION_G) {
        return BLUE; // Acelera��o igual � constante � associada � cor BLUE
    } else {
        return RED; // Acelera��o alta � associada � cor RED
    }
}

// Declara��o da vari�vel do tipo enum cores
enum cores colours;

// Declara��o da vari�vel do tipo union
union {
    int numero;
    float decimal;
    char letra;
} u;

// Defini��o da struct pessoa
struct pessoa {
    int idade;
    char nome[30];
    float estatura;
};

// Declara��o da vari�vel do tipo struct pessoa
struct pessoa Pessoa;

// Defini��o de um typedef para Livro
typedef struct {
    char titulo[100];
    char autor[50];
    int ano_publicacao;
    float preco;
} Livro;

// Declara��o de uma vari�vel do tipo Livro
Livro Livro1;

// Declara��o de vari�veis de tipos diversos
unsigned short int serie;
unsigned long int max32 = 4294967295UL;
const float PI_F = 3.1415927f;
const double PI = 3.141592653589793;
double PI_DOUBLE = M_PI;
char projeto[] = {"Ampliar Tecnologias"};

int main(void) {
    //Definindo configura��es de regionalidade
    setlocale(LC_ALL,"Portuguese");
    // Gerar n�meros aleat�rios
    // Inicializando o gerador de n�meros aleat�rios com uma semente apropriada
    srand((unsigned int)time(NULL));

    // Inicializa��o da vari�vel do tipo enum cores
    colours = RED;
    // Exibindo o valor da vari�vel colours
    printf("Cor selecionada: %d\n", colours); // RED tem valor 0

    // Inicializa��o da vari�vel do tipo union
    u.numero = 42; // Atribuindo um valor ao membro 'numero' da union
    printf("Valor da union (numero): %d\n", u.numero);

    // Modificando o valor da union
    u.decimal = 3.14f; // Atribuindo um valor ao membro 'decimal' da union
    printf("Valor da union (decimal): %.2f\n", u.decimal);

    // Modificando o valor da union novamente
    u.letra = 'A'; // Atribuindo um valor ao membro 'letra' da union
    printf("Valor da union (letra): %c\n", u.letra);

    // Inicializa��o da vari�vel do tipo struct pessoa
    Pessoa.idade = 25;
    strcpy(Pessoa.nome, "Jo�o Silva"); // Atribuindo um valor ao membro 'nome'
    Pessoa.estatura = 1.75f;
    // Exibindo os valores da struct pessoa
    printf("Pessoa:\n");
    printf("Idade: %d\n", Pessoa.idade);
    printf("Nome: %s\n", Pessoa.nome);
    printf("Estatura: %.2f\n", Pessoa.estatura);

    // Inicializa��o da vari�vel do tipo Livro
    strcpy(Livro1.titulo, "O Guia do Mochileiro das Gal�xias");
    strcpy(Livro1.autor, "Douglas Adams");
    Livro1.ano_publicacao = 1979;
    Livro1.preco = 29.90f;
    // Exibindo os valores do Livro
    printf("Livro:\n");
    printf("T�tulo: %s\n", Livro1.titulo);
    printf("Autor: %s\n", Livro1.autor);
    printf("Ano de publica��o: %d\n", Livro1.ano_publicacao);
    printf("Pre�o: %.2f\n", Livro1.preco);

    // Trabalhando com vari�veis de tipos diversos
    serie = 12345;
    printf("N�mero da s�rie: %hu\n", serie);
    printf("Valor m�ximo de 32 bits: %lu\n", max32);
    printf("Valor de PI_F: %.7f\n", PI_F);
    printf("Valor de PI: %.15f\n", PI);
    printf("Valor de PI_DOUBLE: %.15f\n", PI_DOUBLE);
    printf("Projeto: %s\n", projeto);

    // Trabalhando com a acelera��o e cor
    double acceleration = 12.5; // Exemplo de valor de acelera��o

    // Verificar se a acelera��o � alta
    if (is_high_acceleration(acceleration)) {
        printf("A acelera��o de %.2f � alta.\n", acceleration);
    } else {
        printf("A acelera��o de %.2f n�o � alta.\n", acceleration);
    }

    // Obter a cor baseada na acelera��o
    enum cores color = get_color_based_on_acceleration(acceleration);

    // Exibir a cor associada usando n�meros diretamente
    switch (color) {
        case 0: // RED
            printf("A cor associada � acelera��o � RED.\n");
            break;
        case 1: // GREEN
            printf("A cor associada � acelera��o � GREEN.\n");
            break;
        case 2: // BLUE
            printf("A cor associada � acelera��o � BLUE.\n");
            break;
        default:
            printf("Cor desconhecida.\n");
            break;
    }

    // Gerar e exibir 5 n�meros aleat�rios entre 0 e 99
    printf("N�meros aleat�rios:\n");
    for (int i = 0; i < 5; ++i) {
        int random_number = rand() % 100; // N�mero aleat�rio entre 0 e 99
        printf("%d ", random_number);
    }
    printf("\n");

    return 0;
}
