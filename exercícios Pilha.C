#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Estrutura para representar um nó da pilha
struct Node {
    int data;
    struct Node* next;
};

// Função para criar um novo nó
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Erro: Não foi possível alocar memória para o novo nó.\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Estrutura da pilha
struct Stack {
    struct Node* top;
};

//1 Função para inicializar a pilha
void criarPilha(struct Stack* stack) {
    stack->top = NULL;
}

// Função para verificar se a pilha está vazia
int isEmpty(struct Stack* stack) {
    return stack->top == NULL;
}

// Função para inserir um elemento na pilha (push)
void push(struct Stack* stack, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = stack->top;
    stack->top = newNode;
    printf("Inserido %d na pilha.\n", data);
}

// Função para remover um elemento da pilha (pop)
int pop(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Erro: A pilha está vazia.\n");
        exit(1);
    }
    struct Node* temp = stack->top;
    int data = temp->data;
    stack->top = temp->next;
    free(temp);
    return data;
}

// Função para consultar o elemento no topo da pilha (top)
int peek(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Erro: A pilha está vazia.\n");
        exit(1);
    }
    return stack->top->data;
}
//2
void empilha(struct Stack* stack, int data) {
    push(stack, data);
}

//3 Função para desempilhar o elemento do topo da pilha
void desempilha(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Erro: A pilha está vazia, não é possível desempilhar.\n");
        return;
    }
    int data = pop(stack);
    printf("Removido: %d\n", data);
}
//4 Função para consultar o elemento no topo da pilha (top)
int topoPilha(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Erro: A pilha está vazia.\n");
        exit(1);
    }
    return stack->top->data;
}
//5 e 25 Função para calcular o tamanho da pilha
int tamanhoPilha(struct Stack* stack) {
    int tamanho = 0;
    struct Node* current = stack->top;
    
    while (current != NULL) {
        tamanho++;
        current = current->next;
    }
    
    return tamanho;
}
//6
void limpaPilha(struct Stack* stack) {
    while (!isEmpty(stack)) {
        pop(stack);
    }
}
//7 e 22
struct Stack copiaPilha(struct Stack* original) {
    struct Stack copia;
    criarPilha(&copia);
    
    struct Node* current = original->top;
    
    // Percorre a pilha original e empilha os elementos na cópia
    while (current != NULL) {
        empilha(&copia, current->data);
        current = current->next;
    }
    
    return copia;
}

//8 Função para inverter a ordem dos elementos na pilha
void invertePilha(struct Stack* stack) {
    if (isEmpty(stack)) {
        return; // Não é necessário inverter uma pilha vazia
    }
    
    struct Stack pilhaAuxiliar;
    criarPilha(&pilhaAuxiliar);
    
    // Desempilhar todos os elementos da pilha original e empilhar na pilha auxiliar
    while (!isEmpty(stack)) {
        int data = pop(stack);
        push(&pilhaAuxiliar, data);
    }
    
    // Agora, a pilha original está vazia, e a pilha auxiliar contém os elementos na ordem inversa
    // Copiar os elementos de volta para a pilha original
    while (!isEmpty(&pilhaAuxiliar)) {
        int data = pop(&pilhaAuxiliar);
        push(stack, data);
    }
}

int verificaPilhaVazia(struct Stack* stack) {
    return isEmpty(stack);
}

//10 Função para concatenar duas pilhas
void concatenaPilhas(struct Stack* pilha1, struct Stack* pilha2) {
    while (!isEmpty(pilha2)) {
        int data = pop(pilha2);
        push(pilha1, data);
    }
}

// Função auxiliar para inserir um elemento no fundo da pilha
void insereNoFundo(struct Stack* stack, int data) {
    if (isEmpty(stack)) {
        empilha(stack, data);
        return;
    }

    int temp = pop(stack);
    insereNoFundo(stack, data);
    empilha(stack, temp);
}

//11 Função para inverter a ordem dos elementos na pilha sem usar uma pilha auxiliar
void invertePilhaSemUmaPilhaAuxiliar(struct Stack* stack) {
    if (isEmpty(stack)) {
        return;
    }

    int data = pop(stack);
    invertePilhaSemUmaPilhaAuxiliar(stack);
    insereNoFundo(stack, data);
}


