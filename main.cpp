#include <GL/gl.h>
#include <stdio.h>
#include <math.h>
#include <GL/glut.h>
#include <string.h>
#include <windows.h>

float tx = 10, bx = 10, rx = 10, sx = 10, hx = 0;
float windmillAngle = 0;
float shift = 0; // Variable used to move the clouds right and left
float birdY = 0;
float birdDirection = 1;
float birdSpeed = 0.1;

void circle(GLfloat rx, GLfloat ry, GLfloat cx, GLfloat cy) {
    glBegin(GL_POLYGON);
    glVertex2f(cx, cy);
    for (int i = 0; i <= 360; i++) {
        float angle = i * 3.1416 / 180;
        float x = rx * cos(angle);
        float y = ry * sin(angle);
        glVertex2f((x + cx), (y + cy));
    }
    glEnd();
}

void round(GLfloat rx, GLfloat ry, GLfloat cx, GLfloat cy) {
    glBegin(GL_POLYGON);
    glVertex2f(cx, cy);
    for (int i = 0; i <= 360; i++) {
        float angle = i * 3.1416 / 180;
        float x = rx * cos(angle);
        float y = ry * sin(angle);
        glVertex2f((x + cx), (y + cy));
    }
    glEnd();
}

void init(void) {
    glClearColor(0, 0.9, 0.9, 0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0, 500, 0, 500);
}

// Green Bushes
void Bushes() {
    // 1st Bush
    glColor3ub(0, 128, 0);
    circle(20, 30, 20, 180);
    circle(20, 30, 40, 210);
    circle(20, 30, 60, 180);

    // 2nd Bushes
    glColor3ub(154, 205, 50);
    circle(20, 30, 430, 180);
    circle(20, 30, 450, 210);
    circle(20, 30, 470, 180);

    // 3rd Bushes
    glColor3ub(0, 128, 0);
    circle(20, 30, 490, 180);
    circle(20, 30, 510, 210);
}

// Front Road
void road()
{
    // Grass area
    glColor3ub(0, 128, 0);
    glBegin(GL_POLYGON);
    glVertex2d(0, 0);
    glVertex2d(500, 0);
    glVertex2d(500, 75);
    glVertex2d(0, 75);
    glEnd();

    // Car road base
    glColor3ub(255, 255, 255);
    glBegin(GL_POLYGON);
    glVertex2d(0, 0);
    glVertex2d(500, 0);
    glVertex2d(500, 55);
    glVertex2d(0, 55);
    glEnd();

    // Asphalt layer
    glColor3ub(105, 105, 105);
    glBegin(GL_POLYGON);
    glVertex2d(0, 0);
    glVertex2d(500, 0);
    glVertex2d(500, 50);
    glVertex2d(0, 50);
    glEnd();

    // Road markings
    int startX = 15;
    int endX = 50;
    for (int i = 0; i < 10; i++) {
        glColor3ub(255, 255, 255);
        glBegin(GL_POLYGON);
        glVertex2d(startX, 20);
        glVertex2d(endX, 20);
        glVertex2d(endX, 30);
        glVertex2d(startX, 30);
        glEnd();

        startX += 50;
        endX += 50;
    }
}

void sun() {
    glColor3ub(255, 255, 0);
    circle(20, 30, 450, 450);
}

void drawBird(float x, float y) {
    glLineWidth(3.0); // Set line thickness
    glColor3ub(0, 0, 0);
    glBegin(GL_LINES);
        glVertex2f(x, y);
        glVertex2f(x - 10, y + 10);
        glVertex2f(x, y);
        glVertex2f(x + 10, y + 10);
    glEnd();
    glLineWidth(1.0); // Reset line thickness to default
}

void birds() {
    birdY += birdSpeed * birdDirection;
    if (birdY > 10 || birdY < -10) {
        birdDirection *= -1;
    }

    drawBird(100, 400 + birdY);
    drawBird(150, 420 + birdY);
    drawBird(200, 390 + birdY);
    drawBird(250, 410 + birdY);

    glutPostRedisplay();
}

