#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 3

// DECLARAÇÃO DAS STRUCTS

typedef struct Disciplina{
    //char nome_Disc [50];
    char prontuario[50];
    float Prova_Pratica, Projeto, Lista_Exercicio, Media;
};

typedef struct {
    int ativo;
    char prontuario[50];
    char nome[50];
    char data_nasc[50];
    char email_inst[50];
    struct Disciplina disc;
}cad_Alunos;
cad_Alunos Alunos[MAX];

// FIM DA DECLARAÇÃO DAS STRUCTS


// DECLARAÇÃO DAS FUNÇÕES

void alunos_Aprovados();
void alunos_Reprovados();
void alunos_Inativos();
void remover_Aluno();
void alterar_Alunos();
void cadastrar_Alunos();
void listar_Aluno();
void listar_Alunos();
void sub_menu_Alunos();
void menu();

// FIM DA DECLARAÇÃO DAS FUNÇÕES


// FUNÇÕES RELATORIOS

void alunos_Aprovados(cad_Alunos *Alunos ){ //Fazendo

    int pos, cad;

    system("cls");
    printf("\n\t---ALUNOS APROVADOS---\n");

    if(Alunos->ativo==NULL){
        cad = 1;
    } else {
        
        for(int i=0; i<MAX; i++) {

            if((Alunos[i].ativo==1)&(Alunos[i].disc.Media>=7)) {

                printf("\n----------------------------------------------");
                printf("\nProntuario: %s", Alunos[i].prontuario);
                printf("\nNome: %s", Alunos[i].nome);
                printf("\nData de Nascimento: %s", Alunos[i].data_nasc);
                printf("\nEmail Institucional: %s", Alunos[i].email_inst);
                printf("\n----------------------------------------------");
                printf("\nAs Notas do Aluno %s foram:", Alunos[i].nome);
                printf("\n----------------------------------------------");
                printf("\nProva Pratica: %.2f", Alunos[i].disc.Prova_Pratica);
                printf("\nProjeto: %.2f", Alunos[i].disc.Projeto);
                printf("\nLista de Exercicios: %.2f", Alunos[i].disc.Lista_Exercicio);
                printf("\nA sua Media foi: %.2f", Alunos[i].disc.Media);
                printf("\n----------------------------------------------\n\n");
            
            }
        }
        
    }

    if (cad == 1){
        system("cls");
        printf("\n\t---NAO HA ALUNOS CADASTRADOS!---\n\n");
    }
    
    system("pause");
}

void alunos_Reprovados(cad_Alunos *Alunos){// Fazendo

    int pos, cad;

    system("cls");
    printf("\n\t---ALUNOS REPROVADOS---\n");

    if(Alunos->ativo==NULL){
        cad = 1;
    } else {
        
        for(int i=0; i<MAX; i++) {

            if((Alunos[i].ativo==1)&(Alunos[i].disc.Media<7)) {

                printf("\n----------------------------------------------");
                printf("\nProntuario: %s", Alunos[i].prontuario);
                printf("\nNome: %s", Alunos[i].nome);
                printf("\nData de Nascimento: %s", Alunos[i].data_nasc);
                printf("\nEmail Institucional: %s", Alunos[i].email_inst);
                printf("\n----------------------------------------------");
                printf("\nAs Notas do Aluno %s foram:", Alunos[i].nome);
                printf("\n----------------------------------------------");
                printf("\nProva Pratica: %.2f", Alunos[i].disc.Prova_Pratica);
                printf("\nProjeto: %.2f", Alunos[i].disc.Projeto);
                printf("\nLista de Exercicios: %.2f", Alunos[i].disc.Lista_Exercicio);
                printf("\nA sua Media foi: %.2f", Alunos[i].disc.Media);
                printf("\n----------------------------------------------\n\n");
            
            }
        }
        
    }

    if (cad == 1){
        system("cls");
        printf("\n\t---NAO HA ALUNOS CADASTRADOS!---\n\n");
    }
    
    system("pause");
}

void alunos_Inativos(cad_Alunos *Alunos){ //Pronto

    system("cls");
    if(Alunos->ativo!=NULL){
        
            system("cls");
            printf("\n\t---LISTA DE ALUNOS INATIVOS/EXCLUIDOS---\n\n");
            for (int i = 0; i < MAX; i++){

                if(Alunos[i].ativo==2){
                    printf("\n---------------------------");
                    printf("\nProntuario: %s", Alunos[i].prontuario);
                    printf("\nNome: %s", Alunos[i].nome);
                    printf("\nData de Nascimento: %s", Alunos[i].data_nasc);
                    printf("\nEmail Institucional: %s", Alunos[i].email_inst);
                    printf("\n---------------------------");
                    printf("\nAs Notas do Aluno %s foram:", Alunos[i].nome);
                    printf("\n---------------------------");
                    printf("\nProva Pratica: %.2f", Alunos[i].disc.Prova_Pratica);
                    printf("\nProjeto: %.2f", Alunos[i].disc.Projeto);
                    printf("\nLista de Exercicios: %.2f", Alunos[i].disc.Lista_Exercicio);
                    printf("\n---------------------------\n\n");
                }else{
                    system("cls");
                    printf("\n\t---NAO HA ALUNOS INATIVOS/EXCLUIDOS!---\n\n");
                }            
            }
    }else{
        system("cls");
        printf("\n\t---NAO HA ALUNOS CADASTRADOS!---\n\n");
    }
    system("pause");
}

