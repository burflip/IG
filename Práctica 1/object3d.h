#ifndef OBJECT3D_H
#define OBJECT3D_H

#include <GL/glut.h>
#include <vertex.h>
#include <vector>
#include <file_ply_stl.h>

class Object3d
{
public:
    Object3d();
    Object3d(vector<_vertex3f> vertices, vector<_vertex3ui> faces);

    void addVertex(float x, float y, float z);
    void addVertex(_vertex3f vertex);
    void addFace(unsigned int _0,unsigned int _1,unsigned int _2);
    void addFace(_vertex3ui face_coords);
    void clear();

    inline int getVerticesNumber()
    {
        return this->vertices.size();
    }

    inline int getFacesNumber()
    {
        return this->faces.size();
    }

    inline void getVerticesBegin(vector<_vertex3f>::iterator & it)
    {
        it = this->vertices.begin();
    }

    inline void getVerticesEnd(vector<_vertex3f>::iterator & it)
    {
        it = this->vertices.end();
    }

    inline void getFacesBegin(vector<_vertex3ui>::iterator & it)
    {
        it = this->faces.begin();
    }

    inline void getFacesEnd(vector<_vertex3ui>::iterator & it)
    {
        it = this->faces.end();
    }

    inline vector<_vertex3f> & getVertices() {
        return this->vertices;
    }

    inline vector<_vertex3ui> & getFaces() {
        return this->faces;
    }

    inline float getRotationAngle()
    {
        return this->rotation_angle;
    }

    void decrementRotationAngle();
    void incrementRotationAngle();

    _vertex3f & getVertice(unsigned int pos);
    _vertex3ui & getFace(unsigned int pos);

    //DEBUG Functions
    void printVertices();
    void printFaces();

private:
    vector<_vertex3f> vertices;
    vector<_vertex3ui> faces;

    float rotation_angle;

};

#endif // OBJECT3D_H
