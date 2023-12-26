
// This is an embedded system project by Bibek Joshi
// Use Arduino mega 2560 board with this project.
// This can also work with other boards such as uno or even esp-32 but do adust the pin number correctly according to board installed
// don't forget to involve the library

#include <LiquidCrystal_I2C.h>
#include <DHT.h>

# define DHTPIN 6     // defined DHT pin
DHT dht ( DHTPIN, DHT11 ) ;   // initiated dht object

LiquidCrystal_I2C lcd(0x27,16,2);

byte water_drop[8] = {      //bitmap for waterdrop
  B00100,
  B01110,
  B01110,
  B11111,
  B11111,
  B11111,
  B11111,
  B01110
};
byte sun[8] = {     //bit map for Sun
  B00000,
  B01110,
  B11111,
  B11111,
  B11111,
  B11111,
  B01110,
  B00000
};
byte degree_centigrate[8] = {   // bitmap for centigrate
  B10000,
  B00111,
  B01000,
  B01000,
  B01000,
  B01000,
  B01000,
  B00111
};
byte Percentage[8] = {    //bitmap for percentage symbol
  B11001,
  B11011,
  B00010,
  B00110,
  B01100,
  B01000,
  B11011,
  B10011
};

const int rain_sensor=7;    // pin to join rain sensor
const int water_level=A8;   // analog pin to connect to water level sensor


void setup() {
  Serial.begin(9600);   // begin serial monitor at baud rate

  dht.begin();
  lcd.init();
  lcd.clear();        
  lcd.backlight();    // set background led to lit
     
// initiating the bitmap images that we created
  lcd.createChar(7, water_drop);  
  lcd.createChar(6, sun);
  lcd.createChar(5, degree_centigrate);
  lcd.createChar(4, Percentage);

  lcd.setCursor(3,0);
  lcd.print("Project By");
  lcd.setCursor(3,1);
  lcd.print("Your name");   // Enter your name          (don't forget to adjust the set cursor in above line so that name is in center)
  delay(2000);
  lcd.setCursor(2,0);
  lcd.print("Submitted to");
  lcd.setCursor(2,1);
  lcd.print("teachers name");   // to whom the project is submitted (don't forget to adjust the set cursor in above line so that name is in center)
  delay(2000);

 

  pinMode(rain_sensor,INPUT);
  pinMode(water_level,INPUT);
 
 
}

void loop() {

  float humidity = dht.readHumidity ( ) ;
  float temp = dht.readTemperature ( ) ;

   
  int i = digitalRead(rain_sensor);
  int j = analogRead(water_level);
  if(i==0){
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.write(7);           // using the bitmap images that we created for water_drop
      lcd.setCursor(1,0);
      lcd.print("RAIN");
  }
  else{
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.write(6);           // using the bitmap images that we created for sun
    lcd.setCursor(1,0);
    lcd.print("NORAIN");
   
  }
  lcd.setCursor(10,1);
  lcd.print(temp,2);
  Serial.println(temp,2);
  lcd.setCursor(15,1);
  lcd.write(5);               // using the bitmap images that we created for degree_centigrate
  lcd.setCursor(10,0);
  lcd.print(humidity,2);
  Serial.println(humidity,2);
  lcd.setCursor(15,0);
  lcd.write(4);               // using the bitmap images that we created for percentage
  lcd.setCursor(1,1);
  lcd.print(j);
  lcd.setCursor(5,1);
  lcd.print("mm");
  delay(1000);
 
}