void tree() {
    // Back tree trunk
    glColor3ub(139, 69, 19);
    glBegin(GL_POLYGON);
    glVertex2d(75, 180);
    glVertex2d(85, 180);
    glVertex2d(85, 350);
    glVertex2d(75, 350);
    glEnd();

    // Back tree leaves
    glColor3ub(0, 128, 0);
    circle(30, 40, 85, 370);
    circle(20, 30, 90, 340);
    circle(20, 30, 65, 395);

    // Apples on back tree
    glColor3ub(255, 0, 0);
    circle(3, 3, 80, 365);
    circle(3, 3, 95, 350);
    circle(3, 3, 70, 380);

    // Forward tree leaves
    glColor3ub(0, 100, 0);
    circle(40, 50, 45, 360);
    circle(30, 30, 60, 330);
    circle(20, 30, 30, 300);
    circle(20, 30, 60, 300);

    // Forward tree trunk
    glColor3ub(139, 69, 19);
    glBegin(GL_POLYGON);
    glVertex2d(40, 180);
    glVertex2d(50, 180);
    glVertex2d(50, 296);
    glVertex2d(60, 320);
    glVertex2d(55, 326);
    glVertex2d(50, 300);
    glVertex2d(50, 350);
    glVertex2d(45, 350);
    glVertex2d(45, 310);
    glEnd();

    // Apples on forward tree
    glColor3ub(255, 0, 0);
    circle(3, 3, 50, 350);
    circle(3, 3, 40, 340);
    circle(3, 3, 65, 320);
    circle(3, 3, 30, 310);
}

void little_tree()
{
    // 2nd tree
    glColor3ub(139, 69, 19);
    glBegin(GL_POLYGON);
        glVertex2d(65, 60);
        glVertex2d(75, 60);
        glVertex2d(75, 100);
        glVertex2d(65, 100);
    glEnd();

    glColor3ub(0, 100, 0);
    circle(15, 20, 65, 110);
    circle(15, 20, 75, 110);
    circle(15, 20, 70, 130);

    // 1st tree
    glColor3ub(139, 69, 19);
    glBegin(GL_POLYGON);
        glVertex2d(0, 60);
        glVertex2d(10, 60);
        glVertex2d(10, 100);
        glVertex2d(0, 100);
    glEnd();

    glColor3ub(0, 100, 0);
    circle(15, 20, 0, 110);
    circle(15, 20, 10, 110);
    circle(15, 20, 5, 130);

    // 3rd tree
    glColor3ub(139, 69, 19);
    glBegin(GL_POLYGON);
        glVertex2d(125, 60);
        glVertex2d(135, 60);
        glVertex2d(135, 100);
        glVertex2d(125, 100);
    glEnd();

    glColor3ub(0, 100, 0);
    circle(15, 20, 125, 110);
    circle(15, 20, 135, 110);
    circle(15, 20, 130, 130);

    // 4th tree
    glColor3ub(139, 69, 19);
    glBegin(GL_POLYGON);
        glVertex2d(190, 60);
        glVertex2d(200, 60);
        glVertex2d(200, 100);
        glVertex2d(190, 100);
    glEnd();

    glColor3ub(0, 100, 0);
    circle(15, 20, 190, 110);
    circle(15, 20, 200, 110);
    circle(15, 20, 195, 130);

    // 5th tree
    glColor3ub(139, 69, 19);
    glBegin(GL_POLYGON);
        glVertex2d(300, 60);
        glVertex2d(310, 60);
        glVertex2d(310, 100);
        glVertex2d(300, 100);
    glEnd();

    glColor3ub(0, 100, 0);
    circle(15, 20, 300, 110);
    circle(15, 20, 310, 110);
    circle(15, 20, 305, 130);

    // 6th tree
    glColor3ub(139, 69, 19);
    glBegin(GL_POLYGON);
        glVertex2d(365, 60);
        glVertex2d(375, 60);
        glVertex2d(375, 100);
        glVertex2d(365, 100);
    glEnd();

    glColor3ub(0, 100, 0);
    circle(15, 20, 365, 110);
    circle(15, 20, 375, 110);
    circle(15, 20, 370, 130);

    // 7th tree
    glColor3ub(139, 69, 19);
    glBegin(GL_POLYGON);
        glVertex2d(425, 60);
        glVertex2d(435, 60);
        glVertex2d(435, 100);
        glVertex2d(425, 100);
    glEnd();

    glColor3ub(0, 100, 0);
    circle(15, 20, 425, 110);
    circle(15, 20, 435, 110);
    circle(15, 20, 430, 130);

    // 8th tree
    glColor3ub(139, 69, 19);
    glBegin(GL_POLYGON);
        glVertex2d(490, 60);
        glVertex2d(500, 60);
        glVertex2d(500, 100);
        glVertex2d(490, 100);
    glEnd();

    glColor3ub(0, 100, 0);
    circle(15, 20, 490, 110);
    circle(15, 20, 500, 110);
    circle(15, 20, 495, 130);
}

