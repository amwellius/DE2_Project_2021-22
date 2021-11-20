EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L MCU_Module:Arduino_UNO_R3 A?
U 1 1 6198E49A
P 5250 2350
F 0 "A?" H 5950 3400 50  0000 C CNN
F 1 "Arduino_UNO_R3" H 5950 3300 50  0000 C CNN
F 2 "Module:Arduino_UNO_R3" H 5250 2350 50  0001 C CIN
F 3 "https://www.arduino.cc/en/Main/arduinoBoardUno" H 5250 2350 50  0001 C CNN
	1    5250 2350
	1    0    0    -1  
$EndComp
$Comp
L my_power:GND #PWR?
U 1 1 61993515
P 2350 2150
F 0 "#PWR?" H 2350 1900 50  0001 C CNN
F 1 "GND" H 2355 1977 50  0000 C CNN
F 2 "" H 2350 2150 50  0001 C CNN
F 3 "" H 2350 2150 50  0001 C CNN
	1    2350 2150
	1    0    0    -1  
$EndComp
Wire Wire Line
	1550 1450 1700 1450
$Comp
L Transistor_FET:DMG2301L Q?
U 1 1 61995D66
P 2350 1350
F 0 "Q?" V 2692 1350 50  0000 C CNN
F 1 "DMG2301L" V 2601 1350 50  0000 C CNN
F 2 "Package_TO_SOT_SMD:SOT-23" H 2550 1275 50  0001 L CIN
F 3 "https://www.diodes.com/assets/Datasheets/DMG2301L.pdf" H 2350 1350 50  0001 L CNN
	1    2350 1350
	0    -1   -1   0   
$EndComp
$Comp
L Device:R R?
U 1 1 61999A3C
P 2350 1800
F 0 "R?" H 2420 1846 50  0000 L CNN
F 1 "100R" H 2420 1755 50  0000 L CNN
F 2 "Resistor_SMD:R_1206_3216Metric_Pad1.42x1.75mm_HandSolder" V 2280 1800 50  0001 C CNN
F 3 "~" H 2350 1800 50  0001 C CNN
	1    2350 1800
	1    0    0    -1  
$EndComp
Wire Wire Line
	2350 1650 2350 1600
$Comp
L Diode:BZD27Cxx D?
U 1 1 6199B5FD
P 2700 1400
F 0 "D?" V 2654 1480 50  0000 L CNN
F 1 "BZD27Cxx" V 2745 1480 50  0000 L CNN
F 2 "Diode_SMD:D_SMF" H 2700 1225 50  0001 C CNN
F 3 "https://www.vishay.com/docs/85153/bzd27series.pdf" H 2700 1400 50  0001 C CNN
	1    2700 1400
	0    1    1    0   
$EndComp
Wire Wire Line
	2350 1600 2700 1600
Wire Wire Line
	2700 1600 2700 1550
Connection ~ 2350 1600
Wire Wire Line
	2350 1600 2350 1550
Wire Wire Line
	2550 1250 2700 1250
Connection ~ 2700 1250
$Comp
L my_power:+9V #PWR?
U 1 1 6199C5FD
P 3500 1200
F 0 "#PWR?" H 3500 1050 50  0001 C CNN
F 1 "+9V" H 3515 1373 50  0000 C CNN
F 2 "" H 3500 1200 50  0001 C CNN
F 3 "" H 3500 1200 50  0001 C CNN
	1    3500 1200
	1    0    0    -1  
$EndComp
Wire Wire Line
	1550 1250 2150 1250
Wire Wire Line
	2350 1950 2350 2050
Wire Wire Line
	2350 2050 1700 2050
Wire Wire Line
	1700 1450 1700 2050
Connection ~ 2350 2050
Wire Wire Line
	2350 2050 2350 2150
Text Notes 2050 900  0    50   ~ 0
simple reverse polarity safety
Wire Wire Line
	3500 1250 3500 1200
Wire Wire Line
	2700 1250 3350 1250
$Comp
L Device:CP C?
U 1 1 6199FAA3
P 3350 1400
F 0 "C?" H 3468 1446 50  0000 L CNN
F 1 "CP" H 3468 1355 50  0000 L CNN
F 2 "Capacitor_THT:CP_Radial_D6.3mm_P2.50mm" H 3388 1250 50  0001 C CNN
F 3 "~" H 3350 1400 50  0001 C CNN
	1    3350 1400
	1    0    0    -1  
$EndComp
Connection ~ 3350 1250
Wire Wire Line
	3350 1250 3500 1250
