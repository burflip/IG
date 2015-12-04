HEADERS = \ 
    matrix.h \
    file_ply_stl.h \
    vertex.h \
    revolutiongenerator.h \
    object3d.h \
    leg.h \
    torax.h \
    _3dhbasicelement.h \
    body.h \
    hieralchicalspider.h

SOURCES = \
    practica1.cc \
    matrix.cpp \
    file_ply_stl.cc \
    revolutiongenerator.cpp \
    object3d.cpp \
    leg.cpp \
    torax.cpp \
    _3dhbasicelement.cpp \
    body.cpp \
    hieralchicalspider.cpp

LIBS += -L/casa/dmartin/codigo/funciontecas/freeglut/lib \
    -lglut -lGLU

CONFIG += console
QT += opengl

