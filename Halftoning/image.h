#pragma once
#include <GL/freeglut.h>

/// Biblioteca para mostrar imagens de tamanho de potencia de 2
///
/// Como carregar imagem:
///
/// Imagem img = imagem_carrega("nome_do_arquivo.bmp");
///
/// Como mostrar imagem:
///
/// imagem_mostra(img);
///
/// Como copiar uma imagem:
///
/// Imagem img_noma = imagem_copia(img);
///
/// Como acessar o componente vermelho de um pixel (10, 20) da imagem:
///
/// unsigned char vermelho = imagem_pixel_ler(img, 10, 20, COR_R);
///
/// Como atribuir o valor 255 ao componente verde de um pixel (10, 20) da imagem:
///
/// imagem_pixel_escrever(img, 10, 20, COR_G, 255);

typedef struct {
    GLuint _id;
    int largura;
    int altura;
    unsigned char* pixels;
} Imagem;

typedef enum {
    COR_R = 0,
    COR_G = 1,
    COR_B = 2,
} Cor;

Imagem imagem_carrega(char* arquivo);

void imagem_mostra(Imagem img);

Imagem imagem_copia(Imagem img);

unsigned char imagem_pixel_ler(Imagem img, int i, int j, Cor cor);

void imagem_pixel_escrever(Imagem img, int i, int j, Cor cor, unsigned char valor);

