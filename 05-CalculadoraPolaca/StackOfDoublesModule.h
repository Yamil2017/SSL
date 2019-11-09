#ifndef STACKOFDOUBLESMODULE_H
#define STACKOFDOUBLESMODULE_H

#include <stdbool.h>

//const int MAXBUF = 100;

typedef double ItemPila;

const ItemPila pop();

void push(const ItemPila);

bool estaVacia();

bool estaLlena();

#endif
