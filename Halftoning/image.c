#include "image.h"
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <GL/freeglut.h>

Imagem imagem_carrega(char* arquivo){
    Imagem img;
    FILE* pFile = NULL;
    unsigned short nNumPlanes;
    unsigned short nNumBPP;
    int i;

    if ((pFile = fopen(arquivo, "rb")) == NULL) printf("ERROR: get_image - %s not found.\n", arquivo);

    fseek(pFile, 18, SEEK_CUR);

    if ((i = fread(&img.largura, 4, 1, pFile)) != 1) printf("ERROR: get_image - Couldn't read width from %s.\n ", arquivo);
    if ((i = fread(&img.altura, 4, 1, pFile)) != 1) printf("ERROR: get_image - Couldn't read height from %s.\n ", arquivo);
    if ((fread(&nNumPlanes, 2, 1, pFile)) != 1) printf("ERROR: get_image - Couldn't read plane count from %s.\n", arquivo);
    if (nNumPlanes != 1) printf("ERROR: get_image - Plane count from %s.\n ", arquivo);
    if ((i = fread(&nNumBPP, 2, 1, pFile)) != 1) printf("ERROR: get_image - Couldn't read BPP from %s.\n ", arquivo);
    if (nNumBPP != 24) printf("ERROR: get_image - BPP from %s.\n ", arquivo);

    fseek(pFile, 24, SEEK_CUR);

    const int nTotalImagesize = (img.largura * img.altura) * 3;

    unsigned char* const pixels = malloc(nTotalImagesize);
    img.pixels = malloc(nTotalImagesize);

    if ((i = fread(pixels, nTotalImagesize, 1, pFile)) != 1) {
        printf("ERROR: get_image - Couldn't read image pixels from %s.\n ", arquivo);
    }

    for (i = 0; i < nTotalImagesize; i += 3) {
        img.pixels[i    ] = pixels[i + 2];
        img.pixels[i + 1] = pixels[i + 1];
        img.pixels[i + 2] = pixels[i];
    }

    free(pixels);
    fclose(pFile);

    glEnable(GL_TEXTURE_2D);
    glGenTextures(1, &img._id);

    return img;
}

void imagem_mostra(Imagem img){
    glBindTexture(GL_TEXTURE_2D, img._id);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, img.largura, img.altura, 0, GL_RGB, GL_UNSIGNED_BYTE, img.pixels);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    glPushMatrix();
        glBegin(GL_QUADS);
            glTexCoord2f(0, 0); glVertex3f(-1, -1, 1);
            glTexCoord2f(1, 0); glVertex3f( 1, -1, 1);
            glTexCoord2f(1, 1); glVertex3f( 1,  1, 1);
            glTexCoord2f(0, 1); glVertex3f(-1,  1, 1);
        glEnd();
    glPopMatrix();

    glFlush();
}

Imagem imagem_copia(Imagem img){
    Imagem img2;

    const int nTotalImagesize = (img.largura * img.altura) * 3;

    img2.altura = img.altura;
    img2.largura = img.largura;
    img2.pixels = malloc(nTotalImagesize);

    int i;
    for (i = 0; i < nTotalImagesize; ++i){
        img2.pixels[i] = img.pixels[i];
    }

    glEnable(GL_TEXTURE_2D);
    glGenTextures(1, &img2._id);

    return img2;
}

unsigned char imagem_pixel_ler(Imagem img, int i, int j, Cor cor){
    const int local = (i * img.largura + j) * 3;
    return img.pixels[local + cor];
}

void imagem_pixel_escrever(Imagem img, int i, int j, Cor cor, unsigned char valor){
    const int local = (i * img.largura + j) * 3;
    img.pixels[local + cor] = valor;
}
