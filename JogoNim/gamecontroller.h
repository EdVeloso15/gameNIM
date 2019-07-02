#ifndef GAMECONTROLLER_H_INCLUDED
#define GAMECONTROLLER_H_INCLUDED
#include <time.h>
#include <math.h>

int *fileira;
int rodada;
int qtdFileiras;
int modo=0;
int config=0;
int dificuldade = 1;
int contRemover=0;
int linhasRemovidas[5];

int vitoria();
/*
void escolhaModo(int inicio)
{
    int decisao;
    printf("\n");
    espacoTela(inicio);
    printf("ú");
    espacoTela(3);
    printf("Digite 0 para jogar Jogador vs Jogador");
    espacoTela(57);
    printf("ú");
    printf("\n");

    espacoTela(inicio);
    printf("ú");
    espacoTela(3);
    printf("Digite 1 para jogar contra a Maquina");
    espacoTela(59);
    printf("ú");
    printf("\n");

    espacoTela(inicio+4);
    scanf("%1d", &decisao);

    decisao = escolhaBinaria(decisao);

    if(decisao == 1)
    {
        printf("\n");
        espacoTela(2);
        printf("ú");
        espacoTela(3);
        printf("Digite a dificuldade o nivel de dificuldade da maquina.");
        espacoTela(40);
        printf("ú");
        printf("\n");

        espacoTela(2);
        printf("ú");
        espacoTela(3);
        printf("(1)Facil  -  (2)Normal  -  (3)Dificil");
        espacoTela(58);
        printf("ú");
        printf("\n");
        espacoTela(6);
        scanf("%1d",&dificuldade);

        while(dificuldade < 1 || dificuldade > 3)
        {
            espacoTela(2);
            printf("ú");
            espacoTela(3);
            printf("Valor Invalido. Digite-o novamente.");
            espacoTela(60);
            printf("ú");
            printf("\n");

            espacoTela(6);
            scanf("%1d",&dificuldade);
        }
    }

    colunaInter(1,98,2);
    printf("\n");
    linhaInter(100,2);

    modo = decisao;
}
*/
int escolhaBinaria(int decisao)
{
    while(decisao != 0 && decisao != 1)
    {
        espacoTela(2);
        printf("ú");
        espacoTela(3);
        printf("Valor digitado invalido. Digite um valor entre 0 e 1.");
        espacoTela(42);
        printf("ú");
        printf("\n");
        espacoTela(6);
        scanf("%1d", &decisao);
    }
    if(decisao == 0 || decisao == 1)
    {
        espacoTela(2);
        printf("ú");
        espacoTela(3);
        printf("Valor armazenado com sucesso.");
        espacoTela(66);
        printf("ú");
        return decisao;
    }
}

void renderGame(void)
{
    system("mode 800");
    system("cls");
    logoWrapper();
    regra(2);
}

int escolhaFaixa(int decisao, int inicio, int fim)
{
    if(decisao < inicio)
    {
        decisao = inicio;
    }
    else if(decisao > fim)
    {
        decisao = fim;
    }
    return decisao;
}

int * preencherFileiras()
{
    printf("\n");
    espacoTela(2);
    printf("ú");
    espacoTela(3);
    printf("Digite a quantidade de fileiras. (3-5)");
    espacoTela(57);
    printf("ú");
    printf("\n");
    espacoTela(6);

    scanf("%1d", &qtdFileiras);

    if(qtdFileiras > 5)
    {
        printf("\n");
        espacoTela(2);
        printf("ú");
        espacoTela(3);
        printf("Valor invalido. Assumindo o valor maximo de fileiras: 5.");
        espacoTela(39);
        printf("ú");
        qtdFileiras = escolhaFaixa(qtdFileiras,3,5);
        printf("\n");
    }
    if(qtdFileiras < 3)
    {
        printf("\n");
        espacoTela(2);
        printf("ú");
        espacoTela(3);
        printf("Valor invalido. Assumindo o valor minimo de fileiras: 3.");
        espacoTela(39);
        printf("ú");
        qtdFileiras = escolhaFaixa(qtdFileiras,3,5);
        printf("\n");
    }

    espacoTela(2);
    printf("ú");
    espacoTela(3);
    printf("A quantidade maxima de palitos por fileira e de 10 e a minima e 1");
    espacoTela(30);
    printf("ú");
    int *v;
    free(v);
    v = NULL;
    v = (int*) malloc(qtdFileiras * sizeof(int));
    printf("\n");
    linhaInter(100,2);
    int i;

    for(i=1;i<=qtdFileiras;i++)
    {
        printf("\n");
        espacoTela(2);
        printf("ú");
        espacoTela(3);
        printf("Digite a quantidade de palitos na %d fileira", i);
        espacoTela(52);
        printf("ú");
        printf("\n");

        espacoTela(6);
        int valor;
        scanf("%d",&valor);
        if(valor>10)
        {
            printf("\n");
            espacoTela(2);
            printf("ú");
            espacoTela(3);
            printf("Valor invalido. Assumindo o valor maximo de palitos: 10.");
            espacoTela(39);
            printf("ú");
            valor = escolhaFaixa(valor,1,10);
        }
        if(valor<1)
        {
            printf("\n");
            espacoTela(2);
            printf("ú");
            espacoTela(3);
            printf("Valor invalido. Assumindo o valor minimo de palitos: 1.");
            espacoTela(40);
            printf("ú");
            valor = escolhaFaixa(valor,1,10);
        }
        v[i-1] = valor;
    }
    return v;
}

