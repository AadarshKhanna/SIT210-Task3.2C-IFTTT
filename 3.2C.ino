#include "thingProperties.h"

const int LDR_PIN = 12;
int ldrValue = 0;
float Intensity = 0.0; // Declare Intensity variable as a float
bool SunLight = false; // Declare sunLight variable as a bool

void setup() {
  // Initialize serial and wait for port to open:
  Serial.begin(9600);
  // This delay gives the chance to wait for a Serial Monitor without blocking if none is found
  delay(1500);

  // Defined in thingProperties.h
  initProperties();

  // Connect to Arduino IoT Cloud
  ArduinoCloud.begin(ArduinoIoTPreferredConnection);
  setDebugMessageLevel(2);
  ArduinoCloud.printDebugInfo();
}

void loop() {
  // Read the LDR sensor value
  ldrValue = digitalRead(LDR_PIN);

  // Update the Intensity variable in the IoT Cloud
  ArduinoCloud.update();

  Serial.print("LDR Value: ");
  Serial.println(ldrValue);

  delay(1000); // Delay for stability
}

//For SunLight Value
void onSunLightChange() {
  if (ldrValue > 500)
  {
    SunLight = true;
  }
  Serial.print("Sunlight is Present ");
}

//For Getting value of Intensity
void onIntensityChange()  {
  Intensity = ldrValue;
  Serial.print("Intensity changed to: ");
  Serial.println(Intensity);
}
