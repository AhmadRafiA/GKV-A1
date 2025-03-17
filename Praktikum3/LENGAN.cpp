#include <GL/glut.h>

static int shoulder = 0, elbow = 0, wrist = 0;
static int finger[5][2] = {0}; 

void init(void) {
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glShadeModel(GL_FLAT);
}

void drawFinger(float x, float y, float z, int angle1, int angle2) {
    glPushMatrix();
    glTranslatef(x, y, z);
    glRotatef((GLfloat)angle1, 0.0, 0.0, 1.0);
    glTranslatef(0.15, 0.0, 0.0);
    glPushMatrix();
    glScalef(0.3, 0.1, 0.1);
    glutWireCube(1.0);
    glPopMatrix();
    
    glTranslatef(0.15, 0.0, 0.0);
    glRotatef((GLfloat)angle2, 0.0, 0.0, 1.0);
    glTranslatef(0.15, 0.0, 0.0);
    glPushMatrix();
    glScalef(0.3, 0.1, 0.1);
    glutWireCube(1.0);
    glPopMatrix();
    
    glPopMatrix();
}

void display(void) {
    glClear(GL_COLOR_BUFFER_BIT);
    glPushMatrix();

    // Bahu
    glTranslatef(-1.0, 0.0, 0.0);
    glRotatef((GLfloat) shoulder, 0.0, 0.0, 1.0);
    glTranslatef(1.0, 0.0, 0.0);
    glPushMatrix();
    glScalef(2.0, 0.4, 1.0);
    glutWireCube(1.0);
    glPopMatrix();

    // Siku
    glTranslatef(1.0, 0.0, 0.0);
    glRotatef((GLfloat) elbow, 0.0, 0.0, 1.0);
    glTranslatef(1.0, 0.0, 0.0);
    glPushMatrix();
    glScalef(2.0, 0.35, 1.0);
    glutWireCube(1.0);
    glPopMatrix();

    // Pergelangan Tangan
    glTranslatef(1.0, 0.0, 0.0);
    glRotatef((GLfloat) wrist, 0.0, 0.0, 1.0);
    glTranslatef(0.5, 0.0, 0.0);
    glPushMatrix();
    glScalef(1.0, 0.25, 0.8);
    glutWireCube(1.0);
    glPopMatrix();

    // Jari-jari
    drawFinger(0.2, 0.025, 0.4, finger[0][0], finger[0][1]); // Jempol
    drawFinger(0.3, 0.025, 0.35, finger[1][0], finger[1][1]); // Telunjuk
    drawFinger(0.3, 0.025, 0.25, finger[2][0], finger[2][1]); // Tengah
    drawFinger(0.3, 0.025, 0.15, finger[3][0], finger[3][1]); // Manis
    drawFinger(0.3, 0.025, 0.05, finger[4][0], finger[4][1]); // Kelingking

    glPopMatrix();
    glutSwapBuffers();
}

void reshape(int w, int h) {
    glViewport(0, 0, (GLsizei) w, (GLsizei) h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(65.0, (GLfloat) w / (GLfloat) h, 1.0, 20.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(0.0, 0.0, -5.0);
}

void keyboard(unsigned char key, int x, int y) {
    switch (key) {
        case 'w': if (shoulder < 90) shoulder += 5; break;
        case 's': if (shoulder > -90) shoulder -= 5; break;
        case 'a': if (elbow < 135) elbow += 5; break;
        case 'd': if (elbow > 0) elbow -= 5; break;
        case 'q': if (wrist < 45) wrist += 5; break;
        case 'e': if (wrist > -45) wrist -= 5; break;
        case '1': if (finger[0][0] < 90) finger[0][0] += 5; break;
        case '!': if (finger[0][0] > 0) finger[0][0] -= 5; break;
        case '2': if (finger[1][0] < 90) finger[1][0] += 5; break;
        case '@': if (finger[1][0] > 0) finger[1][0] -= 5; break;
        case '3': if (finger[2][0] < 90) finger[2][0] += 5; break;
        case '#': if (finger[2][0] > 0) finger[2][0] -= 5; break;
        case '4': if (finger[3][0] < 90) finger[3][0] += 5; break;
        case '$': if (finger[3][0] > 0) finger[3][0] -= 5; break;
        case '5': if (finger[4][0] < 90) finger[4][0] += 5; break;
        case '%': if (finger[4][0] > 0) finger[4][0] -= 5; break;
        case 27: exit(0); break;
    }
    glutPostRedisplay();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(1080, 720);
    glutCreateWindow("Tangan 3D");
    init();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    glutMainLoop();
    return 0;
}

