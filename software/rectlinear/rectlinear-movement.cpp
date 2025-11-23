//Author: Piotr Paterek, Krak�w 05-08.2016
//Rectlinear movement

#include "hFramework.h"
#include "hCloudClient.h"

float x;
float y;
float z;
float teta;
float alfa;
float beta;
float gamma1;
float delta;
float tetar;
float psi = -50;
float kappa = 0;
int m;
int mot1;
int i;

hPIDRegulator pidReg;

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

void onValueChangeEvent(hId id, const char* data)
{
	LED1.toggle();
	//platform.ui.console("cl1").printf("qq ");
	if (id == "katTeta") {
		teta = atoi(data);
		platform.ui.console("cl2").printf("Gripper angle with base = %f \n", teta);

	}


}

void motorMotion()      //pid regulator for the motor
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

void onKeyEvent(KeyEventType type, KeyCode code) //key handling
{

	switch (code) {



	case KeyCode::Key_P:
		if (type == KeyEventType::Pressed) {
			i = 1;
		}
		if (type == KeyEventType::Released) {
			i = 0;
		}
		break;

	case KeyCode::Key_L:
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
		if (type == KeyEventType::Released) {
			i = 0;
		}
		break;
	case KeyCode::Key_X:
		if (type == KeyEventType::Pressed) {
			i = 10;
		}
		if (type == KeyEventType::Released) {
			i = 0;
		}
		break;

	}
}