//12 Função para calcular a média dos valores na pilha
double calculaMediaPilha(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Erro: A pilha está vazia, não é possível calcular a média.\n");
        exit(1);
    }

    int soma = 0;
    int contador = 0;

    struct Node* current = stack->top;
    while (current != NULL) {
        soma += current->data;
        contador++;
        current = current->next;
    }

    return (double)soma / contador;
}

//13 Função para ordenar a pilha em ordem crescente (Bubble Sort)
void ordenaPilha(struct Stack* stack) {
    int tamanho = 0;
    struct Node* current = stack->top;

    // Conta o número de elementos na pilha
    while (current != NULL) {
        tamanho++;
        current = current->next;
    }

    // Aplica o algoritmo Bubble Sort
    for (int i = 0; i < tamanho - 1; i++) {
        current = stack->top;
        struct Node* nextNode = current->next;

        for (int j = 0; j < tamanho - i - 1; j++) {
            if (current->data > nextNode->data) {
                // Troca os elementos se estiverem fora de ordem
                int temp = current->data;
                current->data = nextNode->data;
                nextNode->data = temp;
            }

            current = current->next;
            nextNode = nextNode->next;
        }
    }
}

//14 Função para copiar a pilha invertida
struct Stack copiaPilhaInvertida(struct Stack* original) {
    struct Stack pilhaCopia;
    criarPilha(&pilhaCopia);

    struct Node* current = original->top;
    while (current != NULL) {
        empilha(&pilhaCopia, current->data);
        current = current->next;
    }

    return pilhaCopia;
}

//15 Função para mesclar duas pilhas em uma terceira pilha
struct Stack mesclaPilhas(struct Stack* pilha1, struct Stack* pilha2) {
    struct Stack pilhaMesclada;
    criarPilha(&pilhaMesclada);

    // Mescla os elementos da primeira pilha
    while (!isEmpty(pilha1)) {
        empilha(&pilhaMesclada, pop(pilha1));
    }

    // Mescla os elementos da segunda pilha
    while (!isEmpty(pilha2)) {
        empilha(&pilhaMesclada, pop(pilha2));
    }

    return pilhaMesclada;
}

//16 Função para remover todas as ocorrências de um valor da pilha
void removeElementoPilha(struct Stack* stack, int valor) {
    struct Stack tempStack;
    criarPilha(&tempStack);

    while (!isEmpty(stack)) {
        int data = pop(stack);
        if (data != valor) {
            push(&tempStack, data);
        }
    }

    // Inverte a pilha temporária e a coloca de volta na pilha original
    while (!isEmpty(&tempStack)) {
        int data = pop(&tempStack);
        push(stack, data);
    }
}

//17 Função para copiar os primeiros n elementos da pilha
struct Stack copiaNPrimeirosElementos(struct Stack* original, int n) {
    struct Stack pilhaCopia;
    criarPilha(&pilhaCopia);

    struct Node* current = original->top;
    int contador = 0;

    while (current != NULL && contador < n) {
        empilha(&pilhaCopia, current->data);
        current = current->next;
        contador++;
    }

    return pilhaCopia;
}

//18 Função para copiar os elementos maiores que o limite da pilha
struct Stack copiaElementosMaiores(struct Stack* original, int limite) {
    struct Stack pilhaCopia;
    criarPilha(&pilhaCopia);

    struct Node* current = original->top;

    while (current != NULL) {
        if (current->data > limite) {
            empilha(&pilhaCopia, current->data);
        }
        current = current->next;
    }

    return pilhaCopia;
}


//19 Função para copiar os elementos menores que o limite da pilha
struct Stack copiaElementosMenores(struct Stack* original, int limite) {
    struct Stack pilhaCopia;
    criarPilha(&pilhaCopia);

    struct Node* current = original->top;

    while (current != NULL) {
        if (current->data < limite) {
            empilha(&pilhaCopia, current->data);
        }
        current = current->next;
    }

    return pilhaCopia;
}


