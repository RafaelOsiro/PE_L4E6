/*
UNIVERSIDADE CATÓLICA DE BRASÍLIA
CURSO: ANÁLISE E DESENVOLVIMENTO DE SISTEMAS
DISCIPLINA: PROGRAMAÇÃO ESTRUTURADA
DOCENTE: JOYCE SIQUEIRA
DISCENTE: RAFAEL RIKI OGAWA OSIRO (UC21100716)

Exercício: 6. Definir a estrutura cuja representação gráfica é dada a seguir, definir os campos com os tipos 
básicos necessários
a) Crie um vetor Cadastro com 5 elementos.
b) Permita ao usuário entrar com dados para preencher esses 5 cadastros.
c) Encontre a pessoa com maior idade entre os cadastrados.
d) Encontre as pessoas do sexo masculino.
e) Encontre as pessoas com salário maior que 1000.
f) Imprima os dados da pessoa cuja identidade seja igual a um valor fornecido pelo usuário.
*/

// !LIBRARIES _________________________________________________________________________________________________
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<errno.h>
#include<stdbool.h>
#include<ctype.h>

//! STRUCTS ___________________________________________________________________________________________________
struct Endereco
{
    char rua[50];
    char bairro[50];
    char cidade[50];
    char estado[50];
    int cep;
};

struct Cadastro
{
    char nome[50];
    struct Endereco endereco;
    float salario;
    int identidade;
    int cpf;
    char estadoCivil[50];
    int telefone;
    int idade;
    char sexo[50];
};

//! MESSAGES OF THE SYSTEM ____________________________________________________________________________________
void messageTitle();
void messageMenu();
void messageNameInput(int index, int option);
void messageConfirmExit();
void messageExit();
void messageOlderUser(struct Cadastro *cadastros, int size);
void messageMaleUser(struct Cadastro *cadastros, int size);
void messageHighSalaryUser(struct Cadastro * cadastros, int size);
void messageFindUserByID(struct Cadastro * cadastros, int size);
void messageAskIDNumberInput();

//! ERROR MESSAGES OF THE SYSTEM ______________________________________________________________________________
void errorMessageInput(int quantityOfError, int option);
void errorExit();

//! VALIDATION INPUT __________________________________________________________________________________________
bool validationString(char *string);
bool validationNumber(int intNumber, float floatNumber, int option);

//! FUNCTION OF THE SYSTEM ____________________________________________________________________________________
int functionOptionInput();
void functionCleanBuffer(char *string, int size);
void functionInputUser(struct Cadastro *cadastros, int size);


