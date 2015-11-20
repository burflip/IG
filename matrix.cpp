#include "matrix.h"
#include <GL/glut.h>
#include <vertex.h>
#include <vector>
#include <file_ply_stl.h>
#include <revolutiongenerator.h>

Matrix::Matrix()
{
    this->multiplier = 1;
}

Matrix::Matrix(vector<_vertex3f> &vertices)
{
    storeObject(vertices);
}

void Matrix::storeObject(vector<_vertex3f> &vertices)
{
    this->vertices = vertices;
}

void Matrix::addVertex(float x, float y, float z)
{
    this->vertices.push_back(_vertex3f(x,y,z));
}

void Matrix::addVertex(_vertex3f vertex)
{
    this->vertices.push_back(vertex);
}

void Matrix::addFace(unsigned int _0,unsigned int _1, unsigned int _2)
{
    this->faces.push_back(_vertex3ui(_0,_1,_2));
}

void Matrix::addFace(_vertex3ui face_coords)
{
    this->faces.push_back(face_coords);
}

void Matrix::drawCurrentObject()
{
    switch(this->drawing_mode) {
    case PUNTOS:
        drawPoints();
        break;
    case ALAMBRE:
        drawWire();
        break;
    case SOLIDO:
        drawSolid();
        break;
    case AJEDREZ:
        drawChess();
        break;
    case MEZCLA:
        drawPoints();
        drawWire();
        drawChess();
        break;
    }

}

void Matrix::drawPoints()
{
    glColor3f(0,1,0);
    glPointSize(4);

    glBegin(GL_POINTS);
    vector<_vertex3f>::iterator it = this->vertices.begin();

    while(it != this->vertices.end()){
        glVertex3f((*it).x * this->multiplier,(*it).y * this->multiplier,(*it).z * this->multiplier);
        it++;
    }
    glEnd();
}

void Matrix::drawWire()
{
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    drawWithTriangles(true);
}

void Matrix::drawSolid()
{
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    drawWithTriangles();
}

void Matrix::drawChess()
{
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    drawWithTriangles();
}

void Matrix::drawWithTriangles(bool wired)
{
    glColor3f(0,1,0);
    glBegin(GL_TRIANGLES);
    vector<_vertex3ui>::iterator it_faces = this->faces.begin();
    float x,y,z;

    while(it_faces != this->faces.end()){
        if(this->drawing_mode == AJEDREZ || (this->drawing_mode == MEZCLA && !wired)){
            if(distance(it_faces,this->faces.begin())%2 == 0) {
                glColor3f(1.0, 0.0, 0.0);
            } else {
                glColor3f(0.0, 0.0, 1.0);
            }
        }
        /**
        cout << "[" << (*it_faces)._0 << "," << (*it_faces)._1 << "," << (*it_faces)._2 << "]" << endl;
        cout << "SIZE:" << this->vertices.size() <<endl;
*/
        x=this->vertices.at((*it_faces)._0).x * this->multiplier;
        y=this->vertices.at((*it_faces)._0).y * this->multiplier;
        z=this->vertices.at((*it_faces)._0).z * this->multiplier;
        glVertex3f(x,y,z);
        x=this->vertices.at((*it_faces)._1).x * this->multiplier;
        y=this->vertices.at((*it_faces)._1).y * this->multiplier;
        z=this->vertices.at((*it_faces)._1).z * this->multiplier;
        glVertex3f(x,y,z);
        x=this->vertices.at((*it_faces)._2).x * this->multiplier;
        y=this->vertices.at((*it_faces)._2).y * this->multiplier;
        z=this->vertices.at((*it_faces)._2).z * this->multiplier;
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

        this->addVertex(x,y,z);
    } while(it_vertices != vertices.end());

    do{
        _0 = (*it_faces);
        ++it_faces;
        _1 = (*it_faces);
        ++it_faces;
        _2 = (*it_faces);
        ++it_faces;

        this->addFace(_0,_1,_2);
    } while(it_faces != faces.end());

}

void Matrix::loadRevolutionModel(char *ply_mode_file, int N)
{
    vector<float> vertices;
    vector<int> faces;
    _file_ply ply;

    float x,y,z;

    ply.open(ply_mode_file);
    ply.read(vertices,faces);

    vector<float>::iterator it_vertices = vertices.begin();

    RevolutionGenerator::generate(N,vertices,*this);

}

void Matrix::clear()
{
    this->vertices.clear();
    this->faces.clear();
}

void Matrix::printVertices()
{
    vector<_vertex3f>::iterator it= this->vertices.begin();
    while(it != this->vertices.end()) {
        cout << "v[" << distance(this->vertices.begin(),it) << "] (" << (*it).x << "," << (*it).y << "," << (*it).z << ")" << endl;
        it++;
    }
}

void Matrix::printFaces()
{
    vector<_vertex3ui>::iterator it= this->faces.begin();
    while(it != this->faces.end()) {
        cout << "f[" << distance(this->faces.begin(),it) << "] (" << (*it)._0 << "," << (*it)._1 << "," << (*it)._2 << ")" << endl;
        it++;
    }
}
