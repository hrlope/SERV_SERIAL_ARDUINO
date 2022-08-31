//programa correspondiente al control de un brazo robotico a traves del servos y teclado del computador
//el brazo que se debe usar debe tener 4 servomotores  
#include <Servo.h>

//Declaracion de variables globales
Servo GRIP;
Servo Alto;
Servo girar;
Servo extn;

int pinit1;
int pinit2;
int pinit3;
int pinit4;
///-------------------
char sinput;
String Key;         

void setup()
{
  GRIP.attach(3);  //grip   ---> Servo - attach()	/pin de los servos a/d
  Alto.attach(5); //Alto
  girar.attach(9); //girar
  extn.attach(6); //extn------extension del brazon 
 //inicializacion de la posicion  
  int pinit1=50;//Posición inicial GRIP
  int pinit2=80;//Posición inicial Alto
  int pinit3=5;//Posición inicial para girar  0
  int pinit4=70;//Posición inicial extención

  GRIP.write(pinit1);  
  Alto.write(pinit2);  
  girar.write(pinit3);  
  extn.write(pinit4);  

  Serial.begin(9600);
}


void loop()
{
  while (Serial.available() > 0)
  {
    sinput = Serial.read();
    Key.concat(sinput);
    delay(15);  
  }
  
  //obtencion de dato de tecla/key para determinar la posicion 
            if (Key.equals("q") == true)
            {
              pinit1=20;
              GRIP.write(pinit1);              // Lleva servo a la posición pinit1
              Serial.println("Cerrar");
              delay(25); 
            }
            if (Key.equals("e") == true)
            {
              pinit1=50;
              GRIP.write(pinit1);              //Lleva servo a la posición pinit1
              Serial.println("Abrir");
              delay(25); 
            }

       //Posición de la Alto 
            if (Key.equals("w") == true)
            {
              pinit2=pinit2;
              Alto.write(pinit2);              //Lleva servo a la posición  pinit2
              Serial.println("Subiendo");
              pinit2=pinit2+5;
              delay(25); 
            }
            if (Key.equals("s") == true)
            {
              pinit2=pinit2;
              Alto.write(pinit2);              //Lleva servo a la posición  pinit2
              Serial.println("Bajando");
              pinit2=pinit2-5;
              delay(25); 
            }
            
       //Posición del girar 
            if (Key.equals("a") == true)
            {
              girar.write(pinit3);               
              Serial.println("dando giro a la Izquierda");
              pinit3=pinit3+5;
              delay(25); 
            }
            if (Key.equals("d") == true)
            {
              girar.write(pinit3);              // 
              Serial.println("dando giro a la Derecha");
              pinit3=pinit3-5;
              delay(25); 
            }

       //Posición de la EXTENDIDA 
            if (Key.equals("z") == true)
            {              
              extn.write(pinit4);              // 
              Serial.println("Adelante");
              pinit4=pinit4+4;
              delay(25); 
            }
            if (Key.equals("x") == true)
            {
              extn.write(pinit4);              // 
              Serial.println("Atras");
              pinit4=pinit4-4;
              delay(25); 
            }                        
  Key = "";
}
