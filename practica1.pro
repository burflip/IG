HEADERS = \ 
    matrix.h \
    file_ply_stl.h \
    vertex.h \
    revolutiongenerator.h

SOURCES = \
    practica1.cc \
    matrix.cpp \
    file_ply_stl.cc \
    revolutiongenerator.cpp

LIBS += -L/casa/dmartin/codigo/funciontecas/freeglut/lib \
    -lglut

CONFIG += console
QT += opengl

