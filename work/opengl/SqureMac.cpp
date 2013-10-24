#include <GLUT/glut.h>
#include <stdlib.h>

void draw(void)
{
    glClearColor(1,0,0,1);
    glClear(GL_COLOR_BUFFER_BIT );
    glutPostRedisplay();
    glFlush();
}

void keyboard(unsigned char key, int x, int y) {
	switch(key) {
		case 27:
			exit(0);
	}
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA );
    glutInitWindowPosition(100,100);
    glutInitWindowSize(400,400);
    glutCreateWindow("Red window");
    glutDisplayFunc(draw);
    glutKeyboardFunc(keyboard);
    glutMainLoop();
    
    return 0;
}