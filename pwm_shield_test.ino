// Test using Adafruits PWM Shield and Music Shields together.
// The PWM shield drives two rgb leds.
// setPWM takes the pwm channel, start pulse, end pulse
// Here I've grouped the channels as rbg sets and played a sound to go along with them. 

#include <Adafruit_PWMServoDriver.h>
#include <Adafruit_VS1053.h>

#define SHIELD_RESET  -1      
#define SHIELD_CS     7     
#define SHIELD_DCS    6
#define CARDCS 4
#define DREQ 3

Adafruit_VS1053_FilePlayer musicPlayer = Adafruit_VS1053_FilePlayer(SHIELD_RESET, SHIELD_CS, SHIELD_DCS, DREQ, CARDCS);
Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver(0x43);


void setup() {

  musicPlayer.begin(); 
  SD.begin(CARDCS);
  musicPlayer.setVolume(10,10);
 
  pwm.begin();
  pwm.setPWMFreq(100);

}

void loop() {
  
  // put your main code here, to run repeatedly:
   pwm.setPWM(0, 4096, 0);
   pwm.setPWM(1, 4096, 0);
   pwm.setPWM(2, 0, 4096);

   pwm.setPWM(4, 4096, 0);
   pwm.setPWM(5, 4096, 0);
   pwm.setPWM(6, 0, 4096);

   delay(3000);

   pwm.setPWM(0, 4096, 0);
   pwm.setPWM(1, 0, 4096);
   pwm.setPWM(2, 0, 4096);

   pwm.setPWM(4, 4096, 0);
   pwm.setPWM(5, 0, 4096);
   pwm.setPWM(6, 0, 4096);
   musicPlayer.playFullFile("track003.mp3");

   delay(2000);
   
   pwm.setPWM(0, 4096, 0);
   pwm.setPWM(1, 0, 4096);
   pwm.setPWM(2, 4096, 0);

   pwm.setPWM(4, 0, 0);
   pwm.setPWM(5, 0, 0);
   pwm.setPWM(6, 0, 0);
   musicPlayer.playFullFile("track001.mp3");

   delay(2000);

   pwm.setPWM(0, 0, 4096);
   pwm.setPWM(1, 4096, 0);
   pwm.setPWM(2, 0, 4096);

   pwm.setPWM(4, 0, 4096);
   pwm.setPWM(5, 4096, 0);
   pwm.setPWM(6, 0, 4096);

   musicPlayer.playFullFile("track002.wav");
   
   delay(2000);   
}
