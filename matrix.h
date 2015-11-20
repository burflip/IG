#ifndef MATRIX_H
#define MATRIX_H

#define PUNTOS 0
#define ALAMBRE 1
#define SOLIDO 2
#define AJEDREZ 3
#define MEZCLA 4

#include <GL/glut.h>
#include <vertex.h>
#include <vector>
#include <file_ply_stl.h>

using namespace std;

class Matrix
{
public:

    Matrix();
    Matrix(vector<_vertex3f> &vertices);
    void storeObject(vector<_vertex3f> &vertices);
    void addVertex(float x, float y, float z);
    void addVertex(_vertex3f vertex);
    void addFace(unsigned int _0,unsigned int _1,unsigned int _2);
    void addFace(_vertex3ui face_coords);
    void drawCurrentObject();


    void loadModel(char * ply_model_file);
    void loadRevolutionModel(char * ply_mode_file, int N);
    void clear();

    inline int getVerticesNumber()
    {
        return this->vertices.size();
    }

    inline int getFacesNumber()
    {
        return this->faces.size();
    }

    inline void setDrawingMode(int d)
    {
        this->drawing_mode = d;
    }
    inline void setMultiplier(float m)
    {
        this->multiplier = m;
    }
    inline void incrementSize()
    {
        setMultiplier(this->multiplier+1);
    }

    inline void decrementSize()
    {
        if(this->multiplier >= 1) {
            setMultiplier(this->multiplier-1);
        }
    }

    //DEBUG FUNCTIONS

    void printVertices();
    void printFaces();

private:

    vector<_vertex3f> vertices;
    vector<_vertex3ui> faces;
    int drawing_mode;
    float multiplier;

    void drawPoints();
    void drawSolid();
    void drawWire();
    void drawChess();
    void drawWithTriangles(bool wired = false);

};

#endif // MATRIX_H
