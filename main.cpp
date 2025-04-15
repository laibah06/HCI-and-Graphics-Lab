#include <GL/glut.h>                //library use to open the window
float CarX=0.0f;                   //CarX is a global variable here speed still 0
void specialkeys (int key,int x,int y)          //this function used to press the arrows key
{
	switch (key) {
		case GLUT_KEY_LEFT:  //use to move the car left
			CarX-=0.1f;      //move left
			break;
		case GLUT_KEY_RIGHT:   //use to move the car right
			CarX+=0.1f;        //move right
			break;
	}
	
	glutPostRedisplay ();     //used to refresh the screen so that we see the moment on screen
}

void drawCar()   //Car ko draw krne k liye hai
{
   glColor3f(1.0f,0.0f,0.0f);     //yeh red color btayega (RGB colors)
   glBegin(GL_QUADS);            //points daina hai takey 4 vertices milkar rectangle banayein (QUAD) , glBegin btayega start hona hai shape draw krni hai
   glVertex2f (CarX -0.2f,-0.2f);
   glVertex2f (CarX +0.2f,-0.2f);
   glVertex2f (CarX +0.2f,0.0f);
   glVertex2f (CarX -0.2f,0.0f);
   glEnd();   //glend btata hai k shape draw krna complete hogya hai   


//wheels add karne hain ab
   glColor3f(0.0f,0.0f,0.0f);  //black color for wheels
   glBegin (GL_QUADS);  //1st wheel
   glVertex2f (CarX -0.15f,-0.25f);
   glVertex2f (CarX -0.05f,-0.25f);
   glVertex2f (CarX -0.05f,-0.2f);
   glVertex2f (CarX -0.15f,-0.2f);
   
   glBegin (GL_QUADS);  //2nd wheel
   glVertex2f (CarX +0.15f,-0.25f);
   glVertex2f (CarX +0.05f,-0.25f);
   glVertex2f (CarX +0.05f,-0.2f);
   glVertex2f (CarX +0.15f,-0.2f);
   glEnd();
}

void display () {
	glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();    //purani screen saaf krni hai  , glLoadIdentity ye coordinate system ko reset karta hai x,y axis
	drawCar();
	glFlush();      //drawing screen par dikhata hai
}

void init ()      //opengl inilitization k liye
{
	glClearColor (0.8f,0.8f,1.0f,1.0f);   //ye line screen ka background ko sky blue karega
	glMatrixMode (GL_PROJECTION);   //ye btayega k screen 2d mode mein hai ya 3d mode mein hai
	glLoadIdentity();
}

int main (int argc,char** argv) {
	glutInit (&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);  //ye btata hai k display mode ek hi hoga yani k screen ek hi open hogi or RGB colours hongy
	glutInitWindowSize(500,500);             //ye window ka size set karega
	glutInitWindowPosition(100,100);        //ye window ki position btayega
	glutCreateWindow("MyOpenGLWindow");   //ye screen ka name hoga
	init();
	glutDisplayFunc(display);
	glutSpecialFunc(specialkeys);   //handling keys
	glutMainLoop();  //loop continue until user jab chahey
	return 0;
}

   
   