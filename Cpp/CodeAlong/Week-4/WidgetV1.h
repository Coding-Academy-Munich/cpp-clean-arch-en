#ifndef WIDGETV1_H
#define WIDGETV1_H
#include <memory>

namespace widget_v1 {
class WidgetV1 {
public:
    WidgetV1();
    ~WidgetV1();

    void PrintWidget() const;

    int GetState() const;
    void SetState(int state);

private:
    class Impl;
    std::unique_ptr<Impl> pImpl;
};
} // namespace widget_v1

#endif // WIDGETV1_H
