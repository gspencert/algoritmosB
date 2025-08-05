#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main(){
    int idade; 
    float tempoSono;
    
    scanf("%d", &idade);
    
    tempoSono = idade/3;

    printf("voce dormiu %.2f anos", tempoSono);

}