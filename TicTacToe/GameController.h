#pragma once
#include <list>
#include <vector>

#include "IWinnerSubject.h"

class GameController : public IWinnerSubject
{
public:
    GameController() : player_moves(10,-1){}
    bool validate_input(char player_input);
    virtual void attach(IWinnerObserver* observer) override;
    virtual void detach(IWinnerObserver* observer) override;
    virtual void notify() override;
    virtual ~GameController() override = default;
private:
    std::list<IWinnerObserver*> observer_list;
    std::vector<int> player_moves;
};
