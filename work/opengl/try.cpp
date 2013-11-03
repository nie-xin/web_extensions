#include <GL/glew.h>
#ifdef __APPLE__
# include <GLUT/freeglut.h>
#else
# include <GL/freeglut.h> // or glut.h #endif

static int g_width = 512;
static int g_height = 512;

void initGlutState()
{
	glutInit();
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);
	glutInitWindowSize(g_width, g_height);
	glutCreateWindow("Hello World");
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
}

void reshape(int w, int h)
{
	g_width = w;
	g_height = h;
	glViewport(0, 0, w, h);
	glutPostRedisplay();
}

void initGLState()
{
	glClearColor(128./255, 200./255, 1, 0);
	glEnable(GL_FRAMEBUFFER_SRGB);
}

static GLunit h_program;
static Glunit h_aTexCoord;
static GLunit h_aColor;

initShaders()
{
	readAndCompileShader("./shaders/simple.vshader", "./shaders/simple.fshader", &h_program);
	h_aVertex = safe_glGetAttribLocation(h_program, "aVertex");
	h_aColor = safe_glGetAttribLocation(h_program, "aColor");
	glBindFragDataLocation(h_program, 0, "fragColor");
}

GLfloat sqVerts[6*2]=
{
  -.5, -.5,
   .5,  .5,
   .5, -.5,
  -.5, -.5,
  -.5,  .5,
  .5, .5 
};

GLfloat sqCol[6*3] = {
  1, 0, 0,
  0, 1, 1,
  0, 0, 1,
  1, 0, 0,
  0, 1, 0,
  0, 1, 1
};

static GLuint sqVertBO, sqColBO;
static void initVBOs(void){
  glGenBuffers(1,&sqVertBO);
  glBindBuffer(GL_ARRAY_BUFFER,sqVertBO);
  glBufferData(
       GL_ARRAY_BUFFER,
       12*sizeof(GLfloat),
       sqVerts,
       GL_STATIC_DRAW);
  glGenBuffers(1,&sqColBO);
  glBindBuffer(GL_ARRAY_BUFFER,sqColBO);
  glBufferData(
       GL_ARRAY_BUFFER,
       18*sizeof(GLfloat),
       sqCol,
       GL_STATIC_DRAW);
}

void display(void){
glUseProgram(h_program); glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); drawObj(sqVertBO, sqColBO,6);
glutSwapBuffers();
// check for errors
if (glGetError() != GL_NO_ERROR){
const GLubyte *errString; errString=gluErrorString(errCode); printf("error: %s\n", errString);
} }

void drawObj(GLuint vertbo, GLuint colbo, int numverts){ glBindBuffer(GL_ARRAY_BUFFER,vertbo); safe_glVertexAttribPointer2(h_aVertex); safe_glEnableVertexAttribArray(h_aVertex);
glBindBuffer(GL_ARRAY_BUFFER,colbo); safe_glVertexAttribPointer3(h_aColor); safe_glEnableVertexAttribArray(h_aColor);
  glDrawArrays(GL_TRIANGLES,0,numverts);
  safe_glDisableVertexAttribArray(h_aVertex);
safe_glDisableVertexAttribArray(h_aColor); }

int main(void)
{
	initGlutState();
	glewInit();
	initGLState();
	initShaders();
	initVBOs();
	glutMainLoop();

	return 0;
}