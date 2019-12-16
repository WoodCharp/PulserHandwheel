const byte A = 2;
const byte B = 3;
int pulserSteps = 0;
int dir;

bool aRead = false, bRead = false;

void setup() {
  pinMode(A, INPUT_PULLUP);
  pinMode(B, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(A), ReadPulserA, FALLING);
  attachInterrupt(digitalPinToInterrupt(B), ReadPulserB, FALLING);
  Serial.begin(115200);
}

void loop() {
  if(aRead && bRead)
  {
    aRead = false;
    bRead = false;

    switch(dir)
    {
      case 1:
        pulserSteps--;
        break;
      case 2:
        pulserSteps++;
        break;
    }
     
    Serial.println(pulserSteps);
  }
}

void ReadPulserA()
{
  dir = 1;
  aRead = true;
}

void ReadPulserB()
{
  dir = 2;
  bRead = true;
}