//20 Função para empilhar um valor na pilha de forma ordenada
void insereOrdenadoPilha(struct Stack* stack, int valor) {
    if (isEmpty(stack) || valor <= stack->top->data) {
        // Caso base: A pilha está vazia ou o valor é menor ou igual ao topo da pilha.
        push(stack, valor);
        return;
    }

    struct Stack tempStack;
    criarPilha(&tempStack);

    // Encontra o ponto de inserção
    while (!isEmpty(stack) && valor > stack->top->data) {
        push(&tempStack, pop(stack));
    }

    // Insere o valor na pilha original
    push(stack, valor);

    // Restaura os elementos temporários de volta para a pilha original
    while (!isEmpty(&tempStack)) {
        push(stack, pop(&tempStack));
    }
}

//21 Função para calcular a soma de todos os elementos na pilha
int somaElementosPilha(struct Stack* stack) {
    int soma = 0;
    struct Node* current = stack->top;
    
    while (current != NULL) {
        soma += current->data;
        current = current->next;
    }
    
    return soma;
}


//23 Função para remover todos os elementos pares da pilha
void removeElementosPares(struct Stack* stack) {
    struct Stack tempStack;
    criarPilha(&tempStack);

    while (!isEmpty(stack)) {
        int elemento = pop(stack);
        if (elemento % 2 != 0) {
            push(&tempStack, elemento);
        }
    }

    // Restaura os elementos ímpares de volta para a pilha original
    while (!isEmpty(&tempStack)) {
        push(stack, pop(&tempStack));
    }
}

//24 Função para inverter a ordem dos elementos na pilha
void inverteOrdemElementos(struct Stack* stack) {
    struct Stack tempStack;
    criarPilha(&tempStack);

    while (!isEmpty(stack)) {
        int elemento = pop(stack);
        push(&tempStack, elemento);
    }

    // Copia os elementos invertidos de volta para a pilha original
    while (!isEmpty(&tempStack)) {
        int elemento = pop(&tempStack);
        push(stack, elemento);
    }
}


//26 Função para comparar duas pilhas e verificar se são iguais
int comparaPilhas(struct Stack* stack1, struct Stack* stack2) {
    struct Node* current1 = stack1->top;
    struct Node* current2 = stack2->top;

    while (current1 != NULL && current2 != NULL) {
        if (current1->data != current2->data) {
            return 0; // As pilhas são diferentes
        }
        current1 = current1->next;
        current2 = current2->next;
    }

    // Se ambas as pilhas chegaram ao final, elas são iguais
    return current1 == NULL && current2 == NULL;
}

//27 Função para intercalar duas pilhas em uma terceira pilha
struct Stack intercalaPilhas(struct Stack* stack1, struct Stack* stack2) {
    struct Stack resultado;
    criarPilha(&resultado);

    struct Node* current1 = stack1->top;
    struct Node* current2 = stack2->top;

    while (current1 != NULL || current2 != NULL) {
        if (current1 != NULL) {
            push(&resultado, current1->data);
            current1 = current1->next;
        }
        if (current2 != NULL) {
            push(&resultado, current2->data);
            current2 = current2->next;
        }
    }

    return resultado;
}

//28 Função para remover todas as ocorrências de um valor específico da pilha
void removeElementoEspecifico(struct Stack* stack, int valor) {
    struct Stack pilhaAuxiliar;
    criarPilha(&pilhaAuxiliar);

    while (!isEmpty(stack)) {
        int elemento = pop(stack);
        if (elemento != valor) {
            push(&pilhaAuxiliar, elemento);
        }
    }

    // Inverter a pilha auxiliar para restaurar a ordem original
    while (!isEmpty(&pilhaAuxiliar)) {
        int elemento = pop(&pilhaAuxiliar);
        push(stack, elemento);
    }
}

//29 Função para criar uma cópia invertida da pilha original
struct Stack copiaInvertidaPilha(struct Stack* stack) {
    struct Stack copiaInvertida;
    criarPilha(&copiaInvertida);

    struct Node* current = stack->top;
    while (current != NULL) {
        push(&copiaInvertida, current->data);
        current = current->next;
    }

