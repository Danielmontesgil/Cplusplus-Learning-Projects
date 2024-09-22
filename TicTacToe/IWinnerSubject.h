#pragma once

class IWinnerObserver;

class IWinnerSubject
{
public:
    virtual void attach(IWinnerObserver *observer) = 0;
    virtual void detach(IWinnerObserver *observer) = 0;
    virtual void notify() = 0;
    virtual ~IWinnerSubject() = default;
};
