#include "HittableList.h"

HittableList::HittableList(std::shared_ptr<Hittable> object)
{
	Add(object);
}

bool HittableList::Hit(const Ray& ray, const float tMin, const float tMax, HitData& hitData) const
{
	HitData tempHitData{};
	bool bHit{ false };
	float closestMax{ tMax };

	// We loop through all the objects and look for the one
	// closest to our ray direction
	for (const auto& object : m_objects)
	{
		if (object->Hit(ray, tMin, closestMax, tempHitData))
		{
			bHit = true;
			closestMax = tempHitData.t;
			hitData = tempHitData;
		}
	}

	return bHit;
}

void HittableList::Add(std::shared_ptr<Hittable> object)
{
	m_objects.push_back(object);
}

void HittableList::Clear()
{
	m_objects.clear();
}
