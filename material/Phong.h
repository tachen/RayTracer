//
// Created by 诸谦 on 15/12/27.
//

#ifndef RAYTRACER_PHONG_H
#define RAYTRACER_PHONG_H


#include "Material.h"
#include "../brdf/Lambertian.h"
#include "../brdf/GlossySpecular.h"
#include <memory>
using namespace std;

class Phong : public Material{
private:
    Lambertian mAmbientBrdf;
    Lambertian mDiffuseBrdf;
    GlossySpecular mSpecularBrdf;
public:
    void scaleAmbientAlbedo(const float k);
    void scaleDiffuseAlbedo(const float k);
    void scaleSpecularAlbedo(const float k,const float exp);
    void setAlbedo(const RGB& color);


    virtual RGB shade(ShadeRec &sr);

    virtual RGB areaLightShade(ShadeRec &sr);
};


#endif //RAYTRACER_PHONG_H
