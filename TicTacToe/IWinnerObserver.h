#pragma once

class IWinnerObserver
{
public:
    virtual void update() = 0;
    virtual ~IWinnerObserver() = default;
};