int main()
{
    int option, quantityOfError = 0, size;
    struct Cadastro cadastros[2];
    bool validation = false, exitValidation = false;

    strcpy(cadastros[0].nome, "rafael");
    strcpy(cadastros[0].endereco.rua, "PQP");
    strcpy(cadastros[0].endereco.bairro, "do caralho");
    strcpy(cadastros[0].endereco.cidade, "Brasolia");
    strcpy(cadastros[0].endereco.estado, "Distrito Federel");
    cadastros[0].endereco.cep = 10;
    cadastros[0].salario = 1000.00;
    cadastros[0].identidade = 1;
    cadastros[0].cpf = 123;
    strcpy(cadastros[0].estadoCivil, "solteiro");
    cadastros[0].telefone = 999333;
    cadastros[0].idade = 10;
    strcpy(cadastros[0].sexo, "masculino");

    strcpy(cadastros[1].nome, "rodrigo");
    strcpy(cadastros[1].endereco.rua, "ashdkjas");
    strcpy(cadastros[1].endereco.bairro, "kkkk");
    strcpy(cadastros[1].endereco.cidade, "goiania");
    strcpy(cadastros[1].endereco.estado, "goias");
    cadastros[1].endereco.cep = 20;
    cadastros[1].salario = 2000.00;
    cadastros[1].identidade = 2;
    cadastros[1].cpf = 456;
    strcpy(cadastros[1].estadoCivil, "solteiro");
    cadastros[1].telefone = 1234;
    cadastros[1].idade = 20;
    strcpy(cadastros[1].sexo, "masculino");


    size = sizeof(cadastros)/sizeof(cadastros[0]);

    do
    {
        messageTitle();
        messageMenu();
        option = functionOptionInput();

        switch (option)
        {
        case 1:
            system("cls");
            quantityOfError = 0;
            functionInputUser(cadastros, size);
            break;

        case 2:
            system("cls");
            quantityOfError = 0;
            messageOlderUser(cadastros, size);
            break;

        case 3:
            system("cls");
            quantityOfError = 0;
            messageMaleUser(cadastros, size);
            break;
        case 4:
            system("cls");
            quantityOfError = 0;
            messageHighSalaryUser(cadastros, size);
            break;
        case 5:
            system("cls");
            quantityOfError = 0;
            messageFindUserByID(cadastros, size);
            break;

        case 6:
            system("cls");
            quantityOfError = 0;
            
            do
            {
                messageConfirmExit();
                option = functionOptionInput();

                if (option == 1)
                {
                    exitValidation = true;
                    validation = true; 
                }
                else if(option == 2)
                {
                    exitValidation = true;
                    validation = false;
                }
                else
                {
                    exitValidation = false;
                    system("cls");
                    quantityOfError++;
                    errorMessageInput(quantityOfError, 1);

                    if (quantityOfError == 3)
                    {
                        errorExit();
                        exit(EXIT_FAILURE);
                    }    
                }

            } while (exitValidation == false);


            system("cls");
            quantityOfError = 0;
            
            break;

        default:
            system("cls");
            quantityOfError++;
            errorMessageInput(quantityOfError, 1);

            if (quantityOfError == 3)
            {
                errorExit();
                exit(EXIT_FAILURE);
            }
            break;
        }
    
    } while (validation == false);
    
    messageExit();
    exit(EXIT_SUCCESS);
}

//! MESSAGES OF THE SYSTEM ____________________________________________________________________________________

//  MESSAGE TITLE OF THE SYSTEM
void messageTitle()
{
    printf("SISTEMA PARA FORMATAR OS NOMES\n\n\n");
}

//  MESSAGE MENU
void messageMenu()
{
    printf("---------------------------------\n");
    printf("[1] ENTRADA DOS DADOS DO CARROS\n");
    printf("[2] ENCONTRAR A MAIOR IDADE DOS CADASTRADOS\n");
    printf("[3] ENCONTRAR OS CADASTRADOS DO SEXO MASCULINO\n");
    printf("[4] ENCONTRAR OS CADASTRADOS COM SAL\265RIO MAIOR QUE R$1.000,00\n");
    printf("[5] ENCONTRAR OS CADASTRADOS PELA IDENTIDADE\n");
    printf("[6] SAIR DO PROGRAMA\n");
    printf("---------------------------------\n\n");
    printf("DIGITE A OP\200\307O DESEJADA: ");
}

//  MESSAGE ASK NAME INPUT
void messageNameInput(int index, int option)
{
    switch (option)
    {
    case 1:
        printf("DIGITE O NOME DA PESSOA %d: ", index);
        break;
    
    case 2:
        printf("DIGITE A RUA DA PESSOA %d: ", index);
        break;

    case 3:
        printf("DIGITE O BAIRRO DA PESSOA %d: ", index);
        break;

    case 4:
        printf("DIGITE A CIDADE DA PESSOA %d: ", index);
        break;

    case 5:
        printf("DIGITE O ESTADO DA PESSOA %d: ", index);
        break;

    case 6:
        printf("DIGITE O CEP DA PESSOA %d: ", index);
        break;

    case 7:
        printf("DIGITE O SAL\265RIO DA PESSOA %d: ", index);
        break;

    case 8:
        printf("DIGITE A IDENTIDADE DA PESSOA %d: ", index);
        break;

    case 9:
        printf("DIGITE O CPF DA PESSOA %d: ", index);
        break;

    case 10:
        printf("DIGITE O ESTADO CIVIL DA PESSOA %d: ", index);
        break;

    case 11:
        printf("DIGITE O TELEFONE DA PESSOA %d: ", index);
        break;

    case 12:
        printf("DIGITE A IDADE DA PESSOA %d: ", index);
        break;
    case 13:
        printf("DIGITE O SEXO DA PESSOA %d: ", index);
        break;
    default:
        break;
    }
}