void clouds2()
{
    glPushMatrix();
    glTranslatef(rx, 0, 0);

    // 1st cloud
    glColor3ub(220, 220, 220);
    circle(20, 30, 460, 460);
    circle(15, 20, 445, 460);
    circle(15, 20, 475, 460);

    // 2nd cloud
    circle(20, 30, 390, 420);
    circle(15, 20, 405, 420);
    circle(15, 20, 375, 420);

    glPopMatrix();

    rx += 0.05;
    if (rx > 0)
        rx = -500;

    glutPostRedisplay();
}

void clouds()
{
    // 1st cloud
    glColor3ub(255, 255, 255);
    round(20, 30, 90 + shift, 460);
    round(15, 20, 110 + shift, 460);
    round(15, 20, 70 + shift, 460);

    // 2nd cloud
    round(20, 30, 185 + shift, 430);
    round(15, 20, 205 + shift, 430);
    round(15, 20, 165 + shift, 430);
}

void windmillBase()
{
    glColor3ub(149, 165, 166); // Pastel peach base
    glBegin(GL_POLYGON);
    glVertex2d(400, 180);
    glVertex2d(420, 180);
    glVertex2d(435, 300); // Slightly wider top for a tapered look
    glVertex2d(385, 300);
    glEnd();
}

void windmillBlades()
{
    glPushMatrix();
    glTranslatef(410, 310, 0); // Move pivot to windmill center
    glRotatef(windmillAngle, 0, 0, 1); // Rotate the blades

    glColor3ub(255, 255, 255); // Pastel blue blades

    for (int i = 0; i < 4; i++) // Four blades
    {
        glBegin(GL_POLYGON);
        glVertex2f(-4, -50);
        glVertex2f(4, -50);
        glVertex2f(6, 50);  // Slightly rounded end
        glVertex2f(-6, 50);
        glEnd();
        glRotatef(90, 0, 0, 1);
    }

    // Circular hub at center of blades
    glColor3ub(240, 230, 140); // Pastel yellow hub
    circle(7, 10, 0, 0);

    glPopMatrix();
}

void windmill()
{
    windmillBase();
    windmillBlades();
}

