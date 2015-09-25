//
//  main.cpp
//  monteCarlo
//
//  Created by Daniel Holst on 2015-09-24.
//  Copyright (c) 2015 Daniel Holst. All rights reserved.
//

#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <GLUT/glut.h>

#include "theRoom.h"
#include "glm/glm/glm.hpp"

const GLfloat EDGE = 50.0;
const GLfloat SQR3 = sqrt(3);
const GLfloat SQR6 = sqrt(6);

void drawWall()
{
    glColor3f(0.1,0.3,0.7);
    glLoadIdentity();
    glTranslatef(4,0,0);
    glRotatef(45, 1, 0, 0);
    glScalef(1.0, 5.0, 1.0);
    glutSolidCube(1.0);
    glFlush();
}

void drawCube()
{
    glColor3f(0.2,0.6,0.0);
    glLoadIdentity();
    glTranslatef(2,0,0);
    glRotatef(30, 2, 2, 2);
    glutSolidCube(1.0);
    glFlush();
    
    
    
}

void drawSphere()
{
    glColor3f(1.0,0.0,0.0);
    glLoadIdentity();
    glTranslatef(0,0,0);
    glutSolidSphere(1.0, 40, 40);
    glFlush();
}

void draw()
{
    
    //Clear screen
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW); //Switch to the drawing perspective
    glLoadIdentity(); //Reset the drawing perspective
    
//    glBegin(GL_TRIANGLES);
// 
//    glColor3f(1, 0, 0);
//    glVertex3f(-0.5f, 0.0f, -4.0f);
//   
//    glColor3f(0,1,0);
//    glVertex3f(0.5f, 0.0f, -4.0f);
//   
//    glColor3f(0,0,1);
//    glVertex3f(0.0f, 1.0f, -4.0f);
//    
//    
//    glEnd();

    glBegin(GL_QUADS); //Begin drawing quadrilaterals
    glColor3f(0.0, 0.3, 0.4);
    
    // 4 corner points on square
    glVertex3f(2.0f, 1.0f, -5.0f);
    glVertex3f(2.0f, 1.0f, -7.0f);
    glVertex3f(-2.0f, 1.0f, -7.0f);
    glVertex3f(-2.0f, 1.0f, -5.0f);
    
    glEnd();


    glBegin(GL_QUADS); //Begin drawing quadrilaterals
    glColor3f(0,0.2,0.7);
    
    // 4 corner points on square
    glVertex3f(2.0f, -1.0f, -5.0f);
    glVertex3f(2.0f, -1.0f, -7.0f);
    glVertex3f(-2.0f, -1.0f, -7.0f);
    glVertex3f(-2.0f, -1.0f, -5.0f);
    
    glEnd();
    
    glBegin(GL_QUADS); //Begin drawing quadrilaterals
    glColor3f(0.5, 0.3, 0.1);
    
    // 4 corner points on square
    glVertex3f(2.0f, -1.0f, -7.0f);
    glVertex3f(2.0f, -1.0f, -5.0f);
    glVertex3f(2.0f, 1.0f, -5.0f);
    glVertex3f(2.0f, 1.0f, -7.0f);
    
    glEnd();
    
    glBegin(GL_QUADS); //Begin drawing quadrilaterals
    glColor3f(0.5, 0.3, 0.1);
    
    // 4 corner points on square
    glVertex3f(-2.0f, -1.0f, -7.0f);
    glVertex3f(-2.0f, -1.0f, -5.0f);
    glVertex3f(-2.0f, 1.0f, -5.0f);
    glVertex3f(-2.0f, 1.0f, -7.0f);
    
    glEnd();
    
    glBegin(GL_QUADS); //Begin drawing quadrilaterals
    glColor3f(0.4,0.2,.1);
    
    // 4 corner points on square
    glVertex3f(-2.0f, -1.0f, -7.0f);
    glVertex3f(2.0f, -1.0f, -7.0f);
    glVertex3f(2.0f, 1.0f, -7.0f);
    glVertex3f(-2.0f, 1.0f, -7.0f);
    
    
    glEnd();
    
    drawSphere();
    
    glutSwapBuffers(); //Send scene to the screen to be shown
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    drawSphere();
    drawCube();
    drawWall();
    
}

//Called when the window is resized
void handleResize(int w, int h)
{

    //Tell OpenGL how to convert from coordinates to pixel values
    glViewport(0, 0, w, h);
    
    glMatrixMode(GL_PROJECTION); //Switch to setting the camera perspective
    
    //Set the camera perspective
    glLoadIdentity(); //Reset the camera
    gluPerspective(45.0,                  //The camera angle
                   (double)w / (double)h, //The width-to-height ratio
                   1.0,                //The near z clipping coordinate
                   200.0);              //The far z clipping coordinate
}


void myInit()
{
    //Initialize GLUT
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800, 800); //Window size
    
    glutCreateWindow("Monte-Carlo ray tracing"); //Create a window
    glEnable(GL_DEPTH_TEST); //Make sure 3D drawing works when one object is in front of another

}


int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    
    myInit();
    
    //Set functions for glutMainLoop to call
    glutDisplayFunc(draw);
    glutReshapeFunc(handleResize);
    
    glutMainLoop();
    
    return 0;
}