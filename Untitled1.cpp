#include <GL/glut.h>
#include <cmath>

void drawCircle(float cx, float cy, float r, int num_segments) {
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(cx, cy);
    for (int i = 0; i <= num_segments; i++) {
        float angle = 2.0f * 3.1415926f * i / num_segments;
        float x = r * cosf(angle);
        float y = r * sinf(angle);
        glVertex2f(cx + x, cy + y);
    }
    glEnd();
}

void drawCloud(float x, float y) {
    glColor3f(1.0f, 1.0f, 1.0f);
    drawCircle(x, y, 0.07f, 50);
    drawCircle(x + 0.08f, y + 0.02f, 0.07f, 50);
    drawCircle(x - 0.08f, y + 0.02f, 0.07f, 50);
    drawCircle(x + 0.04f, y + 0.05f, 0.07f, 50);
    drawCircle(x - 0.04f, y + 0.05f, 0.07f, 50);
}

void drawTree(float x, float y) {
    glColor3f(0.55f, 0.27f, 0.07f);
    glBegin(GL_POLYGON);
    glVertex2f(x - 0.02f, y);
    glVertex2f(x + 0.02f, y);
    glVertex2f(x + 0.02f, y + 0.2f);
    glVertex2f(x - 0.02f, y + 0.2f);
    glEnd();

    glColor3f(0.0f, 0.6f, 0.0f);
    drawCircle(x, y + 0.25f, 0.08f, 30);
    drawCircle(x - 0.05f, y + 0.3f, 0.08f, 30);
    drawCircle(x + 0.05f, y + 0.3f, 0.08f, 30);
}

void drawWindow(float x1, float y1, float x2, float y2) {
    glColor3f(0.4f, 0.8f, 1.0f); // Window background
    glBegin(GL_POLYGON);
    glVertex2f(x1, y1);
    glVertex2f(x2, y1);
    glVertex2f(x2, y2);
    glVertex2f(x1, y2);
    glEnd();

    glColor3f(0.0f, 0.0f, 0.0f); // Grid lines
    float midX = (x1 + x2) / 2.0f;
    float midY = (y1 + y2) / 2.0f;

    glBegin(GL_LINES);
    glVertex2f(midX, y1);
    glVertex2f(midX, y2);
    glVertex2f(x1, midY);
    glVertex2f(x2, midY);
    glEnd();
}

void drawHouse() {
    // House base
    glColor3f(0.8f, 0.6f, 0.4f);
    glBegin(GL_POLYGON);
    glVertex2f(-0.4f, -0.4f);
    glVertex2f(0.4f, -0.4f);
    glVertex2f(0.4f, 0.1f);
    glVertex2f(-0.4f, 0.1f);
    glEnd();

    // Roof
    glColor3f(0.4f, 0.0f, 0.1f);
    glBegin(GL_POLYGON);
    glVertex2f(-0.45f, 0.1f);
    glVertex2f(0.45f, 0.1f);
    glVertex2f(0.0f, 0.5f);
    glEnd();

    // Door
    glColor3f(0.36f, 0.2f, 0.0f);
    glBegin(GL_POLYGON);
    glVertex2f(-0.05f, -0.4f);
    glVertex2f(0.05f, -0.4f);
    glVertex2f(0.05f, -0.1f);
    glVertex2f(-0.05f, -0.1f);
    glEnd();

    // Door knob
    glColor3f(1.0f, 1.0f, 0.0f); // yellow knob
    drawCircle(0.035f, -0.25f, 0.007f, 20);

    // Left window
    drawWindow(-0.3f, -0.1f, -0.15f, 0.05f);

    // Right window
    drawWindow(0.15f, -0.1f, 0.3f, 0.05f);
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();

    drawCloud(-0.6f, 0.7f);
    drawCloud(0.3f, 0.6f);

    drawTree(-0.7f, -0.4f);
    drawTree(0.65f, -0.4f);

    drawHouse();

    glFlush();
}

void init() {
    glClearColor(0.6f, 0.85f, 1.0f, 1.0f);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Colorful House with Trees, Clouds, Rain, and Birds");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}