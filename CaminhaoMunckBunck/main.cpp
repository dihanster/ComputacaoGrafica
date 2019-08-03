/***************************************************************/
/* Computacao Grafica 2018.2 - Profa Dr. Regina Celia Coelho   */
/* Nome: Willian Dihanster Gomes de Oliveira RA: 112269        */
/* Exercicio 4: Braco Mecanico                                 */
/***************************************************************/
#include <stdio.h>
#include <math.h>
#include <windows.h>
#include <GL/freeglut.h>

/*Definicao e inicializacao das variveis globais*/
GLint estado = 0, vazio = 0, andando = 0, cont = 0, cont_corda = 0;
GLint slices = 20, stacks = 20, nrings = 20, largura_tela = 800, altura_tela = 600;
GLdouble x = 0.0, y = 0.0, x_pos = 0.0, y_pos = 0.0, x_mouse = 0.0, y_mouse = 0.0;
GLdouble x_corda = 0.0, y_corda = 0.0, x_tora = 0.0, y_tora = 0.0, x_mouse_novo = 0.0, y_mouse_novo = 0.0;
GLdouble dist_x = 0.0, dist_y = 0.0, dist_euc = 0.0, velocidade_caminhao = 10.0;
GLdouble escala = 150.0, rotacao = 0.0, rot_base = 0.0, rot_braco = 20.0;
GLdouble ang_x = 0.0, ang_y = 0.0, ang_z = 0.0, ang_vet = 0.0;

/*Definicao do tipo de dados da fila*/
struct dados{
    int info;
    double x, y;
    struct dados *prox;
};typedef struct dados tipoDado;

/*Definicao do tipo da fila*/
struct fila{
    tipoDado *primeiro;
    tipoDado *ultimo;
    int tamanho;
};typedef struct fila tipoFila;

/*Inicia uma fila nula*/
tipoFila *filaAux = NULL;

/*Faz a insercao de um novo elemento da fila com coord x e y*/
void insereFinal(double x, double y){
    tipoDado *novo = (tipoDado*) malloc(sizeof(tipoDado));
    novo->x = x;
    novo->y = y;
    if(filaAux == NULL){
        filaAux = (tipoFila*) malloc(sizeof(tipoFila));
        novo->prox = NULL;
        filaAux->primeiro = novo;
        filaAux->ultimo = novo;
    }
    else{
        novo->prox = NULL;
        filaAux->ultimo->prox = novo;
        filaAux->ultimo = novo;
    }
    filaAux->tamanho++;
}

/*Faz a remocao da cabeca da fila*/
void removeFila(tipoFila *filaAux){
    tipoDado *aux = filaAux->primeiro;
    filaAux->primeiro = aux->prox;
    free(aux);
}

/*Faz a impressao dos elementos da fila*/
void imprimeFila(tipoFila *filaAux){
    tipoDado *aux = filaAux->primeiro;
    while(aux != NULL){
        printf("%d",aux->info);
        aux = aux->prox;
    }
}

/*Desenha a tora atual, que o caminhao esta pegando*/
void desenha_tora(){
    glColor3d(0.6, 0.4, 0.2);
    glPushMatrix();
        glTranslated(x_tora, y_tora-10, -100);
        glutSolidSphere(20, slices, stacks);
    glPopMatrix();
}

/*Desenha as toras que estao na fila*/
void desenha_tora_fila(double x_tora_fila, double y_tora_fila){
    glColor3d(0.6, 0.4, 0.2);
    glPushMatrix();
        glTranslated(x_tora_fila, y_tora_fila-10, -100);
        glutSolidSphere(20, slices, stacks);
    glPopMatrix();
}

