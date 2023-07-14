Use Nodered, MQTT, Mbed-simulator in this project
1. go to https://mbed-simulator.alpsayin.com/
2. copy code in Embedded System folder and paste its in browser.
3. Add component following the Embedded Project.pdf file.
4. Open nodered (You can see how to getting started node-red in https://nodered.org/docs/getting-started/)
5. In nodered import node by Embedded Project.json
6. Open MQTT broker (you can see how to access the broker at https://www.hivemq.com/public-mqtt-broker/)
7. Potentiometer_complete lcd will show value of Potentiometer and if Potentiometer >= 0.5 will make the light on and the speaker sound, In dashboard will show Potentiometer value, status of light and speaker if click ON button in dashboard will make the light on and the speaker sound
8. temp_dash_complete lcd and dashboard will show temperature and humidity value if temperature > 25 c led will work and humidity > 80% led2 will work
9. Thermistor_complete sw2 as a power supply if sw1 on or Thermistor value > 0.5 lcd will show ALERT! message and make the speaker sound, dashboard will show status of power supply, sound and Thermistoristor value  
