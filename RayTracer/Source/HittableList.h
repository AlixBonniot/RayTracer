#ifndef HITTABLE_LIST_H
#define HITTABLE_LIST_H

#include "Hittable.h"

#include <vector>
#include <memory>

class HittableList : public Hittable
{
public:
	HittableList() = default;
	HittableList(std::shared_ptr<Hittable> object);

	virtual bool Hit(const Ray& ray, const float tMin, const float tMax, HitData& hitData) const override;

	void Add(std::shared_ptr<Hittable> object);
	void Clear();

private:
	std::vector<std::shared_ptr<Hittable>> m_objects;
};

#endif