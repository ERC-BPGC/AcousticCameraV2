unsigned long startMicro;
 
 void setup() {
  pinMode(14,INPUT);
  pinMode(15,INPUT);
  pinMode(16,INPUT);
  pinMode(17,INPUT);
  Serial.begin(115200);
  startMicro = micros();
}

int count,avg = 0;
int samples = 1000000;

unsigned int sampling_rate = 2000; // in Hz
unsigned int delta_t = 1000000 / sampling_rate; // in microsecs
char data[60];
int val1, val2, val3, val4;

void loop() {
  /*if(count <= 19){
    count++;
  }
  if(count > 19 && count < 70){
  avg += analogRead(14)/50;
  Serial.println(avg);
  count++;
  }
  else{
    Serial.println(analogRead(14)-avg); 
  }
  //int data = analogRead(15) + 20000;
  //Serial.println(data);
  delay(5);*/
  if(micros() - startMicro > delta_t){
    val1 = analogRead(14);
    val2 = analogRead(15);
    val3 = analogRead(16);
    val4 = analogRead(17);
    
    sprintf(data, "%i, %i, %i, %i \n", val1, val2, val3, val4);
    Serial.print(data);
    
    startMicro = micros();
  }
}
