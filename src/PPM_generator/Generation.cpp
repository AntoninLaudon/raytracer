/*
** EPITECH PROJECT, 2023
** B-OOP-400-TLS-4-1-raytracer-tom.laiolo
** File description:
** Generation
*/

#include "Generation.hpp"

PPM::PPM::PPM(int width, int height)
{
    _width = width;
    _height = height;
    _pixels = new RBG[width * height];
    _version = "P3";
    fill({0, 0, 0});
}

PPM::PPM::~PPM()
{
    delete[] _pixels;
}

void PPM::PPM::setVersion(std::string version)
{
    _version = version;
}

void PPM::PPM::setPixel(int x, int y, RBG color)
{
    if (x < 0 || x >= _width || y < 0 || y >= _height)
        return;
    _pixels[y * _width + x] = color;
}

void PPM::PPM::save(const char *filename)
{
    std::ofstream output(filename, std::ios::binary);

    if (output.is_open()) {
        output << _version << std::endl;
        output << _width << std::endl;
        output << _height << std::endl;
        output << "255" << std::endl;

        if (_version == "P3") {
            for (int i = 0; i < _height; i++) {
                for (int j = 0; j < _width; j++) {
                    output << (int)_pixels[i * _width + j].r << " ";
                    output << (int)_pixels[i * _width + j].g << " ";
                    output << (int)_pixels[i * _width + j].b << "\n";
                }
            }
        } else {
            for (int i = 0; i < _height; i++) {
                for (int j = 0; j < _width; j++)
                    output.write((char *)&_pixels[i * _width + j], sizeof(RBG));
            }
        }
    }
    output.close();
}

void PPM::PPM::clear()
{
    fill({0, 0, 0});
}

void PPM::PPM::fill(RBG color)
{
    for (int i = 0; i < _width * _height; i++)
        _pixels[i] = color;
}