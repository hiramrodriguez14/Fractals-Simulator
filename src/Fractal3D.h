#pragma once

#include "ofMain.h"
#include "AbstractFractal.h"
using namespace glm;

class Fractal3D:public AbstractFractal {
    private:
    ofColor currentColor;
        ofMesh mesh;
        ofEasyCam* cam;
        bool currentMeshHasDetail = false;
        bool extrudeAllFaces = false;
    public:
        Fractal3D(const std::string& name, int level,ofEasyCam* cam): AbstractFractal(name, level) ,cam(cam){}
        ~Fractal3D();
       
        vec3 centerOf(vector<vec3>& points);

       void draw()override;
        void draw(map<string, float>);
        void generateTetrahedron(vector<vec3>& base, vec3 peak, int n);
        void reset();
        map<string, float> getDefaultConfig();
        void toggleDetail();
};
