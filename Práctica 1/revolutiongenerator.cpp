#include "revolutiongenerator.h"
#include <vector>
#include <vertex.h>
#include <object3d.h>

RevolutionGenerator::RevolutionGenerator()
{
}

void RevolutionGenerator::generate(unsigned int steps, vector<float> &vertices_vertex, Object3d & obj)
{
    double angulo =  (PI*2)/steps;

    vector<float>::iterator
            it = vertices_vertex.begin(),
            vertices_vertex_end = vertices_vertex.end();
    _vertex3f aux;

    //Vértice tapa abajo
    obj.addVertex(_vertex3f(0,vertices_vertex[1],0));

    while(it != vertices_vertex_end){

        aux.x = (*it);
        ++it;
        aux.y = (*it);
        ++it;
        aux.z = (*it);
        ++it;

        obj.addVertex(aux);

        for(unsigned int i=0; i<steps; i++) {
            double anguloR = angulo * i;
            obj.addVertex(_vertex3f(
                                 aux.x* cos(anguloR) + aux.z * sin(anguloR),
                                 aux.y,
                                 aux.z * cos(anguloR) - aux.x * sin(anguloR)));
        }
    }

    //Vértice tapa arriba
    obj.addVertex(_vertex3f(0,vertices_vertex[vertices_vertex.size()-2],0));

    vector<int> faces_vertex;
    int vertices_number = obj.getVerticesNumber();

    //Caras tapa abajo
    for(unsigned int i=1; i<=steps; i++) {
        if(i==steps) {
            //obj.addFace(_vertex3ui(0,i,(i+1)%steps));
        } else {
            obj.addFace(_vertex3ui(0,i,i+1));
        }
    }

    for(unsigned int i=0; i<=steps; i++){
        if(i==steps) {
            for(unsigned int j=i;j<(vertices_number-steps-1);j=j+steps) {
                obj.addFace(_vertex3ui(j,j+1-steps,j+steps));
                obj.addFace(_vertex3ui(j+steps,j+1,j+1-steps));
            }
        } else {
            for(unsigned int j=i;j<(vertices_number-steps-1);j=j+steps) {
                obj.addFace(_vertex3ui(j,j+1,j+1+steps));
                obj.addFace(_vertex3ui(j+steps,j,j+1+steps));
            }
        }
    }

    //Tapa de arriba

    for (unsigned int i=steps;i>=1;i--) {
        if(i == 1) {
            obj.addFace(_vertex3ui(
                               vertices_number-1,
                               vertices_number-i-1,
                               vertices_number-steps-1));
        } else {
            obj.addFace(_vertex3ui(vertices_number-1,
                                      vertices_number-i-1,
                                      vertices_number-i));
        }

    }

}
