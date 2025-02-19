// Motor 1
const int IN1 = 8;
const int IN2 = 9;

// Motor 2
const int IN3 = 10;
const int IN4 = 11;

void setup() {
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
}

void loop() {
  Adelante();
  Atras();
}

void Adelante(){
   // Mover los motores hacia adelante
  digitalWrite(IN1, HIGH); 
  digitalWrite(IN2, LOW); 
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW); 
  
  delay(2000); // Espera 2 segundos
}

void Atras(){
  // Mover los motores hacia atrás
  digitalWrite(IN1, LOW);   // Motor 1 retrocede
  digitalWrite(IN2, HIGH);  // Motor 1 retrocede
  digitalWrite(IN3, LOW);   // Motor 2 retrocede
  digitalWrite(IN4, HIGH);  // Motor 2 retrocede
  
  delay(2000); // Espera 2 segundos
}
