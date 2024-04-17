#include "Mandelbrot2D.h"

void Mandelbrot::draw(float x, float y, int n, float size, float r, float length) {
    // Calcula el tamaño máximo basado en el ancho y alto de la pantalla
    
    maxSize *= size; // Escala el tamaño máximo según el parámetro size

    // Genera el fractal Mandelbrot centrado en la pantalla
    generateFractal(ofGetWidth() / 2, ofGetHeight() / 2, n, maxSize);

    // Dibuja el mesh del Mandelbrot
    mesh.draw();
}

void Mandelbrot::generateFractal(float x, float y, int n, float maxSize) {
    mesh.clear();

    // Calcula las coordenadas del Mandelbrot en función del tamaño máximo
    float mandelbrotX = x - (maxSize / 2);
    float mandelbrotY = y - (maxSize / 2);

    // Itera sobre las coordenadas del Mandelbrot y agrega los puntos al mesh
    for (int i = 0; i < maxSize; i++) {
        for (int j = 0; j < maxSize; j++) {
            // Calcula las coordenadas en función de la posición relativa al Mandelbrot
            float posX = mandelbrotX + i;
            float posY = mandelbrotY + j;

            // Convertir las coordenadas de píxel a coordenadas complejas en el plano
            double real = ofMap(posX, 0, ofGetWidth(), -2.5, 1.0);
            double imag = ofMap(posY, 0, ofGetHeight(), -1.0, 1.0);
            std::complex<double> c(real, imag);

            // Inicializar el valor de z como 0
            std::complex<double> z(0, 0);

            // Calcular el valor de Mandelbrot para el punto c de forma recursiva
            int mandelbrotValue = calculateMandelbrot(c, z, n);

            // Agregar el punto al mesh con el color determinado
            addPointToMesh(posX, posY, mandelbrotValue, n);
        }
    }

    // Ajusta el modo del mesh y otras configuraciones necesarias
    mesh.setMode(OF_PRIMITIVE_POINTS);
}

int Mandelbrot::calculateMandelbrot(const std::complex<double>& c, const std::complex<double>& z, int n) {
    if (std::abs(z) > 2 || n <= 0) {
        return n; // Se alcanzó el límite de iteraciones o se excedió el límite del conjunto de Mandelbrot
    } else {
        std::complex<double> newZ = z * z + c;
        return 1 + calculateMandelbrot(c, newZ, n - 1); // Llamada recursiva con un número menor de iteraciones
    }
}

void Mandelbrot::addPointToMesh(int x, int y, int mandelbrotValue, int n) {
    // Usar el valor de Mandelbrot para determinar el color del punto
    ofColor color;
    if (mandelbrotValue == n) {
        color = ofColor(0); // El punto pertenece al conjunto de Mandelbrot
    } else {
        color = ofColor::fromHsb(255 * mandelbrotValue / n, 255, 255); // Asignar un color basado en el valor de Mandelbrot
    }

    // Agregar el punto al mesh con el color determinado
    mesh.addVertex(ofVec3f(x, y));
    mesh.addColor(color);
}
