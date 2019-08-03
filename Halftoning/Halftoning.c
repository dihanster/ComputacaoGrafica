#include "image.h"
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <GL/freeglut.h>

void PSI2651(Imagem img, Imagem nova){
    int i, j;
    float erro;

    for (i = 0; i < img.largura; i++){
        for (j = 0; j < img.altura; j++){
            /*Tratamento para o vermelho*/
            if (imagem_pixel_ler(img, i, j, COR_R) > 127){
                imagem_pixel_escrever(nova, i, j, COR_R, 255);
            }
            else {
                imagem_pixel_escrever(nova, i, j, COR_R, 0);
            }
            erro = (imagem_pixel_ler(nova, i, j, COR_R) - imagem_pixel_ler(img, i, j, COR_R))/3;
            if (i < img.largura-1){
                imagem_pixel_escrever(img, i+1, j, COR_R, (imagem_pixel_ler(img, i+1, j, COR_R) - erro));
                if (i < img.altura-1)
                    imagem_pixel_escrever(img, i+1, j+1, COR_R, (imagem_pixel_ler(img, i+1, j+1, COR_R) - erro));
            }
            if (i < img.altura-1)
                imagem_pixel_escrever(img, i, j+1, COR_R, (imagem_pixel_ler(img, i, j+1, COR_R) - erro));

           /*Tratamento para o verde*/
            if (imagem_pixel_ler(img, i, j, COR_G) > 127)
                imagem_pixel_escrever(nova, i, j, COR_G, 255);
            else
                imagem_pixel_escrever(nova, i, j, COR_G, 0);
            erro = (imagem_pixel_ler(nova, i, j, COR_G) - imagem_pixel_ler(img, i, j, COR_G))/3;
            if (i < img.largura-1){
                imagem_pixel_escrever(img, i+1, j, COR_G, (imagem_pixel_ler(img, i+1, j, COR_G) - erro));
                if (i < img.altura-1)
                    imagem_pixel_escrever(img, i+1, j+1, COR_G, (imagem_pixel_ler(img, i+1, j+1, COR_G) - erro));
            }
            if (i < img.altura-1)
                imagem_pixel_escrever(img, i, j+1, COR_G, (imagem_pixel_ler(img, i, j+1, COR_G) - erro));

            /*Tratamento para o azul*/
            if (imagem_pixel_ler(img, i, j, COR_B) > 127)
                imagem_pixel_escrever(nova, i, j, COR_B, 255);
            else
                imagem_pixel_escrever(nova, i, j, COR_B, 0);
            erro = (imagem_pixel_ler(nova, i, j, COR_B) - imagem_pixel_ler(img, i, j, COR_B))/3;
            if (i < img.largura-1){
                imagem_pixel_escrever(img, i+1, j, COR_B, (imagem_pixel_ler(img, i+1, j, COR_B) - erro));
                if (i < img.altura-1)
                    imagem_pixel_escrever(img, i+1, j+1, COR_B, (imagem_pixel_ler(img, i+1, j+1, COR_B) - erro));
            }
            if (i < img.altura-1)
                imagem_pixel_escrever(img, i, j+1, COR_B, (imagem_pixel_ler(img, i, j+1, COR_B) - erro));
        }
    }
}

