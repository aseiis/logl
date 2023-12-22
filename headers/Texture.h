#pragma once

#include "../vendor/glad.h"

#include <string>
#include <iostream>

#include "../vendor/stb_image.h"

class Texture
{
public:
	Texture();
	Texture(const std::string& path, int width, int height, int nbChannels);
	bool LoadData(std::string path, int width, int height, int nbChannels);
	int GetID();

private:
	unsigned int ID;
};