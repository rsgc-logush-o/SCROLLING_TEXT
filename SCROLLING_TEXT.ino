//INTERRUPT TIMER USE
//COMPARE MATCH REGISTER IS 259
//PRESCALER IS 1024
//FREQUENCY IS 6HZ
//ARDUINO CLOCK SPEED IS 16,000,000 HZ OR 16 MHZ
//I WILL HAVE TO USE TIMER1
//


byte charToPrint[95][8]
{
  {0,0,0,0,0,0,0,0},//SPACE
  {1,1,1,1,1,0,1,0},//!
  {3,3,3,0,0,0,0,0},//"
  {0,0,10,31,10,31,10,0},//#
  {4,30,5,14,20,20,15,4},//$
  {0,0,19,11,4,26,25,0},//%
  {0,6,9,6,5,9,22,0},//&
  {0,16,8,0,0,0,0,0},//'
  {16,8,8,8,8,8,16,0},//(
  {8,16,16,16,16,16,8,0},//)
  {0,18,12,63,12,18,0,0},//*
  {0,0,4,4,31,4,4,0},//+
  {0,0,0,0,0,0,16,8},//,
  {0,0,0,0,31,0,0,0},//-
  {0,0,0,0,0,0,1,0},//.
  {64,32,16,8,4,2,1,0},///
  {14,17,25,21,19,17,14,0},//0
  {4,6,5,4,4,4,31,0},//1
  {14,17,16,8,4,2,31,0},//2
  {14,17,16,14,16,17,14,0},//3
  {8,12,10,9,31,8,8,0},//4
  {31,1,15,16,16,16,15,0},//5
  {14,1,1,15,17,17,14,0},//6
  {31,16,8,4,2,1,1,0},//7
  {14,17,17,14,17,17,14,0},//8
  {14,17,17,30,16,16,14,0},//9
  {0,0,1,0,0,1,0,0}, //:
  {0,0,1,0,0,1,1,0},//;
  {0,4,2,1,2,4,0,0},//<
  {0,0,31,0,0,31,0,0},//=
  {0,1,2,4,2,1,0,0},//>
  {14,17,16,8,4,4,0,4},//?
  {28,34,89,85,85,121,2,4},//@
  {14,17,17,31,17,17,17,0},//A
  {15,17,17,15,17,17,15,0},//B
  {14,17,1,1,1,17,14,0},//C
  {15,17,17,17,17,17,15,0},//D
  {31,1,1,31,1,1,31,0},//E
  {31,1,1,15,1,1,1,0},//F
  {14,17,1,1,25,17,14,0},//G
  {17,17,17,31,17,17,17,0},//H
  {7,2,2,2,2,2,7,0},//I
  {28,8,8,8,8,9,6,0},//J
  {17,9,5,3,5,9,17,0},//K
  {1,1,1,1,1,1,31,0},//L
  {17,27,21,17,17,17,17,0},//M
  {17,19,21,25,17,17,17,0},//N
  {14,17,17,17,17,17,14,0},//O
  {15,17,17,15,1,1,1,0},//P
  {14,17,17,17,25,17,46,0},//Q
  {15,17,17,15,17,17,17,0},//R
  {14,17,1,14,16,17,14,0},//S
  {31,4,4,4,4,4,4,0},//T
  {17,17,17,17,17,17,14,0},//U
  {17,17,17,17,17,10,4,0},//V
  {17,17,17,17,21,27,17,0},//W
  {17,17,10,4,10,17,17,0},//X
  {17,10,4,4,4,4,4,0},//Y
  {31,16,8,4,2,1,31,0},//Z
  {3,1,1,1,1,1,3,0},//[
  {0,1,2,4,8,16,0,0},//\
  {3,2,2,2,2,2,3,0},//]
  {2,5,0,0,0,0,0,0},//^
  {0,0,0,0,0,0,31,0},//_
  {1,2,0,0,0,0,0,0},//` 
  {0,0,14,16,30,17,30,0},//a
  {0,1,1,7,9,9,7,0},//b
  {0,0,14,1,1,1,14,0},//c
  {0,8,8,14,9,9,14,0},//d
  {0,0,6,9,15,1,6,0},//e
  {0,12,2,7,2,2,2,0},//f
  {0,0,14,9,9,14,8,6},//g
  {0,1,1,7,9,9,9,0},//h
  {0,2,0,3,2,2,7,0},//i
  {0,8,0,8,8,8,9,6},//j
  {0,1,9,5,3,5,9,0},//k
  {0,3,2,2,2,2,7,0},//l
  {0,0,0,11,21,21,21,0},//m
  {0,0,0,7,9,9,9,0},//n
  {0,0,6,9,9,9,6,0},//o
  {0,0,7,9,9,7,1,1},//p
  {0,0,14,9,9,14,8,8},//q
  {0,0,0,7,9,1,1,0},//r
  {0,0,14,1,6,8,7,0},//s
  {0,2,15,2,2,2,12,0},//t
  {0,0,0,9,9,9,6,0},//u
  {0,0,0,5,5,5,2,0},//v
  {0,0,0,17,17,21,10,0},//w
  {0,0,0,9,6,6,9,0},//x
  {0,0,0,9,9,14,8,6},//y
  {0,0,0,15,4,2,15,0},//z
  {4,2,2,1,2,2,4,0},//{
  {1,1,1,1,1,1,1,0},//|
  {1,2,2,4,2,2,1,0},//}
  {0,0,0,12,3,0,0,0},//~
};




