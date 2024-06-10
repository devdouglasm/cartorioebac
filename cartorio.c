#include <stdio.h>  // biblioteca de comunicação com o usuário;
#include <stdlib.h> // biblioteca de alocação de espaço em memória;
#include <locale.h> // biblioteca de alocações de texto por região;
#include <string.h> // biblioteca responsável pelas string;

void registrar(void){ // função para cadastrar usuários no sistema;
    // criação das variáveis;
    char arquivo[40];
    char cpf[40];
    char nome[40];
    char sobrenome[40];
    char cargo[40];

    printf("Digite o CPF que será cadastrado: "); // coletando informação do usuário;
    scanf("%s", cpf); // armazenando o que o usuário digitou na variável cpf;

    strcpy(arquivo, cpf);

    FILE *file;                 // entra na "biblioteca" de arquivos FILE, e busca file;
    file = fopen(arquivo, "w"); // abre a pasta, procura o arquivo com nome "arquivo", e usa o "w" de write, para criar um arquivo com este nome;
    fprintf(file, "%s", cpf);   // escreve dentro do arquivo a variavel cpf;
    fclose(file);               // fecha o arquivo;

    file = fopen(arquivo, "a"); // abre o arquivo e usa o "a" para atualizar o arquivo;
    fprintf(file, ",");         // escreve dentro do arquivo uma virgula;
    fclose(file);

    printf("Digite o nome a ser cadastrado: ");
    scanf("%s", nome);

    file = fopen(arquivo, "a");
    fprintf(file, "%s", nome);
    fclose(file);

    file = fopen(arquivo, "a");
    fprintf(file, ",");
    fclose(file);

    printf("Digite o sobrenome a ser cadastrado: ");
    scanf("%s", sobrenome);

    file = fopen(arquivo, "a");
    fprintf(file, "%s", sobrenome);
    fclose(file);

    file = fopen(arquivo, "a");
    fprintf(file, ",");
    fclose(file);

    printf("Digite o cargo a ser cadastrado: ");
    scanf("%s", cargo);

    file = fopen(arquivo, "a");
    fprintf(file, "%s", cargo);
    fclose(file);

    getchar(); // da uma pause no sistema esperando o usuário clicar; substituindo o system("pause");
}

void consultar(void)
{

    setlocale(LC_ALL, "Portuguese"); // Definindo a linguagem

    char cpf[40];
    char conteudo[100];

    printf("Digite o CPF a ser consultado: ");
    scanf("%s", cpf);

    FILE *file;             // entra na "biblioteca" de arquivos FILE, e busca file;
    file = fopen(cpf, "r"); // abre a pasta e procura o arquivo cpf, e abre ele em forma de leitura "r" (reader);

    if (file == NULL)
    {
        printf("Não foi possivel abrir o arquivo, não localizado!\n");
        getchar();
    }

    while (fgets(conteudo, 200, file) != NULL)
    {
        printf("\nEssas são as informações do usuário: ");
        printf("%s", conteudo);
        printf("\n\n");
        getchar();
    }

    fclose(file); // sempre fechar o arquivo;
    getchar();
}

void deletar(void)
{

    char cpf[40];

    printf("Digite o CPF do usuário a ser deletado: ");
    scanf("%s", cpf);

    FILE *file;
    file = fopen(cpf, "r");

    if (file == NULL)
    {
        printf("O CPF do usuário não foi encontrado!\n");
        getchar();
    }
    else
    {
        remove(cpf);
        printf("O usuário foi removido com sucesso!\n");
        getchar();
    }
    fclose(file);
    getchar();
}

int main(void)
{

    int opcao = 0; // definindo variáveis
    int laco = 1;

    for (laco = 1; laco == 1;)
    {

        system("clear");

        setlocale(LC_ALL, "Portuguese"); // definindo a linguagem

        printf("### Cartório da EBAC ###\n\n"); // inicio do menu
        printf("Escolha a opção desejada do menu:\n\n");
        printf("\t1 - Registrar nomes\n");
        printf("\t2 - Consultar nomes\n");
        printf("\t3 - Deletar nomes\n\n\n");
        printf("Opção: "); // fim do menu

        scanf("%d", &opcao); // armanzenando a resposta do usuário;
        getchar();

        system("clear"); // limpar a tela (deletar msgs anteriores)

        switch (opcao)
        {
        case 1:
            registrar(); // chamando a função registrar;
            break;

        case 2:
            consultar(); // chamando a função consultar;
            break;

        case 3:
            deletar(); // chamando a função deletar;
            break;

        default:
            printf("Essa opção não existe\n\n\n");
            getchar();
            break;
        }

        printf("Esse software foi desenvolvido por dmdev\n");
    }
}
