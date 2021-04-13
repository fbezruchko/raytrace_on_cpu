#include "hitableList.h"

bool hitableList::hit(const ray &r, float t_min, float t_max, tHitRecord &rec) const
{

    tHitRecord recTemp;
    bool hitAnything = false;
    float closestSoFar = t_max;
    for (int i = 0; i < listSize; i++)
    {
        if (list[i]->hit(r, t_min, closestSoFar, recTemp))
        {
            hitAnything = true;
            closestSoFar = recTemp.t;
            rec = recTemp;
        }
    }
    return hitAnything;
}