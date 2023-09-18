//#include<IO_Port_32bit.h>
#include<LiquidCrystal.h>
#include<Keypad.h>

//IO_Port_8bitmyport(2, 3, 4, 5, 6, 7, 8, 9, ’O’);
int leds[] = {22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37}; 
const byte rows =4;
const byte cols =3;
char keys[rows][cols]={
  {'1','2','3'},
  {'4','5','6'},
  {'7','8','9'},
  {'*','0',' '},
};

byte rowpins[rows]={7,6,5,4};
byte colpins[cols]={3,2,1};
LiquidCrystal lcd(13,12,11,10,9,8);
Keypad keypad=Keypad(makeKeymap(keys),rowpins,colpins,rows,cols);
char key=keypad.getKey();

void setup() {
  // put your setup code here, to run once:
 lcd.begin(16,2);

  for (int i=0; i<16; i++)
  {
    pinMode(leds[i], OUTPUT);
  }
 

}

void loop() {
  // put your main code here, to run repeatedly:
  
  start:
  char volver=0;
  char num=0,ch=0,num1=0;
  char n[16]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
  int i=0,no=0;
  int x=0,len=0,b[16]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
  //int o[8];
  lcd.print("decimal:");
  lcd.setCursor(8,0);
 
  for(i=0;num!=' ';i++)
  {
    num=keypad.waitForKey();
    n[i]=num;
    lcd.print(num);
  }
  no=atof(n);
  lcd.clear();
  lcd.setCursor(0,0);
  //lcd.print("1)binary:");
  
  //ch=keypad.waitForKey();
  
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("decimal");
  lcd.setCursor(8,0);
  lcd.print(no);
  lcd.setCursor(0,1);
//  switch(ch)
//  {
//    case '1':
    lcd.print("binary");
    lcd.setCursor(7,1);
    if(no==0)
    {
     lcd.print("0");
    }
    while(no>0)
    {
    b[len]=no%2;
    no=no/2;
    len++;
    }
   for(x=len-1;x>-1;x--)
   {
   lcd.print(b[x]);
   digitalWrite(leds[x], b[x]);
   }
//   break;
//
//   
//  }

 volver=keypad.waitForKey(); 
 if(volver=='*')
 {
  lcd.clear();
  lcd.setCursor(0,0);
   for(x=len-1;x>-1;x--)
   {
   //lcd.print(b[x]);
   digitalWrite(leds[x],LOW);
   }
  goto start;
 }
  
}
