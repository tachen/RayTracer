/*
 * path.cpp
 *
 *  Created on: 2016年8月5日
 *      Author: zhuqian
 */

#include "path.h"
#include "RGB.h"
#include "scene.h"
#include "reflection.h"
#include "sampler.h"

void PathIntegrator::RequestSamples(Sampler *sampler, Sample *sample,
		const Scene *scene) {
	//申请相应的样本点
	for (int i = 0; i < SAMPLE_DEPTH; ++i) {
		lightSampleOffsets[i] = LightSampleOffsets(1, sample);
		lightNumOffset[i] = sample->Add1D(1);
		bsdfSampleOffsets[i] = BSDFSampleOffsets(1, sample);
		pathSampleOffsets[i] = BSDFSampleOffsets(1, sample);
	}
}

RGB PathIntegrator::Li(const Scene *scene, const Renderer *renderer,
				const RayDifferential &ray,const Sample *sample, const Intersection &isect, Random &rnd,
				MemoryArena& arena) const {

}

