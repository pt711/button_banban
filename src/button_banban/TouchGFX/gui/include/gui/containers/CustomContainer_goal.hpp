#ifndef CUSTOMCONTAINER_GOAL_HPP
#define CUSTOMCONTAINER_GOAL_HPP

#include <gui_generated/containers/CustomContainer_goalBase.hpp>

class CustomContainer_goal : public CustomContainer_goalBase
{
public:
    CustomContainer_goal();
    virtual ~CustomContainer_goal() {}

    virtual void initialize();

    int type = 9;
protected:
};

#endif // CUSTOMCONTAINER_GOAL_HPP