void PSI5796(Imagem img, Imagem nova){
    int i, j;
    float erro;

    for (i = 0; i < img.largura; i++){
        for (j = 0; j < img.altura; j++){
            /*Tratamento para o vermelho*/
            if (imagem_pixel_ler(img, i, j, COR_R) > 127){
                imagem_pixel_escrever(nova, i, j, COR_R, 255);
            }
            else {
                imagem_pixel_escrever(nova, i, j, COR_R, 0);
            }
            erro = (imagem_pixel_ler(nova, i, j, COR_R) - imagem_pixel_ler(img, i, j, COR_R))/2;
            if (i < img.largura-1){
                imagem_pixel_escrever(img, i+1, j, COR_R, (imagem_pixel_ler(img, i+1, j, COR_R) - erro));
                if (i < img.altura-1)
                    imagem_pixel_escrever(img, i+1, j+1, COR_R, (imagem_pixel_ler(img, i+1, j+1, COR_R)));
            }
            if (i < img.altura-1)
                imagem_pixel_escrever(img, i, j+1, COR_R, (imagem_pixel_ler(img, i, j+1, COR_R) - erro));

           /*Tratamento para o verde*/
            if (imagem_pixel_ler(img, i, j, COR_G) > 127)
                imagem_pixel_escrever(nova, i, j, COR_G, 255);
            else
                imagem_pixel_escrever(nova, i, j, COR_G, 0);
            erro = (imagem_pixel_ler(nova, i, j, COR_G) - imagem_pixel_ler(img, i, j, COR_G))/2;
            if (i < img.largura-1){
                imagem_pixel_escrever(img, i+1, j, COR_G, (imagem_pixel_ler(img, i+1, j, COR_G) - erro));
                if (i < img.altura-1)
                    imagem_pixel_escrever(img, i+1, j+1, COR_G, (imagem_pixel_ler(img, i+1, j+1, COR_G)));
            }
            if (i < img.altura-1)
                imagem_pixel_escrever(img, i, j+1, COR_G, (imagem_pixel_ler(img, i, j+1, COR_G) - erro));

            /*Tratamento para o azul*/
            if (imagem_pixel_ler(img, i, j, COR_B) > 127)
                imagem_pixel_escrever(nova, i, j, COR_B, 255);
            else
                imagem_pixel_escrever(nova, i, j, COR_B, 0);
            erro = (imagem_pixel_ler(nova, i, j, COR_B) - imagem_pixel_ler(img, i, j, COR_B))/2;
            if (i < img.largura-1){
                imagem_pixel_escrever(img, i+1, j, COR_B, (imagem_pixel_ler(img, i+1, j, COR_B) - erro));
                if (i < img.altura-1)
                    imagem_pixel_escrever(img, i+1, j+1, COR_B, (imagem_pixel_ler(img, i+1, j+1, COR_B)));
            }
            if (i < img.altura-1)
                imagem_pixel_escrever(img, i, j+1, COR_B, (imagem_pixel_ler(img, i, j+1, COR_B) - erro));
        }
    }
}

