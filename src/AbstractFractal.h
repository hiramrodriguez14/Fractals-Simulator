#pragma once
#include "ofMain.h"
#include "Fractal.h"
using namespace std;
class AbstractFractal : public Fractal {
protected:
    string name;
    int level;

public:
    AbstractFractal() : level(0) {} // Default constructor
    AbstractFractal(const string& name, int level) : name(name), level(level) {} // Constructor to initialize name and level

    // Getter methods
    virtual std::string getName() const override { return name; }
    virtual int getLevel() const override { return level; }

    // Setter methods
    virtual void setName(const string& name) override { this->name = name; }
    virtual void setLevel(int level) override { this->level = level; }


    virtual ~AbstractFractal() {}
};