    return copiaInvertida;
}



//30 Função para verificar se a pilha representa um palíndromo
bool pilhaEhPalindromo(struct Stack* stack) {
    struct Stack pilhaInvertida;
    criarPilha(&pilhaInvertida);

    struct Node* current = stack->top;

    // Inverte a pilha e armazena em pilhaInvertida
    while (current != NULL) {
        push(&pilhaInvertida, current->data);
        current = current->next;
    }

    current = stack->top;

    // Compara a pilha original com a pilha invertida
    while (current != NULL) {
        char originalData = current->data;
        char invertidaData = pop(&pilhaInvertida);

        if (originalData != invertidaData) {
            return false; // Não é um palíndromo
        }
        current = current->next;
    }

    return true; // É um palíndromo
}


int main() {
    struct Stack minhaPilha;
    criarPilha(&minhaPilha);

    // 1. Teste de push e peek
    push(&minhaPilha, 10);
    push(&minhaPilha, 20);
    push(&minhaPilha, 30);
    printf("1. Elemento no topo: %d\n", peek(&minhaPilha));

    // 2. Teste de empilha (empilha é chamado por push)
    empilha(&minhaPilha, 40);

    // 3. Teste de desempilha (desempilha é chamado por pop)
    desempilha(&minhaPilha);

    // 4. Teste de topoPilha
    printf("4. Elemento no topo: %d\n", topoPilha(&minhaPilha));

    // 5 e 25. Teste de tamanhoPilha
    printf("5 e 25. Tamanho da pilha: %d\n", tamanhoPilha(&minhaPilha));

    // 6. Teste de limpaPilha
    printf("6. Limpando a pilha...\n");
    limpaPilha(&minhaPilha);

    // Recria a pilha vazia para os próximos testes
    criarPilha(&minhaPilha);

    // Popula a pilha com valores para testes subsequentes
    push(&minhaPilha, 1);
    push(&minhaPilha, 2);
    push(&minhaPilha, 3);

    // 7 e 22. Teste de copiaPilha
    struct Stack copia = copiaPilha(&minhaPilha);
    printf("7 e 22. Elementos copiados da pilha original:\n");
    while (!isEmpty(&copia)) {
        printf("%d ", pop(&copia));
    }
    printf("\n");

    // 8. Teste de invertePilha
    printf("8. Invertendo a pilha...\n");
    invertePilha(&minhaPilha);

    // 9. Teste de calculaMediaPilha
    printf("9. Média dos valores na pilha: %.2f\n", calculaMediaPilha(&minhaPilha));

    // 10. Teste de concatenaPilhas
    struct Stack outraPilha;
    criarPilha(&outraPilha);
    push(&outraPilha, 100);
    push(&outraPilha, 200);
    push(&outraPilha, 300);
    printf("10. Concatenando pilhas...\n");
    concatenaPilhas(&minhaPilha, &outraPilha);

    // 11. Teste de invertePilhaSemUmaPilhaAuxiliar
    printf("11. Invertendo a pilha sem pilha auxiliar...\n");
    invertePilhaSemUmaPilhaAuxiliar(&minhaPilha);

    // 12. Teste de ordenaPilha (Bubble Sort)
    push(&minhaPilha, 50);
    push(&minhaPilha, 10);
    push(&minhaPilha, 30);
    printf("12. Ordenando a pilha...\n");
    ordenaPilha(&minhaPilha);

    // 13. Teste de copiaPilhaInvertida
    struct Stack copiaInvertida = copiaPilhaInvertida(&minhaPilha);
    printf("13. Elementos copiados e invertidos da pilha original:\n");
    while (!isEmpty(&copiaInvertida)) {
        printf("%d ", pop(&copiaInvertida));
    }
    printf("\n");

    // 14. Teste de mesclaPilhas
    struct Stack pilha1;
    criarPilha(&pilha1);
    push(&pilha1, 11);
    push(&pilha1, 22);
    struct Stack pilha2;
    criarPilha(&pilha2);
    push(&pilha2, 33);
    push(&pilha2, 44);
    struct Stack pilhaMesclada = mesclaPilhas(&pilha1, &pilha2);
    printf("14. Elementos mesclados de pilha1 e pilha2:\n");
    while (!isEmpty(&pilhaMesclada)) {
        printf("%d ", pop(&pilhaMesclada));
    }
    printf("\n");

    // 15. Teste de removeElementoPilha
    push(&minhaPilha, 30);
    push(&minhaPilha, 40);
    printf("15. Removendo o valor 30 da pilha...\n");
    removeElementoPilha(&minhaPilha, 30);

    // 16. Teste de copiaNPrimeirosElementos
    struct Stack copiaN = copiaNPrimeirosElementos(&minhaPilha, 2);
    printf("16. Copiando os primeiros 2 elementos da pilha original:\n");
    
    // 17. Teste de copiaElementosMaiores
    struct Stack maiores = copiaElementosMaiores(&minhaPilha, 30);
    printf("17. Copiando elementos maiores que 30 da pilha original:\n");
    while (!isEmpty(&maiores)) {
        printf("%d ", pop(&maiores));
    }
    printf("\n");

    // 18. Teste de copiaElementosMenores
    struct Stack menores = copiaElementosMenores(&minhaPilha, 30);
    printf("18. Copiando elementos menores que 30 da pilha original:\n");
    while (!isEmpty(&menores)) {
        printf("%d ", pop(&menores));
    }
    printf("\n");

    // 19. Teste de insereOrdenadoPilha
    insereOrdenadoPilha(&minhaPilha, 25);
    printf("19. Inserindo 25 de forma ordenada na pilha...\n");

    // 20. Teste de somaElementosPilha
    printf("20. Soma dos elementos na pilha: %d\n", somaElementosPilha(&minhaPilha));

    // 21. Teste de removeElementosPares
    push(&minhaPilha, 14);
    push(&minhaPilha, 15);
    printf("21. Removendo elementos pares da pilha...\n");
    removeElementosPares(&minhaPilha);

    // 23. Teste de inverteOrdemElementos
    printf("23. Invertendo a ordem dos elementos na pilha...\n");
    inverteOrdemElementos(&minhaPilha);

    // 24. Teste de comparaPilhas
    struct Stack pilha3;
    criarPilha(&pilha3);
    push(&pilha3, 1);
    push(&pilha3, 2);
    push(&pilha3, 3);
    printf("24. Comparando pilha original com pilha3: %d\n", comparaPilhas(&minhaPilha, &pilha3));

    // 26. Teste de intercalaPilhas
    struct Stack pilha4;
    criarPilha(&pilha4);
    push(&pilha4, 1000);
    push(&pilha4, 2000);
    struct Stack pilhaMesclada2 = intercalaPilhas(&minhaPilha, &pilha4);
    printf("26. Intercalei a pilha original com pilha4 e obtenha:\n");
    while (!isEmpty(&pilhaMesclada2)) {
        printf("%d ", pop(&pilhaMesclada2));
    }
    printf("\n");

    // 27. Teste de removeElementoEspecifico
    push(&minhaPilha, 25);
    push(&minhaPilha, 30);
    printf("27. Removendo o valor 25 da pilha...\n");
    removeElementoEspecifico(&minhaPilha, 25);

    // 28. Teste de copiaInvertidaPilha
    struct Stack pilhaInvertida2 = copiaInvertidaPilha(&minhaPilha);
    printf("28. Elementos copiados e invertidos da pilha original:\n");
    while (!isEmpty(&pilhaInvertida2)) {
        printf("%d ", pop(&pilhaInvertida2));
    }
    printf("\n");

    // 29. Teste de pilhaEhPalindromo
    struct Stack pilhaPalindromo;
    criarPilha(&pilhaPalindromo);
    push(&pilhaPalindromo, 1);
    push(&pilhaPalindromo, 2);
    push(&pilhaPalindromo, 1);
    printf("29. Verificando se a pilhaPalindromo é um palíndromo: %s\n", pilhaEhPalindromo(&pilhaPalindromo) ? "Sim" : "Não");

    return 0;
}
