
//Declaration of Arduino pins used as HCF4511 inputs
const int A=2;
const int B=3;
const int C=4;
const int D=5;
const int UN=6;
const int DE=7;
 
void setup() {
  pinMode(A0, INPUT);
  pinMode(A, OUTPUT); //LSB
  pinMode(B, OUTPUT);
  pinMode(C, OUTPUT);
  pinMode(D, OUTPUT); //MSB
  pinMode(UN, OUTPUT);
  pinMode(DE, OUTPUT);
  Serial.begin(9600);
  Serial.println("Hello from Arduino");
}
 
int count = 0; //the variable used to show the number
int decena = 0;
int unidad = 0;
 
void loop() {
    count++; 
    delay(1000); //the delay prevent from button bouncing
    //Serial.println(count);
    if (count == 100) //we want to count from 0 to 9!
      count = 0;
    to_BCD(count); //convert to binary 
}
 
void to_BCD(int valor)
{ int x=0;
  
  while(x<70) //falta ajustar este tiempo
  {
    x++;
    Serial.println(x);
    decena = valor / 10;
    unidad = valor % 10;
    digitalWrite (UN, HIGH);
    digitalWrite (DE, LOW);
    Escribo(unidad);
    delay(18);
    digitalWrite (UN, LOW);
    digitalWrite (DE, HIGH);
    Escribo(decena);
    delay(18);
  };
}

void Escribo(int Dato)
{
  if (Dato == 0) //write 0000
    {
      digitalWrite(A, LOW);
      digitalWrite(B, LOW);
      digitalWrite(C, LOW);
      digitalWrite(D, LOW);
    }
     
    if (Dato == 1) //write 0001
    {
      digitalWrite(A, HIGH);
      digitalWrite(B, LOW);
      digitalWrite(C, LOW);
      digitalWrite(D, LOW);
    }
     
    if (Dato == 2) //write 0010
    {
      digitalWrite(A, LOW);
      digitalWrite(B, HIGH);
      digitalWrite(C, LOW);
      digitalWrite(D, LOW);
    }
     
    if (Dato == 3) //write 0011
    {
      digitalWrite(A, HIGH);
      digitalWrite(B, HIGH);
      digitalWrite(C, LOW);
      digitalWrite(D, LOW);
    }
     
    if (Dato == 4) //write 0100
    {
      digitalWrite(A, LOW);
      digitalWrite(B, LOW);
      digitalWrite(C, HIGH);
      digitalWrite(D, LOW);
    }
     
    if (Dato == 5) //write 0101
    {
      digitalWrite(A, HIGH);
      digitalWrite(B, LOW);
      digitalWrite(C, HIGH);
      digitalWrite(D, LOW);
    }
     
    if (Dato == 6) //write 0110
    {
      digitalWrite(A, LOW);
      digitalWrite(B, HIGH);
      digitalWrite(C, HIGH);
      digitalWrite(D, LOW);
    }
     
    if (Dato == 7) //write 0111
    {
      digitalWrite(A, HIGH);
      digitalWrite(B, HIGH);
      digitalWrite(C, HIGH);
      digitalWrite(D, LOW);
    }
     
    if (Dato == 8) //write 1000
    {
      digitalWrite(A, LOW);
      digitalWrite(B, LOW);
      digitalWrite(C, LOW);
      digitalWrite(D, HIGH);
    }
     
    if (Dato == 9) //write 1001
    {
      digitalWrite(A, HIGH);
      digitalWrite(B, LOW);
      digitalWrite(C, LOW);
      digitalWrite(D, HIGH);
    } 
}