//  MESSAGE ASK CONFIRM EXIT OF THE SYSTEM
void messageConfirmExit()
{
    printf("DESEJA CONFIRMAR A SA\326DA DO SISTEMA?\n\n");
    printf("-------\n");
    printf("[1] SIM\n");
    printf("[2] N\307O\n");
    printf("-------\n\n");
    printf("DIGITE A OP\200\307O DESEJADA: ");
}

//  MESSAGE TO EXIT SYSTEM
void messageExit()
{
    printf("O SISTEMA IR\265 FINALIZAR\n");
}

//  MESSAGE TO FIND AND PRINT OLDER USER
void messageOlderUser(struct Cadastro *cadastros, int size)
{
    int older = 0, aux;

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if(cadastros[i].idade > cadastros[j].idade)
            {
                if(cadastros[i].idade > older)
                {
                    older = cadastros[i].idade;
                    aux = i;
                }
            }
        }
    }

    printf("O USU\265RIO COM MAIOR IDADE \220: %s\n", cadastros[aux].nome);
    printf("ELE POSSUI %d ANOS!\n\n\n", cadastros[aux].idade);
    system("PAUSE");
    system("cls");
}

//  MESSAGE TO FIND MALE USER
void messageMaleUser(struct Cadastro *cadastros, int size)
{
    printf("USU\265RIOS DE SEXO MASCULINO\n\n\n");

    for (int i = 0; i < size; i++)
    {
        if ((strcmp(cadastros[i].sexo, "masculino")) == 0)
        {
            printf("%s\n\n\n", cadastros[i].nome);
        }
    }

    system("PAUSE");
    system("cls");
}

//  MESSAGE TO FIND USER WITH SALARY EQUAL OR HIGH THAN 1000
void messageHighSalaryUser(struct Cadastro * cadastros, int size)
{
    printf("USU\265RIOS COM SAL\265RIO MAIOR QUE R$1.000,00\n\n\n");

    for (int i = 0; i < size; i++)
    {
        if (cadastros[i].salario >= 1000)
        {
            printf("%s\n\n\n", cadastros[i].nome);
        }
    }

    system("PAUSE");
    system("cls");
}

//  MESSAGE TO FIND USER BY ID AND PRINT ALL ENROLL
void messageFindUserByID(struct Cadastro * cadastros, int size)
{
    int identidade, quantityOfError = 0;
    bool validation = false;

    do
    {
        messageAskIDNumberInput();
        scanf("%d", &identidade);
        validation = validationNumber(identidade, 0, 1);

        if (validation == false)
        {
            system("cls");
            quantityOfError++;
            errorMessageInput(quantityOfError, 2);

            if (quantityOfError == 3)
            {
                errorExit();
                exit(EXIT_FAILURE);
            }
        }
    } while (validation == false);
    
    quantityOfError = 0;

    printf("ENCONTRAR O USU\265RIO PELA IDENTIDADE\n\n\n");

    for (int i = 0; i < size; i++)
    {
        if (identidade == cadastros[i].identidade)
        {
            printf("NOME: %s\n", cadastros[i].nome);
            printf("ENDERECO: RUA %s BAIRRO %s CIDADE %s ESTADO %s CEP %d\n", cadastros[i].endereco.rua, cadastros[i].endereco.bairro, cadastros[i].endereco.cidade, cadastros[i].endereco.estado, cadastros[i].endereco.cep);
            printf("SAL\265RIO: %.2f\n", cadastros[i].salario);
            printf("IDENTIDADE: %d\n", cadastros[i].identidade);
            printf("CPF: %d\n", cadastros[i].cpf);
            printf("ESTADO CIVIL: %s\n", cadastros[i].estadoCivil);
            printf("TELEFONE: %d\n", cadastros[i].telefone);
            printf("IDADE: %d\n", cadastros[i].idade);
            printf("SEXO: %s\n\n\n", cadastros[i].sexo);   
        }
        break;
    }

    system("PAUSE");
    system("cls");
}

