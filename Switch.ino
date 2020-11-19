#include <Wire.h>
#include <LiquidCrystal_I2C.h>

const int ok=12;
const int cancel=11;
const int left=13;
const int right=10;
bool flag=0,flag2=0,flag3=0,flag4=0,st=0;

int g=0,m=0,z=0,language=0,razmetka=2;               //WHY WE DONT DO IT LIKE KARIMAS VOID(CREATE IN FUNCTION)

const int in1=2;
const int in2=3;
const int in3=4;
const int in4=5;


// Set the LCD address to 0x27 for a 16 chars and 2 line display
LiquidCrystal_I2C lcd(0x27, 20, 4);


void switchi(){ 
  bool but_state1 =digitalRead(ok);
  if(but_state1&&!flag)
  flag =!flag;
  if(!but_state1&&flag)
  {
    z++;
    flag=!flag;
  }
  //cancel
    bool but_state2 =digitalRead(cancel);
  if(but_state2&&!flag2)
  flag2 =!flag2;
  if(!but_state2&&flag2)
  {
    z=0;
    flag2=!flag2;
  }
  if(z!=0)
  {
    bool but_state3 =digitalRead(right);
  if(but_state3&&!flag3)
  flag3=!flag3;
  if(!but_state3&&flag3)
  {
    if(z==1)
    language++;
    if(z==2)
    razmetka++;
    flag3=!flag3;
  }
    bool but_state4 =digitalRead(left);
  if(but_state4&&!flag4)
  flag4 =!flag4;
  if(!but_state4&&flag4)
  {
    if(z==1)
    language--;
    if(z==2)
    razmetka--;
    flag4=!flag4;
  }
 if(language<0)language=1;
 if(language>1)language=0;
  if(razmetka<2)razmetka=5;
 if(razmetka>5)razmetka=2;
}
if(z<0)z=0;
if(z>2)z=0;
}

String lang[2][6]=
{
  {" qazaq "," BELGISIN TANDANIZ:","TUTAS SIZIQ","TUZIK SIZIQ","VELOSIPEDSHY"," BEYNE"},
  {"english","  CHOOSE MARKING: "," SOLID LINE"," SKIP LINE ","CYCLIST SIGN","PICTURE"}
};


//choosing language
void langch()
{ 
  
  lcd.setCursor(2, 0);
  lcd.print("CHOOSE LANGUAGE:");
  lcd.setCursor(6, 2);
  lcd.print("<");
  lcd.setCursor(14, 2);
  lcd.print(">");
   
   lcd.setCursor(7, 2);lcd.print(lang[language][0]);

 lcd.clear();
  

 
  }        


//choosing marking
int markch()
{ lcd.clear();

  lcd.setCursor(1, 0);lcd.print(lang[language][1]);
  lcd.setCursor(2, 2);lcd.print("<");     
  lcd.setCursor(18, 2);lcd.print(">");
              
  Serial.print(razmetka);   
            
  lcd.setCursor(5, 2);lcd.print(lang[language][razmetka]);
  
  return razmetka;
  }

      
  

                         //number of marking
  void disp()                        //main screen       
{ lcd.clear();

  lcd.setCursor(7, 1);
  lcd.print("1-GOGH");
  lcd.setCursor(3, 2);
  lcd.print("Infomatrix-2019");

  }

  
void setup()
{
  lcd.begin();
  lcd.backlight();
 disp();
 digitalWrite(in1, LOW); digitalWrite(in2, LOW);digitalWrite(in3, LOW); digitalWrite(in4, LOW);

  lcd.home();
  Serial.begin(9600);
  
}


void loop()
  {   
  switchi();
  
  if(z==0)
  disp();
  if(z==1)
  {
    langch();
  }
  if(z==2)
  {markch();/*if(markch()==2||markch()==3){digitalWrite(in1, HIGH); digitalWrite(in4, HIGH);}}  
  if(z==0){digitalWrite(in1, LOW); digitalWrite(in4, LOW);*/}
  
 
  
  }
 
  
