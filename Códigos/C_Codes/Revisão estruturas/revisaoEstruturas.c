#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>
#include <locale.h>

#define ACELERATION_G 9.81
#define PI 3.141592653589793 // Defini��o de PI usando #define

// Defini��o do enum cores
enum cores {
    RED ,
    GREEN,
    BLUE,
    YELLOW,
    GREY,

};

// Fun��o para verificar se a acelera��o � alta
bool is_high_acceleration(double acceleration) {
    return acceleration > ACELERATION_G;
}

// Fun��o para retornar a cor associada com base na acelera��o
enum cores get_color_based_on_acceleration(double acceleration) {
    if (acceleration < ACELERATION_G) {
        return GREEN; // Acelera��o baixa � associada � cor GREEN
    } else if (acceleration == ACELERATION_G) {
        return BLUE;  // Acelera��o igual � constante � associada � cor BLUE
    } else {
        return RED;   // Acelera��o alta � associada � cor RED
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
typedef struct  {
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
char projeto[] = "Ampliar Tecnologias";

int main(void) {
    setlocale(LC_ALL, "Portuguese");
    srand((unsigned) time(0));

    colours = RED;
    printf("Cor selecionada: %d\n", colours);

    u.numero = 42;
    printf("Valor da union (numero): %d\n", u.numero);

    u.decimal = 3.14f;
    printf("Valor da union (decimal): %.2f\n", u.decimal);

    u.letra = 'A';
    printf("Valor da union (letra): %c\n", u.letra);

    Pessoa.idade = 25;
    strcpy(Pessoa.nome, "Jo�o Silva");
    Pessoa.estatura = 1.75f;
    printf("Pessoa:\n");
    printf("Idade: %d\n", Pessoa.idade);
    printf("Nome: %s\n", Pessoa.nome);
    printf("Estatura: %.2f\n", Pessoa.estatura);

    strcpy(Livro1.titulo, "O Guia do Mochileiro das Gal�xias");
    strcpy(Livro1.autor, "Douglas Adams");
    Livro1.ano_publicacao = 1979;
    Livro1.preco = 29.90f;
    printf("Livro:\n");
    printf("T�tulo: %s\n", Livro1.titulo);
    printf("Autor: %s\n", Livro1.autor);
    printf("Ano de publica��o: %d\n", Livro1.ano_publicacao);
    printf("Pre�o: %.2f\n", Livro1.preco);

    serie = 12345;
    printf("N�mero da s�rie: %hu\n", serie);
    printf("Valor m�ximo de 32 bits: %lu\n", max32);
    printf("Valor de PI_F: %.7f\n", PI_F);
    printf("Valor de PI: %.15f\n", PI);
    printf("Projeto: %s\n", projeto);

    const double acceleration = 2.45;

    if (is_high_acceleration(acceleration)) {
        printf("A acelera��o de %.2f � alta.\n", acceleration);
    } else {
        printf("A acelera��o de %.2f n�o � alta.\n", acceleration);
    }

    const enum cores color = get_color_based_on_acceleration(acceleration);

    switch (color) {
        case 0:
            printf("A cor associada � acelera��o � RED.\n");
            break;
        case 1:
            printf("A cor associada � acelera��o � GREEN.\n");
            break;
        case 2:
            printf("A cor associada � acelera��o � BLUE.\n");
            break;
        default:
            printf("Cor desconhecida.\n");
            break;
    }

    printf("N�meros aleat�rios:\n");
    for (int i = 0; i < 5; ++i) {
        short int random_number = (short int)(rand() % 100); // N�mero aleat�rio entre 0 e 99
        printf("%d ", random_number);
    }
    printf("\n");

    return 0;
}
