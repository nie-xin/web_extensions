#include <GLFW/glfw3.h>
 
int main(int argc, char *argv[])
{
  glfwInit();
  
  glfwOpenWindow(0, 0, 0, 0, 0, 0, 0, 0, GLFW_WINDOW);
  
  while (glfwGetWindowParam(GLFW_OPENED))
  {
    /*
    ** ここで OpenGL による描画を行う
    */
    
    glfwSwapBuffers();
  }
  
  glfwTerminate();
  
  return 0;
}