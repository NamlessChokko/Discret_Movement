#pragma once
#ifndef DUMB
#define DUMB

#include "../../Dismov.hpp"

class Dummy : public Entity{
public:
    Dummy(Map &entity_map);
    ~Dummy() override;
    void turn() override;
};


#endif // DUMB