void confGame()
{
    //escolhaModo(2);
    if(modo==0)
    {

        printf("\n");
        espacoTela(2);
        printf("ú");
        espacoTela(3);
        printf("Deseja a configuracao (0)padrao ou (1)customizada?");
        espacoTela(45);
        printf("ú");
        printf("\n");
        espacoTela(6);
        scanf("%1d",&config);
        config = escolhaBinaria(config);
        if(config == 0)
        {
            confPadrao(2);
            free(fileira);
            fileira = NULL;
            qtdFileiras = 3;
            fileira = (int *) malloc(qtdFileiras*sizeof(int));
            fileira[0] = 3;
            fileira[1] = 5;
            fileira[2] = 7;
            linhaInter(100,2);

        }
        else if(config == 1)
        {
            fileira = preencherFileiras();
            printf("\n");
            espacoTela(2);
            printf("ú");
            espacoTela(3);
            printf("Valores armazenados com sucesso.");
            espacoTela(63);
        }
    }
    else
    {
        confPadrao(2);
        free(fileira);
        fileira = NULL;
        qtdFileiras = 3;
        fileira = (int *) malloc(qtdFileiras*sizeof(int));
        fileira[0] = 3;
        fileira[1] = 5;
        fileira[2] = 7;
        linhaInter(100,2);
    }
}

void loadingGame()
{
    int i;

    printf("\n");
    espacoTela(2);
    printf("ú");
    espacoTela(3);
    printf("Estamos Carregando o Jogo");
    espacoTela(70);
    printf("ú");

    clock_t inicio, fim;
    double tempo_levado = 0;

    for(i=3;i>0;i--)
    {

        printf("\n");
        espacoTela(2);
        printf("ú");
        espacoTela(3);
        printf("Espere %d segundos.", i);
        espacoTela(77);
        printf("ú");
        tempo_levado = 0;
        inicio = clock();
        while(tempo_levado < 1)
        {
            fim = clock();
            tempo_levado = ((double)fim - (double)inicio)/CLOCKS_PER_SEC;
        }
    }
    printf("\n");
    linhaInter(100,2);
    tempo_levado = 0;
    inicio = clock();
    while(tempo_levado < 2)
    {
        fim = clock();
        tempo_levado = ((double)fim - (double)inicio)/CLOCKS_PER_SEC;
    }
    srand(time(NULL));
    rodada = rand()%2;
}

void startGame()
{
    gameController();
    //Fazer loop
}

void gameView()
{
    system("cls");
    printf("\n");
    renderGame();
    int i, j, contador;
    for(i = 0; i<qtdFileiras; i++)
    {
        contador = 0;
        printf("\n");
        espacoTela(2);
        printf("ú");
        espacoTela(3);
        if(fileira[i] != 0)
        {
            printf("%d - Fileira: ", i+1);
            for(j=0; j<fileira[i]; j++)
            {
                printf("| ");
                contador++;
            }
            espacoTela(82-(2*contador));
            printf("ú");
        }
        else
        {
            continue;
        }
    }
    printf("\n");
    linhaInter(100,2);
}

void gameController()
{
    //Jogador vs Jogador.
    if(modo == 0)
    {
        while(vitoria() != 1)
        {
            if(rodada == 1)
            {
                rodada = 0;
            }
            else
            {
                rodada = 1;
            }
            gameView();
            printf("\n");
            espacoTela(2);
            printf("ú");
            espacoTela(3);
            printf("Vez do Jogador %d", rodada+1);
            espacoTela(79);
            printf("ú");
            realizarJogada();
        }
    }
    /*
    //Jogador vs Máquina.
    if(modo == 1)
    {
        do
        {
            if(rodada == 0)
            {
                    gameView();
                    realizarJogada();
                    rodada = 1;
            }
            else
            {
                system("pause");
                computadorJogada();
                rodada = 0;
            }
        }while(vitoria() != 1);
    }
    */

}

