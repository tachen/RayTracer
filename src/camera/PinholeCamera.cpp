//
// Created by 诸谦 on 15/12/28.
//


#include "PinholeCamera.h"
#include "transform.h"
#include "sampler.h"
#include "film.h"
PinholeCamera::PinholeCamera(Film * f,Transform * c2w, const float distance, const float zoomFactor)
        :Camera(f,c2w),mDistanceToView(distance),mZoomFactor(zoomFactor){
	xOffset=this->film->xResolution * 0.5f;
	yOffset=this->film->yResolution * 0.5f;
}

void PinholeCamera::setDistanceToView(const float d){
    mDistanceToView=d;
}
//
//Ray PinholeCamera::GenerateRay(const Point& p) const {
//
//    Point zero;
//    Point eye=(*cameraToWorld)(zero);
//    Point pp=(*cameraToWorld)(Point(p.x,p.y,mDistanceToView));
//    Ray ray(eye,Normalize(pp-eye),0);
//
////    Vector dir=Normalize(u * p.x + v * p.y + w * mDistanceToView);//注意这里是d*w 构成左手手坐标系统
////    Ray ray(eye,dir,0);
//    return ray;
//}

float PinholeCamera::GenerateRay(const CameraSample &sample,
                             Ray *ray) const {
	    Point zero;
	    Point eye=(*cameraToWorld)(zero);
	    Point pp=(*cameraToWorld)(Point(sample.imageX-xOffset,sample.imageY-yOffset,mDistanceToView));
	    ray->o=eye;
	    ray->d=Normalize(pp-eye);
	    ray->minT=0;
	    ray->maxT=INFINITY;
	    ray->depth=0;
	    return 1;
}
