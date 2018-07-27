#include "MeMCore.h"

void setup() 
{
   Serial.begin(9600);
}

int i=0;

void loop()
{
  
   Serial.println("   lalalla");
   Serial.print(i++);
//   delay(2000);
}
