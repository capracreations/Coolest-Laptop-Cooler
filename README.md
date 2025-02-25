# Coolest Laptop Cooler
## Overview
![](/images/cooler3.jpg)  
A laptop cooler designed to support >15in laptops with two Noctua NF-P12 redux-1700 PWM fans and a soft foam seal. The cooler supports the use of a LCD1602A module with three push buttons to adjust the fan speed and PWM frequency.

## Requirements
### Softwares
- CAD Software (Solidworks, Fusion360, Onshape)
- 3D-printing Slicer (Cura, Prusaslicer)
- Arduino IDE 2.0 or higher
### Cooler
- 3D-printer
- 2kg PETG filament, any brand and colour(s)
- Arduino Nano
- 2x Noctua NF-P12 redux-1700 PWM
- LCD1602A module
- 3x Push Buttons
- 3-way fan splitter (See resources)
- USB-A fan power adapter (See resources)
- 1x Latching switch (See resources)
- 5x25mm steel dowels (See resources)
- Soft foam roll with tape (See resources)
- Rubber feet (See resources)
- 12V to 5V DC buck converter
- M.# bolt and nut set
- M.# threaded insert set
- jumper wires (too many)

## .STL 3D Model Files
![](/images/cooler_iso.png)  
.stl CAD files for the cooler are provided for download, parts are designed and toleranced to be **_3D-printed without supports_** (with some finicking of slicer settings). As most 3D-printers do not have massive print beds, the cooler has been split up into multiple parts to enable them to be printed. The cooler is assembled using 5x25mm steel dowels for structural stability and various sizes of M.# hex bolts.

## Cooler Code and Fan PWM Frequency
### Code
The code for the cooler is very barebones, and I mean **_VERY BAREBONES_**. All I needed it to do was modulate the PWM frquency and for that purpose alone, I did not code any fancy GUI elements or complicate things more than needed. For example, all user inputs are working off the base timing of the ATmega328 clock, and thus there is no input validation for long presses, double clicks, etc. This although does not mean the code will break, as there are hard-coded limits to variable values, so user inputs cannot break the intended loop unless the code itself is edited.
### Fan PWM Frequency
![](/images/25kHz_PWM_logic.png)  
Noctua fans (and most computer fans) require a 25kHz clock frequency to function optimally, whereas Arduino Nano's come with a base 16kHz clock frequency from the factory. However, this can be worked around with some coding trickery by modifying the PWM output control registers and register timers for pin 9 on the Nano and setting the value to output a 25kHz frequency for the fan PWM input.

## Features
### Foam Seal
![](/images/cooler2.jpg)
The cooler has a soft foam seal around the perimeter of the air channel to conform to every laptops topology and force air through the intake. This ensures the laptop is actually cooled through convection from the inside rather than allowing most of the air to hit the bottom panel and escape through the gaps using a traditional cooler.
### Push Buttons
![](/images/cooler4.jpg)  
As stated prior, the cooler supports a LCD1602A module and three push buttons; the top (green) button increases the PWM frequency by 10%, the bottom (black) button decreases the PWM frequency by 10%, and the middle (white) button ramps the fans from any speed to 0% PWM frequency thus stopping the fans. The screen will update with the current PWM frequency and fan speed with inputs and while ramping down.
### ON/OFF Switch
![](/images/cooler5.jpg)  
The cooler can be turned on and off using a latching switch spliced to the positive lead of the USB-A fan power adapter, thus allowing the user to keep the device plugged-in and ready to use.

## Performance
Prior to having made the Coolest Laptop Cooler, I was . Now my laptop is not the newest in the world and is not the most powerful device out there, sporting a 9th-gen Intel i7 CPU and a RTX2060m GPU, at the time I bought it in 2020, it was lightning fast and responsive. Years of university assignments and gaming binges eventually started showing their impact recently and I was thus running into a lot of thermal throttling issues with GPU temperatures remaining at 88°C under load causing framedrops, longer loading times, stutters, and a loss in responsiveness/performance in regular tasks. So I eventually had enough and decided to look for a solution. A quick Google search nets you a [Llano V13](https://www.amazon.ca/llano-External-Adjustable-Computer-V13/dp/B0CMTCB8Q6/ref=sr_1_2_sspa?crid=1POC0NO5GHSTU&dib=eyJ2IjoiMSJ9.YF-ljNPglwGdckR8lWSFSBiYNVTnB8ScsS9gPuYyK4zyEkwB2Pz2isaRxMyDfI0MmLOB3HVy5thqQah2AGzPVN-Q7KW6M03GhVzpQPtIIt-opvFKd606hsPbgwj5mvkqOPtRIoRVgorMg642wQXM4JZGVPCgWjoH46y9JqrpxYHkLqcqZI9ZM7-TzwKlBYHDv7iEIKZLYxtnZtNi2vNBwlB6MmC3OcY8Zgitqmy9Jg8XkZsMyGG9gqHOCaEgc-BsyZpFfX3Apz0oDuO_xIAUvbeQJFEq263VJ4Zo2n3pjZc.qbEtd4gg2JhvvftbfCLr8Dx7CVbjZUhvKNq3t8RtY7w&dib_tag=se&keywords=laptop+cooler&qid=1740464298&sprefix=laptop+cooler%2Caps%2C97&sr=8-2-spons&sp_csd=d2lkZ2V0TmFtZT1zcF9hdGY&psc=1), which costs a WHOPPING CAD$150! "That's insane", I thought to myself, and insane it is. So I set out to make myself my own _"not as expensive"_ cooler.
### Data and Graphs
![](/Temperature_data/temperature_graphs/blops6_comparison.png)
During data acquisition, It was noted that the designed cooler could achieve up to 24°C cooler temperatures on average during load, this however depends on the program and associated load on the components of all the processes taking place. To mitigate the confusion behind the true performance of the cooler, many games were tested and video streaming was also recorded for a low load test. For transparency, all raw data files, graphs and spreadsheets are available to download and peruse.

## Resources
-[3-way Fan Splitter](https://www.amazon.ca/dp/B0DJPBXZ89?ref=ppx_yo2ov_dt_b_fed_asin_title)  
-[USB-A Fan Power Adapter](https://www.amazon.ca/dp/B0BY43DZ11?ref=ppx_yo2ov_dt_b_fed_asin_title)  
-[Latching Switch](https://www.amazon.ca/dp/B0DJ46XRP6?ref=ppx_yo2ov_dt_b_fed_asin_title&th=1)  
-[5x25mm Steel Dowels](https://www.amazon.ca/dp/B07F3TWSBY?ref=ppx_yo2ov_dt_b_fed_asin_title)  
-[Soft Foam Roll with Tape](https://www.amazon.ca/dp/B0B193G1WC?ref=ppx_yo2ov_dt_b_fed_asin_title&th=1)  
-[Rubber Feet](https://www.amazon.ca/dp/B07PXNTT7K?ref=ppx_yo2ov_dt_b_fed_asin_title&th=1)

