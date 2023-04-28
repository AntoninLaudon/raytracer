/*
** EPITECH PROJECT, 2023
** B-OOP-400-TLS-4-1-raytracer-tom.laiolo
** File description:
** Light
*/

#pragma once

#include <memory>
#include "AElement.hpp"
#include "Data.hpp"

namespace Raytracer {
    class Light : public AElement{
        public:
            Light(const std::string& name, Math::Vector3D& position, Math::Vector3D& rotation);
            ~Light();
            void translate(float x, float y, float z);
            //void rotate(float x, float y, float z);
            void clearElement();
            Math::Point3D Intersect();
            static std::shared_ptr <Raytracer::IElement> createObject(Raytracer::Data data) {
                return std::make_shared<Raytracer::Light>(data.getName(), data.getCenter(), data.getRotation());
            }
        protected:
        private:
    };
}
