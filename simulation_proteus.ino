int count = 0;
char c;
String id;

void setup() {
  Serial.begin(9600);
  pinMode(13, OUTPUT);
  Serial.println("Please scan your RFID TAG");
 
}

void loop() {
  while(Serial.available()>0)
  {
    c = Serial.read();
   count++;
   id += c;
   if(count == 12)  
    {
      Serial.print(id);
      //break;
     
      if(id=="AB123456789A")
      {
        Serial.println("Present Aditya");
        digitalWrite(13, HIGH);
        break;
      }
      if(id=="AC123456789A")
       {
        Serial.println("Present Uby");
        digitalWrite(13, HIGH);
        break;
      }
      else
      {
      digitalWrite(13, LOW);
      Serial.println("Invalid TAG");
      }
    }
  }
  count = 0;
  id="";
  delay(500);

}