int dataPin = 9;
int clockPin = 10;
int latchPin = 8;
int numberOfDisplays = 2;
byte yShift[8];
byte xShift[2][8];


void setup() {

cli(); //TO TURN OFF INTERRUPTS

TCCR1A = 0; //SET REGISTER TO 0
TCCR1B = 0; // SET REGISTER TO 0
TCNT1 = 0; //INITIALIZE COUNTER TO 0 VALUE

OCR1A = 259; //SET THE COMPARE MATCH REGISTER TO 259 VALUE

TCCR1B |= (1 << WGM12); //TURN ON CTC MODE

TCCR1B |= (1 << CS12) | (1 << CS10); // MAKE THE 1024 BIT PRESCALER

TIMSK1 |= (1 << OCIE1A); //ENABLE THE COMPARE INTERRUPT


sei(); //TURN ON INTERRUPTS
// x = new byte[8];
// y = new byte[8];

 pinMode(dataPin, OUTPUT);
 pinMode(clockPin, OUTPUT);
 pinMode(latchPin, OUTPUT);
for(int i = 0; i < numberOfDisplays; i++)
{
 for(int j = 0; j < 8; j++)
 {
    bitWrite(yShift[j], i, 1);
    xShift[j][i] = 255;
 }
}
 // thread(displayToMatrix);

}

void loop() {


//writePixel(7,7);
//writePixel(6,6);
//writePixel(5,5);
//writePixel(4,4);
//writePixel(3,3);
//writePixel(2,2);
//writePixel(1,1);
//writePixel(0,0);
//writePixel(0,7);
//writePixel(1,6);
//writePixel(2,5);
//writePixel(3,4);
//writePixel(4,3);
//writePixel(5,2);
//writePixel(6,1);
//writePixel(7,0);


for(int i = 0; i < 8; i++)
{
  for(int j = 0; j < 8; j++)
  {

    writePixel(i, j);

    //displayToMatrix();

    delay(500);

    erasePixel(i, j);
    
  }
}


  
  
 

}





void writePixel(int xDraw, int yDraw)
{
  if(xDraw < 8)
  {
    bitWrite(xShift[0][yDraw], xDraw, 0);
  }else if(xDraw > 7)
  {
    bitWrite(xShift[0][yDraw], xDraw-8, 0);
  }
    
}
void erasePixel(int xErase, int yErase)
{
  if(xErase < 8)
  {
    bitWrite(xShift[0][yErase], xErase, 0);
  }else if(xErase > 7)
  {
    bitWrite(xShift[0][yErase], xErase-8, 0);
  }

}


ISR(TIMER1_COMPA_vect)
{
   for(int i = 0; i < 8; i++)
  {
  
    digitalWrite(latchPin, LOW);

      for(int j = 0; j < numberOfDisplays; j++)
      {
       shiftOut(dataPin, clockPin, LSBFIRST, xShift[j][i]);
      }
      shiftOut(dataPin, clockPin, LSBFIRST, yShift[i]);

    digitalWrite(latchPin, HIGH);

  //  delay(500);
      
    
  }
}

void scrollText(String stringToPrint)
{

  byte xBuffer[numberOfDisplays][8];
  

 for(int i = 0; i < stringToPrint.length() + numberOfDisplays; i++)
 {
  for(int l = 8; l > -1; l--)
  {
    for(int j = numberOfDisplays - 1; j > -1; j--)
    {
      if(i - j < stringToPrint.length() && i - j > -1)
      {
        for(int h = 0; h < 8; h++)
        {
           xShift[j][h] = ~((charToPrint[stringToPrint.charAt(i-j)-32][7-h]>>l) | (xBuffer[j][h]<<8-l));

           xBuffer[j][h] = ~xShift[j][h];
        }
      }
    }
  }
 }
}


