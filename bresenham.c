// Autor: José Armando Alarcón
#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>

void bersenham(int x0, int y0, int xn, int yn) {
    int dx = abs(xn - x0);
    int dy = abs(yn - y0);
    int M = dy / dx;
    int factorDecision = 2 * dy - dx;
    int x = x0;
    int y = y0;

    // Verificar si el origen es menor que el destino
    if (x0 > xn || y0 > yn) {
        printf("Entrada inválida: El origen debe ser menor que el destino.\n");
        return;
    }

    // Dibujar la línea
    printf("Línea: (%d, %d) -> (%d, %d)\n", x0, y0, xn, yn);
    printf("Puntos: (%d, %d)\n", x, y);

    glBegin(GL_POINTS);
    glVertex2i(x, y);

    while (x < xn) {
        if (factorDecision <= 0) {
            factorDecision += 2 * dy;
        } else {
            factorDecision += 2 * (dy - dx);
            y++;
        }
        x++;
        printf("Puntos: (%d, %d)\n", x, y);
        glVertex2i(x, y);
    }
    glEnd();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 1.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 700, 0, 700);

    // Cambiar las coordenadas según sea necesario
    bersenham(2, 1, 8, 5);

    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Dibujo de línea de Bresenham");
    glutDisplayFunc(display);
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glutMainLoop();

    return 0;
}

