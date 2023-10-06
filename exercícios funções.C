#include <stdio.h>
#include <stdbool.h>
#include <string.h>
 
//exercicios funções
  
//1
int soma (int a, int b)
{
int s = a + b; 
return s;
}

//2  
void trocar (int *a, int *b){
int m;
m = *a;
*a = *b;
*b = m;
} 

// 3
int media (int vetor[], int l){
int m = 0;
for (int i = 0; i < l; i++){
	m += vetor[i];
    } 
return m / l;
}

// 4
int maximo (int vetor[], int l){
int t = 0;
for (int i = 0; i < l; i++){
if (t <= vetor[i]){ 
    t = vetor[i];
    }
}
return t;
}

// 5
void inverter (char *str){
int tamanho = strlen (str);
for (int i = 0,int j = tamanho - 1; i < j; i++, j--){
    char temp = str[i];
    str[i] = str[j];
    str[j] = temp;
    } 
} 
 
//6
int somaMatriz (int vetor[], int l){
int t = 0;
for (int i = 0; i < l; i++){
    t += vetor[i];
    } 
return t;
}
 
//7
void copiaString(char destino[], const char origem[]) {
    strcpy(destino, origem);
}
   
//8
  void
ordenaArray (int array[], int tamanho){
int temp;
for (int i = 0; i < tamanho - 1; i++){
    for (int j = 0; j < tamanho - i - 1; j++){
        if (array[j] > array[j + 1]){
		    temp = array[j];
            array[j] = array[j + 1];
            array[j + 1] = temp;
        }
    }
}
}

//9
int fatorial(int n) {
    if (n <= 1) {
        return 1;
    }
    return n * fatorial(n - 1);
}

//12
int calculaPotencia(int base, int expoente) {
    if (expoente == 0) {
        return 1;
    }
    int resultado = 1;
    for (int i = 0; i < expoente; i++) {
        resultado *= base;
    }
    return resultado;
}

//13
void inverteArray(int array[], int tamanho) {
    int inicio = 0;
    int fim = tamanho - 1;
    while (inicio < fim) {
        int temp = array[inicio];
        array[inicio] = array[fim];
        array[fim] = temp;
        inicio++;
        fim--;
    }
}

//14
int calculaMDC(int a, int b) {
    if (b == 0) {
        return a;
    }
    return calculaMDC(b, a % b);
}

//15
int calculaFibonacci(int n) {
    if (n <= 1) {
        return n;
    }
    int fib[n + 1];
    fib[0] = 0;
    fib[1] = 1;
    for (int i = 2; i <= n; i++) {
        fib[i] = fib[i - 1] + fib[i - 2];
    }
    return fib[n];
}
 
 //16
 int contaCaracteres(const char *str, char caractere) {
    int contador = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == caractere) {
            contador++;
        }
    }
    return contador;
}
 
 //17
 double calculaMediaMatriz(int matriz[][3], int linhas, int colunas) {
    double soma = 0.0;
    int elementos = linhas * colunas;
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            soma += matriz[i][j];
        }
    }
    return soma / elementos;
}

 //18
 void invertePalavra(char *palavra) {
    int tamanho = strlen(palavra);
    int i, j;
    for (i = 0, j = tamanho - 1; i < j; i++, j--) {
        char temp = palavra[i];
        palavra[i] = palavra[j];
        palavra[j] = temp;
    }
}

//19
double calculaMediaPonderada(const double notas[], const double pesos[], int tamanho) {
    double soma_notas = 0.0;
    double soma_pesos = 0.0;
    
    for (int i = 0; i < tamanho; i++) {
        soma_notas += notas[i] * pesos[i];
        soma_pesos += pesos[i];
    }
    
    if (soma_pesos == 0) {
        return 0.0; // Para evitar divisão por zero
    }
    
    return soma_notas / soma_pesos;
}

