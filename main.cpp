/*
1. Para a entrada do programa, é necessário um arquivo .txt nomeado "entrada.txt".
2. Para que funcione corretamente, é esperado que as entradas respeitem os limites de linhas e colunas (22 linhas e 80 colunas).
3. Este programa foi apenas testado em Windows, por isso, foi utilizada a função system("cls").
*/

#include <iostream>
#include <fstream>
#include <windows.h>

using namespace std;

void zeraVizinhos(int vizinhos[22][80]){
     for(int i = 0; i < 22; i++){
        for(int j = 0; j < 80; j++){
            vizinhos[i][j] = 0;
        }
    }
}
void contaVizinhos(int c[22][80], int vizinhos[22][80]){
     for(int i = 0; i < 22; i++){
        for(int j = 0; j < 80; j++){
            if(i == 0){
                if(j == 0){
                   //Confere os vizinhos próximos da célula do canto 1
                    if(c[i][j+1] == 1){
                       vizinhos[i][j]++;
                    }

                    if(c[i+1][j] == 1){
                       vizinhos[i][j]++;
                    }

                    if(c[i+1][j+1] == 1){
                       vizinhos[i][j]++;
                    }

                }else if(j == 79){
                   //Confere os vizinhos próximos da célula do canto 2
                    if(c[i][j-1] == 1){
                       vizinhos[i][j]++;
                    }

                    if(c[i+1][j-1] == 1){
                       vizinhos[i][j]++;
                    }

                    if(c[i+1][j] == 1){
                       vizinhos[i][j]++;
                    }
                }else{
                    //Confere os vizinhos próximos das células entre os cantos de 0 a 80 - na linha 0
                    if(c[i][j-1] == 1){
                       vizinhos[i][j]++;
                    }

                    if(c[i+1][j-1] == 1){
                       vizinhos[i][j]++;
                    }

                    if(c[i+1][j] == 1){
                       vizinhos[i][j]++;
                    }

                    if(c[i+1][j+1] == 1){
                       vizinhos[i][j]++;
                    }

                    if(c[i][j+1] == 1){
                       vizinhos[i][j]++;
                    }
                }
            }else if(i == 21){
                if(j == 0){
                   //Confere os vizinhos próximos da célula do canto 3
                    if(c[i-1][j] == 1){
                       vizinhos[i][j]++;
                    }

                    if(c[i-1][j+1] == 1){
                       vizinhos[i][j]++;
                    }

                    if(c[i][j+1] == 1){
                       vizinhos[i][j]++;
                    }

                }else if(j == 79){
                    //Confere os vizinhos próximos da célula do canto 4
                    if(c[i-1][j] == 1){
                       vizinhos[i][j]++;
                    }

                    if(c[i-1][j-1] == 1){
                       vizinhos[i][j]++;
                    }

                    if(c[i][j-1] == 1){
                       vizinhos[i][j]++;
                    }
                }else{
                    //Confere os vizinhos próximos das células entre os cantos de 0 a 80 - linha 22
                    if(c[i][j-1] == 1){
                       vizinhos[i][j]++;
                    }

                    if(c[i][j+1] == 1){
                       vizinhos[i][j]++;
                    }

                    if(c[i-1][j] == 1){
                       vizinhos[i][j]++;
                    }

                    if(c[i-1][j-1] == 1){
                       vizinhos[i][j]++;
                    }

                    if(c[i-1][j+1] == 1){
                       vizinhos[i][j]++;
                    }
                }
            }else{
            if(j == 0 && i != 0){
                    //Confere os vizinhos próximos das células entre os cantos de 0 a 22 - coluna 0
                    if(c[i+1][j] == 1){
                       vizinhos[i][j]++;
                    }

                    if(c[i-1][j] == 1){
                       vizinhos[i][j]++;
                    }

                    if(c[i][j+1] == 1){
                       vizinhos[i][j]++;
                    }

                    if(c[i-1][j+1] == 1){
                       vizinhos[i][j]++;
                    }

                    if(c[i+1][j+1] == 1){
                       vizinhos[i][j]++;
                    }
            }else if(j == 79 && i != 21){
                    //Confere os vizinhos próximos das células entre os cantos de 0 a 22 - coluna 80
                    if(c[i-1][j] == 1){
                       vizinhos[i][j]++;
                    }

                    if(c[i+1][j] == 1){
                       vizinhos[i][j]++;
                    }

                    if(c[i][j-1] == 1){
                       vizinhos[i][j]++;
                    }

                    if(c[i-1][j-1] == 1){
                       vizinhos[i][j]++;
                    }

                    if(c[i+1][j-1] == 1){
                       vizinhos[i][j]++;
                    }
            }else{
            //todos os casos ''normais''
                    if(c[i-1][j] == 1){
                       vizinhos[i][j]++;
                    }

                    if(c[i+1][j] == 1){
                       vizinhos[i][j]++;
                    }

                    if(c[i][j-1] == 1){
                       vizinhos[i][j]++;
                    }

                    if(c[i][j+1] == 1){
                       vizinhos[i][j]++;
                    }

                    if(c[i-1][j+1] == 1){
                       vizinhos[i][j]++;
                    }

                    if(c[i+1][j+1] == 1){
                       vizinhos[i][j]++;
                    }

                    if(c[i-1][j-1] == 1){
                       vizinhos[i][j]++;
                    }

                    if(c[i+1][j-1] == 1){
                       vizinhos[i][j]++;
                    }
            }

          }
        }
    }

}

void verificaOcupacao(int ocupados[22][80], int c[22][80]){
     for(int i = 0; i < 22; i++){
        for(int j = 0; j < 80; j++){
            if(c[i][j] == 1){
                ocupados[i][j] = 1;
            }else{
                ocupados[i][j] = 0;
            }
        }
    }
}

void geracao(int ocupados[22][80], int vizinhos[22][80], int matrix[22][80]){
     for(int i = 0; i < 22; i++){
        for(int j = 0; j < 80; j++){
            if(ocupados[i][j] == 1){
                if(vizinhos[i][j] == 0 || vizinhos[i][j] == 1){
                    matrix[i][j] = 0;
                }else if(vizinhos[i][j] > 3){
                    matrix[i][j] = 0;
                }
            }else{
                if(vizinhos[i][j] == 3){
                    matrix[i][j] = 1;
                }
            }
        }
    }
}

void mostra(int matrix[22][80]){
     for(int i = 0; i < 22; i++){
        for(int j = 0; j < 80; j++){
            if(matrix[i][j] == 1){
            cout << "*";
            }else{
            cout << " ";
            }
        }
        cout << endl;
    }
}

int main(){
    ifstream in("entrada.txt");

    char c[22][80];

    if(in.is_open() && in.good()){
        for(int i = 0; i < 22; i++){
            for(int j = 0; j < 80; j++){
                in >> c[i][j];
            }
        }
    }

   int vizinhos[22][80], ocupados[22][80];

   int matrix[22][80];

   for(int i = 0; i < 22; i++){
    for(int j = 0; j < 80; j++){
        matrix[i][j] = c[i][j]- '0';
    }
   }

   for(int k = 0; k < 100; k++){
    zeraVizinhos(vizinhos);
    contaVizinhos(matrix, vizinhos);
    verificaOcupacao(ocupados, matrix);
    geracao(ocupados, vizinhos, matrix);
    system("cls");
    Sleep(250);
    mostra(matrix);
   }

    in.close();
    return 0;
}
