#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

#include <stdlib.h>
#include <windows.h>
#include <math.h>
float cx,cz;
float xRotated = 90.0, yRotated = 0.0, zRotated = 0.0;
void keyboard(unsigned char Key,int x,int y)
    {
   if(Key=='w'){cx-=0.1;} if(Key=='s'){cx+=0.1;}//forward and back   moving
    if(Key=='a'){cz-=0.1;} if(Key=='d'){cz+=0.1;}//left and right    moving

    glutPostRedisplay();
    }

void onMouseClick(int button, int state, int x, int y)
{
    if(button==GLUT_LEFT_BUTTON&&state==GLUT_DOWN)
    {

        cx-=0.1;
    }
}
//------------------------------  reshapeFunc  ---------------------------------

void reshapeFunc (int w, int h)
{
    glViewport(0,0,(GLsizei)w,(GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective (40.0, (GLdouble)w / (GLdouble)h, 0.5, 20.0);
    glMatrixMode(GL_MODELVIEW);
}

//------------------------------  display   -------------------------------
void floor()
{
     glPushMatrix();
    glColor3f(0,0.3,0);
    glTranslatef(-7,-1-3.4,1);
    glScalef(15,0.05,15);
    glutSolidCube(6);
    glPopMatrix();

}
void door()
{
     glPushMatrix();
    glColor3f(1,1,1);
    glTranslatef(-7,-4.4,1);
    glScalef(0.15,0.2,0.01);
    glutSolidCube(6);
    glPopMatrix();

    glPushMatrix();
    glColor3f(1,0,0);
    glTranslatef(-6.7,-4.4,1.2);

    glutSolidTorus(0.05,0.1,50,50);
    glPopMatrix();

}
void window()
{
    glPushMatrix();
    glColor3f(1,1,1);
    glTranslatef(-8,-2,1);
    glScalef(1.4,1.2,0.1);
    glutSolidCube(0.6);
    glPopMatrix();
    //
    glPushMatrix();
    glColor3f(1,1,1);
    glTranslatef(-6,-2,1);
    glScalef(1.4,1.2,0.1);
    glutSolidCube(0.6);
    glPopMatrix();


    glPushMatrix();
    glColor3f(1,1,1);
    glTranslatef(-8,-3,1);
    glScalef(1.4,1.2,0.1);
    glutSolidCube(0.6);
    glPopMatrix();
    //
    glPushMatrix();
    glColor3f(1,1,1);
    glTranslatef(-6,-3,1);
    glScalef(1.4,1.2,0.1);
    glutSolidCube(0.6);
    glPopMatrix();
}
void building()
{
    //body of the house
    glPushMatrix();

    glTranslatef(-7,0-3,-2);
    glScalef(2,2,3);
    glBegin (GL_QUADS) ;

    glColor3f(0.0,0.0,0.0);
    glVertex3f(-1.0,1.0,1.0);
    glVertex3f(-1.0,-1.0,1.0);
    glVertex3f(1.0,-1.0,1.0);
    glVertex3f(1.0,1.0,1.0);


    glVertex3f(1.0,1.0,-1.0);
    glVertex3f(1.0,-1.0,-1.0);
    glVertex3f (-1.0,-1.0,-1.0);
    glVertex3f(-1.0,1.0,-1.0);


    glVertex3f(1.0,1.0,1.0);
    glVertex3f(1.0,-1.0,1.0);
    glVertex3f(1.0,-1.0,-1.0);
    glVertex3f(1.0,1.0,-1.0);


    glVertex3f(-1.0,1.0,-1.0);
    glVertex3f(-1.0,-1.0,-1.0);
    glVertex3f(-1.0,-1.0,1.0);
    glVertex3f(-1.0,1.0,1.0);


    glVertex3f (-1.0,1.0,-1.0);
    glVertex3f (-1.0,1.0,1.0);
    glVertex3f(1.0,1.0,1.0);
    glVertex3f(1.0,1.0,-1.0);


    glVertex3f (-1.0,-1.0,-1.0);
    glVertex3f(-1.0,-1.0,1.0);
    glVertex3f(1.0,-1.0,1.0);
    glVertex3f(1.0,-1.0,-1.0);

    glEnd();


    glPopMatrix();

    //head of it
    glPushMatrix();
    glTranslatef(-7,4-4,-2);
    glScalef(2,1,3);
    glBegin(GL_TRIANGLES);           // Begin drawing the pyramid with 4 triangles
      // Front
      glColor3f(1.0f, 0.0f, 0.0f);     // Red
      glVertex3f( 0.0f, 1.0f, 0.0f);

      glVertex3f(-1.0f, -1.0f, 1.0f);

      glVertex3f(1.0f, -1.0f, 1.0f);

      // Right

      glVertex3f(0.0f, 1.0f, 0.0f);

      glVertex3f(1.0f, -1.0f, 1.0f);

      glVertex3f(1.0f, -1.0f, -1.0f);

      // Back

      glVertex3f(0.0f, 1.0f, 0.0f);

      glVertex3f(1.0f, -1.0f, -1.0f);

      glVertex3f(-1.0f, -1.0f, -1.0f);

      // Left
      glVertex3f( 0.0f, 1.0f, 0.0f);

      glVertex3f(-1.0f,-1.0f,-1.0f);

      glVertex3f(-1.0f,-1.0f, 1.0f);
      glEnd();   // Done drawing the pyramid
    glPopMatrix();
}
void tree()
{
    //3 cones function
    glPushMatrix();
    glColor3f(0,1,0);
    glRotatef(-90,1,0,0);
    glTranslatef(-4,0,0-3);
    glScalef(1,0.5,2);
    glutSolidCone(0.5,0.5,50,50);

    glPopMatrix();
    //----
    glPushMatrix();
    glColor3f(0,1,0);
    glRotatef(-90,1,0,0);
    glTranslatef(-4,0,-0.7-3);
    glScalef(1,0.5,2);
    glutSolidCone(0.5,0.5,50,50);

    glPopMatrix();
     //----
    glPushMatrix();
    glColor3f(0,1,0);
    glRotatef(-90,1,0,0);
    glTranslatef(-4,0,-1.4-3);
    glScalef(1,0.5,2);
    glutSolidCone(0.5,0.5,50,50);
    glPopMatrix();
    //


}
void treebase()
{
    glPushMatrix();
    glColor3f(0.2,0,0);
    glTranslatef(-4,-5.2,0);
    glScalef(0.02,0.2,0.1);
    glutSolidCube(6);
    glPopMatrix();

}
void snowman()
{
    // body1
    glColor3f(1,1,1);
    glPushMatrix ();
       glTranslatef    (1.5,-3.4,-2);

      //glRotatef       (zRotated, 0,1,0);
       glutSolidSphere(0.6,70,50);
       //

    glPopMatrix ();
    //--eyes--
    glColor3f(0,0,0);
    glPushMatrix ();
       glTranslatef    (1.2,-3.4,-2.2);

      //glRotatef       (zRotated, 0,1,0);
       glutSolidSphere(0.1,70,50);
       // eye 2
       glColor3f(0,0,0);
    glPushMatrix ();
       glTranslatef    (0.8,-0.4,-2.2);

      //glRotatef       (zRotated, 0,1,0);
       glutSolidSphere(0.1,70,50);
       // body 2

    glPopMatrix ();
    //
        glColor3f(1,1,1);
    glPushMatrix ();
       glTranslatef    (1.5,-4.5, -2);

      //glRotatef       (zRotated, 0,1,0);
       glutSolidSphere(0.8,70,50);
       //

    glPopMatrix ();
    //body 3
    glColor3f(1,1,1);
    glPushMatrix ();
       glTranslatef    (1.5,-5.4, -2);

      //glRotatef       (zRotated, 0,1,0);
       glutSolidSphere(1,70,50);
       //

    glPopMatrix ();
}
void cloud()
{
    glColor3f(1,1,1);
    glPushMatrix ();
       glTranslatef    (1.5+cz,5, -2+cx);

      //glRotatef       (zRotated, 0,1,0);
       glutSolidSphere(1,70,50);
       //

    glPopMatrix ();
        glColor3f(1,1,1);
    glPushMatrix ();
       glTranslatef    (0.5+cz,5, -2+cx);

      //glRotatef       (zRotated, 0,1,0);
       glutSolidSphere(1,70,50);
       //

    glPopMatrix ();
    glColor3f(1,1,1);
    glPushMatrix ();
       glTranslatef    (-0.5+cz,5, -2+cx);

      //glRotatef       (zRotated, 0,1,0);
       glutSolidSphere(1,70,50);
       //

    glPopMatrix ();
    // rotating moon

    glColor3f(0.7,0.7,0.7);
    glPushMatrix ();
       glTranslatef    (10.5,5, -5);

      glRotatef       (zRotated, 0,1,0);
       glutSolidSphere(1,7,50);
       //

    glPopMatrix ();



}

void display (void)
{

    glClear        (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity ();
    glTranslatef    (0.0, 0.0, -15.0);

	//Your code is written here
	//glRotatef(40,1,1,0);
	floor();
    building();
    snowman();
    tree();
    treebase();
    cloud();
    window();
    door();
    glutSwapBuffers();
}

//--------------------------------  idleFunc  ----------------------------------

void idleFunc (void)
{
    zRotated += 1;
    glutPostRedisplay();
}

void texture (void){

const GLfloat light_ambient[]  = { 0.0f, 0.0f, 0.0f, 1.0f };
const GLfloat light_diffuse[]  = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_position[] = { 2.0f, 5.0f, 5.0f, 0.0f };

const GLfloat mat_ambient[]    = { 0.7f, 0.7f, 0.7f, 1.0f };
const GLfloat mat_diffuse[]    = { 0.8f, 0.8f, 0.8f, 1.0f };
const GLfloat mat_specular[]   = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat high_shininess[] = { 100.0f };

    glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK);

    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);

    glEnable(GL_LIGHT0);
    glEnable(GL_NORMALIZE);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHTING);

    glLightfv(GL_LIGHT0, GL_AMBIENT,  light_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE,  light_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);

    glMaterialfv(GL_FRONT, GL_AMBIENT,   mat_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE,   mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR,  mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);


}

//----------------------------------  main  ------------------------------------


int main (int argc, char **argv)
{
    sndPlaySound("Christmas.wav",SND_ASYNC);
    glutInit               (&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE); // buffer mode
    glutInitWindowSize     (800, 700);
    glutInitWindowPosition (700, 200);
    glutCreateWindow       ("20101950");

    glClearColor (1.0, 1.0, 1.0, 0.0);
    glutKeyboardFunc(keyboard);
     glutMouseFunc(onMouseClick);
    glutDisplayFunc (display);
    glutReshapeFunc (reshapeFunc);

    glutIdleFunc    (idleFunc);

    glClearColor(0,0,0,0);
    //texture(); // Lighting and textures


    glutMainLoop();
}