//20
void maiorMenor(int array[], int tamanho, int *maior, int *menor) {
    if (tamanho == 0) {
        *maior = *menor = 0;
        return;
    }
    
    *maior = *menor = array[0];
    
    for (int i = 1; i < tamanho; i++) {
        if (array[i] > *maior) {
            *maior = array[i];
        }
        if (array[i] < *menor) {
            *menor = array[i];
        }
    }
}


//21
void calculaSomaMedia(int array[], int tamanho, int *soma, double *media) {
    *soma = 0;
    for (int i = 0; i < tamanho; i++) {
        *soma += array[i];
    }
    
    if (tamanho == 0) {
        *media = 0.0;
    } else {
        *media = (double)(*soma) / tamanho;
    }
}

//22
void inverteMatriz(int matriz[][3], int linhas, int colunas) {
    for (int i = 0; i < linhas / 2; i++) {
        for (int j = 0; j < colunas; j++) {
            int temp = matriz[i][j];
            matriz[i][j] = matriz[linhas - 1 - i][j];
            matriz[linhas - 1 - i][j] = temp;
        }
    }
}

//23
int contaPalavras(const char *str) {
    int contador = 0;
    bool dentroDaPalavra = false;
    
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == ' ' || str[i] == '\t' || str[i] == '\n') {
            dentroDaPalavra = false;
        } else if (!dentroDaPalavra) {
            dentroDaPalavra = true;
            contador++;
        }
    }
    
    return contador;
}

//24
int calculaMaiorProduto(int array[], int tamanho) {
    if (tamanho < 2) {
        return 0; // Não há dois elementos para calcular o produto
    }
    
    int maiorProduto = array[0] * array[1];
    
    for (int i = 0; i < tamanho; i++) {
        for (int j = i + 1; j < tamanho; j++) {
            int produto = array[i] * array[j];
            if (produto > maiorProduto) {
                maiorProduto = produto;
            }
        }
    }
    
    return maiorProduto;
}

//25
bool verificaPalindromo(const char *str) {
    int esquerda = 0;
    int direita = strlen(str) - 1;
    
    while (esquerda < direita) {
        if (str[esquerda] != str[direita]) {
            return false; // Não é um palíndromo
        }
        esquerda++;
        direita--;
    }
    
    return true; // É um palíndromo
}

//26
void copiaMatriz(int matriz[][3], int linhas, int colunas, int matriz_copia[][3]) {
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            matriz_copia[i][j] = matriz[i][j];
        }
    }
}

