#pragma once
#ifndef CHASER 
#define CHASER

#include "../Dismov.hpp"


class Chaser : public Entity{
private:

protected:
    Entity *objective;

public:
    Chaser(Map &entity_map);
    ~Chaser() override;
    void set_objective(Entity *objective);
    void chase();
    void turn() override;
};


#endif // CHASER    