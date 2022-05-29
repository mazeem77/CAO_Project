int UPDOWN = D1;
int LEFT1 = D2;
int LEFT2 = D3;
int RIGHT1 = D4;
int RIGHT2 = D5;
String array[3]={"x: ", "y: ", "z: "};
String received;
String mData;
int xAxis, yAxis, zAxis;
int delimitor[4];
void setup() {
 pinMode(UPDOWN, OUTPUT);
// pinMode(DOWN, OUTPUT);
 pinMode(LEFT1, OUTPUT);
 pinMode(RIGHT1, OUTPUT);
 pinMode(LEFT2, OUTPUT);
 pinMode(RIGHT2, OUTPUT);
 Serial.begin(9600); /* Define baud rate for serial communication */
}

void loop() {

 if (Serial.available())  /* If data is available on serial port */
    {
      
      received = Serial.readString();
      Serial.println(received);
      delimitor[0] = -1;
      delimitor[1] = received.indexOf(',');
      xAxis = received.substring(delimitor[0]+1,delimitor[1]).toInt();
      delimitor[2] = received.indexOf(',',delimitor[1]+1);
      yAxis = received.substring(delimitor[1]+1,delimitor[2]).toInt();
      delimitor[3] = received.indexOf(',',delimitor[2]+1);
      zAxis = received.substring(delimitor[2]+1,delimitor[3]).toInt();

      Serial.print("xAxis: ");
      Serial.println(xAxis);
      Serial.print("yAxis: ");
      Serial.println(yAxis);
      Serial.print("zAxis: ");
      Serial.println(zAxis);

      if (xAxis > 2 && yAxis > 2){
        digitalWrite(LEFT1,HIGH);
        digitalWrite(LEFT2,HIGH);
        digitalWrite(RIGHT1,LOW);
        digitalWrite(RIGHT2,LOW);
        digitalWrite(UPDOWN,HIGH);      // IN1
      }
      else if (xAxis > 2 && yAxis < -2){
        digitalWrite(LEFT1,LOW);
        digitalWrite(LEFT2,LOW);
        digitalWrite(RIGHT1,HIGH);
        digitalWrite(RIGHT2,HIGH);
        digitalWrite(UPDOWN,LOW);      // IN1
      }

      else if (xAxis < -2 && yAxis > 2){
        digitalWrite(LEFT1,LOW);
        digitalWrite(LEFT2,LOW);
        digitalWrite(RIGHT1,HIGH);
        digitalWrite(RIGHT2,HIGH);
        digitalWrite(UPDOWN,HIGH);      // IN1
      }
      else if (xAxis < -2 && yAxis < -2){
        digitalWrite(LEFT1,HIGH);
        digitalWrite(LEFT2,HIGH);
        digitalWrite(RIGHT1,LOW);
        digitalWrite(RIGHT2,LOW);
        digitalWrite(UPDOWN,LOW);      // IN1
      }

      else if(xAxis > 2){
        digitalWrite(LEFT1,LOW);
        digitalWrite(LEFT2,LOW);
        digitalWrite(RIGHT1,HIGH);
        digitalWrite(RIGHT2,HIGH);
        digitalWrite(UPDOWN,LOW);      // IN1
      }
      else if(xAxis < -2){
        digitalWrite(LEFT1,HIGH);
        digitalWrite(LEFT2,HIGH);
        digitalWrite(RIGHT1,LOW);
        digitalWrite(RIGHT2,LOW);
        digitalWrite(UPDOWN,LOW);      // IN1
      }
//// ***********************************************************
    }
}
