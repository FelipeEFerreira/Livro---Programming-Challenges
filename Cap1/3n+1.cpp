#include <iostream>
#include <stdlib.h>

using namespace std;

int func(int n){
    int total = 1;
    while (n != 1){
        if((n & 1) == 0)
            n /= 2;
        else
           n = (3 * n) + 1; 
        ++total;
    }
    return total;
}

int main(int argc, char** argv){
    int i = 0, j = 0, maior, menor, aux;
    int total = 0;    
    while(scanf("%d %d", &i, &j) != EOF){
        maior = i > j? i:j;
        menor = i > j? j:i;

        for(int k = menor; k <= maior; k++){
            aux = func(k);
            if(aux > total)
                total = aux;
        }
        printf("%d %d %d\n", i, j, total);
        total = 0;
    }
    return 0;
}