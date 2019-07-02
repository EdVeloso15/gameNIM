#ifndef INTERFACE_H_INCLUDED
#define INTERFACE_H_INCLUDED

void espacoTela(int tam)
{
    int j;
    for(j=0; j<tam; j++)
        printf(" ");
}

void linhaInter(int tam, int inicio)
{
    int i;
    espacoTela(inicio);
    for(i=0; i<tam; i++)
        printf("�");
}

void colunaInter(int tam, int tam2, int inicio)
{
    int i;
    int j;
    for(i=0; i<tam; i++)
    {
        printf("\n");
        espacoTela(inicio);
        printf("�");
        for(j=0; j<tam2; j++)
            printf(" ");
        printf("�");
    }
}

void logo(int tam, int inicio)
{
    //Linha 1
    espacoTela(inicio);
    printf("�");
    espacoTela(tam);
    printf(" __  __ ");
    espacoTela(2);
    printf(" __ ");
    espacoTela(2);
    printf(" __  __ ");
    espacoTela(tam);
    printf("�\n");
    //Linha 2
    espacoTela(inicio);
    printf("�");
    espacoTela(tam);
    printf("|  \\|  |");
    espacoTela(2);
    printf("|  |");
    espacoTela(2);
    printf("|  \\/  |");
    espacoTela(tam);
    printf("�\n");
    //Linha 3
    espacoTela(inicio);
    printf("�");
    espacoTela(tam);
    printf("|      |");
    espacoTela(2);
    printf("|  |");
    espacoTela(2);
    printf("|      |");
    espacoTela(tam);
    printf("�\n");
    //Linha 4
    espacoTela(inicio);
    printf("�");
    espacoTela(tam);
    printf("|__|\\__|");
    espacoTela(2);
    printf("|__|");
    espacoTela(2);
    printf("|_|\\/|_|");
    espacoTela(tam);
    printf("�");
}

void logoWrapper()
{
    linhaInter(36,35);
    colunaInter(2, 34,35);
    printf("\n");
    logo(5,35);
    colunaInter(3, 34, 35);
    printf("\n");
    linhaInter(100,2);
}

void regra(int inicio)
{
    colunaInter(1, 98,2);
    printf("\n");
    espacoTela(inicio);
    printf("�");
    espacoTela(3);
    printf("Regras: ");
    espacoTela(87);
    printf("�");
    printf("\n");

    espacoTela(inicio);
    printf("�");
    espacoTela(10);
    printf("Cada jogador retira um n�mero qualquer de palitos de UMA unica fileira.");
    espacoTela(17);
    printf("�");
    printf("\n");

    espacoTela(inicio);
    printf("�");
    espacoTela(10);
    printf("Os jogadores revezam entre si ate ser retirado o ultimo palito.");
    espacoTela(25);
    printf("�");
    printf("\n");

    espacoTela(inicio);
    printf("�");
    espacoTela(10);
    printf("O Jogador que retirou o ultimo palito ganha a partida.");
    espacoTela(34);
    printf("�");
    printf("\n");

    espacoTela(inicio);
    printf("�");
    espacoTela(10);
    printf("Os palitos no jogo serao representados desta forma: |");
    espacoTela(35);
    printf("�");

    colunaInter(1,98,2);
    printf("\n");
    linhaInter(100,2);

}

void confPadrao(int inicio)
{
    printf("\n");
    espacoTela(inicio);
    printf("�");
    espacoTela(3);
    printf("A configuracao padrao do jogo e de 3 linhas");
    espacoTela(52);
    printf("�");
    printf("\n");

    espacoTela(inicio);
    printf("�");
    espacoTela(3);
    printf("A primeira contendo 3 palitos");
    espacoTela(66);
    printf("�");
    printf("\n");

    espacoTela(inicio);
    printf("�");
    espacoTela(3);
    printf("A segunda contendo 5 palitos");
    espacoTela(67);
    printf("�");
    printf("\n");

    espacoTela(inicio);
    printf("�");
    espacoTela(3);
    printf("A terceira contendo 7 palitos");
    espacoTela(66);
    printf("�");
    printf("\n");
}

#endif // INTERFACE_H_INCLUDED
