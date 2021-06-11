#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 2

struct Disciplina{
    //char nome_Disc [50];
    char prontuario[50];
    float Prova_Pratica, Projeto, Lista_Exercicio;
};
struct Aluno{
    int ativo;
    char prontuario[50];
    char nome[50];
    char data_nasc[50];
    char email_inst[50];
    struct Disciplina disc;
}
cad_Alunos[MAX];


void remover_Aluno(){ // falta testar
    
    char pront;

    listar_Alunos();

    printf("\nDigite o Prontuario do aluno a ser excluido: \n");
    gets(pront);
    setbuf(stdin,NULL);

    for (int i = 0; i < MAX; i++)
    {
        if (strcmp(pront, cad_Alunos[i].prontuario)==0)
        {
            cad_Alunos[i].ativo=0;
            printf("\nAluno Excluido com Suscesso\n");
        }else{
            printf("\nAluno nao encontrado!!\n");
        }
    }

}

void cadastrar_Alunos(){ //pronto

    int op, i=0;

    do
    {
        /*for (int i = 0; i < MAX; i++){}*/

        system("cls");
        printf("Digite o Prontuario do Aluno: \n");
        fgets(cad_Alunos[i].prontuario, sizeof(cad_Alunos[i].prontuario), stdin);
        setbuf(stdin,NULL);
        printf("Digite o Nome do Aluno: \n");
        fgets(cad_Alunos[i].nome, sizeof(cad_Alunos[i].nome), stdin);
        setbuf(stdin,NULL);
        printf("Digite a Data de Nascimeto do Aluno: \n");
        fgets(cad_Alunos[i].data_nasc, sizeof(cad_Alunos[i].data_nasc), stdin);
        setbuf(stdin,NULL);
        printf("Digite o Email Institucional do Aluno: \n");
        fgets(cad_Alunos[i].email_inst, sizeof(cad_Alunos[i].email_inst), stdin);
        setbuf(stdin,NULL);

        //Notas

        system("cls");
        printf("\nPreenchendo as Notas e Disciplina do Aluno!\n");
        printf("\nINFORME PRIMEIRO O PRONTUARIO DO MESMO!!\n");
        system("pause");

        printf("\nDigite o Prontuario do Aluno: \n");
        fgets(cad_Alunos[i].prontuario, sizeof(cad_Alunos[i].prontuario), stdin);
        setbuf(stdin,NULL);
        //printf("\nDigite o nome da Disciplina: \n"); //, cad_Alunos[i].disc.nome_Disc
        //fgets(cad_Alunos[i].disc.nome_Disc, sizeof(cad_Alunos[i].disc.nome_Disc), stdin);
        printf("Digite a Nota da Prova Pratica: \n");
        scanf("%f", &cad_Alunos[i].disc.Prova_Pratica);
        setbuf(stdin,NULL);
        printf("Digite a Nota da Projeto: \n");
        setbuf(stdin,NULL);
        scanf("%f", &cad_Alunos[i].disc.Projeto);
        setbuf(stdin,NULL);
        printf("Digite a Nota da Lista de Exercicios: \n");
        scanf("%f", &cad_Alunos[i].disc.Lista_Exercicio);
        setbuf(stdin,NULL);
        cad_Alunos[i].ativo=1;
        i++;

        printf("\n\t1 - Continuar\n\t0 - Sair\n");
        scanf("%d", &op);
        setbuf(stdin,NULL);
        /*if (/* condition */)
        {
            /* code */
        }*/
        
        if(op==0){
            printf("\nSAINDO!!\n");
        }

    } while(op!=0);
    
}

void listar_Aluno(){ // falta testar

    char pront;
    int pos;

    printf("\nDigite o Prontuario do aluno a ser excluido: \n");
    gets(pront);
    setbuf(stdin,NULL);

    for(int i=0; i<MAX; i++) 
    {
        if(strcmp(pront, cad_Alunos[i].prontuario)== 0) 
        {
            printf("\n Aluno encontrado! ");
            pos = i;
        } else 
        {
            pos = -1;
        }
    }
 
    if(pos = -1) 
    {
        printf(" \n Aluno não encontrado! ");
    } else 
    {
        printf(" \n Registro do Aluno Encontrado: ");
        printf("\n----------------------");
        printf("\nProntuario: %s\n", cad_Alunos[pos].prontuario);
        printf("\nNome: %s", cad_Alunos[pos].nome);
        printf("\nData de Nascimento: %s", cad_Alunos[pos].data_nasc);
        printf("\nEmail Institucional: %s", cad_Alunos[pos].email_inst);
        printf("\n----------------------");
        printf("\nAs Notas do Aluno %s foram:", cad_Alunos[pos].nome);
        printf("\n----------------------");
        printf("\nProva Pratica: %.2f", cad_Alunos[pos].disc.Prova_Pratica);
        printf("\nProjeto: %.2f", cad_Alunos[pos].disc.Projeto);
        printf("\nLista de Exercicios: %.2f", cad_Alunos[pos].disc.Lista_Exercicio);
        printf("\n----------------------\n\n");
    }
    
}

void listar_Alunos(){ //pronto

    system("cls");
    printf("\n\t---LISTA DE ALUNOS---\n\n");

    for (int i = 0; i < MAX; i++)
    {
        //system("cls");
        if (cad_Alunos[i].ativo==1)
        {
            printf("\n---------------------------");
            printf("\nProntuario: %s", cad_Alunos[i].prontuario);
            printf("\nNome: %s", cad_Alunos[i].nome);
            printf("\nData de Nascimento: %s", cad_Alunos[i].data_nasc);
            printf("\nEmail Institucional: %s", cad_Alunos[i].email_inst);
            printf("\n---------------------------");
            printf("\nAs Notas do Aluno %s foram:", cad_Alunos[i].nome);
            printf("\n---------------------------");
            printf("\nProva Pratica: %.2f", cad_Alunos[i].disc.Prova_Pratica);
            printf("\nProjeto: %.2f", cad_Alunos[i].disc.Projeto);
            printf("\nLista de Exercicios: %.2f", cad_Alunos[i].disc.Lista_Exercicio);
            printf("\n---------------------------\n\n");
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
        setbuf(stdin,NULL);

        switch (op){
            case 1:
                listar_Alunos();
                break;
            case 2:
                listar_Aluno();
                break;
            case 3:
                cadastrar_Alunos();
                break;
            case 4:
                //alterar_Aluno();
                break;
            case 5:
                remover_Aluno();
                break;
            case 0:
                // Sai do Sub Menu Alunos
                printf("\nSaindo do Menu Alunos!\n");
                break;
            default:
                printf("Opcao invalida!\n\n");
        }
        
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
        setbuf(stdin,NULL);

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
        
    } while (op!=0);
}

int main(){ //pronto
    menu();
    return 0;
}
