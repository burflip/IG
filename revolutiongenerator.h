#ifndef REVOLUTIONGENERATOR_H
#define REVOLUTIONGENERATOR_H

#include<vector>
#include<matrix.h>
#include<vertex.h>
#include<object3d.h>

#define PI 3.14159265

class RevolutionGenerator
{
public:
    RevolutionGenerator();
    static void generate(unsigned int steps,vector<float> &vertices_vertex, Object3d & obj);
};

#endif // REVOLUTIONGENERATOR_H
