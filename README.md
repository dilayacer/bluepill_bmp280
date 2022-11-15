# bluepill_bmp280
Mountaineer Alarm System
The mountaineer alarm system has been developed so that mountaineers are not affected by the ambient conditions they are in when they go to high altitudes. It was intended to be used as a bracelet. STM32 Blue Pill (STM32duino) was used. BMP280 sensor was used to learn the ambient conditions. Modules that will inform the mountaineer when the threshold value is passed were considered. The first of these warning systems is the vibration motor. Vibration is remarkable because it creates a physical effect. Other warning system includes LED. Controlled by LDR, the LED turns on only when it gets dark. Because the LED may not be noticeable in daylight. There is no buzzer in the system. Because the frequency of the sound can create dangerous situations in the environment where the mountaineer is. The data is shown on the internal display.

The schematic of the designed system was drawn on Proteus.

![image](https://user-images.githubusercontent.com/94526687/202036276-00e90f78-0478-4fb7-b72e-4932bf14706d.png)

The project was prepared in Arduino Framework on Platformio.
