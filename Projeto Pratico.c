#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 2

struct Disciplina{
    //char nome_Disc [50];
    int prontuario;
    float Prova_Pratica, Projeto, Lista_Exercicio;
};
struct Aluno{
    int prontuario, ativo;
    char nome[50];
    char data_nasc[50];
    char email_inst[50];
    struct Disciplina disc;
}
cad_ALunos[MAX];


/*void menu();
void cadastrar_Alunos();
void remover_Aluno();
void reprovados();
void pesquisa();
void listar_Alunos();*/

/*void remover_Aluno(){
    int pront;
    listar_Alunos();
    printf("\nDigite o Prontuario do aluno a ser excluido: \n");
    fflush(stdin);
    scanf("%d", &pront);
    for (int i = 0; i < MAX; i++)
    {
        if (cad_Alunos[i].prontuario == pront)
        {
            cad_Alunos[i].ativo=0;
            printf("\nAluno Excluido com Suscesso\n");
        }
        else
        printf("\nAluno nao encontrado!!\n");
    }

    getchar();
}*/

void cadastrar_Alunos(){ //pronto

    int op, i=0;

    do
    {
        /*for (int i = 0; i < MAX; i++){}*/

        system("cls");
        printf("\nDigite o Prontuario do Aluno: \n");
        scanf("%d", &cad_ALunos[i].prontuario);
        fflush(stdin);
        printf("\nDigite o Nome do Aluno: \n");
        gets(cad_ALunos[i].nome);
        fflush(stdin);
        printf("\nDigite a Data de Nascimeto do Aluno: \n");
        gets(cad_ALunos[i].data_nasc);
        fflush(stdin);
        printf("\nDigite o Email Institucional do Aluno: \n");
        gets(cad_ALunos[i].data_nasc);
        fflush(stdin);

        //Notas

        printf("\nPreenchendo as Notas e Disciplina do Aluno!\n");
        printf("\nINFORME PRIMEIRO O PRONTUARIO DO MESMO!!\n");
        system("pause");

        printf("\nDigite o Prontuario do Aluno: \n");
        scanf("%d", &cad_ALunos[i].disc.prontuario);
        //printf("\nDigite o nome da Disciplina: \n"); //, cad_Alunos[i].disc.nome_Disc
        //gets(cad_Alunos[i].disc.nome_Disc);
        printf("\nDigite a Nota da Prova Pratica: \n");
        scanf("%f", &cad_ALunos[i].disc.Prova_Pratica);
        printf("\nDigite a Nota da Projeto: \n");
        scanf("%f", &cad_ALunos[i].disc.Projeto);
        printf("\nDigite a Nota da Lista de Exercicios: \n");
        scanf("%f", &cad_ALunos[i].disc.Lista_Exercicio);
        fflush(stdin);
        cad_ALunos[i].ativo=1;

        i++;

        printf("\n\t1 - Continuar\n\t0 - Sair\n");
        scanf("%d", &op);
        if(op==0){
            printf("\nSAINDO!!\n");
        }

    } while(op!=0);
    getchar();
}

void listar_Aluno(){
}

void listar_Alunos(){ //pronto

    system("cls");
    printf("\n\t---LISTA DE ALUNOS---\n\n");

    for (int i = 0; i < MAX; i++)
    {
        //system("cls");
        if (cad_ALunos[i].ativo==1)
        {
            printf("\n----------------------");
            printf("\nProntuario: %d\n", cad_ALunos[i].prontuario);
            printf("\nNome: %s", cad_ALunos[i].nome);
            printf("\nData de Nascimento: %s", cad_ALunos[i].data_nasc);
            printf("\nEmail Institucional: %s", cad_ALunos[i].email_inst);
            printf("\n----------------------");
            printf("\nAs Notas do Aluno %s foram:", cad_ALunos[i].nome);
            printf("\n----------------------");
            printf("\nProva Pratica: %.2f", cad_ALunos[i].disc.Prova_Pratica);
            printf("\nProjeto: %.2f", cad_ALunos[i].disc.Projeto);
            printf("\nLista de Exercicios: %.2f", cad_ALunos[i].disc.Lista_Exercicio);
            printf("\n----------------------\n\n");
        }

    }
    system("pause");
}

void sub_menu_Alunos(){ //pronto
    int op;
    do
    {
        system("cls");
        printf("Selecione uma Opcao!");
        printf("\n\t1-Listar Todos os Alunos");
        printf("\n\t2-Listar um Aluno");
        printf("\n\t3-Cadastar Aluno"); // nao pode ter dois alunos com o mesmo prontuario
        printf("\n\t4-Alterar Aluno");
        printf("\n\t5-Excluir Aluno"); // Excluir aluno / cancelar matricula
        printf("\n\t0-Sair\n\n");
        scanf("%d", &op);
        getchar();

        switch (op){
            case 1:
                listar_Alunos();
                break;
            /*case 2:
                listar_Aluno();
                break;*/
            case 3:
                cadastrar_Alunos();
                break;
            /*case 4:

                _Aluno();
                break;*/
            case 5:
                //remover_Aluno();
                break;
            case 0:
                // Sai do Sub Menu Alunos
                printf("\nSaindo do Menu Alunos!\n");
                break;
            default:
                printf("Opcao invalida!\n\n");
        }
        getchar();
    } while (op!=0);
}

void menu(){ //pronto
    int op;

    do
    {
        system("cls");
        printf("Selecione uma Opcao!");
        printf("\n\t1-Alunos");
        printf("\n\t2-Relatorios");
        printf("\n\t0-Sair\n\n");
        scanf("%d", &op);
        getchar();

        switch (op){
            case 1:
                sub_menu_Alunos();
                break;
            /*case 2:
                sub_menu_Relatorios();
                break;*/
            case 0:
                printf("\nSAINDO!\n");
                break;
            default:
                printf("Opcao invalida!\n\n");
        }
        getchar();
    } while (op!=0);
}

int main(){ //pronto
    menu();
    return 0;
}
