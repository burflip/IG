#include "matrix.h"
#include <GL/glut.h>
#include <vertex.h>
#include <vector>
#include <file_ply_stl.h>
#include <revolutiongenerator.h>
#include <object3d.h>
#include <leg.h>

Matrix::Matrix()
{
    this->multiplier = 1;
}

void Matrix::storeObject(Object3d & obj)
{
    this->objects.push_back(obj);
    this->current_object = objects.end();
}

void Matrix::store3dHObject(_3dHBasicElement &elem)
{
    this->jerarquic_objects.push_back(elem);
}

void Matrix::draw3dJObjects()
{
    vector<_3dHBasicElement>::iterator it=this->jerarquic_objects.begin();
    while(it != this->jerarquic_objects.end())
    {
        (*it).draw();
        it++;
    }
}

void Matrix::drawPLYObjects()
{
    vector<Object3d>::iterator ply_obj = this->objects.begin();
    while(ply_obj != this->objects.end()) {
        drawPLYObject(ply_obj);
        ply_obj++;
    }
}

void Matrix::drawPLYObject(vector<Object3d>::iterator & obj_it)
{
    switch(this->drawing_mode) {
    case PUNTOS:
        drawPoints((*obj_it));
        break;
    case ALAMBRE:
        drawWire((*obj_it));
        break;
    case SOLIDO:
        drawSolid((*obj_it));
        break;
    case AJEDREZ:
        drawChess((*obj_it));
        break;
    case MEZCLA:
        drawPoints((*obj_it));
        drawWire((*obj_it));
        drawChess((*obj_it));
        break;
    }

}

void Matrix::drawAllObjects()
{
    drawPLYObjects();
}

void Matrix::drawObject(int pos)
{
    vector<Object3d>::iterator it = objects.begin();
    if(pos < this->objects.size())
        it+=pos;
    this->current_object = it;
    drawPLYObject(it);
}

void Matrix::drawObjectTranslated(int pos)
{
    vector<Object3d>::iterator it = objects.begin();
    if(pos < this->objects.size())
        it+=pos;

    this->current_object = it;
    glPushMatrix();
    glScalef(0.5,0.5,0.5);
    glTranslatef(-12,3,-12);
    glRotatef((*it).getRotationAngle(),0,1,0);
    drawPLYObject(it);
    glPopMatrix();
}

void Matrix::drawPoints(Object3d & obj)
{
    glColor3f(0,1,0);
    glPointSize(4);

    glBegin(GL_POINTS);
    vector<_vertex3f>::iterator it_begin,it_end;

    obj.getVerticesBegin(it_begin);
    obj.getVerticesEnd(it_end);

    while(it_begin != it_end){
        glVertex3f((*it_begin).x * this->multiplier,(*it_begin).y * this->multiplier,(*it_begin).z * this->multiplier);
        it_begin++;
    }
    glEnd();
}

void Matrix::drawWire(Object3d & obj)
{
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    drawWithTriangles(obj,true);
}

void Matrix::drawSolid(Object3d & obj)
{
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    drawWithTriangles(obj);
}

void Matrix::drawChess(Object3d & obj)
{
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    drawWithTriangles(obj);
}

void Matrix::drawWithTriangles(Object3d & obj, bool wired)
{
    glColor3f(0,1,0);
    glBegin(GL_TRIANGLES);
    vector<_vertex3ui>::iterator it_begin,it_end,it_faces;

    obj.getFacesBegin(it_begin);
    obj.getFacesBegin(it_faces);
    obj.getFacesEnd(it_end);
    float x,y,z;
    int i = 0;
    while(it_faces != it_end){
        i++;
        if(this->drawing_mode == AJEDREZ || (this->drawing_mode == MEZCLA && !wired)){
            if(distance(it_faces,it_begin)%2 == 0) {
                glColor3f(1.0, 0.0, 0.0);
            } else {
                glColor3f(0.0, 0.0, 1.0);
            }
        }

        x=obj.getVertice((*it_faces)._0).x * this->multiplier;
        y=obj.getVertice((*it_faces)._0).y * this->multiplier;
        z=obj.getVertice((*it_faces)._0).z * this->multiplier;
        glVertex3f(x,y,z);
        x=obj.getVertice((*it_faces)._1).x * this->multiplier;
        y=obj.getVertice((*it_faces)._1).y * this->multiplier;
        z=obj.getVertice((*it_faces)._1).z * this->multiplier;
        glVertex3f(x,y,z);
        x=obj.getVertice((*it_faces)._2).x * this->multiplier;
        y=obj.getVertice((*it_faces)._2).y * this->multiplier;
        z=obj.getVertice((*it_faces)._2).z * this->multiplier;
        glVertex3f(x,y,z);

        ++it_faces;

    }
    glEnd();
}

void Matrix::loadModel(char *ply_model_file)
{
    vector<float> vertices;
    vector<int> faces;
    _file_ply ply;
    Object3d obj;

    float x,y,z;
    int _0,_1,_2;

    ply.open(ply_model_file);
    ply.read(vertices,faces);

    vector<float>::iterator it_vertices = vertices.begin();
    vector<int>::iterator it_faces = faces.begin();

    do {
        x = (*it_vertices);
        ++it_vertices;
        y = (*it_vertices);
        ++it_vertices;
        z = (*it_vertices);
        ++it_vertices;

        obj.addVertex(x,y,z);
    } while(it_vertices != vertices.end());

    do{
        _0 = (*it_faces);
        ++it_faces;
        _1 = (*it_faces);
        ++it_faces;
        _2 = (*it_faces);
        ++it_faces;

        obj.addFace(_0,_1,_2);
    } while(it_faces != faces.end());

    storeObject(obj);

}

void Matrix::loadRevolutionModel(char *ply_mode_file, int N)
{
    vector<float> vertices;
    vector<int> faces;
    _file_ply ply;
    Object3d obj;

    ply.open(ply_mode_file);
    ply.read(vertices,faces);

    vector<float>::iterator it_vertices = vertices.begin();
    RevolutionGenerator::generate(N,vertices,obj);

    storeObject(obj);
}

void Matrix::setDrawingMode(int mode)
{
    this->drawing_mode = mode;
}
