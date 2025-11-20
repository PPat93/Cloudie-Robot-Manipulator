//Author: Piotr Paterek, Kraków 05-08.2016
#include "hFramework.h"
#include "hCloudClient.h"

bool keyW = false;
bool keyS = false;
bool keyA = false;
bool keyD = false;


hPIDRegulator pidReg;



int i = 0;
int m = 0;
int n = 0;
float s;
int mot1 = 0;
int mot2 = 0;


float angle1 = -5;
float angle2 = 10;
float angle3 = 13;
float angle4 = -5;
float angle5 = -11;


hGPIO& lightLeft = hSens1.pin1;
hGPIO& lightRight = hSens2.pin1;

void debugConsole_task()
{
	char ch;

	platform.printf("Wpisz znak:\r\n");
	for (;;) {
		if (platform.read(&ch, 1) == 1) {
			platform.printf("echo: %c\r\n", ch);
		}
	}
}

void status_task()
{
	while (1) {
		platform.ui.label("lb_bat").setText("%2f V", sys.getSupplyVoltage());
		platform.ui.progressBar("pb_bat").setValue(sys.getSupplyVoltageMV() / 15); //supply voltage milivolts

		sys.delay(200);
	}
}

void motorMotion()//pid regulator for the motor
{
	// hPID
	pidReg.setScale(1);
	pidReg.setKP(39.0);
	pidReg.setKI(0.05);
	pidReg.setKD(1000);
// hRegulator
	pidReg.dtMs = 5;
	pidReg.stableRange = 10;
	pidReg.stableTimes = 3;

	hMot1.attachPositionRegulator(pidReg);

}

void cfgHandler()
{
	auto l1 = platform.ui.label("l1");
	auto l2 = platform.ui.label("l2");
	auto b = platform.ui.button("btn1");
	auto slider = platform.ui.input("slider1");
	auto input = platform.ui.input("text");
	platform.ui.loadHtml({Resource::WEBIDE, "/ui.html"});
//	platform.ui.video.enable();
}

void servoMotionSeparately()
{

	hServoModule.s1.calibrate(-90, 2400, 90, 800);  // servos calibration
	hServoModule.s2.calibrate(-90, 2400, 90, 800);
	hServoModule.s3.calibrate(-90, 800, 90, 2400);
	hServoModule.s4.calibrate(-90, 800, 90, 2400);
	hServoModule.s5.calibrate(-90, 800, 90, 2400);

	while (1) {

		sys.delay(10);
		if (i == 1) {                   //following angles on servos with limits

			angle1 += 2;
			if (angle1 > -5) {
				angle1 = -5;
			}
			sys.delay(30);
			platform.ui.console("cl1").printf("Angle3  =  %f \n", angle3);
			platform.ui.console("cl1").printf("Angle2  =  %f \n", angle2);
			platform.ui.console("cl1").printf("Angle1 = %f \n", angle1);
			platform.ui.console("cl1").printf("--------------------------\n");
			hServoModule.s1.rotAbs(angle1);
		} else if (i == 2) {
			angle1 -= 2;

			if (angle1 < -90) {
				angle1 = -90;
			}
			sys.delay(30);
			platform.ui.console("cl1").printf("Angle3  =  %f \n", angle3);
			platform.ui.console("cl1").printf("Angle2  =  %f \n", angle2);
			platform.ui.console("cl1").printf("Angle1 = %f \n", angle1);
			platform.ui.console("cl1").printf("--------------------------\n");
			hServoModule.s1.rotAbs(angle1);

		} else if (i == 3) {
			angle2 += 2;

			if (angle2 > 83) {
				angle2 = 83;
			}
			sys.delay(30);
			platform.ui.console("cl1").printf("Angle3  =  %f \n", angle3);
			platform.ui.console("cl1").printf("Angle2  =  %f \n", angle2);
			platform.ui.console("cl1").printf("Angle1 = %f \n", angle1);
			platform.ui.console("cl1").printf("--------------------------\n");
			hServoModule.s2.rotAbs(angle2);
		} else if (i == 4) {
			angle2 -= 2;

			if (angle2 < -10) {
				angle2 = -10;
			}
			sys.delay(30);
			platform.ui.console("cl1").printf("Angle3  =  %f \n", angle3);
			platform.ui.console("cl1").printf("Angle2  =  %f \n", angle2);
			platform.ui.console("cl1").printf("Angle1 = %f \n", angle1);
			platform.ui.console("cl1").printf("--------------------------\n");
			hServoModule.s2.rotAbs(angle2);
		} else if (i == 5) {
			angle3 -= 2;
			if (angle3 < -35) {
				angle3 = -35;
			}
			sys.delay(30);
			platform.ui.console("cl1").printf("Angle3  =  %f \n", angle3);
			platform.ui.console("cl1").printf("Angle2  =  %f \n", angle2);
			platform.ui.console("cl1").printf("Angle1 = %f \n", angle1);
			platform.ui.console("cl1").printf("--------------------------\n");
			hServoModule.s3.rotAbs(angle3);

		} else if (i == 6) {
			angle3 += 2;
			if (angle3 > 82.5) {
				angle3 = 82.5;
			}
			sys.delay(30);
			platform.ui.console("cl1").printf("Angle3  =  %f \n", angle3);
			platform.ui.console("cl1").printf("Angle2  =  %f \n", angle2);
			platform.ui.console("cl1").printf("Angle1 = %f \n", angle1);
			platform.ui.console("cl1").printf("--------------------------\n");
			hServoModule.s3.rotAbs(angle3);


		} else if (i == 7) {
			angle4 -= 5;
			if (angle4 < -90) {
				angle4 = -90;
			}
			sys.delay(30);
			platform.ui.console("cl2").printf("Angle4  =  %f \n", angle4);
			platform.ui.console("cl2").printf("Angle5  =  %f \n", angle5);
			platform.ui.console("cl2").printf("--------------------------\n");
			hServoModule.s4.rotAbs(angle4);


		} else if (i == 8) {
			angle4 += 5;
			if (angle4 > 90) {
				angle4 = 90;
			}
			sys.delay(30);
			platform.ui.console("cl2").printf("Angle4  =  %f \n", angle4);
			platform.ui.console("cl2").printf("Angle5  =  %f \n", angle5);
			platform.ui.console("cl2").printf("--------------------------\n");
			hServoModule.s4.rotAbs(angle4);

		} else if (i == 9) {
			angle5 -= 5;
			if (angle5  < -120) {
				angle5  = -120;
			}
			sys.delay(30);
			platform.ui.console("cl2").printf("Angle4  =  %f \n", angle4);
			platform.ui.console("cl2").printf("Angle5  =  %f \n", angle5);
			platform.ui.console("cl2").printf("--------------------------\n");
			hServoModule.s5.rotAbs(angle5);

		} else if (i == 10) {
			angle5  += 5;
			if (angle5  > -11) {
				angle5  = -11;
			}
			sys.delay(30);
			platform.ui.console("cl2").printf("Angle4  =  %f \n", angle4);
			platform.ui.console("cl2").printf("Angle5  =  %f \n", angle5);
			platform.ui.console("cl2").printf("--------------------------\n");
			hServoModule.s5.rotAbs(angle5);

		} else if (i == 11) {

			mot1 = 10;
			hMot1.rotRel(mot1);
			sys.delay(30);


		} else if (i == 12) {

			mot1 = -10;
			hMot1.rotRel(mot1);

			sys.delay(30);
		} else {
			i = 0;
			mot1 = 0;

		}
	}
}





