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

const GLfloat EDGE = 50.0;
const GLfloat SQR3 = sqrt(3);
const GLfloat SQR6 = sqrt(6);

bool is_equal(GLfloat a[3], GLfloat b[3]) {
    for (int i = 0; i < 3; ++i) {
        if (abs(a[i] - b[i]) >= 5) {
            return false;
        }
    }
    return true;
}

bool is_equal(GLfloat vertices[4][3]) {
    for (int i = 0; i < 4; ++i) {
        for (int j = i + 1; j < 4; ++j) {
            if (!is_equal(vertices[i], vertices[j])) {
                return false;
            }
        }
    }
    return true;
}

void triangle(GLfloat vertices[3][3], GLfloat color[3]) {
    glColor3fv(color);
    for (int i = 0; i < 3; ++i) {
        glVertex3fv(vertices[i]);
    }
}

bool cmp(GLfloat v1[3], GLfloat v2[3]) {
    for (int i = 2; i >= 0; --i) {
        if (v1[i] != v2[i]) {
            return v1[i] < v2[i];
        }
    }
    return false;
}

void swap(GLfloat v1[3], GLfloat v2[3]) {
    for (int i = 0; i < 3; ++i) {
        GLfloat tmp = v1[i];
        v1[i] = v2[i];
        v2[i] = tmp;
    }
}

void sort(GLfloat vertices[4][3]) {
    for (int i = 0; i < 4; ++i) {
        for (int j = i + 1; j < 4; ++j) {
            if (!cmp(vertices[i], vertices[j])) {
                swap(vertices[i], vertices[j]);
            }
        }
    }
}

void tetra(GLfloat vertices[4][3], GLfloat colors[4][3]) {
    sort(vertices);
    for (int i = 0; i < 4; ++i) {
        GLfloat tri[3][3];
        for (int j = 0; j < 3; ++j) {
            for (int k = 0; k < 3; ++k) {
                tri[j][k] = vertices[(i+j)%4][k];
            }
        }
        triangle(tri, colors[i]);
    }
}

void divide_triangle(GLfloat vertices[4][3], GLfloat colors[4][3]) {
    if (is_equal(vertices)) {
        tetra(vertices, colors);
    }
    else {
        for (int i = 0; i < 4; ++i) {
            GLfloat child[4][3];
            for (int j = 0; j < 4; ++j) {
                for (int k = 0; k < 3; ++k) {
                    child[j][k] = (vertices[i][k] + vertices[(i+j)%4][k]) / 2;
                }
            }
            divide_triangle(child, colors);
        }
    }
}

void display()
{
    GLfloat vertices[4][3] = { {0.0, 0.0, 0.0}, {EDGE, 0.0, 0.0}, {EDGE/2, EDGE*SQR3/2, 0.0}, {EDGE/2, EDGE*SQR3/6, EDGE*SQR6/3} };
    GLfloat colors[4][3] = { {1.0, 1.0, 0.5}, {0.5, 1.0, 0.5}, {0.5, 0.8, 0.5}, {0.5, 0.5, 1.0} };
    
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    glBegin(GL_TRIANGLES);
    divide_triangle(vertices, colors);
    glEnd();
    glFlush();
    
}

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
    glTranslatef(-2,0,0);
    glutSolidSphere(1.0, 40, 40);
    glFlush();
}

void display2()
{
    glClear(GL_COLOR_BUFFER_BIT);
    drawSphere();
    drawCube();
    drawWall();
    
}

void myInit2()
{
    glClearColor(1.0,1.0,1.0,1.0);
    glColor3f(1.0,0.0,0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-5.0, 5.0, -5.0, 5.0);
    glMatrixMode(GL_MODELVIEW);
}

void myinit() {
    glEnable(GL_DEPTH_TEST);
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glColor3f(0.0, 1.0, 0.0);
    
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, EDGE, 0, EDGE*SQR3/2, -EDGE, 0);
    
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE | GLUT_DEPTH);
    
    glutInitWindowSize(600, 600*SQR3/2);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("monteCarlo");
    
    glutDisplayFunc(display2);
    
    myInit2();
    glutMainLoop();
    return 0;
}