void house(int x, int y)
{
    glColor3ub(245, 245, 220); // House base
    glBegin(GL_POLYGON);
    glVertex2d(x, y);
    glVertex2d(x + 80, y);
    glVertex2d(x + 80, y + 60);
    glVertex2d(x, y + 60);
    glEnd();

    glColor3ub(100, 30, 22); // Roof
    glBegin(GL_TRIANGLES);
    glVertex2d(x - 5, y + 60);
    glVertex2d(x + 85, y + 60);
    glVertex2d(x + 40, y + 100);
    glEnd();

    glColor3ub(100, 30, 22); // Door
    glBegin(GL_POLYGON);
    glVertex2d(x + 30, y);
    glVertex2d(x + 50, y);
    glVertex2d(x + 50, y + 30);
    glVertex2d(x + 30, y + 30);
    glEnd();

    // Doorknob (small circle)
    glColor3ub(255, 215, 0); // Gold color
    glBegin(GL_POLYGON);
    for (int i = 0; i < 360; i++)
    {
        float theta = i * 3.14159 / 180;
        glVertex2f(x + 47 + 2 * cos(theta), y + 15 + 2 * sin(theta)); // Right side of the door
    }
    glEnd();

    glColor3ub(173, 216, 230); // Windows
    glBegin(GL_POLYGON);
    glVertex2d(x + 10, y + 35);
    glVertex2d(x + 25, y + 35);
    glVertex2d(x + 25, y + 50);
    glVertex2d(x + 10, y + 50);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2d(x + 55, y + 35);
    glVertex2d(x + 70, y + 35);
    glVertex2d(x + 70, y + 50);
    glVertex2d(x + 55, y + 50);
    glEnd();

    // Window Cross Details
    glColor3ub(255, 215, 0); // Black cross lines

    // Left window
    glBegin(GL_LINES);
    glVertex2d(x + 17.5, y + 35); // Vertical line
    glVertex2d(x + 17.5, y + 50);
    glVertex2d(x + 10, y + 42.5); // Horizontal line
    glVertex2d(x + 25, y + 42.5);
    glEnd();

    // Right window
    glBegin(GL_LINES);
    glVertex2d(x + 62.5, y + 35); // Vertical line
    glVertex2d(x + 62.5, y + 50);
    glVertex2d(x + 55, y + 42.5); // Horizontal line
    glVertex2d(x + 70, y + 42.5);
    glEnd();
}

void car()
{
    glPushMatrix();
    glTranslatef(tx, 0, 0);

    glColor3ub(255, 128, 128); // Pastel Red Car Body
    glBegin(GL_POLYGON);
    glVertex2d(410, 40);
    glVertex2d(490, 40);
    glVertex2d(485, 70);
    glVertex2d(410, 70);
    glEnd();

    glColor3ub(255, 128, 128); // Pastel Red Top
    glBegin(GL_POLYGON);
    glVertex2d(420, 70);
    glVertex2d(475, 70);
    glVertex2d(465, 100);
    glVertex2d(430, 100);
    glEnd();

    // Car windows
    glColor3ub(200, 225, 255); // Light Blue Windows
    glBegin(GL_POLYGON);
    glVertex2d(425, 70);
    glVertex2d(445, 70);
    glVertex2d(445, 90);
    glVertex2d(430, 90);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2d(450, 70);
    glVertex2d(470, 70);
    glVertex2d(465, 90);
    glVertex2d(450, 90);
    glEnd();

    // Car wheels
    glColor3ub(50, 50, 50); // Dark Gray Wheels
    circle(10, 14, 435, 40);
    circle(10, 14, 465, 40);

    glColor3ub(230, 230, 230); // Soft White Wheel Centers
    circle(6, 10, 435, 40);
    circle(6, 10, 465, 40);

    glPopMatrix();

    tx += 0.9;
    if (tx > 0)
        tx = -500;

    glutPostRedisplay();
}