//  MESSAGE ASK ID NUMBER FOR INPUT
void messageAskIDNumberInput()
{
    printf("DIGITE O N\233MERO DA IDENTIDADE DO USU\265RIO: ");
}

//! ERROR MESSAGES OF THE SYSTEM ______________________________________________________________________________

//  ERROR MESSAGE INPUT
void errorMessageInput(int quantityOfError, int option)
{
    switch (option)
    {
    case 1:
        printf("ERRO %d de 3!\n", quantityOfError);
        printf("DIGITE UMA OP\200\307O V\265LIDA\n\n\n");
        break;
    
    case 2:
        printf("ERRO %d de 3!\n", quantityOfError);
        printf("DIGITE UM NOME V\265LIDO\n\n\n");
        break;

    case 3:
        printf("ERRO %d de 3!\n", quantityOfError);
        printf("DIGITE UM N\351MERO V\265LIDO\n\n\n");
        break;

    default:
        break;
    }
}

//  ERROR EXIT SYSTEM
void errorExit()
{
    printf("QUANTIDADE DE ERROS ATINGIDO!\n");
    printf("O SISTEMA IR\265 FINALIZAR!\n\n\n");
}

//! VALIDATION INPUT __________________________________________________________________________________________

//  FUNCTION TO VALIDATE A STRING
bool validationString(char *string)
{
    int index = 0;

    if (strlen(string) == 1)
    {
        if (string[index] == "\n" || string[index] == " " || string[index] == '\0' || string[index] == '\r' || 
        string[index] == '\r\n' || !isalpha(string[index] || !isdigit(string[index])))
        {
            return false;
        }
    }
    else
    {
        while (index < strlen(string))
        {
            if (string[index] != "\n" && string[index] != " " && string[index] != '\0' && string[index] != '\r' && 
            string[index] != '\r\n' && !isspace(string[index]) && (isalpha(string[index]) || isdigit(string[index])))
            {
                return true;
            }
            index++;
        }

        return false;
    }

    return false;
}

//  FUNCTION TO VALIDATE A NUMBER
bool validationNumber(int intNumber, float floatNumber, int option)
{
    switch (option)
    {
    case 1:
        if (intNumber >= 0)
        {
            return true;
        }
        else
        {
            return false;
        }
        break;
    
    case 2:
        if (floatNumber < 0)
        {
            return false;
        }
        else if (floatNumber >= 0)
        {
            return true;
        }
        else
        {
            return false;
        }
        break;

    default:
        return false;
        break;
    }
}

//! FUNCTION OF THE SYSTEM ____________________________________________________________________________________

//  FUNCTION OPTION INPUT
int functionOptionInput()
{
    int number;

    fflush(stdin);
    scanf("%d", &number);

    return number;
}

//  FUNCTION TO CLEAN EXTRA CHARACTERE IN BUFFER
void functionCleanBuffer(char *string, int size)
{
    if (strlen(string) == (size-1))
    {
        char charactere;
        while ((charactere = getchar()) != '\n' && charactere != EOF);
    }
    else
    {
        int i = strlen(string);
        string[i-1] = '\0';
    }
}

