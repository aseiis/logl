#pragma once

#include "../vendor/glad.h">

#include <string>
#include <iostream>

#include "../vendor/stb_image.h"

class Texture
{
public:
	Texture();
	Texture(std::string path, int width, int height, int nbChannels);
	bool LoadData(std::string path, int width, int height, int nbChannels);

private:
	unsigned int ID;
};