void onKeyEvent(KeyEventType type, KeyCode code)    //keys handling 
{

	switch (code) {


	case KeyCode::Right: keyD = type == KeyEventType::Pressed; break;
	case KeyCode::Down:  keyS = type == KeyEventType::Pressed; break;

	case KeyCode::Key_L:
		if (type == KeyEventType::Pressed) {
			i = 1;
		}
		if (type == KeyEventType::Released) {
			i = 0;
		}
		break;

	case KeyCode::Key_P:
		if (type == KeyEventType::Pressed) {
			i = 2;
		}
		if (type == KeyEventType::Released) {
			i = 0;
		}
		break;

	case KeyCode::Key_O:
		if (type == KeyEventType::Pressed) {
			i = 3;
		}
		if (type == KeyEventType::Released) {
			i = 0;
		}
		break;

	case KeyCode::Key_K:
		if (type == KeyEventType::Pressed) {
			i = 4;
		}
		if (type == KeyEventType::Released) {
			i = 0;
		}
		break;

	case KeyCode::Key_J:
		if (type == KeyEventType::Pressed) {
			i = 5;
		}
		if (type == KeyEventType::Released) {
			i = 0;
		}
		break;

	case KeyCode::Key_I:
		if (type == KeyEventType::Pressed) {
			i = 6;
		}
		if (type == KeyEventType::Released) {
			i = 0;
		}
		break;

	case KeyCode::Key_A:
		if (type == KeyEventType::Pressed) {
			i = 7;
		}
		if (type == KeyEventType::Released) {
			i = 0;
		}
		break;


	case KeyCode::Key_D:
		if (type == KeyEventType::Pressed) {
			i = 8;
		}
		if (type == KeyEventType::Released) {
			i = 0;
		}
		break;

	case KeyCode::Key_W:
		if (type == KeyEventType::Pressed) {
			i = 9;
		}
		if (type == KeyEventType::Released) {
			i = 0;
		}
		break;


	case KeyCode::Key_S:
		if (type == KeyEventType::Pressed) {
			i = 10;
		}
		if (type == KeyEventType::Released) {
			i = 0;
		}
		break;

	case KeyCode::Key_Z:
		if (type == KeyEventType::Pressed) {
			i = 11;
		}
		if (type == KeyEventType::Released) {
			i = 0;
		}
		break;
	case KeyCode::Key_X:
		if (type == KeyEventType::Pressed) {
			i = 12;
		}
		if (type == KeyEventType::Released) {
			i = 0;
		}
		break;

	default : break;
	}
}



void hMain()
{

	platform.begin(&RPi);
	platform.ui.configHandler = cfgHandler;
	platform.ui.onKeyEvent = onKeyEvent;
	platform.ui.setProjectId("2026be4b06299d01");

	sys.taskCreate(servoMotionSeparately, 2, 1024, 0);

	sys.taskCreate(motorMotion, 2, 1024, 0);

	sys.taskCreate(debugConsole_task, 2, 1000, 0);
	sys.taskCreate(status_task, 2, 1000, 0);

	hMot1.setSlewRate(0.055);
	hMot2.setSlewRate(0.055);
	hMot3.setSlewRate(0.055);
	hMot4.setSlewRate(0.055);

	hSens1.pin1.setOut();
	hSens2.pin1.setOut();

	hServoModule.enablePower();


	sys.delay(50); // 50ms
	LED2.toggle();

}