//  FUNCTION INPUT STRING
void functionInputUser(struct Cadastro *cadastros, int size)
{
    int quantityOfError = 0;
    bool validation = false;

    for (int i = 0; i < size; i++)
    {
        while (validation == false) //  NOME
        {
            messageTitle();
            messageNameInput(i+1, 1);
            fflush(stdin);
            fgets(cadastros[i].nome, sizeof(cadastros[i].nome), stdin);
            validation = validationString(cadastros[i].nome);

            functionCleanBuffer(cadastros[i].nome, size);

            if (validation == false)
            {
                system("cls");
                quantityOfError++;
                errorMessageInput(quantityOfError, 2);

                if (quantityOfError == 3)
                {
                    errorExit();
                    exit(EXIT_FAILURE);
                }
            }
        }

        system("cls");
        validation = false;

        while (validation == false) //  ENDERECO - > RUA
        {
            messageTitle();
            messageNameInput(i+1, 2);
            fflush(stdin);
            fgets(cadastros[i].endereco.rua, sizeof(cadastros[i].endereco.rua), stdin);
            validation = validationString(cadastros[i].endereco.rua);

            functionCleanBuffer(cadastros[i].endereco.rua, sizeof(cadastros[i].endereco.rua));            

            if (validation == false)
            {
                system("cls");
                quantityOfError++;
                errorMessageInput(quantityOfError, 2);

                if (quantityOfError == 3)
                {
                    errorExit();
                    exit(EXIT_FAILURE);
                }
            }
        }

        system("cls");
        validation = false;

        while (validation == false) //  ENDERECO - > BAIRRO
        {
            messageTitle();
            messageNameInput(i+1, 3);
            fflush(stdin);
            fgets(cadastros[i].endereco.bairro, sizeof(cadastros[i].endereco.bairro), stdin);
            validation = validationString(cadastros[i].endereco.bairro);

            functionCleanBuffer(cadastros[i].endereco.bairro, sizeof(cadastros[i].endereco.bairro));

            if (validation == false)
            {
                system("cls");
                quantityOfError++;
                errorMessageInput(quantityOfError, 2);

                if (quantityOfError == 3)
                {
                    errorExit();
                    exit(EXIT_FAILURE);
                }
            }
        }

        system("cls");
        validation = false;
        
        while (validation == false) //  ENDERECO - > CIDADE
        {
            messageTitle();
            messageNameInput(i+1, 4);
            fflush(stdin);
            fgets(cadastros[i].endereco.cidade, sizeof(cadastros[i].endereco.cidade), stdin);
            validation = validationString(cadastros[i].endereco.cidade);

            functionCleanBuffer(cadastros[i].endereco.cidade, sizeof(cadastros[i].endereco.cidade));

            if (validation == false)
            {
                system("cls");
                quantityOfError++;
                errorMessageInput(quantityOfError, 3);

                if (quantityOfError == 3)
                {
                    errorExit();
                    exit(EXIT_FAILURE);
                }
            }
        }

        system("cls");
        validation = false;
        
        while (validation == false) //  ENDERECO - > ESTADO
        {
            messageTitle();
            messageNameInput(i+1, 5);
            fflush(stdin);
            fgets(cadastros[i].endereco.estado, sizeof(cadastros[i].endereco.estado), stdin);
            validation = validationString(cadastros[i].endereco.estado);

            functionCleanBuffer(cadastros[i].endereco.estado, sizeof(cadastros[i].endereco.estado));

            if (validation == false)
            {
                system("cls");
                quantityOfError++;
                errorMessageInput(quantityOfError, 3);

                if (quantityOfError == 3)
                {
                    errorExit();
                    exit(EXIT_FAILURE);
                }
            }
        }

        system("cls");
        validation = false;

        while (validation == false) //  ENDERECO - > CEP
        {
            messageTitle();
            messageNameInput(i+1, 6);
            fflush(stdin);
            scanf("%d", &cadastros[i].endereco.cep);
            
            validation = validationNumber(cadastros[i].endereco.cep, 0, 1);

            if (validation == false)
            {
                system("cls");
                quantityOfError++;
                errorMessageInput(quantityOfError, 3);

                if (quantityOfError == 3)
                {
                    errorExit();
                    exit(EXIT_FAILURE);
                }
            }
        }

        system("cls");
        validation = false;

        while (validation == false) //  SALARIO
        {
            messageTitle();
            messageNameInput(i+1, 7);
            fflush(stdin);
            scanf("%f", &cadastros[i].salario);

            validation = validationNumber(0, cadastros[i].salario, 2);

            if (validation == false)
            {
                system("cls");
                quantityOfError++;
                errorMessageInput(quantityOfError, 3);

                if (quantityOfError == 3)
                {
                    errorExit();
                    exit(EXIT_FAILURE);
                }
            }
        }

        system("cls");
        validation = false;

        while (validation == false) //  IDENTIDADE
        {
            messageTitle();
            messageNameInput(i+1, 8);
            fflush(stdin);
            scanf("%d", &cadastros[i].identidade);

            validation = validationNumber(cadastros[i].identidade, 0, 2);
            if (validation == false)
            {
                system("cls");
                quantityOfError++;
                errorMessageInput(quantityOfError, 3);

                if (quantityOfError == 3)
                {
                    errorExit();
                    exit(EXIT_FAILURE);
                }
            }
        }

        system("cls");
        validation = false;

        while (validation == false) //  CPF
        {
            messageTitle();
            messageNameInput(i+1, 9);
            fflush(stdin);
            scanf("%d", &cadastros[i].cpf);

            validation = validationNumber(cadastros[i].cpf, 0, 2);
            if (validation == false)
            {
                system("cls");
                quantityOfError++;
                errorMessageInput(quantityOfError, 3);

                if (quantityOfError == 3)
                {
                    errorExit();
                    exit(EXIT_FAILURE);
                }
            }
        }

        system("cls");
        validation = false;

        while (validation == false) //  ESTADO CIVIL
        {
            messageTitle();
            messageNameInput(i+1, 10);
            fflush(stdin);
            fgets(cadastros[i].estadoCivil, sizeof(cadastros[i].estadoCivil), stdin);
            validation = validationString(cadastros[i].estadoCivil);

            functionCleanBuffer(cadastros[i].estadoCivil, sizeof(cadastros[i].estadoCivil));

            if (validation == false)
            {
                system("cls");
                quantityOfError++;
                errorMessageInput(quantityOfError, 3);

                if (quantityOfError == 3)
                {
                    errorExit();
                    exit(EXIT_FAILURE);
                }
            }
        }

        system("cls");
        validation = false;

        while (validation == false) //  TELEFONE
        {
            messageTitle();
            messageNameInput(i+1, 11);
            fflush(stdin);
            scanf("%d", &cadastros[i].telefone);

            validation = validationNumber(cadastros[i].telefone, 0, 1);

            if (validation == false)
            {
                system("cls");
                quantityOfError++;
                errorMessageInput(quantityOfError, 3);

                if (quantityOfError == 3)
                {
                    errorExit();
                    exit(EXIT_FAILURE);
                }
            }
        }

        system("cls");
        validation = false;

        while (validation == false) //  IDADE
        {
            messageTitle();
            messageNameInput(i+1, 12);
            fflush(stdin);
            scanf("%d", &cadastros[i].idade);

            validation = validationNumber(cadastros[i].idade, 0, 1);

            if (validation == false)
            {
                system("cls");
                quantityOfError++;
                errorMessageInput(quantityOfError, 3);

                if (quantityOfError == 3)
                {
                    errorExit();
                    exit(EXIT_FAILURE);
                }
            }
        }

        system("cls");
        validation = false;

        while (validation == false) //  SEXO
        {
            messageTitle();
            messageNameInput(i+1, 13);
            fflush(stdin);
            fgets(cadastros[i].sexo, sizeof(cadastros[i].sexo), stdin);
            
            validation = validationString(cadastros[i].sexo);

            if (validation == false)
            {
                system("cls");
                quantityOfError++;
                errorMessageInput(quantityOfError, 3);

                if (quantityOfError == 3)
                {
                    errorExit();
                    exit(EXIT_FAILURE);
                }
            }
        }

        system("cls");
        validation = false;
    }
}