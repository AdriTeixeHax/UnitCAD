#include <cstdint>

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