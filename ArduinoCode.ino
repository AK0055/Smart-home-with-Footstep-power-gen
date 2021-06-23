// Import the Liquid Crystal to display in LCD
#include <LiquidCrystal.h>
//Initialise the LCD pins with the arduino. 
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
//Signal 1
int led1=10;//RED
int led2=9;//YELLOW
int led3=8;//GREEN
//Signal 2
int led4=13;//RED
int led5=7;//YELLOW
int led6=0;//GREEN
int FlamePin=A3;
char c;
 //define LED connecting pins into lcd fn using Liquid crystal
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
int count=0; //No. of Steps
int voltage=0;//Total voltage from each sensor at current loop
int total=0;//Total voltage from all sensors till current loop
int tempr=A5;
int Gas=1;
String voice; 

void setup() {
  Serial.begin(9600);
  // Setup the pin modes for each LED, Buzzer and LCD display as OUTPUT 
  pinMode(6,OUTPUT) ; 
  pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);
  pinMode(led3,OUTPUT);
  pinMode(led4,OUTPUT);
  pinMode(led5,OUTPUT);
  pinMode(led6,OUTPUT);
  pinMode(Gas,INPUT_PULLUP);
  pinMode(FlamePin, INPUT_PULLUP);
  Serial.begin(9600);

}
void loop() {
  //delay(5000);
  if (Serial.available()){
    c = Serial.read();
    //Serial.println(c);
    voice+=c;  
   if (voice.length() > 0)
  {
    //Serial.println(voice); 
       if(voice=='o')
       {
         digitalWrite(13, HIGH);
        }  
  if(voice == 'f')
  {
   digitalWrite(13, LOW);
    } 
voice="";
}}

int gasin=digitalRead(Gas);
  //Read analogue voltage from each sensor
  int a=analogRead(A0);
  int b=analogRead(A1);
  int c=analogRead(A2);
  int Temp = analogRead(tempr);
  Temp = Temp * 0.48828125;
  lcd.begin(16, 2);
   lcd.setCursor(5,0);
   lcd.print(Temp);lcd.print("C");
     lcd.setCursor(5,1);
     if(gasin == HIGH){
    lcd.print("Gas!");
  }
else{
  lcd.print("No gas");
 
}
delay(500);
lcd.clear();
digitalWrite(13, HIGH);
int Flame = digitalRead(FlamePin);

if(Flame==HIGH)
{
  lcd.setCursor(5, 0);
  lcd.print("FLAME");
   lcd.setCursor(3, 1);
  lcd.print("DETECTED");
  delay(1000);
  lcd.clear();
  delay(200);
  
}
 float v1 = a* (5.0 / 1023.0);
  float v2 = b* (5.0 / 1023.0);
  float v3 = c* (5.0 / 1023.0);
  voltage=v1+v2+v3;
  Serial.println(voltage);//print to terminal
  //LCD has 2 lines, and can display 16 characters per line
   // Print to the LCD screen at 0th line
   if (v1>0&&v2>0&&v3>0){// if all three sensors produce voltage
    count=count+3;
   }
   // if 2 out of 3 sensors produce voltage
   else if(v2==0&&v1>0&&v3>0){
    count=count+2;
   }
   else if(v1==0&&v2>0&&v3>0){
    count=count+2;
   }
   else if(v3==0&&v2>0&&v1>0){
    count=count+2;
   }
   //if only  1 sensor produces voltage
   else if(v1==0&&v2==0&&v3>0){
    count++;
   }
   else if(v3==0&&v2>0&&v1==0){
    count++;
   }
   else if(v3==0&&v2==0&&v1>0){
    count++;
   }
  //print total voltage and no. of steps taken to LCD
  lcd.print("Volt:");
  //total=previous total+no. of steps*voltage at that loop
  total=total+voltage*count;
  lcd.print(voltage);
  lcd.print(" Steps:");
  lcd.print(count);
  lcd.setCursor(0,1);
  lcd.print("Total volt:");
  lcd.print(total);
  analogWrite(6,total);
  //each sensor produces approx 3.8V per step,if greater than that, it can glow LEDs
  if(voltage>4){
  //Whenever green@signal2 glows,red@1 glows
  digitalWrite(led6,HIGH);//For GREEN2 signal
  digitalWrite(led1,HIGH);//For RED1 signal
  delay(1000);
  //After some delay,yellow@1 glows followed by green@1
  digitalWrite(led1,LOW);
  digitalWrite(led2,HIGH);
  delay(500);
  digitalWrite(led2,LOW);
  digitalWrite(led6,LOW);
  digitalWrite(led3,HIGH);
  //In the same way red@2 glows and process repeats
  digitalWrite(led4,HIGH);
  delay(1000);
  digitalWrite(led4,LOW);//make RED LED LOW
  digitalWrite(led5,HIGH);
  delay(500);
  digitalWrite(led5,LOW);
  digitalWrite(led3,LOW);
  }
  delay(500);
}//make 0.5s delay
