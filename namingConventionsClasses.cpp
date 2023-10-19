#ifndef NAMING_CONVENTIONS // Uso de flags en vez de #pragma once, a pesar de que la mayoría de los compiladores ya lo soporten, para evitar errores.
#define NAMING_CONVENTIONS

// *.h file code here

#endif

/* ORDEN DE INCLUSIÓN DE LIBRERÍAS: */
// Librerías de la STL
// Librerías de otras dependencias (Gráfica, GUI, matemáticas...)
// Librerías propias

// STL
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
/* #include <cstdint> */ // No incluir librerías que ya formen parte de otras (cstdint ya está incluida en iostream)

// OpenGL graphics
#ifndef GLEW_STATIC
#define GLEW_STATIC
#endif // Preferentemente incluir las guards en la propia configuración del proyecto
#include <GL/glew.h>
#include <GLFW/glfw3.h>

// OpenGL math
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

// GUI
#include <imgui/imgui.h>
#include <imgui/imgui_impl_glfw.h>
#include <imgui/imgui_impl_opengl3.h>

/* EXPRESIONES CONSTANTES */
#define glAssert(x) if (!(x)) __debugbreak(); // Uso de define para funciones, en camelCase como si estuviese definida en otro lugar.
#define EXAMPLE_PATH "paths/example.png"      // Uso de define para strings ya que es más rápido que un constexpr
constexpr uint16_t EXAMPLE_VAR = 269;         // Uso de constexpr para variables de un tamaño o tipo concreto.
#define EXAMPLE_VAR_2 269U;                   // Alternativa: utilizar las terminaciones f, U, etc. para indicar el tipo cuando se quiera usar un define.
// Las expresiones numéricas en mayúsculas con guiones bajos de separación.

namespace Namespace // Namespaces en PascalCase como las clases.
{
    uint8_t exampleFunc(void) { return 0; }
};

class Example
{
private: // Con guión bajo para variables privadas
    uint8_t _exampleMember1;
    uint8_t _exampleMember2;

public: // Sin guión bajo para variables públicas
    uint32_t exampleMember3;
    uint32_t exampleMember4;
    uint16_t* exampleMember5;

public: // Repetición de public para distinguir entre métodos y atributos
    uint8_t   getExampleMember1    (void) { return  _exampleMember1; }
    uint8_t*  getExampleMember1_ptr(void) { return &_exampleMember1; } // Con ptr porque no es un puntero en la declaración de la clase
    uint16_t* getExampleMember5    (void) { return   exampleMember5; } // Sin ptr porque ya es un puntero en la declaración de la clase

    void setExampleMember2(uint8_t value) { _exampleMember2 = value; } 
    void setExampleMember5(uint8_t value) { *exampleMember5 = value; }

    bool operator == (const Example& example) { return true; } // En sobrecarga de operadores, separar la palabra operator del propio operador

    uint8_t someFunction(void) // Uso de void en las declaraciones de las clases para especificar que no tiene argumento
    {
        this->setExampleMember5(5); // Utilización de this para funciones que se usan dentro de la misma clase
        return 0;
    }
};

/* ORDEN: */
// Variables privadas - protegidas - públicas
// Forma canónica
// Getters (const)
// Setters
// Sobrecarga de operadores (menos asignación [=])
// Funciones de la propia clase