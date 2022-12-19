#include <LiquidCrystal_I2C.h>
#include <EEPROM.h>
#include <Wire.h>
#include <HX711_ADC.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 20, 4);
HX711_ADC LoadCell(3, 4);
int a = 100;
int b = 200;
int c = 300;
int N = 0;
int s = 0;
int manhinh=1;
int tkl1=0;
int tkl2=0;
int tkl3=0;
int sl1=0;
int sl2=0;
int sl3=0;
const int den1 = 5;
const int den2 = 6;
const int den3 = 13;
const int NUT1 = 7;                                                                                                                                                                                                                  
const int NUT2 = 8;
const int NUT3 = 9;
const int NEXT = 10;
const int BACK =11;
const int LAY=12;
long t;
void setup()
{
  pinMode(den1, OUTPUT);
  pinMode(den2, OUTPUT);
  pinMode(den3, OUTPUT);
  pinMode(NUT1, INPUT_PULLUP );
  pinMode(NUT2, INPUT_PULLUP);
  pinMode(NUT3, INPUT_PULLUP);
   pinMode(NEXT, INPUT_PULLUP);
  pinMode(BACK, INPUT_PULLUP);

  pinMode(LAY, INPUT_PULLUP);

  LoadCell.begin();
  LoadCell.tare(); // reset loadcell về 0
  LoadCell.start(2000);
  LoadCell.setCalFactor(1916.32); // chỉnh tỉ lệ để có kq đo chính xác
  lcd.init();
  lcd.backlight();

  lcd.print("TRUONG DH NL TP HCM");
  lcd.setCursor(0 , 1);
  lcd.print("SV:NGUYEN MINH TAN");
  lcd.setCursor(0 , 2);
  lcd.print("MSSV: 18118125");
  lcd.setCursor(0 , 3);
  lcd.print("LOP: DH18TD");
  delay(3000);
  lcd.clear();
  lcd.print("CAM BIEN TRONG DKTD");
  lcd.setCursor(7 , 1);
  lcd.print("DO AN");
  lcd.setCursor(2 , 2);
  lcd.print("LAM CAN DIEN TU");
  lcd.setCursor(3 ,3);
  lcd.print("BANG LOADCELL  ");
  delay(3000);
  lcd.clear();
}
void loop()
{
  nutnhan();
  {
    LoadCell.update();
    if(manhinh==1)
    {
    if (millis() > t + 25)
    {
      float i = LoadCell.getData(); 
      float ii = i ;
      lcd.setCursor(0, 0);
      lcd.print("KHOI LUONG:");
      lcd.setCursor(19, 0);
      lcd.print("g");
      t = millis();
      lcd.setCursor(0, 1);
      lcd.print("Loai 1:");
      lcd.setCursor(8, 1);
      lcd.print(a);
      lcd.setCursor(12, 1);
      lcd.print("g");
      lcd.setCursor(0, 2);
      lcd.print("Loai 2:");
      lcd.setCursor(8, 2);
      lcd.print(b);
      lcd.setCursor(12, 2);
      lcd.print("g");
      lcd.setCursor(0, 3);
      lcd.print("Loai 3:");
      lcd.setCursor(8, 3);
      lcd.print(c);
      lcd.setCursor(12, 3);
      lcd.print("g");

     if(ii<a && 0<ii)
      {
        lcd.setCursor(14, 1);
        lcd.print("   ");
        lcd.setCursor(14, 2);
        lcd.print("   ");
        lcd.setCursor(14, 3);
        lcd.print("   ");
        digitalWrite(den1, HIGH);
        digitalWrite(den2, LOW);
        digitalWrite(den3, LOW);
         lcd.setCursor(14, 1);
        lcd.print("ON1 ");
        lcd.setCursor(14, 2);
        lcd.print("   ");
        lcd.setCursor(14, 3);
        lcd.print("   ");
    if((digitalRead(LAY) == LOW))
    {
        tkl1= tkl1+ii;
        sl1=sl1+1;
      }}
      if (ii >= a && ii<b)
      {
        
        
        digitalWrite(den1, LOW);
        digitalWrite(den2, HIGH);
        digitalWrite(den3, LOW);
        lcd.setCursor(14, 2);
        lcd.print("ON2 ");
        lcd.setCursor(14, 1);
        lcd.print("OFF1");
        lcd.setCursor(14, 3);
        lcd.print("   ");
if((digitalRead(LAY) == LOW))
{
        tkl2= tkl2+ii;
        sl2=sl2+1;
      }}
      if (ii >= b &&ii<c)
      {
        digitalWrite(den2, LOW);
        digitalWrite(den1, LOW);
        digitalWrite(den3, HIGH);
        lcd.setCursor(14, 3);
        lcd.print("ON3 ");
        lcd.setCursor(14, 1);
        lcd.print("OFF1");
        lcd.setCursor(14, 2);
        lcd.print("OFF2");
if((digitalRead(LAY) == LOW))
{
        tkl3= tkl3+ii;
        sl3= sl3+1;
      }}
      if (ii >= c)
      { 
        digitalWrite(den3, HIGH);
        digitalWrite(den1, HIGH);
        digitalWrite(den2, HIGH);
        lcd.setCursor(14, 3);
        lcd.print("ON3 ");
        lcd.setCursor(14, 1);
        lcd.print("ON1");
        lcd.setCursor(14, 2);
        lcd.print("ON2");
      }
      if ( ii > i);
      {

        lcd.setCursor(12, 0);
        lcd.print(ii, 1);
      }
      if ((ii == 0) || (ii < 1) || (ii < 0))
      {
        lcd.setCursor(12, 0);
        lcd.print("00000");                                                                                                                                                                                                                                                   \
      }}
    }

  }
}

