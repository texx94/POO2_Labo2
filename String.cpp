#include "String.hpp"
#include <cstring>

using namespace std;

/* CONSTRUCTEURS */
// Constructeur sans paramètres
String::String() : value(nullptr), length(0) {};

// Constructeur à partir d'une chaîne de caractère
String::String(const char* value) {
   if (value) {
      this->length = strlen(value);
      this->value = new char[this->length + 1];
      strcpy(this->value, value);
   } else {
      this->length = 0;
      this->value = new char[0];
   }
}

// Constructeur de copie
String::String(const String& s) {
   length = strlen(s.value);
   value = new char[length + 1];
   strcpy(value, s.value);
}

/* METHODES */
