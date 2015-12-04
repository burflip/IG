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
#include <object3d.h>
#include <leg.h>
#include <torax.h>

using namespace std;

class Matrix
{
public:

    Matrix();

    void storeObject(Object3d & object);
    void store3dHObject(_3dHBasicElement & elem);

    void drawCurrentObject();
    void draw3dJObjects();
    void drawPLYObjects();
    void drawPLYObject(vector<Object3d>::iterator & obj_it);
    void drawAllObjects();
    void drawObject(int pos);
    void drawObjectTranslated(int pos);

    void loadModel(char * ply_model_file);
    void loadRevolutionModel(char * ply_mode_file, int N);

    inline Object3d & getCurrentObject()
    {
        return (*current_object);
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

    void setDrawingMode(int mode);

private:

    vector<Object3d> objects;
    vector<Object3d>::iterator current_object;
    vector<_3dHBasicElement> jerarquic_objects;

    int drawing_mode;
    float multiplier;

    void drawPoints(Object3d & obj);
    void drawSolid(Object3d & obj);
    void drawWire(Object3d & obj);
    void drawChess(Object3d & obj);
    void drawWithTriangles(Object3d & obj, bool wired = false);

};

#endif // MATRIX_H
