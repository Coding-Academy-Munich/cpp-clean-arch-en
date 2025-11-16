#ifndef WIDGETV2_H
#define WIDGETV2_H
#include <memory>

namespace widget_v2 {
class WidgetV2 {
public:
    WidgetV2();
    ~WidgetV2();

    void PrintWidget() const;

    int GetState() const;
    int& GetState();
    void SetState(int state);

private:
    class Impl;
    std::unique_ptr<Impl> pImpl;
};
} // namespace widget_v2

#endif // WIDGETV2_H