/*Desenha o braco mecanico*/
void desenha_braco(){
    glColor3d(0, 0, 0);

    /*Faz a base do negocio parte de baixo*/
    glPushMatrix();
        glTranslated(0.04, -0.21, 0);
        glScaled(1.1, 0.4, 0.5);
        glutWireCube(0.14);
    glPopMatrix();

    /*Faz a base do negocio, parte do meio*/
    glPushMatrix();
        glTranslated(0.042, -0.165, 0);
        glScaled(0.8, 0.60, 0.5);
        glutWireCube(0.05);
    glPopMatrix();

    /*Hierarquia dos bracos*/
    glPushMatrix();

        glTranslated(+0.04, 0, 0);
        glRotated(rot_base, 0, 1, 0);
        glTranslated(-0.04, 0, 0);

        /*Parte principal parada*/
        glPushMatrix();
            glScaled(0.4, 1.5, 0.5);
            glutWireCube(0.2);
        glPopMatrix();

        /*Quadradinho de baixo*/
        glPushMatrix();
            glTranslated(0.08, -0.12, 0);
            glScaled(1.5, 1.1, 0.5);
            glutWireCube(0.05);
        glPopMatrix();

        /*Hierarquia do braco*/
        glPushMatrix();
            glRotated(rot_braco/2, 0, 0, 1);

            /*braco amarelo*/
            glPushMatrix();
                glTranslated(0.11, 0.07, 0);
                glRotated(-100, 0, 0, 1);
                glScaled(1.2, 0.2, 0.5);
                glutWireCube(0.2);
            glPopMatrix();

            /*Braco de cima*/
            glPushMatrix();
                glTranslated(0.13, 0.20, 0);
                glRotated(rot_braco/2, 0, 0, 1);
                glRotated(-140, 0, 0, 1);
                glScaled(1.7, 0.2, 0.5);
                glutWireCube(0.2);
            glPopMatrix();

            /*parte do braco amarelo que encolhe*/
            glPushMatrix();
                glRotated(-rot_braco/8, 0, 0, 1);
                glPushMatrix();
                    glTranslated(0.09, -0.05, 0);
                    glRotated(-100, 0, 0, 1);
                    glScaled(1.1, 0.2, 0.5);
                    glutWireCube(0.1);
                glPopMatrix();
            glPopMatrix();

            /*Cordinha*/
            glRotated(-rot_braco/2, 0, 0, 1);
            glPushMatrix();
                glTranslated(0.20 + x_corda, 0.20 + y_corda, 0);
                glScaled(0.03, 1.5, 0.03);
                glutWireCube(0.2);
            glPopMatrix();

        glPopMatrix();

    glPopMatrix();
}

/*Desenha o caminhao*/
void desenha_caminhao(){
    /*Frente do caminhao*/
    glPushMatrix();
        glTranslated(-0.4, -0.14, 0);
        glutWireCube(0.4);
    glPopMatrix();

    /*Desenha traseira do caminhao*/
    glPushMatrix();
        glTranslated(0.20, -0.29, 0);
        glScaled(1.5, 0.2, 1);
        glutWireCube(0.5);
    glPopMatrix();

    /*Roda dianteira 1*/
    glPushMatrix();
        glTranslated(-0.35, -0.46, 0.2);
        glScaled(0.3, 0.3, 0.3);
        glutSolidTorus(0.1, 0.3, slices, nrings);
    glPopMatrix();

    /*Roda dianteira 2*/
    glPushMatrix();
        glTranslated(-0.35, -0.46, -0.2);
        glScaled(0.3, 0.3, 0.3);
        glutSolidTorus(0.1, 0.3, slices, nrings);
    glPopMatrix();

    /*Roda traseira 1*/
    glPushMatrix();
        glTranslated(+0.35, -0.46, 0.2);
        glScaled(0.3, 0.3, 0.3);
        glutSolidTorus(0.1, 0.3, slices, nrings);
    glPopMatrix();

    /*Roda traseira 2*/
    glPushMatrix();
        glTranslated(+0.35, -0.46, -0.2);
        glScaled(0.3, 0.3, 0.3);
        glutSolidTorus(0.1, 0.3, slices, nrings);
    glPopMatrix();
}

/*Funcao principal para o desenhos do caminhao e as toras*/
void display(){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    /*Checa os limites da tela*/
    if (x_pos > 355)
        x_pos = 355;
    if (x_pos < -330)
        x_pos = -330;
    if (y_pos > 230)
        y_pos = 230;
    if (y_pos < -205)
        y_pos = -205;

    /*Desenha a tora atual e as toras na fila*/
    if (filaAux != NULL){
        tipoDado *aux = filaAux->primeiro;
        if (estado == 0){
            x_tora = aux->x;
            y_tora = aux->y;
        }
        desenha_tora();
        aux = aux->prox;
        while (aux != NULL){
            desenha_tora_fila(aux->x, aux->y);
            aux = aux->prox;
        }
    }

    glPushMatrix();
        /*Aplica as transformacoes no desenho do caminhao e braco*/
        glTranslated(x_pos, y_pos, 0.0);
        glScaled(escala, escala, escala);
        glRotated(rotacao, 0, 0, 1);
        glRotated(ang_x, 1, 0, 0);
        glRotated(ang_y, 0, 1, 0);
        glRotated(ang_z, 0, 0, 1);
        glRotated(180, 0, 1, 0);

        glPushMatrix();
            glTranslated(0, 0.025, 0);
            glScaled(1.1, 1.1, 1.1);
            desenha_braco();
        glPopMatrix();

        glPushMatrix();
            desenha_caminhao();
        glPopMatrix();

    glPopMatrix();

    glutSwapBuffers();
}

