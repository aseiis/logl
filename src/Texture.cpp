#include "../headers/Texture.h"

Texture::Texture()
{
    ID = 0;
}

Texture::Texture(const std::string& path, int width, int height, int nbChannels)
{
    glGenTextures(1, &ID);
    glBindTexture(GL_TEXTURE_2D, ID);
    
    // set the texture wrapping/filtering options (on the currently bound texture object)
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	this->LoadData(path, width, height, nbChannels);
}

int Texture::GetID()
{
    return this->ID;
}

bool Texture::LoadData(std::string path, int width, int height, int nbChannels)
{
    unsigned char* data = stbi_load(path.c_str(), &width, &height, &nbChannels, 0);
    bool status;

    if (data)
    {
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);
        status = true;
    }
    else
    {
        std::cout << "Failed to load texture at " << path << std::endl;
        status = false;
    }
    stbi_image_free(data);
    return status;
}

