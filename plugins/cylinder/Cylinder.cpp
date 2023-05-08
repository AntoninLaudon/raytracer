/*
** EPITECH PROJECT, 2023
** B-OOP-400-TLS-4-1-raytracer-tom.laiolo
** File description:
** Cylinder
*/

#include "Cylinder.hpp"

Raytracer::Cylinder::Cylinder(const std::string name, Math::Point3D center, Math::Vector3D direction, Math::Vector3D rotation, PPM::RGB rgb, double radius)
{
    _name = name;
    _center = center;
    _direction = direction;
    _rotation = rotation;
    _radius = radius;
    _type = CYLINDER;
    _rgb = rgb;
}

Raytracer::Cylinder::~Cylinder()
{
}

void Raytracer::Cylinder::translate(double x, double y, double z)
{
    _center.setX(_center.getX() + x);
    _center.setY(_center.getY() + y);
    _center.setZ(_center.getZ() + z);
}

void Raytracer::Cylinder::rotate(double x, double y, double z)
{
    _rotation.setX(_rotation.getX() + x);
    _rotation.setY(_rotation.getY() + y);
    _rotation.setZ(_rotation.getZ() + z);
}

double Raytracer::Cylinder::getLuminosity(std::vector<Raytracer::IElement *> &elements, const Math::Point3D &land) const
{
    (void)elements;
    (void)land;
    // double luminosity = 0.1;
    // int nbrLights = 0;
    // double dot = 0;

    // for (auto &element : elements) {
    //     if (element->getType() == Raytracer::LIGHT) {
    //         nbrLights++;
    //         Math::Vector3D centerToLight((_center.getX() - element->getCenter().getX()), (_center.getY() - element->getCenter().getY()), (_center.getZ() - element->getCenter().getZ()));
    //         Math::Vector3D centerToLand((_center.getX() - land.getX()), (_center.getY() - land.getY()), (_center.getZ() - land.getZ()));
    //         centerToLand.normalize();
    //         centerToLight.normalize();
    //         dot = centerToLand.dot(centerToLight);

    //         for (auto &primitive : elements) {
    //             if (primitive->getType() == Raytracer::PRIMITIVE && primitive->getName() != _name) {
    //                 std::shared_ptr<Math::Point3D> hit = primitive->hits(Math::Ray(land, element->getCenter() - land));
    //                 if (hit != nullptr) {
    //                     dot = 0;
    //                     break;
    //                 }
    //             }
    //         }
    //         luminosity += dot;
    //     }
    // }
    // if (nbrLights == 0)
    //     return luminosity;
    // luminosity /= nbrLights;

    // luminosity = luminosity < 0.1 ? 0.1 : luminosity;
    // if (luminosity == luminosity)
    //     return luminosity;
    return 1;

}

std::shared_ptr<Math::Point3D> Raytracer::Cylinder::hits(const Math::Ray &ray)
{
    Math::Point3D p = ray.getOrigin();
    Math::Point3D pa = _center;
    Math::Vector3D va = _rotation;
    Math::Vector3D v = ray.getDirection();
    double r = _radius;

    Math::Vector3D tmp1 = v - v.dot(va) * va;
    Math::Vector3D tmp2 = (p - pa) - (p - pa).dot(va) * va;
    double a = tmp1.dot(tmp1);
    double b = 2 * tmp1.dot(tmp2);
    double c = tmp2.dot(tmp2) - r * r;
    double delta = b * b - 4 * a * c;

    if (delta < 0)
        return nullptr;
    double t1 = (-b - sqrt(delta)) / (2 * a);
    double t2 = (-b + sqrt(delta)) / (2 * a);
    if (t1 < 0 && t2 < 0)
        return nullptr;
    if (t1 < 0)
        return std::make_shared<Math::Point3D>(p + t2 * v);
    if (t2 < 0)
        return std::make_shared<Math::Point3D>(p + t1 * v);
    if (t1 < t2)
        return std::make_shared<Math::Point3D>(p + t1 * v);
    return std::make_shared<Math::Point3D>(p + t2 * v);
}

extern "C" Raytracer::IElement *createObject(Raytracer::Data data) {
    std::cout << "Creating cylinder : " << data.getName() << std::endl;
    return new Raytracer::Cylinder(data.getName(), data.getCenter(), data.getDirection1(), data.getRotation(), data.getRGB(), data.getDouble());
}

extern "C" Raytracer::ElemType getType() {
    return Raytracer::CYLINDER;
}