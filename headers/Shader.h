#pragma once

#include "../vendor/glad.h" // include glad to get all the required OpenGL headers

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>


class Shader
{
public:
    // constructor reads and builds the shader
    Shader(std::string vertexPath, std::string fragmentPath);
    ~Shader(); //selfmade
    int GetID();
    // use/activate the shader
    void use();
    // utility uniform functions
    void setBool(const std::string& name, bool value) const;
    void setInt(const std::string& name, int value) const;
    void setFloat(const std::string& name, float value) const;

private:
    // the program ID
    unsigned int ID;
};