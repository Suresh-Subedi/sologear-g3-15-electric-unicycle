# Sologear G3-15 Electric Unicycle
Sologear G3-15 Electric Unicycle reverse engineering to reuse motherboard with custom firmware

![image](https://user-images.githubusercontent.com/7327694/182027742-2f7adce6-3381-420a-9f2c-5847d1e44d63.png)
![image](https://user-images.githubusercontent.com/7327694/182027750-17d46af4-bab4-4cc0-809f-929fa3575e1d.png)
#### Connections
|STM32F103|MPU 6050|Comment         |
|---------|--------|----------------|
|PB7      |SDA     |Via resistor R31|
|PB6      |SCL     |Via resistor R33|

|STM32F103|SWD|
|---------|---|
|PA14     |SWC|
|PA13     |SWD|
|         |3V3|
|         |GND|

|STM32F103|P4 Battery Indicator|Color |Comment        |
|---------|--------------------|------|---------------|
|PA15     |1                   |Black |Via resistor R1|
|PB4      |2                   |Blue  |Via resistor R2|
|PB5      |3                   |Yellow|Via resistor R3|
|PB8      |4                   |Green |Via resistor R4|
|         |5                   |Red   |+5V            |

### Firmware
Existing firmware was unprotected and could be read using STM-Link V2. Soldering headers was a bit difficult as pin holes were already filled with solder.

### Components
STM32F103C8T6\
InvenSense MPU 6050\
6 MOSFET ST P75NF75&

### Battery
59.2V/4.4Ah 260Wh SAMSUNG/22PM\
Hy-LYX-1602B-22PM-144900042

### Motor
CST e-BIKE PRO Li-ion Electronic\
14AMK1512615052\
XINAOMA

### Useful software
STM32 ST-LINK Utility\
Ghidra with SVD-Loader

### Connections
|Marking on board|Connections|Connected                    |
|----------------|-----------|-----------------------------|
|P2              |2          |5v SPK Unpopulated           |
|P3              |3          |2p connected to switch LED   |
|P4              |5          |2mm: battery level           |
|P5              |5          |2.5mm: hall effect sensor    |
|P6              |2          |Disconnected                 |
|P7              |2          |Switch                       |
#### Switch
|Marking on board|Color|Switch|
|----------------|-----|------|
|P3              |Red  |      |
|P3              |Black|      |
|P7              |Red  |      |
|P7              |White|Center|
#### LED Display
|Marking on board|Color |Display|
|----------------|------|-------|
|P4              |Red   |       |
|P4              |Black |       |
|P4              |Blue  |       |
|P4              |Yellow|       |
|P4              |Green |       |
#### Charging port
Red
Black
Connected to battery
#### Motor connection
|Color |Marking on board|
|------|----------------|
|Yellow|Y?              |
|Green |V               |
|Blue  |W               |

![image](https://user-images.githubusercontent.com/7327694/181603426-59b6c1a9-ce35-4718-99e6-8ff5b3bffbaf.png)

