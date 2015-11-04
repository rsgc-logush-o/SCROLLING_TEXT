//INTERRUPT TIMER USE
//COMPARE MATCH REGISTER IS 259
//PRESCALER IS 1024
//FREQUENCY IS 60HZ
//ARDUINO CLOCK SPEED IS 16,000,000 HZ OR 16 MHZ
//I WILL HAVE TO USE TIMER1
//


byte charToPrint[95][5]
{
  {0, 0, 0, 0, 0}, //SPACE
  {95, 0, 0, 0, 0}, //!
  {7, 7, 0, 0, 0}, //"
  {20, 62, 20, 62, 20}, //#
  {36, 42, 107, 42, 18}, //$
  {76, 44, 16, 104, 100}, //%
  {52, 74, 84, 32, 80}, //&
  {7, 0, 0, 0, 0}, //'
  {62, 65, 0, 0, 0}, //(
  {65, 62, 0, 0, 0}, //)
  {21, 14, 14, 21, 0}, //*
  {8, 8, 62, 8, 8}, //+
  {128, 96, 0, 0, 0}, //,
  {8, 8, 8, 8, 8}, //-
  {64, 0, 0, 0, 0}, //.
  {32, 16, 8, 4, 2}, ///
  {62, 81, 73, 69, 62}, //0
  {68, 66, 127, 64, 64}, //1
  {66, 97, 81, 73, 70}, //2
  {65, 73, 73, 73, 54}, //3
  {8, 12, 10, 127, 8}, //4
  {71, 69, 69, 69, 57}, //5
  {62, 73, 73, 73, 48}, //6
  {97, 17, 9, 5, 3}, //7
  {54, 73, 73, 73, 54}, //8
  {6, 73, 73, 73, 62}, //9
  {34, 0, 0, 0, 0}, //:
  {64, 34, 0, 0, 0}, //;
  {8, 20, 34, 0, 0}, //<
  {20, 20, 20, 20, 20}, //=
  {34, 20, 8, 0, 0}, //>
  {2, 1, 81, 9, 6}, //?
  {62, 73, 85, 93, 94}, //@
  {126, 9, 9, 9, 126}, //A
  {127, 73, 73, 73, 54}, //B
  {62, 65, 65, 65, 34}, //C
  {127, 65, 65, 65, 62}, //D
  {127, 73, 73, 73, 73}, //E
  {127, 9, 9, 9, 9}, //F
  {62, 65, 65, 81, 50}, //G
  {127, 8, 8, 8, 127}, //H
  {65, 65, 127, 65, 65}, //I
  {33, 65, 65, 63, 1}, //J
  {127, 8, 20, 34, 65}, //K
  {127, 64, 64, 64, 64}, //L
  {127, 2, 4, 2, 127}, //M
  {127, 2, 4, 8, 127}, //N
  {62, 65, 65, 65, 62}, //O
  {127, 9, 9, 9, 6}, //P
  {62, 65, 81, 62, 64}, //Q
  {127, 9, 9, 25, 102}, //R
  {38, 73, 73, 73, 50}, //S
  {1, 1, 127, 1, 1}, //T
  {63, 64, 64, 64, 63}, //U
  {31, 32, 64, 32, 31}, //V
  {127, 32, 16, 32, 127}, //W
  {99, 20, 8, 20, 99}, //X
  {3, 4, 120, 4, 3}, //Y
  {97, 81, 73, 69, 67}, //Z
  {127, 65, 0, 0, 0}, //[
  {2, 4, 8, 16, 32}, //\
  {65, 127, 0, 0, 0}, //]
  {4, 2, 1, 2, 4}, //^
  {64, 64, 64, 64, 64}, //_
  {1, 2, 0, 0, 0}, //`
  {32, 84, 84, 84, 120}, //a
  {127, 72, 72, 72, 48}, //b
  {56, 68, 68, 68, 68}, //c
  {48, 72, 72, 72, 127}, //d
  {56, 84, 84, 84, 24}, //e
  {68, 126, 69, 1, 2}, //f
  {24, 164, 164, 164, 124}, //g
  {127, 8, 8, 8, 112}, //h
  {64, 68, 125, 64, 64}, //i
  {64, 128, 132, 125, 4}, //j
  {127, 8, 20, 34, 64}, //k
  {64, 65, 127, 64, 64}, //l
  {120, 8, 48, 8, 112}, //m
  {120, 8, 8, 8, 112}, //n
  {56, 68, 68, 68, 56}, //o
  {252, 20, 20, 20, 8}, //p
  {8, 20, 20, 20, 252}, //q
  {120, 8, 8, 8, 16}, //r
  {72, 84, 84, 84, 36}, //s
  {8, 8, 126, 72, 8}, //t
  {56, 64, 64, 64, 56}, //u
  {24, 32, 64, 32, 24}, //v
  {56, 64, 32, 64, 56}, //w
  {68, 40, 16, 40, 68}, //x
  {156, 160, 64, 32, 28}, //y
  {68, 100, 84, 76, 68}, //z
  {8, 54, 65, 0, 0}, //{
  {127, 0, 0, 0, 0}, //|
  {65, 54, 8, 0, 0}, //}
  {8, 8, 16, 16, 0} //~
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
  
  pinMode(dataPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(latchPin, OUTPUT);
 
    for (int j = 0; j < 8; j++)
    {
      yShift[j] = 255;
      bitWrite(yShift[j], j, 0);

    }
}

void loop() 
{
scrollText("HELLO WORLD!  ", 50);
}








ISR(TIMER1_COMPA_vect)
{
  for (int i = 0; i < 8; i++)
  {

    digitalWrite(latchPin, LOW);



    for(int j = numberOfDisplays-1; j > -1; j--)
    {
    shiftOut(dataPin, clockPin, MSBFIRST, ~(xShift[j][i]));
    }
    shiftOut(dataPin, clockPin, MSBFIRST, ~(yShift[i]));


    digitalWrite(latchPin, HIGH);

    


  }
}

void scrollText(String stringToPrint, int scrollSpeed)
{

//  byte stringBitmap[stringToPrint.length() * 6];
//  for (int i = 0; i < stringToPrint.length(); i++)
//  {
//    for (int j = 0; j < 6; j++)
//    {
//      if (j == 5)
//      {
//        stringBitmap[i * 6 + j] = 0;
//      } else
//      {
//        stringBitmap[i * 6 + j] = charToPrint[stringToPrint.charAt(i) - 32][j];
//      }
//    }
//  }


  for (int i = 0; i < stringToPrint.length(); i++)//this is to select each character in the string from the bitmap
  {
    for(int l = 0; l < 6; l++)//this is to get the column of each character
    {
      for(int h = numberOfDisplays-1; h > -1; h--)
      {
        for (int k = 7; k > -1; k--)//this is to write the column of each character k is what column
        {
          if (k == 0 && h == 0)
          {
            for (int j = 0; j < 8; j++)
            {        
              bitWrite(xShift[h][j], k, bitRead(charToPrint[stringToPrint.charAt(i) - 32][l], j));         
            }
          }else if(k == 0 && h != 0)
          {
            for (int j = 0; j < 8; j++)
            {
              bitWrite(xShift[h][j], k, bitRead(xShift[h-1][j], 7));
            } 
           }else
           {
              for (int j = 0; j < 8; j++)
              {
                bitWrite(xShift[h][j], k, bitRead(xShift[h][j], k-1));
              }
              
           }
           
        }
      }
      delay(scrollSpeed);
    }
      
  }
    
}
  

