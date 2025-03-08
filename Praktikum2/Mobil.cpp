#include <GL/glut.h>
#include <math.h>

#define PI 3.1415926535898

void DrawCircle(float x, float y, float radius) {
    glBegin(GL_POLYGON);
    for (int i = 0; i < 100; i++) {
        float angle = 2.0f * PI * i / 100;
        glVertex2f(x + radius * cos(angle), y + radius * sin(angle));
    }
    glEnd();
}

void DrawCar() {
    glClear(GL_COLOR_BUFFER_BIT);
    
    // **Badan Mobil (Bawah)**
    glPushMatrix();
        glColor3f(0.15f, 0.15f, 0.5f);
        glBegin(GL_QUADS);
            glVertex2f(-0.6f, -0.15f);
            glVertex2f( 0.6f, -0.15f);
            glVertex2f( 0.6f,  0.1f);
            glVertex2f(-0.6f,  0.1f);
        glEnd();
    glPopMatrix();

    // **Pintu Depan**
    glPushMatrix();
        glColor3f(0.0f, 0.0f, 0.0f);
        glBegin(GL_QUADS);
            glVertex2f( 0.07f,  0.07f);
            glVertex2f( 0.15f,  0.07f);
            glVertex2f( 0.15f,  0.045f);
            glVertex2f( 0.07f,  0.045f);
        glEnd();
    glPopMatrix();

    // **Pintu Belakang**
    glPushMatrix();
        glColor3f(0.0f, 0.0f, 0.0f);
        glBegin(GL_QUADS);
            glVertex2f( -0.25f,  0.07f);
            glVertex2f( -0.17f,  0.07f);
            glVertex2f( -0.17f,  0.045f);
            glVertex2f( -0.25f,  0.045f);
        glEnd();
    glPopMatrix();

    // **Bagian Atas Mobil**
    glPushMatrix();
        glColor3f(0.0f, 0.0f, 0.0f);
        glBegin(GL_QUADS);
            glVertex2f(-0.45f,  0.1f);
            glVertex2f( 0.41f,  0.1f);
            glVertex2f( 0.3f,  0.3f);
            glVertex2f(-0.3f,  0.3f);
        glEnd();
    glPopMatrix();

    // **Jendela Kiri**
    glPushMatrix();
        glColor3f(0.8f, 0.8f, 0.8f);
        glBegin(GL_QUADS);
            glVertex2f(-0.32f, 0.13f);
            glVertex2f(-0.05f, 0.13f);
            glVertex2f(-0.05f, 0.26f);
            glVertex2f(-0.25f, 0.26f);
        glEnd();
    glPopMatrix();

    // **Jendela Kanan**
    glPushMatrix();
        glColor3f(0.8f, 0.8f, 0.8f);
        glBegin(GL_QUADS);
            glVertex2f(0.05f, 0.13f);
            glVertex2f(0.30f, 0.13f);
            glVertex2f(0.25f, 0.26f);
            glVertex2f(0.05f, 0.26f);
        glEnd();
    glPopMatrix();

    // **Lampu Depan**
    glPushMatrix();
        glColor3f(1.0f, 1.0f, 0.0f); 
        glBegin(GL_QUADS);
            glVertex2f(0.6f, 0.0f);
            glVertex2f(0.63f, 0.03f);
	    glVertex2f(0.63f, 0.07f);
            glVertex2f(0.6f, 0.1f);
        glEnd();
    glPopMatrix();

    // **Lampu Belakang**
    glPushMatrix();
        glColor3f(1.0f, 0.0f, 0.0f);
        glBegin(GL_QUADS);
            glVertex2f(-0.6f, 0.0f);
            glVertex2f(-0.63f, 0.03f);
	    glVertex2f(-0.63f, 0.07f);
            glVertex2f(-0.6f, 0.1f);
        glEnd();
    glPopMatrix();

    // **Roda Kiri**
    glPushMatrix();
	glTranslatef(0.8f, 0.15f, 0.0f);
        glColor3f(0.0f, 0.0f, 0.0f);
        DrawCircle(-0.4f, -0.3f, 0.1f);
    glPopMatrix();
    glPushMatrix();
	glTranslatef(0.8f, 0.15f, 0.0f);
        glColor3f(1.0f, 1.0f, 1.0f);
        DrawCircle(-0.4f, -0.3f, 0.05f);
    glPopMatrix();

    // **Roda Kanan**
    glPushMatrix();
	glTranslatef(-0.8f, 0.15f, 0.0f);
        glColor3f(0.0f, 0.0f, 0.0f);
        DrawCircle(0.4f, -0.3f, 0.1f);
    glPopMatrix();
    glPushMatrix();
	glTranslatef(-0.8f, 0.15f, 0.0f);
        glColor3f(1.0f, 1.0f, 1.0f);
        DrawCircle(0.4f, -0.3f, 0.05f);
    glPopMatrix();

    glFlush();
}

int main
(int argc, char* argv[]) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Mobil 2D");
    glClearColor(0.4f, 0.8f, 1.0f,1.0f);
    glutDisplayFunc(DrawCar);
    glutMainLoop();
    return 0;
}

