#ifndef WIDGETV3_H
#define WIDGETV3_H
#include <memory>
#include "propagate_const.h"

namespace widget_v3 {
class WidgetV3 {
public:
    WidgetV3();
    ~WidgetV3();

    void PrintWidget() const;

    int GetState() const;
    int& GetState();
    void SetState(int state);

private:
    class Impl;
    std::experimental::propagate_const<std::unique_ptr<Impl>> pImpl;
};
} // namespace widget_v3

#endif // WIDGETV3_H
