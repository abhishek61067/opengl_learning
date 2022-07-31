#include <windows.h>
#include <GL/glut.h>

void init ()
{
    glClearColor (1,1,1,1);//select clearing (background) color
    glMatrixMode(GL_PROJECTION);  //initialize viewing values
    glLoadIdentity(); // to load the program
    gluOrtho2D (0.0, 500, 0.0, 500.00); //glOrtho2D - the display will be in the range of this area
}
void display()
{
    glClear (GL_COLOR_BUFFER_BIT);//clear all pixels
    glColor3f (0.0, 1.0, 0.0);//set color to green
    glPointSize(5.0f);//set point size to 10 pixels
    glBegin(GL_LINE_STRIP);
      glVertex2i(0, 0);//defines a point at x = 100, y = 150, z = 0;
      glVertex2i(75, 150);//this function takes only 2 parameters, z is always 0.     
    glEnd();
    glFlush (); //start processing buffered OpenGL routines
}
//Declare initial window size, position, and display mode (single buffer and RGBA).
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
//GLUT_SINGLE - This means that the program is automatically drawing straight to the window.
//GLUT_DOUBLE -  giving the program buffer to draw what it has to, then transfer what is actually needed to the screen.
//GLUT_RGB - An alias for GLUT_RGBA.
//GLUT_DEPTH - Bit mask to request a window with a depth buffer.
    glutInitWindowSize (500,500);
    glutInitWindowPosition (0, 0);
    glutCreateWindow ("Lab 2 – Create Points");
    init ();
    glutDisplayFunc(display);
    glutMainLoop();
}
