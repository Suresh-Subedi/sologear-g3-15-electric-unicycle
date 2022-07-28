# Sologear G3-15 Electric Unicycle
Sologear G3-15 Electric Unicycle reverse engineering to reuse motherboard with custom firmware

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
|P2              |2          |5v SPK unpopulated           |
|P3              |3          |2p connected power status led|
|P4              |5          |2mm: battery level           |
|P5              |5          |2.5mm: hall effect sensor    |
|P6              |2          |disconnected                 |
|P7              |2          |led/switch                   |
