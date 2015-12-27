//
// Created by 诸谦 on 15/12/27.
//

#include "Matte.h"
#include "../common/Ray.h"
#include "../scene/Scene.h"

Matte::Matte(const RGB& _albedo):
        mAmbientBrdf(shared_ptr<Lambertian>(new Lambertian(_albedo))),
        mDiffuseBrdf(shared_ptr<Lambertian>(new Lambertian(_albedo))){

}

void Matte::scaleAmbientAlbedo(const float k) {
    mAmbientBrdf->scaleAlbedo(k);
}

void Matte::scaleDiffuseAlbedo(const float k) {
    mDiffuseBrdf->scaleAlbedo(k);
}

void Matte::setAlbedo(const RGB &color) {
    mAmbientBrdf->setAlbedo(color);
    mDiffuseBrdf->setAlbedo(color);
}

RGB Matte::shade(ShadeRec &sr) {
    Vector3 wo=-sr.ray.direction;
    RGB L=sr.scene.ambient()->L(sr)*mAmbientBrdf->rho(sr,wo);
    unsigned long lignt_num=sr.scene.getLightNum();
    for(unsigned long i=0;i<lignt_num;++i){
        Vector3 wi=sr.scene.getLight(i)->getDirection(sr);
        double ndotl=sr.normal.dot(wi);
        if(ndotl>0){
            L=L+sr.scene.getLight(i)->L(sr)*mDiffuseBrdf->f(sr,wi,wo)*ndotl;
        }
    }
    return L;
}

RGB Matte::areaLightShade(ShadeRec &sr) {
    return RGB(0,0,0);
}
