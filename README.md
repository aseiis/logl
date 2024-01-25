This is a cross-platform project for building a minimal OpenGL application. It uses CMake that can work both on Windows and Linux (should work on MacOS but hasn't be tested yet)

The code follows the tutorial at https://learnopengl.com/

## How to build and run?

### Linux

Make sure to have at least the following packages installed (Debian-based, Ubuntu...): 
```
apt update
apt install libglfw3 libglfw3-dev
```

For Fedora, Arch and other distros, check the packages for GLFW3.

Depending on your system, you might need/want to install Mesa which is an open-source implementation of OpenGL.

To build and run the project, just run the minimal script provided: ```./buildandrun.sh```

### Windows

On Windows, **Visual Studio** si recommanded as it is very common in the industry for graphics prog. Remember to install the extension for **CMake**.

You need to install the **GLFW3 library** and set the directory path to a ***new environnement variable*** <code>GLFW_DIR</code> that you'll create. You can find source code or even binaries there: https://www.glfw.org/download.

**IMPORTANT:** <br/>
**The CMake file is configured to use an environnement variable nammed <code>GLFW_DIR</code> that you *MUST* set to the path of the directory where GLFW3 is installed. It'll automatically extract the include files as well as the lib.**

If the CMake generation behave erratically, try to delete the cache and re-run CMake generation with "Project" > "Delete Cache and Reconfigure".

### Note on GLAD dependency

***GLAD*** is an **OpenGL loader** that prepare all the encessary OpenGL functions we need. We use a **single header file glad.h** (along with khrplatform.h) that is **dependent of the GLFW version** we're using. Depending of the version, you might need to replace the GLAD header file with a different one that you'll find there: https://glad.dav1d.de/