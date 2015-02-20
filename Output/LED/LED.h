Title: LED.h
+* Authors: Clark Asher
+* Group: The A Team
+* For: Senior Design - Metering Project
+* Date: 2/18/2015
+*
+* Library definition for controlling LEDs
+*
+*/
+
+
+#ifndef LED_h
+#define LED_h
+
+class Bargraph
+{
+	public:
+
+		Bargraph();
+	
+		unsigned int ConvertPower();   //converts instantaneous power to binary data
+		bool LEDwrite();   //triggers LEDs for bargraph
+
+};
