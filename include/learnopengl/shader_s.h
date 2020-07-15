#ifndef SHADER_H
#define SHADER_H

#include "../glad/glad.h"
#include "../glm/glm.hpp"

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

using namespace std;

class Shader {
public:
    unsigned int ID;

    // constructor generates the shader on the fly
    // ------------------------------------------------------------------------
    Shader(const char *vertexPath, const char *fragmentPath) {
        // 1. retrieve the vertex/fragment source code from filePath
        cout << "vertexPath:" << vertexPath << " fragmentPath:" << fragmentPath << endl;
        string vertexCode;
        string fragmentCode;
        ifstream vShaderFile;
        ifstream fShaderFile;
        // ensure ifstream objects can throw exceptions:
        vShaderFile.exceptions(ifstream::failbit | ifstream::badbit);
        fShaderFile.exceptions(ifstream::failbit | ifstream::badbit);
        try {
            cout << "start open shader" << endl;
            // open files
            vShaderFile.open(vertexPath);
            fShaderFile.open(fragmentPath);
            stringstream vShaderStream, fShaderStream;
            // read file's buffer contents into streams
            cout << "read buffer from shader " << endl;
            vShaderStream << vShaderFile.rdbuf();
            fShaderStream << fShaderFile.rdbuf();
            // close file handlers
            vShaderFile.close();
            fShaderFile.close();
            // convert stream into string
            vertexCode = vShaderStream.str();
            fragmentCode = fShaderStream.str();
        } catch (std::ifstream::failure &e) {
            cout << "ERROR::SHADER::FILE_NOT_SUCCESFULLY_READ == " << endl;
        }

        if (vertexCode.c_str() != NULL) {
            cout << "vertexCode is not null \n" << vertexCode.c_str() << endl;
        }
        if (fragmentCode.c_str() != NULL) {
            cout << "fragCode is not null\n" << fragmentCode.c_str() << endl;
        }

        cout << " begin create shader " << endl;
        const char *vShaderCode = vertexCode.c_str();
        const char *fShaderCode = fragmentCode.c_str();
        cout << " ok begin create  shader variable " << endl;
        // 2. compile shaders
        unsigned int vertex, fragment;
        // vertex shader
        cout << "oh glCreate Vertex Shader Shader start " << endl;
        ///没有通过glad加载gl函数，导致这里直接崩溃，因为只有将gl函数加载到当前的上下文中，才能使用glXXX函数。
        vertex = glCreateShader(GL_VERTEX_SHADER);
        cout << "oh glCreate Vertex Shader Shader end " << endl;
        cout << "shader attach source  start " << endl;
        glShaderSource(vertex, 1, &vShaderCode, NULL);
        cout << "shader attach source end" << endl;
        glCompileShader(vertex);
        checkCompileErrors(vertex, "VERTEX");
        // fragment Shader
        fragment = glCreateShader(GL_FRAGMENT_SHADER);
        glShaderSource(fragment, 1, &fShaderCode, NULL);
        glCompileShader(fragment);
        checkCompileErrors(fragment, "FRAGMENT");
        // shader Program
        ID = glCreateProgram();
        glAttachShader(ID, vertex);
        glAttachShader(ID, fragment);
        glLinkProgram(ID);
        checkCompileErrors(ID, "PROGRAM");
        // delete the shaders as they're linked into our program now and no longer necessary
        glDeleteShader(vertex);
        glDeleteShader(fragment);

    }

    // activate the shader
    // ------------------------------------------------------------------------
    void use() {
        glUseProgram(ID);
    }

    void deleteID() {
        glDeleteProgram(ID);
    }

    // utility uniform functions
    // ------------------------------------------------------------------------
    void setBool(const std::string &name, bool value) const {
        glUniform1i(glGetUniformLocation(ID, name.c_str()), (int) value);
    }

    // ------------------------------------------------------------------------
    void setInt(const std::string &name, int value) const {
        glUniform1i(glGetUniformLocation(ID, name.c_str()), value);
    }

    // ------------------------------------------------------------------------
    void setFloat(const std::string &name, float value) const {
        glUniform1f(glGetUniformLocation(ID, name.c_str()), value);
    }

    void setMat4(const std::string &name, const glm::mat4 &mat) const {
        glUniformMatrix4fv(glGetUniformLocation(ID, name.c_str()), 1, GL_FALSE, &mat[0][0]);
    }

private:
    // utility function for checking shader compilation/linking errors.
    // ------------------------------------------------------------------------
    void checkCompileErrors(unsigned int shader, std::string type) {
        cout << "check compile status " << endl;
        int success;
        char infoLog[1024];
        if (type != "PROGRAM") {
            glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
            if (!success) {
                glGetShaderInfoLog(shader, 1024, NULL, infoLog);
                cout << "ERROR::SHADER_COMPILATION_ERROR of type: " << type << "\n" << infoLog
                     << "\n -- --------------------------------------------------- -- " << endl;
            } else {
                cout << "compile program success" << endl;
            }
        } else {
            glGetProgramiv(shader, GL_LINK_STATUS, &success);

            if (!success) {
                glGetProgramInfoLog(shader, 1024, NULL, infoLog);
                cout << "ERROR::PROGRAM_LINKING_ERROR of type: " << type << "\n" << infoLog
                     << "\n -- --------------------------------------------------- -- " << endl;
            } else {
                cout << " compile shader success" << endl;
            }
        }
    }
};

#endif
