#include<iostream>
#include<stdio.h>
#include<string>

void atualiza_campo(int resultado[][101], const int lin, const int col, const int n, const int m){
    for(int i = (lin - 1); i <= (lin + 1); i++){
        for(int j = (col - 1); j <= (col + 1); j++){
            if(i == lin && j == col)
                continue;
            else if((i >= 0 && i <= n) && (j >= 0 && j <= m))
                resultado[i][j]++;
        }
    }
}

void reset(int res[][101], const int n, const int m){
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            res[i][j] = 0;
}

int main(int argc, char** argv){
    std::string str;
    char campo[101][101];
    int resultado[101][101];
    int n, m, qtd = 0;

    scanf("%d %d", &n, &m);
    while(true){
        if(n == 0 && m ==0){
            break;
        }

        if( qtd )
            printf("\n");

        reset(resultado, n, m);

        for(int i = 0; i < n; i++){
            scanf("%s", campo[i]);
        }

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(campo[i][j] == '*'){
                    resultado[i][j] = 999;
                    atualiza_campo(resultado, i, j, n, m);
                }
            }
        }

        printf("Field #%d:\n", ++qtd);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(resultado[i][j] >= 999)
                    std::cout << '*';
                else
                    std::cout << resultado[i][j];
            }
            printf("\n");
        }
        std::cin >> n >> m;
    } 
}