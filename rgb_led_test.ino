// RGB Led
// Richard D. Gregorio Jr.
// Using the pwm digital pins on the uno to drive a common anode rgb led. 


byte RedLED = 9; 
byte BluLED = 10;
byte GrnLED = 11;  
int  RedFade;
int  BluFade;
int  GrnFade;

void setup () {
  Serial.begin(9600);
  pinMode (RedLED, OUTPUT);
  pinMode (BluLED, OUTPUT);
  pinMode (GrnLED, OUTPUT);
}
  
void loop () {
  
  //red, green, blue
  //yellow, magenta, cyan
  //white

  rgb_light(255,0,0);
  delay(1000);
  rgb_light(0,255,0);
  delay(1000);
  rgb_light(0,0,255);
  delay(1000);
  rgb_light(255,255,0);
  delay(1000);
  rgb_light(255,0,255);
  delay(1000);
  rgb_light(0,255,255);
  delay(1000);
  rgb_light(255,255,255);
  delay(1000);
  rgb_light(255,127,0);
  delay(1000);
  rgb_light(127,0,127);
  delay(1000);
  
}  

//because its a common anode led
//we need to reverse the color code to
//be able to use the more common rgb codes
int webColor(int LedColor) {
  int x = (LedColor-255) * -1;
  return x;
}

//feed it a rgb value and it lights up
void rgb_light(int Red, int Green, int Blue) {
  analogWrite(RedLED, webColor(Red));
  analogWrite(GrnLED, webColor(Green));
  analogWrite(BluLED, webColor(Blue));
}

void out() {
  //turn it off
  analogWrite(RedLED, 255); //Turns off the RED Element
  analogWrite(GrnLED, 255); //Turns off the GREEN Element
  analogWrite(BluLED, 255); //Turns off the BLUE Element
}

void fade() {
  for (int j=5; j<256; j++){
    delay(20);
    rgb_light(j,0,0);
  }

  delay(500);

  for (int i=255; i>5; i--){
    delay(20);
    rgb_light(i,0,0);
  }

  delay(500); 
}

