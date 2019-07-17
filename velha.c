//última alteração feita em 04/07/2019
//alterções: inserção da função escolheSimbolo(), marcaPosicao() e modificação da verificaPosicao().
//             Também foram feitos testes na função sorteiaPrimeiro()
  //próximos passos: implementar a função verificaSituacaoDoJogo(), arrumar a main()
   //                [está servindo mais para testes no momento] e melhorar a exibição das matrizes*/

#include <stdio.h>
#include <stdlib.h>//Bibliote para utilizar o srand
#include <time.h>//Biblioteca para gerar nova semente do srand
#define N 3

int jogo [N][N];

void mostraPosicoes();
void inicializaMatriz();
int sorteiaPrimeiro();
char escolheSimbolo();


//Pede posicao ao usuario que sera analisada na funcao veriricaPosicaoVazia
int pedePosicao();
int marcaPosicao(int posicao, int jogador);

//a posição nessa função é baseada na matriz exibida no início do jogo.
//o usuário só necessita informar um dos números da primeira matriz
int verificaPosicaoVazia(int i, int j);

//1 -> jogador 1 venceu
//2 -> jogador 2 venceu
//0 -> velha
//3 -> ainda não acabou
int verificaSituacaoDoJogo();

void mostraPosicoes(){

  printf("---------------------------\n");
  printf("|      JOGO DA VELHA      | \n");
  printf("|        UTFPR 2019       |\n");
  printf("|                         |\n");
  printf("|         ALUNOS          |\n");
  printf("|     Jhonatan Cunha      |\n");
  printf("|      Jessé Pires       |\n");
  printf("---------------------------\n\n");
  printf("        1 |  2 |  3  \n");
  printf("      --------------\n");
  printf("        4 |  5 |  6  \n");
  printf("      --------------\n");
  printf("        7 |  8 |  9  \n");

  printf("\n\n");
}

//INICIALIZA A MATRIZ COM CAMPOS VAZIOS
void inicializaMatriz(){

  for(int i = 0; i < N; i++){

    for(int j = 0; j < N; j++){

      jogo[i][j] = 0;

    }

  }
}

//Sortei qual vai ser o primeiro player a jogador
//P1 OU P2
int sorteiaPrimeiro(){

  srand( (unsigned)time NULL);

  return (rand() % 2) + 1;

}

//MARCA A POSICAO ESCOLHIDA PELO JOGADOR
//SO MARCA SE A POSICAO ESTIVER VAZIA
int marcaPosicao(int posicao, int jogador){

  int i, j;

  switch(posicao){

    case 1:

      i = 0;
      j = 0;
      break;

    case 2:

      i = 0;
      j = 1;
      break;

    case 3:

      i = 0;
      j = 2;
      break;

    case 4:

      i = 1;
      j = 0;
      break;

    case 5:

      i = 1;
      j = 1;
      break;

    case 6:

      i = 1;
      j = 2;
      break;

    case 7:

      i = 2;
      j = 0;
      break;

    case 8:

      i = 2;
      j = 1;
      break;

    case 9:

      i = 2;
      j = 2;
      break;

    default:

      return -1;

  }

  //VERIFICA SE i E j ESTÃO VAZIAS
  if(verificaPosicaoVazia(i, j) == 0){

    jogo[i][j] = jogador;
    return 0;
  }else{
    printf("======================\n");
    printf("  Posicao Preenchida!\n");
    printf("======================\n");
      return -1;
    }

}

//FUNCAO PARA VERIFICAR SE CAMPO ESTÁ VAZIA
int verificaPosicaoVazia(int i, int j){

  if(jogo[i][j] == 0){

    return 0;

  }

  return -1;

}

//FUNCAO PARA PLAYER 1 ESCOLHER X OU O
char escolheSimbolo(){

  char simbolo;
  printf("===================================\n");
  printf("SÍMBOLO PARA JOGADOR 1 (O ou X): ");
  scanf(" %c", &simbolo);
  printf("===================================\n");

  while(simbolo != 'X' && simbolo != 'O' && simbolo != 'x' && simbolo != 'o'){
    printf("SÍMBOLO INVÁLIDO!\n");
    printf("SÍMBOLO PARA JOGADOR 1 (O ou X): ");
    scanf(" %c", &simbolo);
  printf("===================================\n");
  }

  return simbolo;

}

//PEDE UMA POSICAO PARA CADA PLAYER
int pedePosicao(){
  int x;
  do{
  printf("===================================\n");
    printf("    DIGITE UMA POSIÇÃO: ");
    scanf(" %d", &x);
  printf("===================================\n");
    fflush(stdin);
//Verifica se os dados de entrada sao validos
//Funcao isdigit verifica se o dado de entrada é uma letra do alfabeto
    if(x < 1 || x > 9){
      printf("======================\n");
      printf("   Posicao Invalida!\n");
      printf("======================\n");
    }

  }while(x < 1 || x > 9);
  return x;
}