void Rogers(Imagem img, Imagem nova){
    int i, j;
    float erro;

    for (i = 0; i < img.largura; i++){
        for (j = 0; j < img.altura; j++){
            /*Tratamento para o vermelho*/
            if (imagem_pixel_ler(img, i, j, COR_R) > 127){
                imagem_pixel_escrever(nova, i, j, COR_R, 255);
            }
            else {
                imagem_pixel_escrever(nova, i, j, COR_R, 0);
            }
            erro = (imagem_pixel_ler(nova, i, j, COR_R) - imagem_pixel_ler(img, i, j, COR_R))/8;
            if (i < img.largura-1){
                imagem_pixel_escrever(img, i+1, j, COR_R, (imagem_pixel_ler(img, i+1, j, COR_R) - (3 * erro)));
                if (i < img.altura-1)
                    imagem_pixel_escrever(img, i+1, j+1, COR_R, (imagem_pixel_ler(img, i+1, j+1, COR_R) - (2 * erro)));
            }
            if (i < img.altura-1)
                imagem_pixel_escrever(img, i, j+1, COR_R, (imagem_pixel_ler(img, i, j+1, COR_R) - (3 * erro)));

           /*Tratamento para o verde*/
            if (imagem_pixel_ler(img, i, j, COR_G) > 127)
                imagem_pixel_escrever(nova, i, j, COR_G, 255);
            else
                imagem_pixel_escrever(nova, i, j, COR_G, 0);
            erro = (imagem_pixel_ler(nova, i, j, COR_G) - imagem_pixel_ler(img, i, j, COR_G))/8;
            if (i < img.largura-1){
                imagem_pixel_escrever(img, i+1, j, COR_G, (imagem_pixel_ler(img, i+1, j, COR_G) - (3 * erro)));
                if (i < img.altura-1)
                    imagem_pixel_escrever(img, i+1, j+1, COR_G, (imagem_pixel_ler(img, i+1, j+1, COR_G) - (2*erro)));
            }
            if (i < img.altura-1)
                imagem_pixel_escrever(img, i, j+1, COR_G, (imagem_pixel_ler(img, i, j+1, COR_G) - (3 * erro)));

            /*Tratamento para o azul*/
            if (imagem_pixel_ler(img, i, j, COR_B) > 127)
                imagem_pixel_escrever(nova, i, j, COR_B, 255);
            else
                imagem_pixel_escrever(nova, i, j, COR_B, 0);
            erro = (imagem_pixel_ler(nova, i, j, COR_B) - imagem_pixel_ler(img, i, j, COR_B))/8;
            if (i < img.largura-1){
                imagem_pixel_escrever(img, i+1, j, COR_B, (imagem_pixel_ler(img, i+1, j, COR_B) - (3 * erro)));
                if (i < img.altura-1)
                    imagem_pixel_escrever(img, i+1, j+1, COR_B, (imagem_pixel_ler(img, i+1, j+1, COR_B) - (2 * erro)));
            }
            if (i < img.altura-1)
                imagem_pixel_escrever(img, i, j+1, COR_B, (imagem_pixel_ler(img, i, j+1, COR_B) - (3 * erro)));
        }
    }
}

void FloydSteinberg(Imagem img, Imagem nova){
    int i, j;
    float erro;

    for (i = 0; i < img.largura; i++){
        for (j = 0; j < img.altura; j++){
            /*Tratamento para o vermelho*/
            if (imagem_pixel_ler(img, i, j, COR_R) > 127){
                imagem_pixel_escrever(nova, i, j, COR_R, 255);
            }
            else {
                imagem_pixel_escrever(nova, i, j, COR_R, 0);
            }
            erro = (imagem_pixel_ler(nova, i, j, COR_R) - imagem_pixel_ler(img, i, j, COR_R))/16;
            if (i < img.largura-1){
                imagem_pixel_escrever(img, i, j+1, COR_R, (imagem_pixel_ler(img, i, j+1, COR_R) - (7 * erro)));
                if (i < img.altura-1)
                    imagem_pixel_escrever(img, i+1, j+1, COR_R, (imagem_pixel_ler(img, i+1, j+1, COR_R) - (1 * erro)));
            }
            if (i < img.altura-1)
                imagem_pixel_escrever(img, i+1, j, COR_R, (imagem_pixel_ler(img, i+1, j, COR_R) - (5 * erro)));
            if (i > 0 && i < img.altura-1)
                imagem_pixel_escrever(img, i+1, j-1, COR_R, (imagem_pixel_ler(img, i+1, j-1, COR_R) - (3 * erro)));

           /*Tratamento para o verde*/
            if (imagem_pixel_ler(img, i, j, COR_G) > 127)
                imagem_pixel_escrever(nova, i, j, COR_G, 255);
            else
                imagem_pixel_escrever(nova, i, j, COR_G, 0);
            erro = (imagem_pixel_ler(nova, i, j, COR_G) - imagem_pixel_ler(img, i, j, COR_G))/16;
            if (i < img.largura-1){
                imagem_pixel_escrever(img, i, j+1, COR_G, (imagem_pixel_ler(img, i, j+1, COR_G) - (7 * erro)));
                if (i < img.altura-1)
                    imagem_pixel_escrever(img, i+1, j+1, COR_G, (imagem_pixel_ler(img, i+1, j+1, COR_G) - (1 * erro)));
            }
            if (i < img.altura-1)
                imagem_pixel_escrever(img, i+1, j, COR_G, (imagem_pixel_ler(img, i+1, j, COR_G) - (5 * erro)));
            if (i > 0 && i < img.altura-1)
                imagem_pixel_escrever(img, i+1, j-1, COR_G, (imagem_pixel_ler(img, i+1, j-1, COR_G) - (3 * erro)));

            /*Tratamento para o azul*/
            if (imagem_pixel_ler(img, i, j, COR_B) > 127)
                imagem_pixel_escrever(nova, i, j, COR_B, 255);
            else
                imagem_pixel_escrever(nova, i, j, COR_B, 0);
            erro = (imagem_pixel_ler(nova, i, j, COR_B) - imagem_pixel_ler(img, i, j, COR_B))/16;
            if (i < img.largura-1){
                imagem_pixel_escrever(img, i, j+1, COR_B, (imagem_pixel_ler(img, i, j+1, COR_B) - (7 * erro)));
                if (i < img.altura-1)
                    imagem_pixel_escrever(img, i+1, j+1, COR_B, (imagem_pixel_ler(img, i+1, j+1, COR_B) - (1 * erro)));
            }
            if (i < img.altura-1)
                imagem_pixel_escrever(img, i+1, j, COR_B, (imagem_pixel_ler(img, i+1, j, COR_B) - (5 * erro)));
            if (i > 0 && i < img.altura-1)
                imagem_pixel_escrever(img, i+1, j-1, COR_B, (imagem_pixel_ler(img, i+1, j-1, COR_B) - (3 * erro)));

        }
    }
}

