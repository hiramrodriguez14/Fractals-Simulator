#pragma once
#include "AbstractFractal.h"

class Fern : public AbstractFractal {
public:
    Fern(const std::string& name, int level) : AbstractFractal(name, level) {}

    void draw(float x, float y, float n); 
    void draw()override;
};
