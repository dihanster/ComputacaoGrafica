/***************************************************************/
/* Computacao Grafica 2018.2 - Profa Dr. Regina Celia Coelho   */
/* Nome: Willian Dihanster Gomes de Oliveira RA: 112269        */
/* Exercicio 3: Cachorrinho com Transformacoes Tridimensionais */
/***************************************************************/
#include <stdio.h>
#include <math.h>
#include <windows.h>
#include <GL/freeglut.h>

/*Definicao e inicializacao das variveis globais*/
GLint slices = 20, stacks = 20, largura_tela = 800, altura_tela = 600, andando = 0, cont = 0;
GLdouble dist_euc = 0.0, x = 0.0, y = 0.0, x_pos = 0.0, y_pos = 0.0, x_mouse = 0.0, y_mouse = 0.0, aux_rot = 0.0;
GLdouble ang_vet = 0.0, velocidade_cachorro = 10.0, rotacao = 0.0, dist_x = 0.0, dist_y = 0.0, soma_ang_rabo = 3.0;
GLdouble rot_perna = 0.0, ang_x = 0.0, ang_y = 0.0, ang_z = 0.0, escala = 300.0, soma_ang = 5.0, rot_rabo = 0.0;

/*Faz o desennho da cabeca do cachorro*/
void cabeca(){
    glColor3d(0.9176, 0.8706, 0.7255);
    glPushMatrix();
        glTranslated(x + 0.0, -y + 0.0, 0.0);
        glutSolidSphere(0.1, slices, stacks);
    glPopMatrix();
}

/*Faz o desennho dos do cachorro*/
void olhos(){
    glColor3d(0, 0, 0);
    glPushMatrix();
        glTranslated(x + 0.08, -y + 0.01, 0.05);
        glutSolidSphere(0.02,slices,stacks);
    glPopMatrix();
    glPushMatrix();
        glTranslated(x + 0.08, -y + 0.01, -0.05);
        glutSolidSphere(0.02,slices,stacks);
    glPopMatrix();
}

/*Faz o desennho do focinho do cachorro*/
void focinho(){
    glColor3d(0.3765, 0.3373, 0.2863);
    glPushMatrix();
        glTranslated(x + 0.06, -y - 0.05, 0.00);
        glScaled(1.0, 1.0, 1.4);
        glRotated(90, 1, 0, 0);
        glutSolidSphere(0.04, slices, stacks);
    glPopMatrix();
}

void lingua(){
    glColor3d(1.0, 0.0, 0.0);
    glPushMatrix();
        glTranslated(x + 0.07, -y - 0.07, 0.00);
        glScaled(1.0, 1.5, 1.0);
        glRotated(90, 1, 0, 0);
        glutSolidSphere(0.02, slices, stacks);
    glPopMatrix();
}

/*Faz o desennho do corpo do cachorro*/
void corpo(){
    glColor3d(0.9176, 0.8706, 0.7255);
    glPushMatrix();
        glTranslated(x - 0.10, -y - 0.13, -0.10);
        glScaled(1.3, 0.70, 1.0);
        glutSolidCylinder(0.11, 0.20, slices, stacks);
    glPopMatrix();
}

/*Faz o desennho do rabo do cachorro*/
void rabo(){
    glColor3d(0.9176, 0.8706, 0.7255);
     glPushMatrix();
        glTranslated(x - 0.15, -y - 0.14, 0.0);
        glRotated(rot_rabo, 0, 1, 0);
        glRotated(180, 0, 0, 1);
        glutSolidTeapot(0.08);
    glPopMatrix();
}

