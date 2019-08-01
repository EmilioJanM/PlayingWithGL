#pragma once

class Time{
private:
	static float oldT, newT;
public:
	static float DeltaTime;
	static void updateDelta(float f) {
		oldT = newT;
		newT = f;
		DeltaTime = newT - oldT;
	}

};

float Time::oldT = 0;
float Time::newT = 0;
float Time::DeltaTime = 0;