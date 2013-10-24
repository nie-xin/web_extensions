#include <GL/glew.h>
#include <GLUT/glut.h>

void render(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
 
    glTranslatef(0, 0, -30);
 
    // Green Sphere
    glPushMatrix();
        glColor3f(0.6, 0.9, 0);
        glTranslatef(7, -5, 0);
        glutSolidSphere(5, 50, 50);
    glPopMatrix();
 
    // Blue Cube
    glPushMatrix();
        glColor3f(0.0, 0.5, 0.9);
        glTranslatef(0, 5, 0);
        glRotatef(45, 1, 0, 0);
        glRotatef(45, 0, 1, 0);
        glutSolidCube(8);
    glPopMatrix();
 
    // Violet Cone
    glPushMatrix();
        glColor3f(0.7, 0.0, 1.0);
        glTranslatef(-7, -5, 0);
        glRotatef(-65, 0, 1, 0);
        glRotatef(-65, 1, 0, 1);
        glutSolidCone(5, 10, 100, 100);
    glPopMatrix();
 
    glFlush();
    glutSwapBuffers();
}
 
void init(void)
{
    glClearColor( 0.0, 0.0, 0.0, 0.0 );
    glClearDepth( 1.0 );
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHTING);
    glShadeModel(GL_SMOOTH);
    glEnable(GL_COLOR_MATERIAL);
    glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);
    glEnable(GL_LIGHT0);
}
 
void reshape(int w, int h)
{
    float aspectRatio = (float)w/(float)h;
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45, aspectRatio, 1.0, 100.0);
    glMatrixMode(GL_MODELVIEW);
}
 
int main(int argc, char** argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH );
    glutInitWindowSize(400, 300);
    glutCreateWindow("GLUT on Sublime Text");
    init();
    glutReshapeFunc(reshape);
    glutDisplayFunc(render);
    glutMainLoop();
    return 0;
}