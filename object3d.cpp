#include "object3d.h"
#include <matrix.h>

Object3d::Object3d()
{
    rotation_angle = 0;
}

Object3d::Object3d(vector<_vertex3f> vertices, vector<_vertex3ui> faces)
{
    this->vertices = vertices;
    this->faces = faces;
}

void Object3d::clear()
{
    this->vertices.clear();
    this->faces.clear();
}

void Object3d::decrementRotationAngle()
{
    if(this->rotation_angle <= 0) {
        this->rotation_angle = 360;
    }
    this->rotation_angle--;
}

void Object3d::incrementRotationAngle()
{
    if(this->rotation_angle >= 360) {
        this->rotation_angle = 0;
    }
    this->rotation_angle++;
}

_vertex3f &Object3d::getVertice(unsigned int pos) {
    if(pos < vertices.size()) {
        return this->vertices.at(pos);
    } else {
        return this->vertices.at(0);
    }
}

_vertex3ui &Object3d::getFace(unsigned int pos) {
    if(pos < faces.size()) {
        return this->faces.at(pos);
    } else {
        return this->faces.at(0);
    }
}

void Object3d::printVertices()
{
    vector<_vertex3f>::iterator it= this->vertices.begin();
    while(it != this->vertices.end()) {
        cout << "v[" << distance(this->vertices.begin(),it) << "] (" << (*it).x << "," << (*it).y << "," << (*it).z << ")" << endl;
        it++;
    }
}

void Object3d::printFaces()
{
    vector<_vertex3ui>::iterator it= this->faces.begin();
    while(it != this->faces.end()) {
        cout << "f[" << distance(this->faces.begin(),it) << "] (" << (*it)._0 << "," << (*it)._1 << "," << (*it)._2 << ")" << endl;
        it++;
    }
}


void Object3d::addVertex(float x, float y, float z)
{
    this->vertices.push_back(_vertex3f(x,y,z));
}

void Object3d::addVertex(_vertex3f vertex)
{
    this->vertices.push_back(vertex);
}

void Object3d::addFace(unsigned int _0,unsigned int _1, unsigned int _2)
{
    this->faces.push_back(_vertex3ui(_0,_1,_2));
}

void Object3d::addFace(_vertex3ui face_coords)
{
    this->faces.push_back(face_coords);
}
