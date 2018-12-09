#-------------------------------------------------
#
# Project created by QtCreator 2018-11-29T14:58:09
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Simplex
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        mainwindow.cpp

HEADERS += \
        mainwindow.h \
    SistemasdeControle/headers/restrictedOptimization/simplex.h \
    SistemasdeControle/src/restrictedOptimization/simplex.hpp \
    SistemasdeControle/headers/primitiveLibs/LinAlg/linalg.h \
    SistemasdeControle/src/primitiveLibs/LinAlg/linalg.hpp \
    SistemasdeControle/headers/restrictedOptimization/linprog.h \
    SistemasdeControle/src/restrictedOptimization/linprog.hpp \
    SistemasdeControle/headers/primitiveLibs/LinAlg/matrixrestriction.h \
    SistemasdeControle/src/primitiveLibs/LinAlg/matrixrestriction.hpp \
    SistemasdeControle/headers/primitiveLibs/LinAlg/matrix.h \
    SistemasdeControle/headers/optimizationLibs/leastsquare.h \
    SistemasdeControle/headers/optimizationLibs/optimization.h \
    SistemasdeControle/headers/optimizationLibs/pso.h \
    SistemasdeControle/headers/optimizationLibs/recursiveleastsquare.h \
    SistemasdeControle/headers/optimizationLibs/relay.h \
    SistemasdeControle/headers/primitiveLibs/LinAlg/identifiers.h \
    SistemasdeControle/headers/primitiveLibs/LinAlg/linalg.h \
    SistemasdeControle/headers/primitiveLibs/LinAlg/matrix.h \
    SistemasdeControle/headers/primitiveLibs/LinAlg/matrixrestriction.h \
    SistemasdeControle/headers/primitiveLibs/LinAlg/matrixrestriction.hpp \
    SistemasdeControle/headers/primitiveLibs/polynom.h \
    SistemasdeControle/headers/primitiveLibs/polynom.h.du4996 \
    SistemasdeControle/headers/primitiveLibs/primitives.h \
    SistemasdeControle/headers/restrictedOptimization/activeset.h \
    SistemasdeControle/headers/restrictedOptimization/activeset.hpp \
    SistemasdeControle/headers/restrictedOptimization/generalisedrestrictednewton.h \
    SistemasdeControle/headers/restrictedOptimization/linprog.h \
    SistemasdeControle/headers/restrictedOptimization/polyhedron.h \
    SistemasdeControle/headers/restrictedOptimization/polyhedron.hpp \
    SistemasdeControle/headers/restrictedOptimization/quadprog.h \
    SistemasdeControle/headers/restrictedOptimization/recursiveactiveset.h \
    SistemasdeControle/headers/restrictedOptimization/simplex.h \
    SistemasdeControle/src/optimizationLibs/leastsquare.hpp \
    SistemasdeControle/src/optimizationLibs/optimization.hpp \
    SistemasdeControle/src/optimizationLibs/pso.hpp \
    SistemasdeControle/src/optimizationLibs/recursiveleastsquare.hpp \
    SistemasdeControle/src/optimizationLibs/relay.hpp \
    SistemasdeControle/src/primitiveLibs/LinAlg/linalg.hpp \
    SistemasdeControle/src/primitiveLibs/LinAlg/matrix.hpp \
    SistemasdeControle/src/primitiveLibs/LinAlg/matrix.hpp.Ag5656 \
    SistemasdeControle/src/primitiveLibs/LinAlg/matrixrestriction.hpp \
    SistemasdeControle/src/primitiveLibs/polynom.hpp \
    SistemasdeControle/src/primitiveLibs/polynom.hpp.KI9960 \
    SistemasdeControle/src/restrictedOptimization/activeset.hpp \
    SistemasdeControle/src/restrictedOptimization/generalisedrestrictednewton.hpp \
    SistemasdeControle/src/restrictedOptimization/linprog.hpp \
    SistemasdeControle/src/restrictedOptimization/polyhedron.hpp \
    SistemasdeControle/src/restrictedOptimization/quadprog.hpp \
    SistemasdeControle/src/restrictedOptimization/recursiveactiveset.hpp \
    SistemasdeControle/src/restrictedOptimization/simplex.hpp

FORMS += \
        mainwindow.ui