// FIM DE RELATORIOS


// FUNÇÕES GERAIS

void remover_Aluno(cad_Alunos *Alunos){ // Pronto
    
    char pront[50];
    int pos;

    system("cls");
    if(Alunos->ativo!=NULL){

        system("cls");
        printf("\n\t---LISTA DE ALUNOS---\n\n");
        listar_Alunos(Alunos);

        printf("\nDigite o Prontuario do Aluno a ser Excluido: \n");
        gets(pront);

        for (int i = 0; i < MAX; i++)
        {
            if (strcmp(pront, Alunos[i].prontuario)==0)
            {
                pos = i;
                break;
            }else{
                pos = -1;
            }
        }
        if (pos == -1){
            system("cls");
            printf("\n\t---Aluno nao Encontrado!---\n");
        }else{
            /*
            ALUNO->ATIVO = 1 -- ALUNO ATIVO
            ALUNO->ATIVO = 2 -- ALUNO EXCLUIDO/INATIVO
            */
            system("cls");
            Alunos[pos].ativo=2;
            printf("\n\t---Aluno Excluido com Suscesso!---\n");
        }
    }else{
        system("cls");
        printf("\n\t---NAO HA ALUNOS CADASTRADOS!---\n\n");
    }

    system("pause");
}

void alterar_Alunos(cad_Alunos *Alunos){// Pronto
    
    char pront[50];
    int pos;
    float Soma;

    system("cls");
    if(Alunos->ativo!=NULL){
        system("cls");
        printf("\n\t---LISTA DE ALUNOS---\n\n");
        listar_Alunos(Alunos);

        printf("\nDigite o Prontuario do Aluno a ser Atualizado:\n");
        gets(pront);

        for (int i = 0; i < MAX; i++)
        {
            if (strcmp(pront, Alunos[i].prontuario)==0){
                pos = i;
                break;
            }else{
                pos = -1;
            }
        }
        if (pos == -1){
            system("cls");
            printf("\n\t---Aluno nao Encontrado ou Prontuario incorreto!---\n");
        }else{
            int op;
            system("cls");
            printf("\n\t---ESCOLHA O DADO A SER ATUALIZADO---\n\n");
            printf("\n\t1-Nome\n\t2-Data de Nascimento\n\t3-Email\n\t4-Nota Prova Pratica\n\t5-Nota Projeto\n\t6-Nota Lista de Exercicio\n\t7-Ativar Matricula do Aluno\n\t8-Desativar Matricula do Aluno\n");

            printf("\nDigite a Opcao Desejada!\n");
            scanf("%d", &op);
            setbuf(stdin,NULL);

            switch (op)
            {
            case 1:
                system("cls");
                printf("\nDigite o nome do Aluno a ser Alterado:\n");
                fgets(Alunos[pos].nome, sizeof(Alunos[pos].nome), stdin);
                setbuf(stdin,NULL);
                break;
            case 2:
                system("cls");
                printf("\nDigite a Data de Nascimento do Aluno a ser Alterado:\n");
                fgets(Alunos[pos].data_nasc, sizeof(Alunos[pos].data_nasc), stdin);
                setbuf(stdin,NULL);
                break;
            case 3:
                system("cls");
                printf("\nDigite o Email do Aluno a ser Alterado:\n");
                fgets(Alunos[pos].email_inst, sizeof(Alunos[pos].email_inst), stdin);
                setbuf(stdin,NULL);
                break;
            case 4:
                system("cls");
                printf("\nDigite a nota da Prova Pratica a ser Alterado:\n");
                scanf("%f", &Alunos[pos].disc.Prova_Pratica);
                setbuf(stdin,NULL);
                break;
            case 5:
                system("cls");
                printf("\nDigite a nota do Projeto a ser Alterado:\n");
                scanf("%f", &Alunos[pos].disc.Projeto);
                setbuf(stdin,NULL);
                break;
            case 6:
                system("cls");
                printf("\nDigite a nota da Lista de Exercicio a ser Alterado:\n");
                scanf("%f", &Alunos[pos].disc.Lista_Exercicio);
                setbuf(stdin,NULL);
                break;
            case 7:
                system("cls");
                Alunos[pos].ativo=1;
                printf("\nO Aluno %s foi reativado na instituicao!", Alunos[pos].nome);
                break;
            case 8:
                system("cls");
                Alunos[pos].ativo=2;
                printf("\nO Aluno %s foi desativado na instituicao!", Alunos[pos].nome);
                break;
            default:
                system("cls");
                printf("\n\t---!OPCAO INVALIDA!---\n");
                break;
            }
            
            Soma = Alunos[pos].disc.Prova_Pratica + Alunos[pos].disc.Projeto + Alunos[pos].disc.Lista_Exercicio;
            Alunos[pos].disc.Media = Soma/3;

            printf("\n\t---Aluno Alterado com Suscesso!---\n");
        }
    }else{
        system("cls");
        printf("\n\t---NAO HA ALUNOS CADASTRADOS!---\n\n");
    }
    
    system("pause");
}