/*Faz o desennho das patas do cachorro*/
void patas(){
    glColor3d(0.9176, 0.8706, 0.7255);

    glPushMatrix();
        glTranslated(x - 0.01, -y - 0.2, -0.07);
        glRotated(rot_perna, 0, 0, 1);
        glScaled(1.0, 3.0, 1.0);
        glutSolidCube(0.05);
    glPopMatrix();

      glPushMatrix();
        glTranslated(x - 0.01, -y - 0.2, 0.07);
        glRotated(-rot_perna, 0, 0, 1);
        glScaled(1.0, 3.0, 1.0);
        glutSolidCube(0.05);
    glPopMatrix();

    glPushMatrix();
        glTranslated(x - 0.2, -y - 0.2, -0.07);
        glRotated(-rot_perna, 0, 0, 1);
        glScaled(1.0, 3.0, 1.0);
        glutSolidCube(0.05);
    glPopMatrix();

      glPushMatrix();
        glTranslated(x - 0.2, -y - 0.2, 0.07);
        glRotated(rot_perna, 0, 0, 1);
        glScaled(1.0, 3.0, 1.0);
        glutSolidCube(0.05);
    glPopMatrix();

    glPushMatrix();
        glTranslated(x - 0.175,- y - 0.26, 0.07);
        glRotated(rot_perna, 0, 0, 1);
        glScaled(1.3, 1.0, 1.0);
        glutSolidSphere(0.015, slices, stacks);
    glPopMatrix();

    glPushMatrix();
        glTranslated(x - 0.175, -y - 0.26, -0.07);
        glRotated(-rot_perna, 0, 0, 1);
        glScaled(1.3, 1.0, 1.0);
        glutSolidSphere(0.015, slices, stacks);
    glPopMatrix();

    glPushMatrix();
        glTranslated(x + 0.016, -y - 0.26, 0.07);
        glRotated(rot_perna, 0, 0, 1);
        glScaled(1.3, 1.0, 1.0);
        glutSolidSphere(0.015, slices, stacks);
    glPopMatrix();

    glPushMatrix();
        glTranslated(x + 0.016, -y - 0.26, -0.07);
        glRotated(-rot_perna, 0, 0, 1);
        glScaled(1.3, 1.0, 1.0);
        glutSolidSphere(0.015, slices, stacks);
    glPopMatrix();
}

/*Faz o desennho das orelhas do cachorro*/
void orelhas(){
    glColor3d(0.3765, 0.3373, 0.2863);

    glPushMatrix();
        glTranslated(x + 0.02, -y + 0.06, 0.05);
        glRotated(90, 1, 0, 0);
        glScaled(1.0, 1.7, 1.0);
        glRotated(20,0,0,1);
        glRotated(-70,1,0,0);
        glutSolidSphere(0.03, slices, stacks);
    glPopMatrix();

    glPushMatrix();
        glTranslated(x + 0.02, -y + 0.06, -0.05);
        glRotated(90, 1, 0, 0);
        glScaled(1.0, 1.7, 1.0);
        glRotated(-30,0,1,0);
        glRotated(-180, 1, 0, 0);
        glRotated(70, 1, 0, 0);
        glutSolidSphere(0.03, slices, stacks);
    glPopMatrix();
}

/*Desenha um bola para o cachorro correr atras na posicao do mouse*/
void bola_cachorro(){
    glColor3d(1.0, 0.0, 0.0);
    glPushMatrix();
        glTranslated(x_mouse, y_mouse, 0.0);
        glScaled(200, 200, 200);
        glutSolidSphere(0.1, slices, stacks);
    glPopMatrix();
}

/*Desenha um osso para o cachorro perseguir*/
void osso_pro_cachorro(){
    glColor3d(1.0, 1.0, 1.0);
    glPushMatrix();
        glTranslated(x_mouse+10, y_mouse, 0.0);
        glScaled(70, 70, 70);
        glutSolidSphere(0.1, slices, stacks);
    glPopMatrix();

    glPushMatrix();
        glTranslated(x_mouse-10, y_mouse, 0.0);
        glScaled(70, 70, 70);
        glutSolidSphere(0.1, slices, stacks);
    glPopMatrix();

    glPushMatrix();
        glTranslated(x_mouse, y_mouse, 0.0);
        glScaled(80, 40, 40);
        glutSolidSphere(0.1, slices, stacks);
    glPopMatrix();
}