void JarvisJudiceNinke(Imagem img, Imagem nova){
    int i, j;
    float erro;

    for (i = 0; i < img.largura; i++){
        for (j = 0; j < img.altura; j++){
            /*Tratamento para o vermelho*/
            if (imagem_pixel_ler(img, i, j, COR_R) > 127){
                imagem_pixel_escrever(nova, i, j, COR_R, 255);
            }
            else {
                imagem_pixel_escrever(nova, i, j, COR_R, 0);
            }
            erro = (imagem_pixel_ler(nova, i, j, COR_R) - imagem_pixel_ler(img, i, j, COR_R))/48;

            if (i < img.largura-1){
                imagem_pixel_escrever(img, i, j+1, COR_R, (imagem_pixel_ler(img, i, j+1, COR_R) - (7 * erro)));
                if (i < img.largura-2){
                    imagem_pixel_escrever(img, i, j+2, COR_R, (imagem_pixel_ler(img, i, j+2, COR_R) - (5 * erro)));
                }
            }
            if (i < img.altura-1){
                imagem_pixel_escrever(img, i+1, j, COR_R, (imagem_pixel_ler(img, i+1, j, COR_R) - (7 * erro)));
                if (i > 0)
                    imagem_pixel_escrever(img, i+1, j-1, COR_R, (imagem_pixel_ler(img, i+1, j-1, COR_R) - (5 * erro)));
                if (i > 1)
                    imagem_pixel_escrever(img, i+1, j-2, COR_R, (imagem_pixel_ler(img, i+1, j-2, COR_R) - (3 * erro)));
                if (i < img.largura-1)
                    imagem_pixel_escrever(img, i+1, j+1, COR_R, (imagem_pixel_ler(img, i+1, j+1, COR_R) - (5 * erro)));
                if (i < img.largura-2)
                    imagem_pixel_escrever(img, i+1, j+2, COR_R, (imagem_pixel_ler(img, i+1, j+2, COR_R) - (3 * erro)));
            }
            if (i < img.altura-2){
                imagem_pixel_escrever(img, i+2, j, COR_R, (imagem_pixel_ler(img, i+2, j, COR_R) - (5 * erro)));
                if (i > 0)
                    imagem_pixel_escrever(img, i+2, j-1, COR_R, (imagem_pixel_ler(img, i+2, j-1, COR_R) - (5 * erro)));
                if (i > 1)
                    imagem_pixel_escrever(img, i+2, j-2, COR_R, (imagem_pixel_ler(img, i+2, j-2, COR_R) - (3 * erro)));
                if (i < img.largura-1)
                    imagem_pixel_escrever(img, i+2, j+1, COR_R, (imagem_pixel_ler(img, i+2, j+1, COR_R) - (3 * erro)));
                if (i < img.largura-2)
                    imagem_pixel_escrever(img, i+2, j+2, COR_R, (imagem_pixel_ler(img, i+2, j+2, COR_R) - (1 * erro)));
            }

             /*Tratamento para o verde*/
            if (imagem_pixel_ler(img, i, j, COR_G) > 127){
                imagem_pixel_escrever(nova, i, j, COR_G, 255);
            }
            else {
                imagem_pixel_escrever(nova, i, j, COR_G, 0);
            }
            erro = (imagem_pixel_ler(nova, i, j, COR_G) - imagem_pixel_ler(img, i, j, COR_G))/48;

            if (i < img.largura-1){
                imagem_pixel_escrever(img, i, j+1, COR_G, (imagem_pixel_ler(img, i, j+1, COR_G) - (7 * erro)));
                if (i < img.largura-2){
                    imagem_pixel_escrever(img, i, j+2, COR_G, (imagem_pixel_ler(img, i, j+2, COR_G) - (5 * erro)));
                }
            }
            if (i < img.altura-1){
                imagem_pixel_escrever(img, i+1, j, COR_G, (imagem_pixel_ler(img, i+1, j, COR_G) - (7 * erro)));
                if (i > 0)
                    imagem_pixel_escrever(img, i+1, j-1, COR_G, (imagem_pixel_ler(img, i+1, j-1, COR_G) - (5 * erro)));
                if (i > 1)
                    imagem_pixel_escrever(img, i+1, j-2, COR_G, (imagem_pixel_ler(img, i+1, j-2, COR_G) - (3 * erro)));
                if (i < img.largura-1)
                    imagem_pixel_escrever(img, i+1, j+1, COR_G, (imagem_pixel_ler(img, i+1, j+1, COR_G) - (5 * erro)));
                if (i < img.largura-2)
                    imagem_pixel_escrever(img, i+1, j+2, COR_G, (imagem_pixel_ler(img, i+1, j+2, COR_G) - (3 * erro)));
            }
            if (i < img.altura-2){
                imagem_pixel_escrever(img, i+2, j, COR_G, (imagem_pixel_ler(img, i+2, j, COR_G) - (5 * erro)));
                if (i > 0)
                    imagem_pixel_escrever(img, i+2, j-1, COR_G, (imagem_pixel_ler(img, i+2, j-1, COR_G) - (5 * erro)));
                if (i > 1)
                    imagem_pixel_escrever(img, i+2, j-2, COR_G, (imagem_pixel_ler(img, i+2, j-2, COR_G) - (3 * erro)));
                if (i < img.largura-1)
                    imagem_pixel_escrever(img, i+2, j+1, COR_G, (imagem_pixel_ler(img, i+2, j+1, COR_G) - (3 * erro)));
                if (i < img.largura-2)
                    imagem_pixel_escrever(img, i+2, j+2, COR_G, (imagem_pixel_ler(img, i+2, j+2, COR_G) - (1 * erro)));
            }

             /*Tratamento para o azul*/
            if (imagem_pixel_ler(img, i, j, COR_B) > 127){
                imagem_pixel_escrever(nova, i, j, COR_B, 255);
            }
            else {
                imagem_pixel_escrever(nova, i, j, COR_B, 0);
            }
            erro = (imagem_pixel_ler(nova, i, j, COR_B) - imagem_pixel_ler(img, i, j, COR_B))/48;

            if (i < img.largura-1){
                imagem_pixel_escrever(img, i, j+1, COR_B, (imagem_pixel_ler(img, i, j+1, COR_B) - (7 * erro)));
                if (i < img.largura-2){
                    imagem_pixel_escrever(img, i, j+2, COR_B, (imagem_pixel_ler(img, i, j+2, COR_B) - (5 * erro)));
                }
            }
            if (i < img.altura-1){
                imagem_pixel_escrever(img, i+1, j, COR_B, (imagem_pixel_ler(img, i+1, j, COR_B) - (7 * erro)));
                if (i > 0)
                    imagem_pixel_escrever(img, i+1, j-1, COR_B, (imagem_pixel_ler(img, i+1, j-1, COR_B) - (5 * erro)));
                if (i > 1)
                    imagem_pixel_escrever(img, i+1, j-2, COR_B, (imagem_pixel_ler(img, i+1, j-2, COR_B) - (3 * erro)));
                if (i < img.largura-1)
                    imagem_pixel_escrever(img, i+1, j+1, COR_B, (imagem_pixel_ler(img, i+1, j+1, COR_B) - (5 * erro)));
                if (i < img.largura-2)
                    imagem_pixel_escrever(img, i+1, j+2, COR_B, (imagem_pixel_ler(img, i+1, j+2, COR_B) - (3 * erro)));
            }
            if (i < img.altura-2){
                imagem_pixel_escrever(img, i+2, j, COR_B, (imagem_pixel_ler(img, i+2, j, COR_B) - (5 * erro)));
                if (i > 0)
                    imagem_pixel_escrever(img, i+2, j-1, COR_B, (imagem_pixel_ler(img, i+2, j-1, COR_B) - (5 * erro)));
                if (i > 1)
                    imagem_pixel_escrever(img, i+2, j-2, COR_B, (imagem_pixel_ler(img, i+2, j-2, COR_B) - (3 * erro)));
                if (i < img.largura-1)
                    imagem_pixel_escrever(img, i+2, j+1, COR_B, (imagem_pixel_ler(img, i+2, j+1, COR_B) - (3 * erro)));
                if (i < img.largura-2)
                    imagem_pixel_escrever(img, i+2, j+2, COR_B, (imagem_pixel_ler(img, i+2, j+2, COR_B) - (1 * erro)));
            }

        }
    }
}

