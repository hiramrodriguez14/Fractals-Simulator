#pragma once
#include "Fractal.h"
#include "ofMain.h"
using namespace std;

//Abstract class for fractals
class AbstractFractal : public Fractal {
protected:
    string name;
    int level;

public:
    AbstractFractal() : name(""),level(0) {} // Default constructor
    AbstractFractal(const string& name, int level) : name(name), level(level) {} // Constructor to initialize name and level

    void draw()=0;//Draw method that will call respective draw for every fractal

    // Getter methods
    virtual std::string getName() const { return name; }
    virtual int getLevel() const { return level; }

    // Setter methods
    virtual void setName(const string& name)  { this->name = name; }
    virtual void setLevel(int level)  { this->level = level; }

    //Destructor
    virtual ~AbstractFractal() {}
};
