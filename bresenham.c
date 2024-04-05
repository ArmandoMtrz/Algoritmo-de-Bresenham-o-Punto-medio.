//Autor: José Armando Alarcón
#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>

void bersenham(int x0, int y0, int xn, int yn) {
    int dx = abs(xn - x0);
    int dy = abs(yn - y0);
    int M = dy / dx;
    int decisionFactor = 2 * dy - dx;
    int x = x0;
    int y = y0;

    // Check if the origin is smaller than the destination
    if (x0 > xn || y0 > yn) {
        printf("Invalid input: Origin should be smaller than the destination.\n");
        return;
    }

    // Draw the line
    printf("Line: (%d, %d) -> (%d, %d)\n", x0, y0, xn, yn);
    printf("Points: (%d, %d)\n", x, y);

    glBegin(GL_POINTS);
    glVertex2i(x, y);

    while (x < xn) {
        if (decisionFactor <= 0) {
            decisionFactor += 2 * dy;
        } else {
            decisionFactor += 2 * (dy - dx);
            y++;
        }
        x++;
        printf("Points: (%d, %d)\n", x, y);
        glVertex2i(x, y);
    }
    glEnd();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 1.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 500, 0, 500);

    // Change the coordinates as needed
    bersenham(2, 1, 8, 5);

    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Bresenham Line Drawing");
    glutDisplayFunc(display);
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glutMainLoop();

    return 0;
}