void Stucki(Imagem img, Imagem nova){
    int i, j;
    float erro;

    for (i = 0; i < img.largura; i++){
        for (j = 0; j < img.altura; j++){
            /*Tratamento para o vermelho*/
            if (imagem_pixel_ler(img, i, j, COR_R) > 127){
                imagem_pixel_escrever(nova, i, j, COR_R, 255);
            }
            else {
                imagem_pixel_escrever(nova, i, j, COR_R, 0);
            }
            erro = (imagem_pixel_ler(nova, i, j, COR_R) - imagem_pixel_ler(img, i, j, COR_R))/42;

            if (i < img.largura-1){
                imagem_pixel_escrever(img, i, j+1, COR_R, (imagem_pixel_ler(img, i, j+1, COR_R) - (8 * erro)));
                if (i < img.largura-2){
                    imagem_pixel_escrever(img, i, j+2, COR_R, (imagem_pixel_ler(img, i, j+2, COR_R) - (4 * erro)));
                }
            }
            if (i < img.altura-1){
                imagem_pixel_escrever(img, i+1, j, COR_R, (imagem_pixel_ler(img, i+1, j, COR_R) - (8 * erro)));
                if (i > 0)
                    imagem_pixel_escrever(img, i+1, j-1, COR_R, (imagem_pixel_ler(img, i+1, j-1, COR_R) - (4 * erro)));
                if (i > 1)
                    imagem_pixel_escrever(img, i+1, j-2, COR_R, (imagem_pixel_ler(img, i+1, j-2, COR_R) - (2 * erro)));
                if (i < img.largura-1)
                    imagem_pixel_escrever(img, i+1, j+1, COR_R, (imagem_pixel_ler(img, i+1, j+1, COR_R) - (4 * erro)));
                if (i < img.largura-2)
                    imagem_pixel_escrever(img, i+1, j+2, COR_R, (imagem_pixel_ler(img, i+1, j+2, COR_R) - (2 * erro)));
            }
            if (i < img.altura-2){
                imagem_pixel_escrever(img, i+2, j, COR_R, (imagem_pixel_ler(img, i+2, j, COR_R) - (4 * erro)));
                if (i > 0)
                    imagem_pixel_escrever(img, i+2, j-1, COR_R, (imagem_pixel_ler(img, i+2, j-1, COR_R) - (2 * erro)));
                if (i > 1)
                    imagem_pixel_escrever(img, i+2, j-2, COR_R, (imagem_pixel_ler(img, i+2, j-2, COR_R) - (1 * erro)));
                if (i < img.largura-1)
                    imagem_pixel_escrever(img, i+2, j+1, COR_R, (imagem_pixel_ler(img, i+2, j+1, COR_R) - (2 * erro)));
                if (i < img.largura-2)
                    imagem_pixel_escrever(img, i+2, j+2, COR_R, (imagem_pixel_ler(img, i+2, j+2, COR_R) - (1 * erro)));
            }

            /*Tratamento para o verde*/
            if (imagem_pixel_ler(img, i, j, COR_B) > 127){
                imagem_pixel_escrever(nova, i, j, COR_B, 255);
            }
            else {
                imagem_pixel_escrever(nova, i, j, COR_B, 0);
            }
            erro = (imagem_pixel_ler(nova, i, j, COR_B) - imagem_pixel_ler(img, i, j, COR_B))/42;

            if (i < img.largura-1){
                imagem_pixel_escrever(img, i, j+1, COR_B, (imagem_pixel_ler(img, i, j+1, COR_B) - (8 * erro)));
                if (i < img.largura-2){
                    imagem_pixel_escrever(img, i, j+2, COR_B, (imagem_pixel_ler(img, i, j+2, COR_B) - (4 * erro)));
                }
            }
            if (i < img.altura-1){
                imagem_pixel_escrever(img, i+1, j, COR_B, (imagem_pixel_ler(img, i+1, j, COR_B) - (8 * erro)));
                if (i > 0)
                    imagem_pixel_escrever(img, i+1, j-1, COR_B, (imagem_pixel_ler(img, i+1, j-1, COR_B) - (4 * erro)));
                if (i > 1)
                    imagem_pixel_escrever(img, i+1, j-2, COR_B, (imagem_pixel_ler(img, i+1, j-2, COR_B) - (2 * erro)));
                if (i < img.largura-1)
                    imagem_pixel_escrever(img, i+1, j+1, COR_B, (imagem_pixel_ler(img, i+1, j+1, COR_B) - (4 * erro)));
                if (i < img.largura-2)
                    imagem_pixel_escrever(img, i+1, j+2, COR_B, (imagem_pixel_ler(img, i+1, j+2, COR_B) - (2 * erro)));
            }
            if (i < img.altura-2){
                imagem_pixel_escrever(img, i+2, j, COR_B, (imagem_pixel_ler(img, i+2, j, COR_B) - (4 * erro)));
                if (i > 0)
                    imagem_pixel_escrever(img, i+2, j-1, COR_B, (imagem_pixel_ler(img, i+2, j-1, COR_B) - (2 * erro)));
                if (i > 1)
                    imagem_pixel_escrever(img, i+2, j-2, COR_B, (imagem_pixel_ler(img, i+2, j-2, COR_B) - (1 * erro)));
                if (i < img.largura-1)
                    imagem_pixel_escrever(img, i+2, j+1, COR_B, (imagem_pixel_ler(img, i+2, j+1, COR_B) - (2 * erro)));
                if (i < img.largura-2)
                    imagem_pixel_escrever(img, i+2, j+2, COR_B, (imagem_pixel_ler(img, i+2, j+2, COR_B) - (1 * erro)));
            }

            /*Tratamento para o azul*/
            if (imagem_pixel_ler(img, i, j, COR_B) > 127){
                imagem_pixel_escrever(nova, i, j, COR_B, 255);
            }
            else {
                imagem_pixel_escrever(nova, i, j, COR_B, 0);
            }
            erro = (imagem_pixel_ler(nova, i, j, COR_B) - imagem_pixel_ler(img, i, j, COR_B))/42;

            if (i < img.largura-1){
                imagem_pixel_escrever(img, i, j+1, COR_B, (imagem_pixel_ler(img, i, j+1, COR_B) - (8 * erro)));
                if (i < img.largura-2){
                    imagem_pixel_escrever(img, i, j+2, COR_B, (imagem_pixel_ler(img, i, j+2, COR_B) - (4 * erro)));
                }
            }
            if (i < img.altura-1){
                imagem_pixel_escrever(img, i+1, j, COR_B, (imagem_pixel_ler(img, i+1, j, COR_B) - (8 * erro)));
                if (i > 0)
                    imagem_pixel_escrever(img, i+1, j-1, COR_B, (imagem_pixel_ler(img, i+1, j-1, COR_B) - (4 * erro)));
                if (i > 1)
                    imagem_pixel_escrever(img, i+1, j-2, COR_B, (imagem_pixel_ler(img, i+1, j-2, COR_B) - (2 * erro)));
                if (i < img.largura-1)
                    imagem_pixel_escrever(img, i+1, j+1, COR_B, (imagem_pixel_ler(img, i+1, j+1, COR_B) - (4 * erro)));
                if (i < img.largura-2)
                    imagem_pixel_escrever(img, i+1, j+2, COR_B, (imagem_pixel_ler(img, i+1, j+2, COR_B) - (2 * erro)));
            }
            if (i < img.altura-2){
                imagem_pixel_escrever(img, i+2, j, COR_B, (imagem_pixel_ler(img, i+2, j, COR_B) - (4 * erro)));
                if (i > 0)
                    imagem_pixel_escrever(img, i+2, j-1, COR_B, (imagem_pixel_ler(img, i+2, j-1, COR_B) - (2 * erro)));
                if (i > 1)
                    imagem_pixel_escrever(img, i+2, j-2, COR_B, (imagem_pixel_ler(img, i+2, j-2, COR_B) - (1 * erro)));
                if (i < img.largura-1)
                    imagem_pixel_escrever(img, i+2, j+1, COR_B, (imagem_pixel_ler(img, i+2, j+1, COR_B) - (2 * erro)));
                if (i < img.largura-2)
                    imagem_pixel_escrever(img, i+2, j+2, COR_B, (imagem_pixel_ler(img, i+2, j+2, COR_B) - (1 * erro)));
            }

        }
    }
}

void Halftoning(){
    /*Carregando a imagem original da Lena e criando uma copia*/
    Imagem img = imagem_carrega("C:/Users/willi/Downloads/Unifesp/2018.2/Computação Gráfica/Exercicos pra entregar/ExercicioI/lena.bmp");
    Imagem nova = imagem_copia(img);

    /*Escolha do metodo de Halftoning*/
    //PSI2651(img, nova);
    //PSI5796(img, nova);
    //Rogers(img, nova);
    //FloydSteinberg(img, nova);
    //JarvisJudiceNinke(img, nova);
    Stucki(img, nova);

    /*Mostrando a imagem resultado*/
    imagem_mostra(nova);
}

int main(int argc, char **argv){
    /*Inicializacao do openGL*/
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE| GLUT_RGB);
    glutInitWindowPosition(50, 100);
    glutInitWindowSize(512, 512);

    /*Criacao da Janela de exibicao e exibicao da imagem*/
    glutCreateWindow("Halftoning");
    glutDisplayFunc(Halftoning);

    /*Programa em Loop*/
    glutMainLoop (); //Mostra tudo e espera
    return 0;
}