/*Faz a leitura das coordenadas atuais do mouse*/
void interacao_mouse(int botao, int estado, int x, int y){
    /* Checa se algum botao foi presionado*/
    if (botao == GLUT_LEFT_BUTTON && estado == GLUT_DOWN){
        /*Checa os limites da tela*/
        if (x > 720)
            x = 720;
        if (x < 115)
            x = 115;
        if (y > 490)
            y = 490;
        if (y < 90)
            y = 90;

        /*Transforma as coordenados do mouse*/
        x_mouse_novo = x - largura_tela/2;
        y_mouse_novo = - y + altura_tela/2;

        /*Insere as coordenadas na fila de toras*/
        insereFinal(x_mouse_novo, y_mouse_novo);
    }
}

/*Funcao que calcula a posicao do caminhao e etc*/
void move_caminhao(){
    if (estado == 7){
        x_mouse = -285.0;
        y_mouse = -190.0;
    }
    else {
        if (filaAux != NULL && estado == 0){
            x_mouse = filaAux->primeiro->x;
            y_mouse = filaAux->primeiro->y;
        }
        else if (estado == 14){
                x_mouse = 0.0;
                y_mouse = 0.0;
        }
    }

    dist_x = x_mouse - x_pos;
    dist_y = y_mouse - y_pos;
    dist_euc = sqrt(dist_x * dist_x + dist_y * dist_y);

    /*Verifica se a dist. do caminhao ao ponto eh menor que e velocidade do caminhao*/
    if (dist_euc < velocidade_caminhao){
        x_pos = x_mouse;
        y_pos = y_mouse;
        if (andando == 1 && estado == 0)
            estado = 1;
        andando = 0;
    }
    /*Se nao, entao ainda tem que andar mais, tbm calcula-se o angulo que deve andar*/
    else {
        andando = 1;
        ang_vet = atan2(dist_y, dist_x);
        x_pos += cos(ang_vet) * velocidade_caminhao;
        y_pos += sin(ang_vet) * velocidade_caminhao;
        if (estado == 0)
            rotacao = (ang_vet * 100/3.14);
    }
}

/*Funcao que atualiza a cena a cada determinado valor de tempo*/
void atualiza_cena(int value){
    move_caminhao();

    /*Estados possiveis para o caminhao*/

    /*vira a base pra preparar*/
    if (estado == 1){
        if (rot_base < 90)
            rot_base += 2.0;
        else
            estado = 2;
    }

    /*Abaixa*/
    if (estado == 2){
        if (rot_braco > -30){
            rot_braco -= 2.0;
            if (cont_corda < 25){
                x_corda += 0.0055;
                y_corda -= 0.007;
                cont_corda++;
            }
        }
        else {
            estado = 3;
            cont_corda = 0;
        }
    }

    /*Volta pra cima*/
    if (estado == 3){
        if (rot_braco < 20){
            rot_braco += 2.0;
            if (cont_corda < 25){
                x_corda -= 0.0055;
                y_corda += 0.007;
                x_tora -= 0.5;
                y_tora += 1;
                cont_corda++;
            }
        }
        else {
            estado = 4;
            cont_corda = 0;
        }
    }

    /*Volta a base*/
    if (estado == 4){
        if (rot_base > 0){
            rot_base -= 2.0;
            x_tora -= 0.5;
            y_tora -= 0.5;
        }
        else
            estado = 5;
    }

    /*Abaixa pra soltar a tora*/
    if (estado == 5){
        if (rot_braco > -30){
            rot_braco -= 2.0;
            if (cont_corda < 25){
                x_corda += 0.0055;
                y_corda -= 0.007;
                x_tora -= 0.4;
                y_tora -= 0.65;
                cont_corda++;
            }
        }
        else {
            estado = 6;
            cont_corda = 0;
        }
    }

    /*Gira o caminhao*/
    if (estado == 6){
        if (ang_y < 180){
            ang_y += 10.0;
            x_tora += 3;
            y_tora += 0.5;
        }
        else
            estado = 7;
    }

    /*Vai andar, pra jogar a tora fora*/
    if (estado == 7){
        //if (andando){
        x_mouse = -285.0;
        y_mouse = -190.0;
        //}
        x_tora = x_pos + 55;
        y_tora = y_pos + 3.5;
        if (x_pos == -285.0)
            estado = 8;
    }

    /*Volta pra cima*/
    if (estado == 8){
        if (rot_braco < 20){
            rot_braco += 2.0;
            if (cont_corda < 25){
                x_corda -= 0.0055;
                y_corda += 0.007;
                x_tora -= 0.5;
                y_tora += 1;
                cont_corda++;
            }
        }
        else {
            cont_corda = 0;
            estado = 9;
        }
    }

     /*vira a base pra preparar*/
    if (estado == 9){
        if (rot_base < 90){
            rot_base += 2.0;
            x_tora -= 0.7;
            y_tora -= 0.3;
        }
        else
            estado = 10;
    }

    /*Abaixa*/
    if (estado == 10){
        if (rot_braco > -30){
            rot_braco -= 2.0;
            if (cont_corda < 25){
                x_corda += 0.0055;
                y_corda -= 0.007;
                //x_tora -= 0.1;
                y_tora -= 2;
                cont_corda++;
            }
        }
        else {
            estado = 11;
            cont_corda = 0;
        }
    }

    /*Volta pra cima*/
    if (estado == 11){
        if (rot_braco < 20){
            rot_braco += 2.0;
            if (cont_corda < 25){
                x_corda -= 0.0055;
                y_corda += 0.007;
                cont_corda++;
            }
        }
        else {
            estado = 12;
            cont_corda = 0;
        }
    }

    /*Volta a base*/
    if (estado == 12){
        if (rot_base > 0)
            rot_base -= 2.0;
        else
            estado = 13;
    }

    /*Gira o caminhao*/
    if (estado == 13){
        if (ang_y > 0)
        ang_y -= 5.0;
        else
            estado = 14;
    }

    /*Volta pro centro*/
    if (estado == 14){
        x_mouse = 0.0;
        y_mouse = 0.0;
        if (!andando)
            estado = 15;
    }

    /*Verifica se ainda tem tora na fila. Se tem, estado 0 para recomecar*/
    if (estado == 15){
        if (filaAux->primeiro->prox != NULL){
            filaAux->primeiro = filaAux->primeiro->prox;
            estado = 0;
        }
        else
            x_mouse = y_mouse = 0;
    }

    glutPostRedisplay();
    glutTimerFunc(30, atualiza_cena, 0);
}