void cadastrar_Alunos(cad_Alunos *Alunos){ //Pronto

    int op, i=0,pos=0;
    float Soma;
    char pront[50];

    do
    {
        system("cls");
        printf("Digite o Prontuario do Aluno:\n");
        gets(pront);
        setbuf(stdin,NULL);
        
        for(int j = 0; j<MAX; j++){
            if(strcmp(pront, Alunos[j].prontuario)==0){
                printf("\n!Prontuario ja Cadastrado!\n");
                pos = -1;
                break;
            }
        }
        
        if(pos != -1){
            //setbuf(stdin,NULL);
            strcpy(Alunos[i].prontuario, pront);

            printf("Digite o Nome do Aluno:\n");
            fgets(Alunos[i].nome, sizeof(Alunos[i].nome), stdin);
            setbuf(stdin,NULL);
            printf("Digite a Data de Nascimeto do Aluno:\n");
            fgets(Alunos[i].data_nasc, sizeof(Alunos[i].data_nasc), stdin);
            setbuf(stdin,NULL);
            printf("Digite o Email Institucional do Aluno:\n");
            fgets(Alunos[i].email_inst, sizeof(Alunos[i].email_inst), stdin);
            setbuf(stdin,NULL);

            //Notas

            system("cls");
            printf("\nPreenchendo as Notas do Aluno!\n");
            //printf("\nINFORME PRIMEIRO O PRONTUARIO DO MESMO!!\n");
            system("pause");

            //printf("\nDigite o nome da Disciplina: \n"); //, cad_Alunos[i].disc.nome_Disc
            //fgets(cad_Alunos[i].disc.nome_Disc, sizeof(cad_Alunos[i].disc.nome_Disc), stdin);

            system("cls");
            printf("Digite a Nota da Prova Pratica:\n");
            scanf("%f", &Alunos[i].disc.Prova_Pratica);
            setbuf(stdin,NULL);
            printf("Digite a Nota da Projeto:\n");
            setbuf(stdin,NULL);
            scanf("%f", &Alunos[i].disc.Projeto);
            setbuf(stdin,NULL);
            printf("Digite a Nota da Lista de Exercicios:\n");
            scanf("%f", &Alunos[i].disc.Lista_Exercicio);
            setbuf(stdin,NULL);
            Alunos[i].ativo=1; // 1 para ALUNO ATIVO e 2 para INATIVO/EXCLUIDO
            
            Soma = Alunos[i].disc.Prova_Pratica + Alunos[i].disc.Projeto + Alunos[i].disc.Lista_Exercicio;
            Alunos[i].disc.Media = Soma/3;

            i++;
        }

        pos=0;

        printf("\n\tDeseja Adicionar mais Alunos?");
        printf("\n\t1 - Continuar\n\t0 - Sair\n");
        scanf("%d", &op);
        setbuf(stdin,NULL);
        // colocar um if para testar o final de adições de alunos basedo no MAX
        if (op == 1)
        {   
            if (i >= MAX)
            {
                system("cls");
                printf("\nLimite de cadastros atingido!!\n");
                op = 0;
                break;
            }
        }
        
        if(op==0){
            system("cls");
            printf("\nSAINDO!!\n");
            system("cls");
        }

    } while(op!=0);
    
}

