#ifndef REVOLUTIONGENERATOR_H
#define REVOLUTIONGENERATOR_H

#include<vector>
#include<matrix.h>
#include<vertex.h>

#define PI 3.14159265

class RevolutionGenerator
{
public:
    RevolutionGenerator();
    static void generate(unsigned int steps,vector<float> &vertices_vertex, Matrix &matrix);
private:
    void addCovers();
};

#endif // REVOLUTIONGENERATOR_H