//27
 int contaCaracteresUnicos(const char *str) {
    int caracteres[256] = {0}; // Assumindo codificação ASCII
    
    int contador = 0;
    
    for (int i = 0; str[i] != '\0'; i++) {
        int valorAscii = (int)str[i];
        if (caracteres[valorAscii] == 0) {
            caracteres[valorAscii] = 1;
            contador++;
        }
    }
    
    return contador;
}
 
 
int main() {
    // Exercício 1: Soma
    int resultado_soma = somaque(5, 3);
    printf("Exercício 1: Soma(5, 3) = %d\n", resultado_soma);

    // Exercício 2: Trocar
    int a = 6, b = 9;
    printf("Exercício 2: Antes da troca: a=%d, b=%d\n", a, b);
    trocar(&a, &b);
    printf("Exercício 2: Após a troca: a=%d, b=%d\n", a, b);

    // Exercício 3: Média
    int valores_media[] = {10, 20, 30, 40, 50};
    int tamanho_media = sizeof(valores_media) / sizeof(valores_media[0]);
    double resultado_media = media(valores_media, tamanho_media);
    printf("Exercício 3: Média = %.2f\n", resultado_media);

    // Exercício 4: Máximo
    int valores_maximo[] = {5, 2, 10, 3};
    int tamanho_maximo = sizeof(valores_maximo) / sizeof(valores_maximo[0]);
    int resultado_maximo = maximo(valores_maximo, tamanho_maximo);
    printf("Exercício 4: Valor máximo = %d\n", resultado_maximo);

    // Exercício 5: Inverter String
    char minhaString[] = "OpenAI";
    printf("Exercício 5: Antes da inversão: %s\n", minhaString);
    inverter(minhaString);
    printf("Exercício 5: Após a inversão: %s\n", minhaString);

     // Exercício 6: Soma dos Elementos de uma Matriz
    int matriz[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int linhas = 3;
    int colunas = 3;
    int soma = somaMatriz(matriz, linhas, colunas);
    printf("Exercício 6: Soma dos elementos da matriz = %d\n", soma);

    // Exercício 7: Copiar String
    char origem[] = "Copiar esta string.";
    char destino[50]; // Deve ser grande o suficiente para conter a cópia.
    copiaString(origem, destino);
    printf("Exercício 7: String copiada: %s\n", destino);

    // Exercício 8: Ordenar Array
    int array[] = {5, 2, 10, 3};
    int tamanho = sizeof(array) / sizeof(array[0]);
    ordenaArray(array, tamanho);
    printf("Exercício 8: Array ordenado: ");
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    // Exercício 9: Fatorial
    int numero = 5;
    int fatorial = calculaFatorial(numero);
    printf("Exercício 9: Fatorial de %d = %d\n", numero, fatorial);

      // Exercício 11: Potência
    int base = 2;
    int expoente = 4;
    int resultado_potencia = calculaPotencia(base, expoente);
    printf("Exercício 11: %d elevado a %d = %d\n", base, expoente, resultado_potencia);

    // Exercício 12: Inverter Array
    int array_inverter[] = {1, 2, 3, 4, 5};
    int tamanho_inverter = sizeof(array_inverter) / sizeof(array_inverter[0]);
    printf("Exercício 12: Array antes da inversão: ");
    for (int i = 0; i < tamanho_inverter; i++) {
        printf("%d ", array_inverter[i]);
    }
    printf("\n");
    inverteArray(array_inverter, tamanho_inverter);
    printf("Exercício 12: Array após a inversão: ");
    for (int i = 0; i < tamanho_inverter; i++) {
        printf("%d ", array_inverter[i]);
    }
    printf("\n");

    // Exercício 13: MDC (Máximo Divisor Comum)
    int numero1 = 24;
    int numero2 = 36;
    int resultado_mdc = calculaMDC(numero1, numero2);
    printf("Exercício 13: MDC de %d e %d = %d\n", numero1, numero2, resultado_mdc);

    // Exercício 14: Fibonacci
    int posicao_fibonacci = 6;
    int resultado_fibonacci = calculaFibonacci(posicao_fibonacci);
    printf("Exercício 14: Fibonacci na posição %d = %d\n", posicao_fibonacci, resultado_fibonacci);

    // Exercício 15: Contar Caracteres
    const char *texto_contar = "banana";
    char caractere_contar = 'a';
    int resultado_contar = contaCaracteres(texto_contar, caractere_contar);
    printf("Exercício 15: O caractere '%c' aparece %d vezes na string.\n", caractere_contar, resultado_contar);

    // Exercício 16: Média de Matriz
    int matriz_media[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int linhas_media = 3;
    int colunas_media = 3;
    double resultado_media_matriz = calculaMediaMatriz(matriz_media, linhas_media, colunas_media);
    printf("Exercício 16: Média dos elementos da matriz = %.2f\n", resultado_media_matriz);

    // Exercício 17: Inverter Palavra
    char palavra_inverter[] = "OpenAI";
    printf("Exercício 17: Palavra antes da inversão: %s\n", palavra_inverter);
    invertePalavra(palavra_inverter);
    printf("Exercício 17: Palavra após a inversão: %s\n", palavra_inverter);

      // Exercício 18: Média Ponderada
    int notas[] = {80, 90, 75, 88};
    int pesos[] = {2, 2, 1, 3};
    int tamanho = sizeof(notas) / sizeof(notas[0]);
    double media_ponderada = calculaMediaPonderada(notas, pesos, tamanho);
    printf("Exercício 18: Média ponderada = %.2f\n", media_ponderada);

    // Exercício 19: Maior e Menor Valor no Array
    int valores[] = {42, 7, 13, 24, 56, 89, 4};
    int tamanho_valores = sizeof(valores) / sizeof(valores[0]);
    int maior, menor;
    maiorMenor(valores, tamanho_valores, &maior, &menor);
    printf("Exercício 19: Maior valor no array = %d\n", maior);
    printf("Exercício 19: Menor valor no array = %d\n", menor);

    // Exercício 20: Soma e Média de Valores em um Array
    int array_valores[] = {10, 20, 30, 40, 50};
    int tamanho_array = sizeof(array_valores) / sizeof(array_valores[0]);
    int soma_valores;
    double media_valores;
    somaMediaArray(array_valores, tamanho_array, &soma_valores, &media_valores);
    printf("Exercício 20: Soma dos valores no array = %d\n", soma_valores);
    printf("Exercício 20: Média dos valores no array = %.2f\n", media_valores);

    // Exercício 21: Inverter Matriz
    int matriz_inverter[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int linhas_inverter = 3;
    int colunas_inverter = 3;
    inverteMatriz(matriz_inverter, linhas_inverter, colunas_inverter);
    printf("Exercício 21: Matriz invertida:\n");
    for (int i = 0; i < linhas_inverter; i++) {
        for (int j = 0; j < colunas_inverter; j++) {
            printf("%d ", matriz_inverter[i][j]);
        }
        printf("\n");
    }

    // Exercício 22: Contar Palavras em uma String
    const char *frase = "abacate e uma fruta";
    int contador_palavras = contaPalavras(frase);
    printf("Exercício 22: Número de palavras na frase = %d\n", contador_palavras);

    // Exercício 23: Contar Palavras
    const char *frase = "Esta é uma frase de exemplo.";
    int resultado_conta_palavras = contaPalavras(frase);
    printf("Exercício 23: Número de palavras na frase: %d\n", resultado_conta_palavras);

    // Exercício 24: Maior Produto
    int valores_produto[] = {5, 2, 10, 3};
    int tamanho_produto = sizeof(valores_produto) / sizeof(valores_produto[0]);
    int resultado_produto = calculaMaiorProduto(valores_produto, tamanho_produto);
    printf("Exercício 24: Maior produto entre dois elementos = %d\n", resultado_produto);

    // Exercício 25: Verificar Palíndromo
    const char *palindromo = "radar";
    bool resultado_palindromo = verificaPalindromo(palindromo);
    if (resultado_palindromo) {
        printf("Exercício 25: A string é um palíndromo.\n");
    } else {
        printf("Exercício 25: A string não é um palíndromo.\n");
    }

    // Exercício 26: Copiar Matriz
    int minhaMatriz[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int linhas_matriz = 3;
    int colunas_matriz = 3;
    int minhaMatrizCopia[3][3];
    copiaMatriz(minhaMatriz, linhas_matriz, colunas_matriz, minhaMatrizCopia);
    printf("Exercício 26: Matriz original:\n");
    for (int i = 0; i < linhas_matriz; i++) {
        for (int j = 0; j < colunas_matriz; j++) {
            printf("%d ", minhaMatriz[i][j]);
        }
        printf("\n");
    }
    printf("Exercício 26: Matriz cópia:\n");
    for (int i = 0; i < linhas_matriz; i++) {
        for (int j = 0; j < colunas_matriz; j++) {
            printf("%d ", minhaMatrizCopia[i][j]);
        }
        printf("\n");
    }

    // Exercício 27: Contar Caracteres Únicos
    const char *texto_caracteres_unicos = "abbcccdeeff";
    int resultado_caracteres_unicos = contaCaracteresUnicos(texto_caracteres_unicos);
    printf("Exercício 27: Número de caracteres únicos na string: %d\n", resultado_caracteres_unicos);

    return 0;
}
