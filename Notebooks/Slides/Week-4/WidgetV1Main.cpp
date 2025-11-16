#include "WidgetV1.h"
#include <iostream>

using widget_v1::WidgetV1;

int main() {
    WidgetV1 w;
    std::cout << "Non-const WidgetV1\n";
    w.PrintWidget();
    w.SetState(42);
    std::cout << "State is: " << w.GetState() << "\n";
    w.PrintWidget();

    const WidgetV1 w2;
    std::cout << "Const WidgetV1\n";
    w2.PrintWidget();
    // w2.SetState(42);
    std::cout << "State is: " << w2.GetState() << "\n";
    w2.PrintWidget();
}