void nutnhan()
{
  if (digitalRead(NUT1) == HIGH)
  {
    delay(100);
    s++;
  }
  if (s == 1)
  {
    lcd.setCursor(18, 1);
    lcd.print("<=");
    lcd.setCursor(18, 2);
    lcd.print("  ");
    lcd.setCursor(18, 3);
    lcd.print("  ");
    if (digitalRead(NUT2) == HIGH)
    {
      delay(100);
      a++;

    }
    if (digitalRead(NUT3) == HIGH)
    {
      delay(100);
      a--;

    }

  }
  if (s == 2)
  {
 
    lcd.setCursor(18, 2);
    lcd.print("<=");
   lcd.setCursor(18, 1);
    lcd.print("  ");
    lcd.setCursor(18, 3);
    lcd.print("  ");
    if (digitalRead(NUT2) == HIGH)
    {
      delay(100);
      b++;

    }
    if (digitalRead(NUT3) == HIGH)
    {
      delay(0);
      b--;

    }

  }
  if (s == 3)
  {
  
    lcd.setCursor(18, 3);
    lcd.print("<=");
    lcd.setCursor(18, 2);
    lcd.print("  ");
    lcd.setCursor(18, 1);
    lcd.print("  ");

    if (digitalRead(NUT2) == HIGH)
    {
      delay(0);
      c++;

    }
    if (digitalRead(NUT3) == HIGH)
    {
      delay(0);
      c--;

    }
  }
  if (s >= 4)
  {
    lcd.setCursor(18, 1);
    lcd.print("  ");
    lcd.setCursor(18, 2);
    lcd.print("  ");
    lcd.setCursor(18, 3);
    lcd.print("  ");
    s = 0;
  }
   if (digitalRead(NEXT) == LOW)
      {
        delay(0);
        manhinh = 2; lcd.clear();
      }
    //CODE MAN 2
  
  if (manhinh == 2)
  { 
   lcd.setCursor(0,0);
   lcd.print("TONG KHOI LUONG|");
   lcd.setCursor(0,1);
   lcd.print("TKL1:");
   lcd.setCursor(6,1);
   lcd.print(tkl1);
   lcd.setCursor(0,2);
   lcd.print("TKL2:");
   lcd.setCursor(6,2);
   lcd.print(tkl2);
   lcd.setCursor(0,3);
   lcd.print("TKL3:");
   lcd.setCursor(6,3);
   lcd.print(tkl3);
   lcd.setCursor(13,1);
   lcd.print("SL:"); 
   lcd.setCursor(16,1);
   lcd.print(sl1);
   
   lcd.setCursor(13,2);
   lcd.print("SL:"); 
   lcd.setCursor(16,2);
   lcd.print(sl2);
   
   lcd.setCursor(13,3);
   lcd.print("SL:"); 
   lcd.setCursor(16,3);
   lcd.print(sl3);
   
  }
  if (digitalRead(BACK) == LOW)
    {
      delay(0);
      manhinh = 1; lcd.clear();
    }
}


 
