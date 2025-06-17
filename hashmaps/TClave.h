#ifndef TLISTAESTATICA_TClave_H
#define TLISTAESTATICA_TClave_H

typedef char TClave;

void crearClave (char n, TClave* e);
void mostrarClave (TClave* e);
void asignarClave(TClave* original, TClave* copia);
int igualClave (TClave* uno, TClave* dos);
int mayorClave(TClave* uno,TClave* dos);
int hash (TClave* c);

#endif //TLISTAESTATICA_TClave_H
