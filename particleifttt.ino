// This #include statement was automatically added by the Particle IDE.
#include <BH1750.h> //header files that include BH175O library //
                    //which use to interface with the sensor
BH1750 sensor(0x23, Wire);
double DataSunlight = 0; 


void setup() {//This setup() function is called once when the device starts.
sensor.begin();//initialize the sensor 
sensor.set_sensor_mode(BH1750::forced_mode_high_res2); //configure it to use high-resolution mode 2
Particle.variable("Sunlight",DataSunlight); //create a Particle variable called "Sunlight" that points to DataSunlight
                                            //allowing us to retrieve the value of the sunlight from the Particle cloud
Serial.begin();//start serial communication for debugging purposes.
}


void loop() {//function is called repeatedly 
sensor.make_forced_measurement(); //take a single measurement using the sensor's make_forced_measurement() method
DataSunlight = sensor.get_light_level();//store the measured value of sunlight in the DataSunlight variable
String data_light = String(DataSunlight);//convert DataSunlight to a string then store it in data_light String
Particle.publish("Sunlight", data_light, PRIVATE); //publish the data_light value as a private event with the name "Sunlight"
delay(7000); //wait for 7 seconds before taking another measurement
}