void listar_Aluno(cad_Alunos *Alunos){ // Pronto

    char pront[50];
    int pos, i;

    system("cls");
    if(Alunos->ativo!=NULL){
        system("cls");
        printf("\nDigite o Prontuario do aluno a ser Pesquisado:\n");
        gets(pront);
        setbuf(stdin,NULL);

        for(i = 0; i<MAX; i++) 
        {
            if(strcmp(pront, Alunos[i].prontuario)==0){
                system("cls");
                printf("\n\t---Aluno encontrado!---\n");
                //getchar();
                pos = i;
                break;
            } else{
                pos = -1;
            }
        }
    
        if(pos == -1){
            system("cls");
            printf(" \n\t---Aluno nao encontrado!---\n\n");
        } else{
            //system("cls");
            printf(" \nAperte ENTER para mostrar o aluno:\n\n");
            getchar();

            system("cls");
            printf("\nRegistro do Aluno Encontrado:");
            printf("\n----------------------");
            printf("\nProntuario: %s", Alunos[pos].prontuario);
            printf("\nNome: %s", Alunos[pos].nome);
            printf("\nData de Nascimento: %s", Alunos[pos].data_nasc);
            printf("\nEmail Institucional: %s", Alunos[pos].email_inst);
            printf("\n----------------------");
            printf("\nAs Notas do Aluno %s foram:", Alunos[pos].nome);
            printf("\n----------------------");
            printf("\nProva Pratica: %.2f", Alunos[pos].disc.Prova_Pratica);
            printf("\nProjeto: %.2f", Alunos[pos].disc.Projeto);
            printf("\nLista de Exercicios: %.2f", Alunos[pos].disc.Lista_Exercicio);
            printf("\nMedia: %.2f", Alunos[pos].disc.Media);
            printf("\n----------------------\n\n");
        }
    }else{
        system("cls");
        printf("\n\t---NAO HA ALUNOS CADASTRADOS!---\n\n");
    }

    system("pause");
    system("cls");
}

void listar_Alunos(cad_Alunos *Alunos){ //pronto

    system("cls");
    if(Alunos->ativo!=NULL){
        system("cls");
        printf("\n\t---LISTA DE ALUNOS---\n\n");
        for (int i = 0; i < MAX; i++)
        {
            if (Alunos[i].ativo==1){
            
                printf("\n---------------------------");
                printf("\nProntuario: %s", Alunos[i].prontuario);
                printf("\nNome: %s", Alunos[i].nome);
                printf("\nData de Nascimento: %s", Alunos[i].data_nasc);
                printf("\nEmail Institucional: %s", Alunos[i].email_inst);
                printf("\n---------------------------");
                printf("\nAs Notas do Aluno %s foram:", Alunos[i].nome);
                printf("\n---------------------------");
                printf("\nProva Pratica: %.2f", Alunos[i].disc.Prova_Pratica);
                printf("\nProjeto: %.2f", Alunos[i].disc.Projeto);
                printf("\nLista de Exercicios: %.2f", Alunos[i].disc.Lista_Exercicio);
                printf("\nMedia: %.2f", Alunos[i].disc.Media);
                printf("\n---------------------------\n");

            }
        }
    }else{
        system("cls");
        printf("\n\t---NAO HA ALUNOS CADASTRADOS!---\n\n");
    }
    system("pause");
    system("cls");
}

void sub_menu_Alunos(){ //Pronto
    int op;

    system("cls");
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
                listar_Alunos(Alunos);
                break;
            case 2:
                listar_Aluno(Alunos);
                break;
            case 3:
                cadastrar_Alunos(Alunos);
                break;
            case 4:
                alterar_Alunos(Alunos);
                break;
            case 5:
                remover_Aluno(Alunos);
                break;
            case 0:
                // Sai do Sub Menu Alunos
                printf("\nSaindo do Menu Alunos!\n");
                break;
            default:
                printf("\n\n!Opcao invalida!\n\n");
        }
        
    } while (op!=0);
}

void sub_menu_Relatorios(){// Pronto

    int op;

    system("cls");
    do
    {
        system("cls");
        setbuf(stdin,NULL);
        printf("\n\t\tSelecione uma Opcao!\n");
        printf("\n\t1-Listar Todos os Alunos Aprovados:");
        printf("\n\t2-Listar Todos os Alunos Reprovados:");
        printf("\n\t3-Mostrar Todos os Alunos Excluidos/Inativos:");
        printf("\n\t0-Sair\n\n");
        scanf("%d", &op);
        setbuf(stdin,NULL);

        switch (op){

            case 1:
                alunos_Aprovados(Alunos);
                break;
            case 2:
                alunos_Reprovados(Alunos);
                break;
            case 3:
                alunos_Inativos(Alunos);
                break;
            case 0:
                // Sai do Sub Menu Alunos
                printf("\nSaindo do Menu Relatorios!\n");
                break;
            default:
                printf("\n\n!Opcao invalida!\n\n");
        }
        
    } while (op!=0);
}

void menu(){ //Pronto
    int op;

    system("cls");
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
            case 2:
                sub_menu_Relatorios();
                break;
            case 0:
                system("cls");
                printf("\nSAINDO!\n");
                break;
            default:
                printf("Opcao invalida!\n\n");
        }
        
    } while (op!=0);
}

int main(){ //Pronto
    
    menu();
    return 0;
} 

// FIM DAS FUNÇÕES GERAIS