void gameOver()
{
    system("cls");
    renderGame();
    printf("\n");
    espacoTela(2);
    printf("ú");
    espacoTela(3);
    printf("O jogador %d VENCEU!!!", rodada+1);
    espacoTela(74);
    printf("ú");
    printf("\n");
    linhaInter(100,2);
}

int vitoria()
{
    int i, j, contador;
    contador = 0;
    for(i = 0; i<qtdFileiras; i++)
    {
        if(fileira[i] == 0)
            contador++;
    }
    if(contador == qtdFileiras)
    {
        return 1;
    }
    else
        return 0;
}

void realizarJogada()
{
    int jogadaF, jogadaP;
    printf("\n");
    espacoTela(2);
    printf("ú");
    espacoTela(3);
    printf("Digite a fileira que deseja remover palitos.");
    espacoTela(51);
    printf("ú");
    printf("\n");

    espacoTela(6);
    scanf("%1d", &jogadaF);

    while(fileira[jogadaF-1] == 0 || jogadaF < 0 || jogadaF > qtdFileiras)
    {
        espacoTela(2);
        printf("ú");
        espacoTela(3);
        printf("Jogada Invalida. Realize novamente");
        espacoTela(61);
        printf("ú");
        printf("\n");

        espacoTela(6);
        scanf("%1d", &jogadaF);
    }

    printf("\n");
    espacoTela(2);
    printf("ú");
    espacoTela(3);
    printf("Digite a quantidade que deseja remover de palitos.");
    espacoTela(45);
    printf("ú");
    printf("\n");

    espacoTela(6);
    scanf("%1d", &jogadaP);
    while(jogadaP < 0 || jogadaP > fileira[jogadaF-1])
    {
        espacoTela(2);
        printf("ú");
        espacoTela(3);
        printf("Jogada Invalida. Realize novamente.");
        espacoTela(60);
        printf("ú");
        printf("\n");

        espacoTela(6);
        scanf("%1d", &jogadaP);
    }
    /*if(fileira[jogadaF]- jogadaP == 0)
    {
        linhasRemovidas[contRemover] = jogadaF-1;
        contRemover++;
    }*/
    fileira[jogadaF-1] -= jogadaP;
}
/*
void computadorJogada()
{
    int i,j;
    int randomizador;
    if(dificuldade == 1)
    {
        for(i=0;i<5;i++)
        {
            if(linhasRemovidas[i]<qtdFileiras)
            {
                if(linhasRemovidas[i] == i)
                {
                    i++;
                }
                printf("I\n%d\n",i);
                system("pause");
                randomizador = (rand() % (fileira[i])+1);
                printf("\nFileira I\n%d\n", fileira[i]);
                system("pause");
                if(randomizador - fileira[i] == 0)
                {
                    linhasRemovidas[contRemover] = i;
                    contRemover++;
                    system("pause");
                }

                if(fileira[i-1] != NULL)
                {
                    fileira[i-1] -= randomizador;
                    break;
                    system("pause");
                }
                if(fileira[i] != NULL)
                {
                    fileira[i] -= randomizador;
                    break;
                    system("pause");
                }
                system("pause");
            }
        }
    }
}
*/
/*
    else if(dificuldade == 2)
    {
        for(i = 0; i<qtdFileiras;i++)
        {
            if(fileira[i] != 0)
            {
                if(fileira[i] == 1)
                {
                    fileira[i]--;
                    break;
                }
                fileira[i] -= fileira[i]-1;
                break;
            }
            else
                continue;
        }
    }
    else
    {
        for(i=0; i<qtdFileiras; i++)
        {


        }

    }
}

int *decParaBinario(int n)
{
    int numBinario[16];
    int resultado;
    int i = 15;
    while (n > 0)
    {
        numBinario[i] = n % 2;
        n = n / 2;
        i--;
    }
    for(;i>=0;i--)
    {
        numBinario[i] = 0;
    }

}

int acharMaximo(int *a, int n) {
    int c, maximo, i;

    maximo = a[0];
    i = 0;

    for (c = 1; c < n; c++)
    {
        if (a[c] > maximo)
        {
            i = c;
            maximo = a[c];
        }
    }

return i;
}
*/
#endif // GAMECONTROLLER_H_INCLUDED
