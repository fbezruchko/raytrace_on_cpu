#ifndef HITABLELISTH
#define HITABLELISTH

#include "hitable.h"

class hitableList : public hitable
{
public:
    hitableList() {}
    hitableList(hitable **l, int n)
    {
        list = l;
        listSize = n;
    }
    virtual bool hit(
        const ray &r, float t_min, float t_max, tHitRecord &rec) const;
    hitable **list;
    int listSize;
};



#endif