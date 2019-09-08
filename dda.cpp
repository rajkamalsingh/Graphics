#include<math.h>
#include<GL/gl.h>
#include<GL/glut.h>
#include<GL/glu.h>
#include<stdlib.h>
#include<stdio.h>
#include<iostream>
using namespace std;
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

void draw(void)
{

glClearColor(0,0,0,0);
glClear(GL_COLOR_BUFFER_BIT);

glMatrixMode(GL_PROJECTION);

glLoadIdentity();
gluOrtho2D(0.0, 640.0, 0.0,480.0);
glColor3f(1, 0, 0);

glBegin(GL_LINE_STRIP);
float x,y,x1,y1,x2,y2,dx,dy,loop,m;
 
cout<<"enter the values of x1 and y1 ";
cin>>x1>>y1;
cout<<"Enter the value of x2 and y2: ";
cin>>x2>>y2;
 
dx=abs(x2-x1);
dy=abs(y2-y1);
if(dx >= dy)
 loop=dx;
else
 loop=dy;

m=dy/dx;
x=x1;
y=y1;
int i=1;
if(m<1)
 {
  while (i<=loop)
   {
     glVertex2f(x,y);
     x=x+1;
     y=y+m;
     i=i+1;
     
    }
 }
else
 {
  while (i<=loop)
   {
     glVertex2f(x,y);
     x=x+(1/m);
     y=y+1;
     i=i+1;
     
    }
 }
glEnd();
glFlush();
}

int main(int argc, char **argv)
{
glutInit(&argc, argv);
glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
glutInitWindowPosition(30, 50);
glutInitWindowSize(500, 500);
glutCreateWindow("First OpenGL Program");
glutDisplayFunc(draw);
glutMainLoop();
return 0;

}
