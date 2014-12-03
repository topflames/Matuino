//  Rudementary Beat Detection for Arduino
//  A Rudimentary beat detection algorithm for Arduino
//  Takes a sample of music volume for [sampleWindow]
//  Then if detects above averaged [sampleWindow]
//  Outputs beat to [sendb]=HIGH.
 
const int sampleWindow = 5; // Sample window width in mS (50 mS = 20Hz)
const int beatWindow = 50;
unsigned int sample;
unsigned int beat;
const int sendb = 7;
 
void setup() 
{
   Serial.begin(9600);
 pinMode(12,OUTPUT);
}
 
 
void loop() 
{
   unsigned long startMillis= millis();  // Start of sample window
 
   // collect data for 50 mS
   while (millis() - startMillis < sampleWindow)
   {
      for (int i = 0;i<5;i++)
      {
       sample = sample + analogRead(5);
      }
      sample = sample/5;
      Serial.print("sample: ");
      Serial.println(sample);
      
   }
   
    startMillis= millis();
    while (millis() - startMillis < beatWindow){
      beat= analogRead(5);
       Serial.print("Print: ");
      Serial.println(beat);
       if (beat>sample)
       {
       digitalWrite(sendb,HIGH);
       delay(25);
       digitalWrite(sendb,LOW);
       }
       else
       {
       digitalWrite(7,LOW);
       }
       delay(50);
    }
}
