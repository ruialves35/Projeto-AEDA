#include "Multibanco.h"
#include <string>   //to_string

using namespace std;

/**
 * Constructor of Derived Class Multibanco.
 * Initializes referencia on 0 and nome "Multibanco"
 */
Multibanco::Multibanco(): Pagamento(), referencia(0){}

/**
 * Constructor of Derived Class Multibanco.
 * @param valorTotal TotalValue of the Payment
 * @param referencia Referencia of Multibanco
 */
Multibanco::Multibanco(double valorTotal, int referencia): Pagamento(valorTotal), referencia(referencia){}



/**
 * Gets the Referencia of Multibanco
 * @return referencia
 */
int Multibanco::getReferencia() const { return referencia; }

/**
 * Sets the Referencia of Multibanco
 * @param referencia Value to set
 */
void Multibanco::setReferencia(int referencia) {
    string ref = to_string(referencia);
    if (ref.length() != 9 || referencia < 0){
        cout << "Referencia inválida. Tente novamente" << endl;
    }
    else{
        this-> referencia = referencia;
    }
}


/**
 * returns a string with information of Multibanco
 * This information is of the form "Multibanco. Referencia: .... "
 * @return string with information
 */
void Multibanco::getInfo(ostream& o) const {
    o << "Multibanco\nReferencia: " + to_string(referencia) + "\n" + "\n";
}