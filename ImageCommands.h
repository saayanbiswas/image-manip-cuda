#ifndef IMAGE_COMMANDS_H_
#define IMAGE_COMMANDS_H_

#include <cuda.h>
#include <cuda_runtime.h>

#include <iostream>
#include <string>

#include <cmath>

#include "device_launch_parameters.h"

#define PI 3.14159265358979323846f

class ImageCommand {
public:
	virtual void execute(uchar4** image, size_t* height, size_t* width) = 0;
	virtual std::string toString() = 0;
	virtual ~ImageCommand();
};

class BlackWhiteImageCommand : public ImageCommand {
public:
	void execute(uchar4** image, size_t* height, size_t* width);
	std::string toString();
};

class RotateImageCommand : public ImageCommand {
	float phi;
public:
	RotateImageCommand(float phi);
	void execute(uchar4** image, size_t* height, size_t* width);
	std::string toString();
};

class GammaCorrectionImageCommand : public ImageCommand {
	float gc;
public:
	GammaCorrectionImageCommand(float gc);
	void execute(uchar4** image, size_t* height, size_t* width);
	std::string toString();
};

class RadialDistortionImageCommand : public ImageCommand {
	float k1;
public:
	RadialDistortionImageCommand(float phi);
	void execute(uchar4** image, size_t* height, size_t* width);
	std::string toString();
};


class ContrastImageCommand : public ImageCommand {
	float alpha;
public:
	ContrastImageCommand(float alpha);
	void execute(uchar4** image, size_t* height, size_t* width);
	std::string toString();
};

class SharpeningImageCommand : public ImageCommand {
public:
	void execute(uchar4** image, size_t* height, size_t* width);
	std::string toString();
};

class SkewImageCommand : public ImageCommand {
	float thetaX, thetaY;
public:
	SkewImageCommand(float thetaX, float thetaY);
	void execute(uchar4** image, size_t* height, size_t* width);
	std::string toString();
};

class GaussianBlurImageCommand : public ImageCommand {
public:
	void execute(uchar4** image, size_t* height, size_t* width);
	std::string toString();
};

#endif