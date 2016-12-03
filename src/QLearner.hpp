#ifndef QLEARNER_HPP_INCLUDED
#define QLEARNER_HPP_INCLUDED

#include "Experience.hpp"
#include "Table.hpp"

class QLearner
{
    float learning_rate;
    float discount;
    Table estimated_rewards;
    Experience experience;

    int getBestAction(int);
    float getMaxReward(int);

public:
    QLearner(float, float);
    void initialize(int, int);
    void setState(int);
    void setAction(int);
    void update(float, int);
    int computeAction();
};

#endif // QLEARNER_HPP_INCLUDED
