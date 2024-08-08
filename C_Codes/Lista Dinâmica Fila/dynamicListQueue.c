#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

// Defini��o do n� da fila
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Fun��o para criar um novo n�
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Erro ao alocar mem�ria.\n");
        exit(1); // Encerra o programa em caso de falha na aloca��o
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Fun��o para enfileirar (inserir no final)
void enqueue(Node** front, Node** rear, int data) {
    Node* newNode = createNode(data);
    if (*rear == NULL) {
        // Se a fila est� vazia
        *front = *rear = newNode;
    } else {
        // Adiciona no final da fila
        (*rear)->next = newNode;
        *rear = newNode;
    }
}

// Fun��o para desenfileirar (remover do in�cio)
void dequeue(Node** front, Node** rear) {
    if (*front == NULL) {
        printf("A fila est� vazia, n�o h� elementos para remover.\n");
        return;
    }

    Node* temp = *front;
    *front = (*front)->next;

    if (*front == NULL) {
        // Se a fila ficou vazia, o rear tamb�m deve ser NULL
        *rear = NULL;
    }

    free(temp);
    printf("Elemento removido do in�cio da fila.\n");
}

// Fun��o para imprimir a fila
void printQueue(Node* front) {
    Node* current = front;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int main() {
    setlocale(LC_ALL, "Portuguese");
    Node* front = NULL; // In�cio da fila
    Node* rear = NULL;  // Final da fila
    int choice, data;

    srand(time(NULL));

    while (1) {
        printf("\nFila Din�mica: ");
        printQueue(front);
        printf("\n1. Inserir na fila\n");

        if (front != NULL) {
            printf("2. Remover da fila\n");
        }

        printf("3. Sair\nEscolha uma op��o: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                data = rand() % 100;
                enqueue(&front, &rear, data);
                printf("N�mero %d enfileirado.\n", data);
                break;
            case 2:
                if (front != NULL) {
                    dequeue(&front, &rear);
                } else {
                    printf("A fila est� vazia, n�o h� elementos para remover.\n");
                }
                break;
            case 3:
                // Libera a mem�ria alocada para a fila
                while (front != NULL) {
                    Node* temp = front;
                    front = front->next;
                    free(temp);
                }
                return 0;
            default:
                printf("Op��o inv�lida.\n");
        }
    }
}
