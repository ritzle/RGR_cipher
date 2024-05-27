#ifndef CIPHERS_H
#define CIPHERS_H

#include "functionAfin.h"
#include "functionVernam.h"
#include "functionBekon.h"
#include "functionRSA.h"
#include "functionSkitala.h"

#include <filesystem>

void Affin();
void Vernam();
void Bacon();
void RSA();
void Skitala();

void isValidSystemPassword();

#endif