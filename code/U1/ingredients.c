#include <stdio.h>
#include <stdbool.h>

int isPrime(int zahl){
    for(int i = 2; i < zahl - 1; i = i+1){
        if (zahl % i == 0){
            return false;
        }
    }
    return true;
}

int main(){
    int zahl = 13;
    if(isPrime(zahl)){
        printf("Is Prime\n");
    }else{
        printf("Is not\n");
    }
    return 0;
}