#include "WidgetV2.h"
#include <iostream>

using widget_v2::WidgetV2;

int main() {
    WidgetV2 w;
    std::cout << "Non-const WidgetV2\n";
    w.PrintWidget();
    w.SetState(42);
    std::cout << "State is: " << w.GetState() << "\n";
    w.PrintWidget();

    const WidgetV2 w2;
    std::cout << "Const WidgetV2\n";
    w2.PrintWidget();
    // w2.SetState(42);
    std::cout << "State is: " << w2.GetState() << "\n";
    w2.PrintWidget();
}