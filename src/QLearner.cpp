#include "QLearner.hpp"

int QLearner::getBestAction(int state)
{
    int best_action = 0;
    for(int i = 1; i < estimated_rewards[state].size(); i++)
    {
        float max_reward = estimated_rewards[state][best_action];
        if(estimated_rewards[state][i] > max_reward)
        {
            best_action = i;
        }
    }
    return best_action;
}

float QLearner::getMaxReward(int state)
{
    int best_action = getBestAction(state);
    return estimated_rewards[state][best_action];
}

QLearner::QLearner(float alpha, float gamma)
{
    learning_rate = alpha;
    discount = gamma;
}

void QLearner::initialize(int states, int actions)
{
    estimated_rewards = createTable(states, actions, 0);
    experience.current_state = 0;
    experience.action = 0;
}

void QLearner::setState(int state)
{
    experience.current_state = state;
}

void QLearner::setAction(int action)
{
    experience.action = action;
}

void QLearner::update(int reward, float state)
{
    experience.reward = reward;
    experience.next_state = state;

    float estimate = estimated_rewards[experience.current_state][experience.action];
    estimate += learning_rate*(experience.reward + discount*getMaxReward(experience.next_state) - estimate);

    experience.current_state = state;
    experience.action = getBestAction(experience.current_state);
}

int QLearner::getAction()
{
    return experience.action;
}
