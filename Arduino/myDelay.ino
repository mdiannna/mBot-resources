
#include "MeMCore.h"

bool myDelay(int milliseconds, unsigned int &startDelay) {
    if( millis()-startDelay >= milliseconds) {
      startDelay = millis();
      return true;  
    }
    return false;
}

void setup() {
  Serial.begin(9600);
  Serial.print("Started");
}

// De fiecare data cand am un myDelay nou, trebuie sa adaug o variabila noua asa
unsigned int startPrinting1 = millis();
unsigned int startPrinting2 = millis();

void loop() {
  // Exemplu de utilizare
  // pentru fiecare data cand folosesc, trebuie sa declar o alta variabila de start, de ex. startPrinting1, startPrinting2 etc.
  if(myDelay(1000, startPrinting1)) {
    Serial.println("Yep");  
  }
  
  // Al doilea exemplu de utilizare
  // Atentie, acest delay nu tine cont de alte delayuri definite mai sus sau mai jos!!!
  // Actiunea se va executa in general o data la 2 secunde
  if(myDelay(2000, startPrinting2)) {
    Serial.println("It's working!");  
  }
}