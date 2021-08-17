#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#define nFuncionarios 2

typedef struct funcionario
    {
        char nome[100];
        struct end
        {
            char rua[50], comp[50], bairro[50], cidade[50];
            int num;
        } endereco;
        char cpf[20];
        char dtnasc[20];
        char temdepend[10];
        char sexo[20];
        struct horastrab
        {
            int semana1, semana2, semana3;
        } horastrabalhadas;
    } FUNCIONARIO;

void preencheFormulario(FUNCIONARIO v[nFuncionarios])
{
    for(int i = 0; i < nFuncionarios; i++)
    {
        fflush(stdin);
        printf("\n");
        printf("Digite o nome do funcionário: ");
        fgets(v[i].nome, 50, stdin);
        printf("Digite o endereço da rua em que o funcionário mora: ");
        fgets(v[i].endereco.rua, 50, stdin);
        printf("Digite o complemento do endereço do funcionário: ");
        fgets(v[i].endereco.comp, 50, stdin);
        printf("Digite o bairro em que o funcionário mora: ");
        fgets(v[i].endereco.bairro, 50, stdin);
        printf("Digite a cidade em que o funcionário mora: ");
        fgets(v[i].endereco.cidade, 50, stdin);
        printf("Digite o número da casa do funcionário: ");
        scanf("%i", &v[i].endereco.num);
        printf("Digite o cpf do funcionário: ");
        fflush(stdin);
        fgets(v[i].cpf, 20, stdin);
        printf("Digite a data de nascimento do funcionário(formato: dd/mm/aaaa): ");
        fgets(v[i].dtnasc, 20, stdin);
        printf("Digite se o funcionário possui dependentes(s/n): ");
        fgets(v[i].temdepend, 10, stdin);
        printf("Digite o sexo do funcionário: ");
        fgets(v[i].sexo, 20, stdin);
        printf("Digite as horas trabalhadas na semana1 pelo funcionário: ");
        scanf("%i", &v[i].horastrabalhadas.semana1);
        printf("Digite as horas trabalhadas na semana2 pelo funcionário: ");
        scanf("%i", &v[i].horastrabalhadas.semana2);
        printf("Digite as horas trabalhadas na semana3 pelo funcionário: ");
        scanf("%i", &v[i].horastrabalhadas.semana3);
    }
}

void imprimeFuncionario(FUNCIONARIO v[nFuncionarios])
{
    for(int i = 0; i < nFuncionarios; i++)
    {
        printf("\nNome: %s", v[i].nome);
        printf("Endereço: %s", v[i].endereco.rua);
        printf("Complemento: %s", v[i].endereco.comp);
        printf("Bairro: %s", v[i].endereco.bairro);
        printf("Cidade: %s", v[i].endereco.cidade);
        printf("Número: %i", v[i].endereco.num);
        printf("\nCPF: %s", v[i].cpf);
        printf("Nasc: %s", v[i].dtnasc);
        printf("Dependentes? %s", v[i].temdepend);
        printf("Sexo: %s", v[i].sexo);
        printf("Semana1: %i", v[i].horastrabalhadas.semana1);
        printf("\nSemana2: %i", v[i].horastrabalhadas.semana2);
        printf("\nSemana3: %i\n", v[i].horastrabalhadas.semana3);
    }

}

int main()
{
    setlocale(LC_ALL,"");
    FUNCIONARIO func[nFuncionarios];

    preencheFormulario(func);

    system("cls");
    imprimeFuncionario(func);
}

