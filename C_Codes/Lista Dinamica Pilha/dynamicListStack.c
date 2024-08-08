#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

// Defini��o do n� da pilha
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Fun��o para criar um novo n�
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Fun��o para empurrar um novo n� no topo da pilha
void push(Node** top, int data) {
    Node* newNode = createNode(data);
    newNode->next = *top;
    *top = newNode;
}

// Fun��o para remover o n� do topo da pilha
void pop(Node** top) {
    if (*top == NULL) {
        printf("A pilha est� vazia, n�o h� elementos para remover.\n");
        return;
    }

    Node* temp = *top;
    *top = (*top)->next;
    free(temp);
    printf("Elemento removido do topo da pilha.\n");
}

// Fun��o para imprimir a pilha
void printStack(Node* top) {
    Node* current = top;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int main() {
    setlocale(LC_ALL, "Portuguese");
    Node* top = NULL;  // Inicializa o topo da pilha
    int choice, data;

    srand(time(NULL));

    while (1) {
        if(top != NULL){
            printf("Pilha Din�mica: ");
            printStack(top);
            printf("\n1. Inserir na pilha\n2. Remover da pilha\n3. Sair\nEscolha uma op��o: ");
            scanf("%d", &choice);
        } else {
            printf("\n1. Inserir na pilha\n3. Sair\nEscolha uma op��o: ");
            scanf("%d", &choice);
            if (choice == 2) {
                printf("Op��o Inv�lida\n");
                continue;
            } 
        }

        switch (choice) {
            case 1:
                data = rand() % 100;
                push(&top, data);
                printf("N�mero %d inserido na pilha.\n", data);
                break;
            case 2:
                pop(&top);
                break;
            case 3:
                // Libera a mem�ria alocada para a pilha
                while (top != NULL) {
                    Node* temp = top;
                    top = top->next;
                    free(temp);
                }
                return 0;
            default:
                printf("Op��o inv�lida.\n");
        }
    }
}