//VERIFICA SE O JOGO ACABOU OU NÃO
//1 -> jogador 1 venceu
//2 -> jogador 2 venceu
//3 -> velha
//-1 -> ainda não acabou
int verificaSituacaoDoJogo(){
        int cont = 0;

        //Verificação Linha jogador 1

        for(int i = 0; i < N; i++){
          for(int j = 0; j < N; j++){
              if(jogo[i][j] == 1){
                  cont++;
              }
          }
          if(cont == 3){
            printf("======================\n");
            printf("   JOGADOR 1 GANHOU\n");
            printf("======================\n");
            return 1;
          }
          cont = 0;
        }

        //Verificação Linha jogador 2

                for(int i = 0; i < N; i++){
                  for(int j = 0; j < N; j++){
                        if(jogo[i][j] == 2){
                            cont++;
                        }
                  }
                      if(cont == 3){
                        printf("======================\n");
                        printf("   JOGADOR 2 GANHOU\n");
                        printf("======================\n");
                        return 2;
                      }
                  cont = 0;
                }




          //Verificação coluna jogador 1

            for(int j = 0; j < N; j++){
                for(int i = 0; i < N; i++){
                  if(jogo[i][j] == 1){
                      cont++;
                  }
                }
                if(cont == 3){
                  printf("======================\n");
                  printf("   JOGADOR 1 GANHOU\n");
                  printf("======================\n");
                  return 1;
                }
              cont = 0;
            }



        //Verificação coluna jogador 2


              for(int j = 0; j < N; j++){
                for(int i = 0; i < N; i++){
                  if(jogo[i][j] == 2){
                      cont++;
                  }
                }
                if(cont == 3){
                  printf("======================\n");
                  printf("   JOGADOR 2 GANHOU\n");
                  printf("======================\n");
                  return 2;
                }
                cont = 0;
              }


      //Verifica Diagonal Principal do jogador 1

              for(int i = 0; i < N; i++){
                    if(jogo[i][i] == 1){
                      cont++;
                    }
                }
                if(cont == 3){
                  printf("======================\n");
                  printf("   JOGADOR 1 GANHOU\n");
                  printf("======================\n");
                  return 1;
               }
              cont = 0;

      //verifica diagonal secundaria do jogador 1
      for(int i = 0; i < N; i++){
          for(int j = 0; j < N; j++){
            if(jogo[i][j] != 0 && jogo[i][j] != 2){
                if(i+j == 2){
                    cont++;
                }
            }
          }
          if(cont  == 3){
            printf("======================\n");
            printf("   JOGADOR 1 GANHOU\n");
            printf("======================\n");
                return 1;
          }
      }
        cont = 0;


      //Verifica Diagonal Principal do jogador 2

            for(int i = 0; i < N; i++){
                if(jogo[i][i] == 2){
                  cont++;
                }
            }

              if(cont == 3){
                printf("======================\n");
                printf("   JOGADOR  GANHOU\n");
                printf("======================\n");
              return 2;
              }
              cont = 0;

          //verifica diagonal secundaria do jogador 2
          for(int i = 0; i < N; i++){
              for(int j = 0; j < N; j++){
                  if(jogo[i][j] != 0 && jogo[i][j] != 1){
                      if(i+j == 2){
                          cont++;
                      }
                  }
              }
          if(cont  == 3){
            printf("======================\n");
            printf("   JOGADOR 2 GANHOU\n");
            printf("======================\n");
            return 2;
          }

        }

        cont = 0;

        for(int i =0; i< 3; i++){
          for(int j= 0; j < 3; j++){
            if(jogo[i][j] != 0){
              cont++;
            }
          }
        }

        if(cont == 9){
          printf("======================\n");
          printf("      DEU VELHA\n");
          printf("======================\n");
          return 3;
        }

        return -1;
}

int main(){

  char jogadorUm, jogadorDois;
  int posicao, jogadorAtual;
  int flag = 0;

  int ganhador;

  mostraPosicoes();
  inicializaMatriz();

  jogadorUm = escolheSimbolo();

  if(jogadorUm == 'X' || jogadorUm == 'x'){

    jogadorDois = 'O';

  }else{

    jogadorDois = 'X';

  }

  printf("\n\n       JOGADOR 1: %c\n", jogadorUm);
  printf("       JOGADOR 2: %c\n", jogadorDois);

  jogadorAtual = sorteiaPrimeiro();

  printf("\n\n  JOGADOR %d COMEÇA O JOGO!\n\n", jogadorAtual);


        do{


              posicao = pedePosicao();
              int verify = marcaPosicao(posicao, jogadorAtual);
              if(verify != -1){
                  for(int i = 0; i < 3; i++){

                    printf("\n");

                    for(int j = 0; j < 3; j++){

                      if(jogo[i][j] == 0){

                        printf("    ");

                      }else if(jogo[i][j] == 1){

                        printf("  %c ", jogadorUm);

                      }else{

                        printf("  %c ", jogadorDois);

                      }
                      if(j != 2){
                      printf("|");
                      }
                    }
                    if(i != 2){
                    printf("\n--------------\n");
                    }
                  }
                    if(jogadorAtual == 1){

                      jogadorAtual = 2;

                    }else{
                      jogadorAtual = 1;
                    }

                printf("\n\n");

              ganhador = verificaSituacaoDoJogo();

              if(ganhador == 1 || ganhador == 2 || ganhador == 3){
                break;
              }
                      
          printf("É A VEZ DO JOGADOR %d\n", jogadorAtual);
}
        }while(ganhador != 1 || ganhador != 2 || ganhador != 3);


  return 0;

}
