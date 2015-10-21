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
01111101,
01111101,
01111101,
00000001,
01111101,
01111101,
01111101,
01111101
};

const byte I[8] =
{
00000001,
11101111,
11101111,
11101111,
11101111,
11101111,
11101111,
00000001
};

const byte J[8] =
{
11000001,
11110111,
11110111,
11110111,
11110111,
11110111,
01110111,
10001111
};

const byte K[8] =
{
01111101,
01110011,
01001111,
00111111,
01011111,
01101111,
01110011,
01111101
};

const byte L[8] =
{
01111111,
01111111,
01111111,
01111111,
01111111,
01111111,
01111111,
00000001
};

const byte M[8] =
{
01111101,
00111001,
01010101,
01101101,
01111101,
01111101,
01111101,
01111101
};

const byte N[8] =
{
01111101,
00111101,
01011101,
01101101,
01110101,
01111001,
01111101,
01111101
};

const byte O[8] =
{
10000011,
01111101,
01111101,
01111101,
01111101,
01111101,
01111101,
10000011
};

const byte P[8] =
{
00000011,
01111101,
01111101,
01111101,
00000011,
01111111,
01111111,
01111111
};

const byte Q[8] =
{
10000011,
01111101,
01111101,
01111101,
01111101,
01111001,
01111101,
10000010
};

const byte R[8] =
{
00000011,
01111101,
01111101,
00000011,
01111011,
01111101,
01111101,
01111101
};

const byte S[8] =
{
10000001,
01111111,
01111111,
10000011,
11111101,
11111101,
11111101,
00000011
};
const byte T[8] =
{
00000001,
11101111,
11101111,
11101111,
11101111,
11101111,
11101111,
11101111
};

const byte U[8] =
{
01111101,
01111101,
01111101,
01111101,
01111101,
01111101,
01111101,
10000011
};

const byte V[8] =
{
01111101,
01111101,
01111101,
01111101,
01111101,
10111011,
11010111,
11101111
};

const byte W[8] =
{
01111101,
01111101,
01111101,
01111101,
01101101,
01010101,
00111001,
01111101
};
const byte X[8] =
{
01111101,
10111011,
11010111,
11101111,
11010111,
10111011,
01111101,
01111101
};
const byte Y[8] =
{
01111101,
01111101,
10111011,
11101111,
11101111,
11101111,
11101111,
11101111
};

const byte Z[8] =
{
00000001,
11111011,
11110111,
11101111,
11011111,
10111111,
01111111,
00000001
};


int dataPin = 9;
int clockPin = 10;
int latchPin = 8;
int numberOfDisplays = 2;
byte y[8];
byte x[2][8];


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
    bitWrite(y[j], i, 1);
    x[j][i] = 255;
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
    bitWrite(x[0][yDraw], xDraw, 0);
  }else if(xDraw > 7)
  {
    bitWrite(x[0][yDraw], xDraw-8, 0);
  }
    
}
void erasePixel(int xErase, int yErase)
{
  if(xErase < 8)
  {
    bitWrite(x[0][yErase], xErase, 0);
  }else if(xErase > 7)
  {
    bitWrite(x[0][yErase], xErase-8, 0);
  }

}


ISR(TIMER1_COMPA_vect)
{
   for(int i = 0; i < 8; i++)
  {
  
    digitalWrite(latchPin, LOW);

      for(int j = 0; j < numberOfDisplays; j++)
      {
       shiftOut(dataPin, clockPin, LSBFIRST, x[j][i]);
      }
      shiftOut(dataPin, clockPin, LSBFIRST, y[i]);

    digitalWrite(latchPin, HIGH);

  //  delay(500);
      
    
  }
}

void scrollText()
{
  for(int i = 0; i < numberOfDisplays; i++)
  {
    for(int j = 7; j > -1; j--)
    {
     
      for(int l = 0; l < 8; l++)
      {
        if(i > 0)
        {
          x[i-1][l] = A[l]<<8-j;
        }
        x[i][l] = A[l]>>j;
        
      }
      
    }
   
  }
}


