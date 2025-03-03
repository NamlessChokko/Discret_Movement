#pragma once 
#ifndef CLEANER
#define CLEANER

#include "../Entities.hpp"

class Cleaner : public Chaser {
    private:
    corpse *objective;    
    int corpse_id;

    public:
        Cleaner(Map &map);
        ~Cleaner();
        void kill_objective() override;
        void chase() override;
        void find_objective();
        void turn() override;
};


#endif // CLEANER