//Author: Piotr Paterek, Krak�w 05-08.2016

#include "hFramework.h"
#include "hCloudClient.h"

float x;
float y;
float z;
float teta = 0;
float alfa = 0;
float beta;
float gamma1 = 0;
float delta = 0;
float tetar;
float kappa = 0;
float psi = -50;
float z1;
int i;
int mot1;


hPIDRegulator pidReg;

void debugConsole_task()
{
	char ch;

	platform.printf("Enter char:\r\n");
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

void onValueChangeEvent(hId id, const char* data)   // text box handling
{
	LED1.toggle();
	//platform.ui.console("cl1").printf("qq ");
	if (id == "slider1") {
		int val = atoi(data);

//		platform.ui.console("cl1").printf("slider %s changed to %d \n", id.str(), val);
	} else if (id == "wspX") {
		x = atoi(data);
//		platform.ui.console("cl2").printf("na %s jest wspolrzedna x = %f \n", id.str(), x);
	} else if (id == "wspY") {
		y = atoi(data);
//		platform.ui.console("cl2").printf("na %s jest wspolrzedna y = %f \n", id.str(), y);
	} else if (id == "wspZ") {
		z = atoi(data);
//		platform.ui.console("cl2").printf("na %s jest wspolrzedna z = %f \n", id.str(), z);
	} else if (id == "katTeta") {
		teta = atoi(data);
//		platform.ui.console("cl2").printf("na %s jest wspolrzedna z = %f \n", id.str(), teta);

	}


}

void onKeyEvent(KeyEventType type, KeyCode code)            //keys handling
{

	switch (code) {
	case KeyCode::Key_A:
		if (type == KeyEventType::Pressed) {
			i = 5;
		}
		if (type == KeyEventType::Released) {
			i = 0;
		}
		break;
	case KeyCode::Key_D:
		if (type == KeyEventType::Pressed) {
			i = 6;
		}
		if (type == KeyEventType::Released) {
			i = 0;
		}
		break;
	case KeyCode::Key_W:
		if (type == KeyEventType::Pressed) {
			i = 7;
		}
		if (type == KeyEventType::Released) {
			i = 0;
		}
		break;
	case KeyCode::Key_S:
		if (type == KeyEventType::Pressed) {
			i = 8;
		}
		if (type == KeyEventType::Released) {
			i = 0;
		}
		break;
	case KeyCode::Key_Z:
		if (type == KeyEventType::Pressed) {
			i = 9;
		}
		break;
	case KeyCode::Key_X:
		if (type == KeyEventType::Pressed) {
			i = 0;
		}

		break;

	}
}



void servoMotionXYZ()
{
	hServoModule.s1.calibrate(-90, 2400, 90, 800); //servo calibrations
	hServoModule.s2.calibrate(-90, 2400, 90, 800);
	hServoModule.s3.calibrate(-90, 800, 90, 2400);
	hServoModule.s4.calibrate(-90, 800, 90, 2400);
	hServoModule.s5.calibrate(-90, 800, 90, 2400);

	while (1) {                     //reversed kinematics calculations
		sys.delay(10);

		tetar = teta * M_PI / 180;
		float r = y - 150.0 * cosf(tetar);
		float h = x - 150.0 * sinf(tetar);

		float d1 = sqrt(pow(h, 2) + pow(r, 2));
		float betar = acosf((45000.0 - pow(d1, 2)) / (45000.0));
		beta = betar;

		float alfar = atanf(h / r) + acosf(d1 / 300.0);
		alfa = (180 * (alfar - (M_PI / 2))) / M_PI; //first servo angles

		float d2 = sqrt(27541.0 + 21300.0 * cosf(betar));

		float gammar = acosf((17459.0 + pow(d2, 2)) / (300.0 * d2)) + acosf((pow(d2, 2) - 18779) / (122 * d2)) + alfar - (M_PI / 2);
		gamma1 = (180.0 * (gammar)) / M_PI;  // second servo angles

		float A = sqrt(25000.0 - 15000.0 * cosf(0.428 + alfar - tetar));
		float  kat1 = acosf((20000.0 + pow(A, 2)) / (300.0 * A));
		float kat2 = M_PI - alfar - kat1;
		float B = sqrt(pow(27, 2) + pow(A, 2) - 2 * 27 * A * cosf(kat2));
		float kat3 = acosf((pow(B, 2) + pow(27, 2) - pow(A, 2)) / (54 * B));
		float kat4 = acosf((-18779.0 + pow(B, 2)) / (122.0 * B));

		delta = (M_PI - kat3 - kat4) * 180.0 / M_PI; // third servo angles
            z1 = 8300*z/360;                                                  

		if (i == 5) {                                   //servo angles with limits
			if (kappa > 90) {
				kappa = 90;
			}
			kappa += 2;
			hServoModule.s4.rotAbs(kappa);

			platform.ui.console("cl1").printf("Psi =  %f \n", psi);
			platform.ui.console("cl1").printf("Kappa =  %f \n", kappa);
			platform.ui.console("cl1").printf("--------------------------\n");

		} else if (i == 6) {
			if (kappa < -90) {
				kappa = -90;
			}
			kappa -= 2;
			hServoModule.s4.rotAbs(kappa);

			platform.ui.console("cl1").printf("Psi =  %f \n", psi);
			platform.ui.console("cl1").printf("Kappa =  %f \n", kappa);
			platform.ui.console("cl1").printf("--------------------------\n");

		} else if (i == 7) {
			if (psi > -40) {
				psi = -40;
			}
			psi += 2;
			hServoModule.s5.rotAbs(psi);

			platform.ui.console("cl1").printf("Psi =  %f \n", psi);
			platform.ui.console("cl1").printf("Kappa =  %f \n", kappa);
			platform.ui.console("cl1").printf("--------------------------\n");

		} else if (i == 8) {
			if (psi < -110) {
				psi = -110;
			}
			psi -= 2;
			hServoModule.s5.rotAbs(psi);

			platform.ui.console("cl1").printf("Psi =  %f \n", psi);
			platform.ui.console("cl1").printf("Kappa =  %f \n", kappa);
			platform.ui.console("cl1").printf("--------------------------\n");

		} else if (i == 9) {                        // motor handling
			if (hMot1.getEncoderCnt() +5 < z1) {
				if (1) {
					sys.delay(10);
					hMot1.rotAbs(hMot1.getEncoderCnt() + 5);
				}

				platform.ui.console("cl1").printf("Encoder ticks =  %d \n", hMot1.getEncoderCnt());



			} else if (hMot1.getEncoderCnt() - 5 > z1) {
				if (1) {
					sys.delay(10);
					hMot1.rotAbs(hMot1.getEncoderCnt() - 5);
				}
				platform.ui.console("cl1").printf("Encoder ticks =  %d \n", hMot1.getEncoderCnt());




			} else if (hMot1.getEncoderCnt() == z1) {

				hMot1.setPower(0);

			} else {

			}
		}
	}
}




void motor()                        //pid regulator for motor
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


void onButtonEvent(hId id, ButtonEventType type)                //button handling
{


	UiButton b = platform.ui.button("btn1");
	if (id == "btn1") {
		if (type == ButtonEventType::Pressed) {

			platform.ui.console("cl2").printf("Alfa =  %f \n", alfa);
			platform.ui.console("cl2").printf("Gamma =  %f \n", beta);
			platform.ui.console("cl2").printf("Delta =  %f \n", gamma1);
			platform.ui.console("cl2").printf("-------------------------\n");

			hServoModule.s1.rotAbs(alfa);
			hServoModule.s2.rotAbs(gamma1);
			hServoModule.s3.rotAbs(delta);



		}
	}
}




void hMain()
{
	// For connection via Android:
	platform.begin(&RPi);
	platform.ui.configHandler = cfgHandler;
	platform.ui.onButtonEvent = onButtonEvent;

	sys.setLogDev(&Serial);

	platform.ui.onValueChangeEvent = onValueChangeEvent;


	platform.ui.onKeyEvent = onKeyEvent;

	platform.ui.setProjectId("69e9e8c852599cce");
	sys.taskCreate(servoMotionXYZ, 2, 1024, 0);
	sys.taskCreate(motor, 2, 1024, 0);

	sys.taskCreate(debugConsole_task, 2, 1000, 0);
	sys.taskCreate(status_task, 2, 1000, 0);
	sys.delay(20);

	hServoModule.enablePower();
}
