#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Desafio Super Trunfo - Países
// Tema 1 - Cadastro das Cartas
// Este código inicial serve como base para o desenvolvimento do sistema de cadastro de cartas de cidades.
// Siga os comentários para implementar cada parte do desafio.
//Teste larissa

typedef struct {
    char name[50];                                  // Nome das cidades
    int populacao;                                  // População
    int area;                                       // Área
    int pib;                                        // PIB
    int numeroPontoTuristico;                       // Número de pontos turísticos. 
} Cidade;

typedef struct {
    char name[50];                                   // Nome do estado
    Cidade *cidades;                                  // Ponteiro para a cidades
} Estado;                                            // Aqui contem tanto o nome do estado quanto as cidades relacionadas a esse estado.

typedef struct {
    char name[50];                                  // Nome do País
    Estado *estados;                                 // Ponteiro para os estados (alocação dinâmica) ou seja "Estado" é o tipo e "estado" é a variavel.
} Pais;                                             // Nesse formato a estrutura contem tanto o nome do país quanto aponto para os estados relacionado a esse país. Ficando mais facil gerenciar.

//Remover o /n que causa o erro quando dou enter pulando a linha de código
void removerOEnter(char *enter){
    enter[strcspn(enter, "\n")] = 0;               // strcspn forma elegante para averiguar o \n sem precisar fazer um loop explicito
}

//Função de cadastro dos países.
Pais cadastroDePais(){                            // Não requer parametros pois o cadastro será feito mediante um for.
    Pais pais;                                    //Declarando a variavel pais com o Typo de dado País, que se refere a função struct
    
    printf("\nDigite aqui o nome do país: ");
    fgets(pais.name, sizeof(pais.name), stdin);   // 1° parametro sera a variavel que recebera o nome do pais, 2° é para que o fgets não tente ler mais que os 50 caracteres já especificado, 3° fala o tipo de entrada de dado que sera o teclado. 
    removerOEnter(pais.name);                     // O fgets ao final adiciona \n que em str pode dar problemas, por isso a função de remoção de \n

    // Fazer a devida alocação na memória para os estados
    pais.estados = (Estado*)malloc(8 * sizeof(Estado)); // O malloc tem um ponteiro do tipo *avoid, então fazemos a conversão de tipo explicitamente para o tipo Estado, em seguida usa-se a função malloc para alocação dinâmica de memória, e por fim especifica o tamanho de bytes para garantir espaço suficiênte para alocar 8 estrutura do tipo estado.

    // Criar o loop para cadastro dos estados
    for (int i=0; i<8; i++) {

        printf("\nColoque a sigla do Estado %d do País %s: ", i + 1, pais.name);
        fgets(pais.estados[i].name, sizeof(pais.estados[i].name), stdin);
        removerOEnter(pais.estados[i].name);

        // alocar a memória para as cidades
        pais.estados[i].cidades = (Cidade*)malloc(4 * sizeof(Cidade));

        // Loop para adicionar as cidades
        for (int j=0; j<4; j++) {
            printf("\nDigite o nome da Cidade %d pertencente ao Estado %s", j + 1, pais.estados[i].name);
            fgets(pais.estados[i].cidades[j].name, sizeof(pais.estados[i].cidades[j].name), stdin);
            removerOEnter(pais.estados[i].cidades[j].name);

            printf("\nDigite o número populacional pertencente da Cidade %s do Estado %s: ", pais.estados[i].cidades[j].name, pais.estados[i]);
            fgets(pais.estados[i].cidades[j].populacao, sizeof(pais.estados[i].cidades[j].populacao), stdin);

            printf("\nDigite a área da Cidade %s pertencente ao Estado %s: ", pais.estados[i].cidades[j].name, pais.estados[i]);
            fgets(pais.estados[i].cidades[j].area, sizeof(pais.estados[i].cidades[j].area), stdin);

            printf("\nDigite o PIB da Cidade %s pertencente ao Estado %s: ", pais.estados[i].cidades[j], pais.estados[i]);
            fgets(pais.estados[i].cidades[j].pib, sizeof(pais.estados[i].cidades[j].pib), stdin);

            printf("\nDigite o número de pontos turísticos da Cidade %s pertencente ao Estado %s: ", pais.estados[i].cidades[j].name, pais.estados[i]);
            fgets(pais.estados[i].cidades[j].numeroPontoTuristico, sizeof(pais.estados[i].cidades[j].numeroPontoTuristico), stdin);


        }

    }
    return pais;
}





int main() {
    // Sugestão: Defina variáveis separadas para cada atributo da cidade.
    // Exemplos de atributos: código da cidade, nome, população, área, PIB, número de pontos turísticos.
    
    // Cadastro das Cartas:
    // Sugestão: Utilize a função scanf para capturar as entradas do usuário para cada atributo.
    // Solicite ao usuário que insira as informações de cada cidade, como o código, nome, população, área, etc.
    
    // Exibição dos Dados das Cartas:
    // Sugestão: Utilize a função printf para exibir as informações das cartas cadastradas de forma clara e organizada.
    // Exiba os valores inseridos para cada atributo da cidade, um por linha.

    return 0;
}