$Comp
L Device:C C?
U 1 1 619A03DC
P 3700 1400
F 0 "C?" H 3815 1446 50  0000 L CNN
F 1 "C" H 3815 1355 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric_Pad1.18x1.45mm_HandSolder" H 3738 1250 50  0001 C CNN
F 3 "~" H 3700 1400 50  0001 C CNN
	1    3700 1400
	1    0    0    -1  
$EndComp
$Comp
L Device:C C?
U 1 1 619A0D96
P 4000 1400
F 0 "C?" H 4115 1446 50  0000 L CNN
F 1 "C" H 4115 1355 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric_Pad1.18x1.45mm_HandSolder" H 4038 1250 50  0001 C CNN
F 3 "~" H 4000 1400 50  0001 C CNN
	1    4000 1400
	1    0    0    -1  
$EndComp
Wire Wire Line
	3500 1250 3700 1250
Connection ~ 3500 1250
Connection ~ 3700 1250
Wire Wire Line
	3700 1250 4000 1250
Wire Wire Line
	4000 1550 3700 1550
Connection ~ 3700 1550
Wire Wire Line
	3700 1550 3500 1550
$Comp
L my_power:GND #PWR?
U 1 1 619A1622
P 3500 1550
F 0 "#PWR?" H 3500 1300 50  0001 C CNN
F 1 "GND" H 3505 1377 50  0000 C CNN
F 2 "" H 3500 1550 50  0001 C CNN
F 3 "" H 3500 1550 50  0001 C CNN
	1    3500 1550
	1    0    0    -1  
$EndComp
Connection ~ 3500 1550
Wire Wire Line
	3500 1550 3350 1550
Wire Wire Line
	4000 1250 5150 1250
Wire Wire Line
	5150 1250 5150 1350
Connection ~ 4000 1250
$Comp
L my_power:VCC #PWR?
U 1 1 619A2B42
P 5450 1300
F 0 "#PWR?" H 5450 1150 50  0001 C CNN
F 1 "VCC" H 5465 1473 50  0000 C CNN
F 2 "" H 5450 1300 50  0001 C CNN
F 3 "" H 5450 1300 50  0001 C CNN
	1    5450 1300
	1    0    0    -1  
$EndComp
Wire Wire Line
	5450 1300 5450 1350
$Comp
L my_power:+3V3 #PWR?
U 1 1 619A4338
P 5350 1200
F 0 "#PWR?" H 5350 1050 50  0001 C CNN
F 1 "+3V3" H 5365 1373 50  0000 C CNN
F 2 "" H 5350 1200 50  0001 C CNN
F 3 "" H 5350 1200 50  0001 C CNN
	1    5350 1200
	1    0    0    -1  
$EndComp
Wire Wire Line
	5350 1200 5350 1350
$Comp
L my_power:GND #PWR?
U 1 1 619A4F11
P 5150 3700
F 0 "#PWR?" H 5150 3450 50  0001 C CNN
F 1 "GND" H 5155 3527 50  0000 C CNN
F 2 "" H 5150 3700 50  0001 C CNN
F 3 "" H 5150 3700 50  0001 C CNN
	1    5150 3700
	1    0    0    -1  
$EndComp
Wire Wire Line
	5150 3700 5150 3550
Wire Wire Line
	5150 3550 5250 3550
Wire Wire Line
	5250 3550 5250 3450
Connection ~ 5150 3550
Wire Wire Line
	5150 3550 5150 3450
Wire Wire Line
	5250 3550 5350 3550
Wire Wire Line
	5350 3550 5350 3450
Connection ~ 5250 3550
NoConn ~ 5750 2150
NoConn ~ 5750 1950
Wire Wire Line
	5750 1750 6300 1750
$Comp
L dk_Pushbutton-Switches:GPTS203211B S?
U 1 1 619A8804
P 6500 1750
F 0 "S?" H 6500 2025 50  0000 C CNN
F 1 "GPTS203211B" H 6500 1934 50  0000 C CNN
F 2 "digikey-footprints:PushButton_12x12mm_THT_GPTS203211B" H 6700 1950 50  0001 L CNN
F 3 "http://switches-connectors-custom.cwind.com/Asset/GPTS203211BR2.pdf" H 6700 2050 60  0001 L CNN
F 4 "CW181-ND" H 6700 2150 60  0001 L CNN "Digi-Key_PN"
F 5 "GPTS203211B" H 6700 2250 60  0001 L CNN "MPN"
F 6 "Switches" H 6700 2350 60  0001 L CNN "Category"
F 7 "Pushbutton Switches" H 6700 2450 60  0001 L CNN "Family"
F 8 "http://switches-connectors-custom.cwind.com/Asset/GPTS203211BR2.pdf" H 6700 2550 60  0001 L CNN "DK_Datasheet_Link"
F 9 "/product-detail/en/cw-industries/GPTS203211B/CW181-ND/3190590" H 6700 2650 60  0001 L CNN "DK_Detail_Page"
F 10 "SWITCH PUSHBUTTON SPST 1A 30V" H 6700 2750 60  0001 L CNN "Description"
F 11 "CW Industries" H 6700 2850 60  0001 L CNN "Manufacturer"
F 12 "Active" H 6700 2950 60  0001 L CNN "Status"
	1    6500 1750
	1    0    0    -1  