/*Funcao principal para o desenhos do cachorro*/
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

    glPushMatrix();
        /*Aplica as transformacoes no desenho do cachorro*/
        glTranslated(x_pos, y_pos, 0.0);
        glScaled(escala, escala, escala);
        glRotated(rotacao, 0, 0, 1);
        glRotated(ang_x, 1, 0, 0);
        glRotated(ang_y, 0, 1, 0);
        glRotated(ang_z, 0, 0, 1);

        /*Faz o desenho das partes do cachorro para monta-lo*/
        if (!andando)
            lingua();
        else
            rot_rabo = 0.0;
        focinho();
        rabo();
        corpo();
        orelhas();
        olhos();
        patas();
        cabeca();
    glPopMatrix();

    /*Desenha um objeto para o cachorro seguir, na posicao do mouse*/
    //bola_cachorro();
    osso_pro_cachorro();

    glutSwapBuffers();
}

/*Faz a leitura das coordenadas atuais do mouse*/
void interacao_mouse(int x, int y){
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
    x_mouse = x - largura_tela/2;
    y_mouse = - y + altura_tela/2;
}

/*Funcao que calcula a posicao do cachorro*/
void move_cachorro(){
    dist_x = x_mouse - x_pos;
    dist_y = y_mouse - y_pos;
    dist_euc = sqrt(dist_x * dist_x + dist_y * dist_y);

    /*Verifica se a dist. do cachorro ao ponto eh menor que e velocidade do cachorro*/
    if (dist_euc < velocidade_cachorro){
        x_pos = x_mouse;
        y_pos = y_mouse;
        andando = 0;
        rot_perna = 0.0;
    }
    /*Se nao, entao ainda tem que andar mais, tbm calcula-se o angulo que deve andar*/
    else {
        andando = 1;
        ang_vet = atan2(dist_y, dist_x);
        x_pos += cos(ang_vet) * velocidade_cachorro;
        y_pos += sin(ang_vet) * velocidade_cachorro;
        rotacao = (ang_vet * 100/3.14);
    }
    /*Se o cachorro esta andando, mexe as patinhas e o rabo*/
    if (andando == 1){
        if (rot_perna == 30 || rot_perna == -30){
            soma_ang = -soma_ang;
        }
        rot_perna += soma_ang;
    }
    if (rot_rabo == 30 || rot_rabo == -30){
        soma_ang_rabo = -soma_ang_rabo;
    }
    rot_rabo += soma_ang_rabo;
}

/*Funcao que atualiza a cena a cada determinado valor de tempo*/
void atualiza_cena(int value){
    move_cachorro();
    glutPostRedisplay();
    glutTimerFunc(30, atualiza_cena, 0);
}

/*Funcao para leitura dsa teclas para rotacao do cachorro em x,y,z e escala*/
static void funcoes_teclas(unsigned char key, int x, int y){
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
            if (escala > 200)
                escala -= 10.0;
            break;
        case 'S':
            if (escala < 600)
                escala += 10.0;
            break;
    }
    glutPostRedisplay();
}

/*Faz a inicializacao das funcoes, modos, janelas e etc das funcoes da GL e GLUT*/
void inicializacao(){
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(largura_tela, altura_tela);
    glutCreateWindow("Cachorrinho com Tranformacoes 3D");
    glutDisplayFunc(display);
    glutPassiveMotionFunc(interacao_mouse);
    glutKeyboardFunc(funcoes_teclas);
    glutTimerFunc(25, atualiza_cena, 0);
    glClearColor(0.0, 0.5451, 0.5451, 1);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glEnable(GL_DEPTH_TEST);
    glOrtho(-largura_tela/2, largura_tela/2, -altura_tela/2, altura_tela/2, -100, 100);
}

int main(int argc, char** argv){
    glutInit(&argc, argv);
    inicializacao();
    glutMainLoop();
    return 0;
}
