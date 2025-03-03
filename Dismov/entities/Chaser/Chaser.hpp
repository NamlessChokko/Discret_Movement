#pragma once
#ifndef CHASER 
#define CHASER

#include "../../Dismov.hpp"


class Chaser : public Entity{
private:
    Entity *objective;

public:
    Chaser(Map &entity_map);
    ~Chaser() override;
    void set_objective(Entity *objective);
    virtual void chase();
    virtual void kill_objective();
    void turn() override;
};


#endif // CHASER    