$EndComp
$Comp
L Device:R R?
U 1 1 619A9DEB
P 6800 2000
F 0 "R?" H 6870 2046 50  0000 L CNN
F 1 "R" H 6870 1955 50  0000 L CNN
F 2 "" V 6730 2000 50  0001 C CNN
F 3 "~" H 6800 2000 50  0001 C CNN
	1    6800 2000
	1    0    0    -1  
$EndComp
Wire Wire Line
	6700 1750 6800 1750
Wire Wire Line
	6800 1750 6800 1850
$Comp
L my_power:GND #PWR?
U 1 1 619AA9BA
P 6800 2250
F 0 "#PWR?" H 6800 2000 50  0001 C CNN
F 1 "GND" H 6805 2077 50  0000 C CNN
F 2 "" H 6800 2250 50  0001 C CNN
F 3 "" H 6800 2250 50  0001 C CNN
	1    6800 2250
	1    0    0    -1  
$EndComp
Wire Wire Line
	6800 2250 6800 2150
$Comp
L Connector:Barrel_Jack_Switch J?
U 1 1 619AB9F6
P 1250 1350
F 0 "J?" H 1307 1667 50  0000 C CNN
F 1 "Barrel_Jack_Switch" H 1307 1576 50  0000 C CNN
F 2 "Connector_BarrelJack:BarrelJack_Wuerth_6941xx301002" H 1300 1310 50  0001 C CNN
F 3 "~" H 1300 1310 50  0001 C CNN
	1    1250 1350
	1    0    0    -1  
$EndComp
Wire Wire Line
	1550 1350 1700 1350
Wire Wire Line
	1700 1350 1700 1450
Connection ~ 1700 1450
Text Notes 1200 3300 0    50   ~ 0
To HC-SR04
$Comp
L my_power:VCC #PWR?
U 1 1 619B3260
P 1950 2600
F 0 "#PWR?" H 1950 2450 50  0001 C CNN
F 1 "VCC" H 1965 2773 50  0000 C CNN
F 2 "" H 1950 2600 50  0001 C CNN
F 3 "" H 1950 2600 50  0001 C CNN
	1    1950 2600
	1    0    0    -1  
$EndComp
Wire Wire Line
	1500 2700 1950 2700
Wire Wire Line
	1950 2700 1950 2600
$Comp
L Connector:Conn_01x05_Female J?
U 1 1 619B4ADE
P 1300 2900
F 0 "J?" H 1192 2475 50  0000 C CNN
F 1 "Conn_01x05_Female" H 1192 2566 50  0000 C CNN
F 2 "" H 1300 2900 50  0001 C CNN
F 3 "~" H 1300 2900 50  0001 C CNN
	1    1300 2900
	-1   0    0    1   
$EndComp
Text Label 4500 2350 0    50   ~ 0
TRIG
Wire Wire Line
	1500 3000 1950 3000
NoConn ~ 1950 3000
$Comp
L my_power:GND #PWR?
U 1 1 619BAD93
P 1950 3100
F 0 "#PWR?" H 1950 2850 50  0001 C CNN
F 1 "GND" H 1955 2927 50  0000 C CNN
F 2 "" H 1950 3100 50  0001 C CNN
F 3 "" H 1950 3100 50  0001 C CNN
	1    1950 3100
	1    0    0    -1  
$EndComp
Wire Wire Line
	1500 3100 1950 3100
Text Label 4500 2250 0    50   ~ 0
ECHO
Wire Wire Line
	3800 2800 3800 2250
Wire Wire Line
	3800 2250 4750 2250
Wire Wire Line
	1500 2800 3800 2800
Wire Wire Line
	3900 2900 3900 2350
Wire Wire Line
	3900 2350 4750 2350
Wire Wire Line
	1500 2900 3900 2900
$EndSCHEMATC