void servoMotionPath()
{
	hServoModule.s1.calibrate(-90, 2400, 90, 800);  //servo calibration
	hServoModule.s2.calibrate(-90, 2400, 90, 800);
	hServoModule.s3.calibrate(-90, 800, 90, 2400);
	hServoModule.s4.calibrate(-90, 800, 90, 2400);
	hServoModule.s5.calibrate(-90, 800, 90, 2400);

	while (1) {                                     //inversed kinematics calculations
		sys.delay(10);

		tetar = teta * M_PI / 180;
		float r = y - 150.0 * cosf(tetar);
		float h = x - 150.0 * sinf(tetar);

		float d1 = sqrt(pow(h, 2) + pow(r, 2));
		float betar = acosf((45000.0 - pow(d1, 2)) / (45000.0));
		beta = betar;

		float alfar = atanf(h / r) + acosf(d1 / 300.0);
		alfa = (180 * (alfar - (M_PI / 2))) / M_PI; //first servo angle

		float d2 = sqrt(27541.0 + 21300.0 * cosf(betar));

		float gammar = acosf((17459.0 + pow(d2, 2)) / (300.0 * d2)) + acosf((pow(d2, 2) - 18779) / (122 * d2)) + alfar - (M_PI / 2);
		gamma1 = (180.0 * (gammar)) / M_PI;  // ksecond servo angle

		float A = sqrt(25000.0 - 15000.0 * cosf(0.428 + alfar - tetar));
		float  kat1 = acosf((20000.0 + pow(A, 2)) / (300.0 * A));
		float kat2 = M_PI - alfar - kat1;
		float B = sqrt(pow(27, 2) + pow(A, 2) - 2 * 27 * A * cosf(kat2));
		float kat3 = acosf((pow(B, 2) + pow(27, 2) - pow(A, 2)) / (54 * B));
		float kat4 = acosf((-18779.0 + pow(B, 2)) / (122.0 * B));

		delta = (M_PI - kat3 - kat4) * 180.0 / M_PI; // third servo angle
	
		if (i == 1) {                                   //servo angles with limits
		    if (x>129){                                                      
		        x=129                   ;                                      
		    }                                                                
			x += 2;
			hServoModule.s1.rotAbs(alfa);
			hServoModule.s2.rotAbs(gamma1);
			hServoModule.s3.rotAbs(delta);
			platform.ui.console("cl1").printf("Delta  =  %f \n", delta);
			platform.ui.console("cl1").printf("Gamma  =  %f \n", gamma1);
			platform.ui.console("cl1").printf("Alfa = %f \n", alfa);
			platform.ui.console("cl1").printf("--------------------------\n");
		} else if (i == 2) {
			x -= 2;
			hServoModule.s1.rotAbs(alfa);
			hServoModule.s2.rotAbs(gamma1);
			hServoModule.s3.rotAbs(delta);
			platform.ui.console("cl1").printf("Delta  =  %f \n", delta);
			platform.ui.console("cl1").printf("Gamma  =  %f \n", gamma1);
			platform.ui.console("cl1").printf("Alfa = %f \n", alfa);
			platform.ui.console("cl1").printf("--------------------------\n");


		} else if (i == 3) {
			y += 2;
			hServoModule.s1.rotAbs(alfa);
			hServoModule.s2.rotAbs(gamma1);
			hServoModule.s3.rotAbs(delta);
			platform.ui.console("cl1").printf("Delta  =  %f \n", delta);
			platform.ui.console("cl1").printf("Gamma  =  %f \n", gamma1);
			platform.ui.console("cl1").printf("Alfa = %f \n", alfa);
			platform.ui.console("cl1").printf("--------------------------\n");

		} else if (i == 4) {
			y -= 2;
			hServoModule.s1.rotAbs(alfa);
			hServoModule.s2.rotAbs(gamma1);
			hServoModule.s3.rotAbs(delta);
			platform.ui.console("cl1").printf("Delta  =  %f \n", delta);
			platform.ui.console("cl1").printf("Gamma  =  %f \n", gamma1);
			platform.ui.console("cl1").printf("Alfa = %f \n", alfa);
			platform.ui.console("cl1").printf("--------------------------\n");
		} else if (i == 5) {
			if (kappa > 90) {
				kappa = 90;
			}
			kappa += 2;
			hServoModule.s4.rotAbs(kappa);

			platform.ui.console("cl2").printf("Psi =  %f \n", psi);
			platform.ui.console("cl2").printf("Kappa =  %f \n", kappa);
			platform.ui.console("cl2").printf("--------------------------\n");

		} else if (i == 6) {
			if (kappa < -90) {
				kappa = -90;
			}
			kappa -= 2;
			hServoModule.s4.rotAbs(kappa);

			platform.ui.console("cl2").printf("Psi =  %f \n", psi);
			platform.ui.console("cl2").printf("Kappa =  %f \n", kappa);
			platform.ui.console("cl2").printf("--------------------------\n");

		} else if (i == 7) {
			if (psi > -40) {
				psi = -40;
			}
			psi += 2;
			hServoModule.s5.rotAbs(psi);

			platform.ui.console("cl2").printf("Psi =  %f \n", psi);
			platform.ui.console("cl2").printf("Kappa =  %f \n", kappa);
			platform.ui.console("cl2").printf("--------------------------\n");

		} else if (i == 8) {
			if (psi < -110) {
				psi = -110;
			}
			psi -= 2;
			hServoModule.s5.rotAbs(psi);

			platform.ui.console("cl2").printf("Psi =  %f \n", psi);
			platform.ui.console("cl2").printf("Kappa =  %f \n", kappa);
			platform.ui.console("cl2").printf("--------------------------\n");

		} else if (i == 9) {                        //motor control
        
			mot1 = 10;
			hMot1.rotRel(mot1);
			sys.delay(30);


		} else if (i == 10) {

			mot1 = -10;
			hMot1.rotRel(mot1);

			sys.delay(30);
		} else {
			i = 0;
			mot1 = 0;
		}

	}


}






void hMain()
{
	// For connection via Android:
	platform.begin(&RPi);
	platform.ui.configHandler = cfgHandler;
	platform.ui.onKeyEvent = onKeyEvent;
	sys.setLogDev(&Serial);

	platform.ui.onValueChangeEvent = onValueChangeEvent;

	platform.ui.setProjectId("53321f290d15eede");
	sys.taskCreate(servoMotionPath, 2, 1024, 0);
	sys.taskCreate(motorMotion, 2, 1024, 0);

	sys.taskCreate(debugConsole_task, 2, 1000, 0);
	sys.taskCreate(status_task, 2, 1000, 0);
	sys.delay(20);

	hServoModule.enablePower();
}