void truck()
{
    glPushMatrix();
    glTranslatef(bx, 0, 0);

    glColor3ub(152, 251, 152); // Pastel Green Truck Body
    glBegin(GL_POLYGON);
    glVertex2d(450, 40);
    glVertex2d(505, 40);
    glVertex2d(505, 110);
    glVertex2d(450, 110);
    glEnd();

    glColor3ub(255, 182, 193); // Pastel Pink Cabin
    glBegin(GL_POLYGON);
    glVertex2d(505, 40);
    glVertex2d(535, 40);
    glVertex2d(535, 70);
    glVertex2d(505, 70);
    glEnd();

    glColor3ub(255, 182, 193); // Pastel Pink Top
    glBegin(GL_POLYGON);
    glVertex2d(505, 70);
    glVertex2d(525, 70);
    glVertex2d(515, 90);
    glVertex2d(505, 90);
    glEnd();

    // Truck window
    glColor3ub(200, 225, 255); // Light Blue Window
    glBegin(GL_POLYGON);
    glVertex2d(505, 70);
    glVertex2d(520, 70);
    glVertex2d(515, 85);
    glVertex2d(505, 85);
    glEnd();

    // Truck wheels
    glColor3ub(50, 50, 50); // Dark Gray Wheels
    circle(10, 14, 460, 40);
    circle(10, 14, 510, 40);

    glColor3ub(230, 230, 230); // Soft White Wheel Centers
    circle(6, 10, 460, 40);
    circle(6, 10, 510, 40);

    glPopMatrix();

    bx += 0.7;
    if (bx > 0)
        bx = -510;

    glutPostRedisplay();
}

void flower()
{
    glColor3ub(255, 0, 0);
    circle(3, 5, 450, 210);
    circle(3, 5, 455, 205);
    circle(3, 5, 455, 215);
    circle(3, 5, 460, 210);
    glColor3ub(255, 105, 180);
    circle(3, 5, 455, 210);

    glColor3ub(255, 0, 0);
    circle(3, 5, 440, 195);
    circle(3, 5, 440, 185);
    circle(3, 5, 435, 190);
    circle(3, 5, 445, 190);
    glColor3ub(255, 105, 180);
    circle(3, 5, 440, 190);

    glColor3ub(255, 0, 0);
    circle(3, 5, 470, 195);
    circle(3, 5, 470, 185);
    circle(3, 5, 465, 190);
    circle(3, 5, 475, 190);
    glColor3ub(255, 105, 180);
    circle(3, 5, 470, 190);

    // Left side flower
    glColor3ub(255, 0, 0);
    circle(3, 5, 30, 205);
    circle(3, 5, 30, 195);
    circle(3, 5, 25, 200);
    circle(3, 5, 35, 200);
    glColor3ub(255, 105, 180);
    circle(3, 5, 30, 200);

    glColor3ub(255, 105, 180);
    circle(3, 5, 10, 215);
    circle(3, 5, 10, 205);
    circle(3, 5, 5, 210);
    circle(3, 5, 15, 210);
    glColor3ub(255, 0, 0);
    circle(3, 5, 10, 210);
}

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);

    // Sky Color
    glColor3ub(30, 144, 255);
    glBegin(GL_POLYGON);
        glVertex2d(0, 0);
        glVertex2d(500, 0);
        glVertex2d(500, 500);
        glVertex2d(0, 500);
    glEnd();

    Bushes();

    // Ground Color
    glColor3ub(0, 255, 0);
    glBegin(GL_POLYGON);
        glVertex2d(0, 0);
        glVertex2d(500, 0);
        glVertex2d(500, 180);
        glVertex2d(0, 180);
    glEnd();

    // Scene Objects
    little_tree();
    road();
    sun();
    clouds();

    // Move birds to the right
    glPushMatrix();
    glTranslatef(50, 0, 0); // Move right by 50 units
    birds();
    glPopMatrix();

    tree();
    truck();
    car();
    flower();
    windmill();
    house(100, 180);
    house(250, 180);

    glFlush();
    glutSwapBuffers();
}


void update(int value)
{
    windmillAngle += 5;
    if (windmillAngle > 360) windmillAngle -= 360;
    glutPostRedisplay();
    glutTimerFunc(100, update, 0);
}


int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(1200, 800);
    glutInitWindowPosition(200, 0);
    glutCreateWindow("221002411 - 221002127");
    init();
    glutDisplayFunc(display);
    glutTimerFunc(16, update, 0);
    glutMainLoop();
    return 0;
}