/*Funcao para leitura das teclas para rotacao do caminhao, e rotacao do braco, da base, e escala*/
static void funcoes_teclas(unsigned char key, int x, int y){
    /*Teclas
        q encerra o programa
        x e X roda no eixo x (x soma no angulo, X subtrai no angulo)
        y e Y roda no eixo y
        z e Z roda no eixo z
        s e S escala o modelo
        r e R rodam a base
        b e B rodam o braco
    */

    switch (key){
        case 27 :
        case 'q':
            exit(0);
            break;
        case 'x':
            ang_x += 10;
            break;
        case 'y':
            ang_y += 10;
            break;
        case 'z':
            ang_z += 10;
            break;
        case 'X':
            ang_x -= 10;
            break;
        case 'Y':
            ang_y -= 10;
            break;
        case 'Z':
            ang_z -= 10;
            break;
        case 's':
            if (escala > 100)
                escala -= 10.0;
            break;
        case 'S':
            if (escala < 400)
                escala += 10.0;
            break;
        case 'r':
            if (rot_base > -90)
                rot_base -= 10;
            break;
        case 'R':
            if (rot_base < 90)
                rot_base += 10;
            break;
        case 'b':
                if (rot_braco > -30){
                    rot_braco -= 2;
                    x_corda += 0.0055;
                    y_corda -= 0.007;
                }
            break;
        case 'B':
                if (rot_braco < 20){
                    rot_braco += 2;
                    x_corda -= 0.0055;
                    y_corda += 0.007;
                }
            break;
    }
    glutPostRedisplay();
}

/*Faz a inicializacao das funcoes, modos, janelas e etc das funcoes da GL e GLUT*/
void inicializacao(){
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(largura_tela, altura_tela);
    glutCreateWindow("Caminhao Munck Munch");
    glutDisplayFunc(display);
    glutMouseFunc(interacao_mouse);
    glutKeyboardFunc(funcoes_teclas);
    glutTimerFunc(25, atualiza_cena, 0);
    glClearColor(1, 1, 1, 1);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glEnable(GL_DEPTH_TEST);
    glOrtho(-largura_tela/2, largura_tela/2, -altura_tela/2, altura_tela/2, -100, 100);
}

/*Programa principal*/
int main(int argc, char** argv){
    glutInit(&argc, argv);
    inicializacao();
    glutMainLoop();
    return 0;
}
