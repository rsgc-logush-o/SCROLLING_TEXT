//INTERRUPT TIMER USE
//COMPARE MATCH REGISTER IS 259
//PRESCALER IS 1024
//FREQUENCY IS 6HZ
//ARDUINO CLOCK SPEED IS 16,000,000 HZ OR 16 MHZ
//I WILL HAVE TO USE TIMER1
//

const byte A[8] =
{
-B10000011,
-B01111101,
-B01111101,
-B01111101,
-B00000001,
-B01111101,
-B01111101,
-B01111101
};

const byte B[8] =
{
  -B00000011,
  -B01111101,
  -B01111101,
  -B00000011,
  -B01111101,
  -B01111101,
  -B01111101,
  -B00000011
};

const byte C[8] =
{
-B10000011,
-B01111101,
-B01111111,
-B01111111,
-B01111111,
-B01111111,
-B01111101,
-B10000011
};

const byte D[8] =
{
-B00000011,
-B01111101,
-B01111101,
-B01111101,
-B01111101,
-B01111101,
-B01111101,
-B00000011

};

const byte E[8] =
{
-B00000001,
-B01111111,
-B01111111,
-B00000011,
-B01111111,
-B01111111,
-B01111111,
-B00000001
};

const byte F[8] =
{
-B00000001,
-B01111111,
-B01111111,
-B00000011,
-B01111111,
-B01111111,
-B01111111,
-B01111111
};

const byte G[8] =
{
-B10000011,
-B01111101,
-B01111111,
-B01111111,
-B01111111,
-B01110001,
-B01111101,
-B10000011
};

const byte H[8] =
{
-B01111101,
-B01111101,
-B01111101,
-B00000001,
-B01111101,
-B01111101,
-B01111101,
-B01111101
};

const byte I[8] =
{
-B00000001,
-B11101111,
-B11101111,
-B11101111,
-B11101111,
-B11101111,
-B11101111,
-B00000001
};

const byte J[8] =
{
-B11000001,
-B11110111,
-B11110111,
-B11110111,
-B11110111,
-B11110111,
-B01110111,
-B10001111
};

const byte K[8] =
{
-B01111101,
-B01110011,
-B01001111,
-B00111111,
-B01011111,
-B01101111,
-B01110011,
-B01111101
};

const byte L[8] =
{
-B01111111,
-B01111111,
-B01111111,
-B01111111,
-B01111111,
-B01111111,
-B01111111,
-B00000001
};

const byte M[8] =
{
-B01111101,
-B00111001,
-B01010101,
-B01101101,
-B01111101,
-B01111101,
-B01111101,
-B01111101
};

const byte N[8] =
{
-B01111101,
-B00111101,
-B01011101,
-B01101101,
-B01110101,
-B01111001,
-B01111101,
-B01111101
};

const byte O[8] =
{
-B10000011,
-B01111101,
-B01111101,
-B01111101,
-B01111101,
-B01111101,
-B01111101,
-B10000011
};

const byte P[8] =
{
-B00000011,
-B01111101,
-B01111101,
-B01111101,
-B00000011,
-B01111111,
-B01111111,
-B01111111
};

const byte Q[8] =
{
-B10000011,
-B01111101,
-B01111101,
-B01111101,
-B01111101,
-B01111001,
-B01111101,
-B10000010
};

const byte R[8] =
{
-B00000011,
-B01111101,
-B01111101,
-B00000011,
-B01111011,
-B01111101,
-B01111101,
-B01111101
};

const byte S[8] =
{
-B10000001,
-B01111111,
-B01111111,
-B10000011,
-B11111101,
-B11111101,
-B11111101,
-B00000011
};
const byte T[8] =
{
-B00000001,
-B11101111,
-B11101111,
-B11101111,
-B11101111,
-B11101111,
-B11101111,
-B11101111
};

const byte U[8] =
{
-B01111101,
-B01111101,
-B01111101,
-B01111101,
-B01111101,
-B01111101,
-B01111101,
-B10000011
};

const byte V[8] =
{
-B01111101,
-B01111101,
-B01111101,
-B01111101,
-B01111101,
-B10111011,
-B11010111,
-B11101111
};

const byte W[8] =
{
-B01111101,
-B01111101,
-B01111101,
-B01111101,
-B01101101,
-B01010101,
-B00111001,
-B01111101
};
const byte X[8] =
{
-B01111101,
-B10111011,
-B11010111,
-B11101111,
-B11010111,
-B10111011,
-B01111101,
-B01111101
};
const byte Y[8] =
{
-B01111101,
-B01111101,
-B10111011,
-B11101111,
-B11101111,
-B11101111,
-B11101111,
-B11101111
};

const byte Z[8] =
{
-B00000001,
-B11111011,
-B11110111,
-B11101111,
-B11011111,
-B10111111,
-B01111111,
-B00000001
};

const byte space[8] = 
{
-B11111111,
-B11111111,
-B11111111,
-B11111111,
-B11111111,
-B11111111,
-B11111111,
-B11111111
};

const byte a[8] =
{
-B11111111,
-B11111111,
-B10000111,
-B11111011,
-B10000011,
-B01111011,
-B01111011,
-B10000011
};

const byte b[8] =
{
-B01111111,
-B01111111,
-B01111111,
-B01111111,
-B00000111,
-B01111011,
-B01111011,
-B00000111
};

const byte c[8] =
{
-B11111111,
-B11111111,
-B10000111,
-B01111011,
-B01111111,
-B01111111,
-B01111011,
-B10000111
};

const byte d[8] =
{
-B11111011,
-B11111011,
-B11111011,
-B11111011,
-B10000011,
-B01111011,
-B01111011,
-B10000011
};

const byte e[8] =
{
-B11111111,
-B11111111,
-B10000111,
-B01111011,
-B00000011,
-B01111111,
-B01111011,
-B10000111
};

const byte f[8] =
{
-B11000111,
-B10111011,
-B10111111,
-B00001111,
-B10111111,
-B10111111,
-B10111111,
-B10111111
};

const byte g[8] =
{
-B10000111,
-B01110111,
-B01110111,
-B01110111,
-B10000111,
-B11110111,
-B01110111,
-B10001111
};

const byte h[8] = 
{
-B01111111,
-B01111111,
-B01111111,
-B01000111,
-B00111011,
-B01111011,
-B01111011,
-B01111011
};

const byte i[8] = 
{
-B11101111,
-B11111111,
-B11001111,
-B11101111,
-B11101111,
-B11101111,
-B11101111,
-B11100111
};

const byte j[8] = 
{
-B11111011,
-B11111111,
-B11110011,
-B11111011,
-B11111011,
-B11111011,
-B01111011,
-B10000111
};

const byte k[8] = 
{
-B01111111,
-B01110111,
-B01101111,
-B01011111,
-B00111111,
-B01011111,
-B01101111,
-B01110111
};

//char ASCII[256]
//{
//
//}




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
  

 for(int i = 0; i < stringToPrint.length() + numberOfDisplays)
 {
  for(int l = 8; l > -1; l--)
  {
    for(int j = numberOfDisplays - 1; j > -1; j--)
    {
      if(i - j < stringToPrint.length() && i - j > -1)
      {
        for(int h = 0; h < 8; h++)
        {
           xShift[j][h] = ~((charToPrint[stringToPrint.charAt(i-j)-65][7-h]>>l) | (xBuffer[j][h]<<8-l));

           xBuffer[j][h] = ~xShift[j][h];
        }
      }
    }
  }
 }
}


